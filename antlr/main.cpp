#include <iostream>

#include "ProBaseVisitor.h"
#include "ProLexer.h"
#include "ProParser.h"
#include "antlr4-runtime.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace std;
using namespace antlr4;

class IRGenerator : public ProBaseVisitor {
  llvm::LLVMContext context;
  llvm::IRBuilder<> builder;
  std::unique_ptr<llvm::Module> module;

 public:
  IRGenerator() : builder(context), module(new llvm::Module("top", context)) {}

  virtual antlrcpp::Any visitProg(ProParser::ProgContext *ctx) override {
    // Get a function with the return type void and no arguments and set it as
    // the main function
    llvm::FunctionType *funcType =
        llvm::FunctionType::get(llvm::Type::getVoidTy(this->context), false);
    llvm::Function *mainFunc = llvm::Function::Create(
        funcType, llvm::Function::ExternalLinkage, "main", this->module.get());

    // Create the entry basic block
    llvm::BasicBlock *entryBlock =
        llvm::BasicBlock::Create(this->context, "entry", mainFunc);
    // Set the insertion point to the entry block
    builder.SetInsertPoint(entryBlock);
    // Visit all children of the program node
    cout << "DBG_F Visiting program" << endl;
    visitChildren(ctx);

    cout << "DBG_F Creating return instruction" << endl;
    // Create a return instruction
    builder.CreateRetVoid();

    cout << "RET6\n";

    return nullptr;
  }

  virtual antlrcpp::Any visitExpr(ProParser::ExprContext *ctx) override {
    cout << "Visiting expression\n";
    // Check if the expression is an integer
    if (ctx->INT() != nullptr) {
      return visitIntExpr(ctx);
    }

    // Check if the expression is an identifier
    if (ctx->ID() != nullptr) {
      return visitIdExpr(ctx);
    }

    // Check if the expression is an array construction
    if (ctx->array_construction() != nullptr) {
      return visitArray_construction(ctx->array_construction());
    }

    // Check if the expression is an char
    if (ctx->CHAR() != nullptr) {
      cout << "Visiting char expression\n";
      return visitCharExpr(ctx);
    }

    // Check if the expression is a string
    if (ctx->STRING() != nullptr) {
      cout << "Visiting string expression\n";
      return visitStringExpr(ctx);
    }

    if (ctx->function_call() != nullptr) {
      cout << "DBG_F1\n";
      return visitFunction_call(ctx->function_call());
    }

    throw std::runtime_error("Expression type not handled");
    return nullptr;
  }

  virtual antlrcpp::Any visitStatement(
      ProParser::StatementContext *ctx) override {
    if (ctx->assignment() != nullptr) {
      return visitAssignment(ctx->assignment());
    }

    if (ctx->expr() != nullptr) {
      return visitExpr(ctx->expr());
    }

    if (ctx->function_declaration() != nullptr) {
      return visitFunction_declaration(ctx->function_declaration());
    }

    throw std::runtime_error("Statement type not handled");
    return nullptr;
  }

  antlrcpp::Any visitStringExpr(ProParser::ExprContext *ctx) {
    antlr4::tree::TerminalNode *terminalNode = ctx->STRING();

    Token *token = terminalNode->getSymbol();
    string text = token->getText();
    // get value at index 1 because the first and last character is a double
    // quote ("hello" -> hello)
    string value = text.substr(1, text.size() - 2);
    // add null terminator
    value += '\0';

    llvm::Constant *constantDataArray =
        llvm::ConstantDataArray::getString(context, value, true);

    llvm::GlobalVariable *globalVariable = new llvm::GlobalVariable(
        *module, constantDataArray->getType(), true,
        llvm::GlobalValue::InternalLinkage, constantDataArray, "string");

    llvm::Value *pointer = builder.CreatePointerCast(
        globalVariable,
        llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)));

    return pointer;
  }

  bool isInternalFunction(std::string funcName) {
    string internalFunctions[] = {"putchar", "printf"};
    for (auto internalFunction : internalFunctions) {
      if (internalFunction == funcName) {
        return true;
      }
    }
    return false;
  }

  llvm::Value *callInternalFunction(std::string funcName,
                                    std::vector<llvm::Value *> args) {
    if (funcName == "printf") {
      llvm::Function *printfFunc;

      if (functionProtos.count("printf") == 0) {
        // Create a printf function prototype
        llvm::FunctionType *printfType = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(context),
            llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)), true);
        printfFunc =
            llvm::Function::Create(printfType, llvm::Function::ExternalLinkage,
                                   "printf", module.get());
        functionProtos["printf"] = printfFunc;
      } else {
        printfFunc = functionProtos["printf"];
      }

      // Create a call to the printf function
      llvm::Value *call = builder.CreateCall(printfFunc, args);

      return call;
    }

    if (funcName == "putchar") {
      llvm::Function *putcharFunc;

      if (functionProtos.count("putchar") == 0) {
        // Create a putchar function prototype
        llvm::FunctionType *putcharType = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(context),
            llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)),
            false);
        putcharFunc =
            llvm::Function::Create(putcharType, llvm::Function::ExternalLinkage,
                                   "putchar", module.get());
        functionProtos["putchar"] = putcharFunc;
      } else {
        putcharFunc = functionProtos["putchar"];
      }

      // Create a call to the putchar function
      llvm::Value *call = builder.CreateCall(putcharFunc, args);

      return call;
    }

    throw std::runtime_error("Internal function not found");

    return nullptr;
  }

  virtual antlrcpp::Any visitFunction_call(
      ProParser::Function_callContext *ctx) override {
    std::vector<llvm::Value *> args;

    // Visit all arguments
    if (ctx->expr_list() != nullptr) {
      args = std::any_cast<std::vector<llvm::Value *>>(
          visitExpr_list(ctx->expr_list()));
    } else {
      cout << "EXPR_LIST is null\n";
    }

    // Get the function name
    std::string funcName = ctx->ID()->getText();

    llvm::Value *result = nullptr;

    if (isInternalFunction(funcName)) {
      return callInternalFunction(funcName, args);
    }

    // call the function
    llvm::Function *function = functionProtos[funcName];

    if (function == nullptr) {
      throw std::runtime_error("Function not found: " + funcName);
    }

    // Create a call to the function
    result = builder.CreateCall(function, args);

    return result;
  }

  virtual antlrcpp::Any visitFunction_declaration(
      ProParser::Function_declarationContext *ctx) override {
    cout << "Visiting function declaration\n";

    // Get return type from first token
    std::string returnType = ctx->ID(0)->getSymbol()->getText();

    cout << "returnType: " << returnType << endl;

    std::string funcName = ctx->ID(1)->getSymbol()->getText();

    // create new block from function body
    llvm::Function *function = llvm::Function::Create(
        llvm::FunctionType::get(llvm::Type::getVoidTy(context), false),
        llvm::Function::ExternalLinkage, funcName, module.get());

    // Create a new basic block for the function
    llvm::BasicBlock *basicBlock =
        llvm::BasicBlock::Create(context, funcName, function);

    // Save the current insertion point
    llvm::BasicBlock *currentBlock = builder.GetInsertBlock();

    // Set the newly created block as the current block of execution
    builder.SetInsertPoint(basicBlock);

    // Visit the function's body
    visitBlock(ctx->block());

    // Add a return statement at the end of the function
    builder.CreateRetVoid();

    // Restore the previous insertion point
    builder.SetInsertPoint(currentBlock);

    // Save the function prototype

    functionProtos[funcName] = function;

    return nullptr;
  }

  virtual antlrcpp::Any visitBlock(ProParser::BlockContext *ctx) override {
    cout << "Visiting block\n";
    for (auto statement : ctx->statement()) {
      visitStatement(statement);
    }
    return nullptr;
  }

  antlrcpp::Any visitCharExpr(ProParser::ExprContext *ctx) {
    antlr4::tree::TerminalNode *terminalNode = ctx->CHAR();

    Token *token = terminalNode->getSymbol();
    string text = token->getText();
    // get value at index 1 because the first and last character is a single
    // quote ('a' -> a)
    char value = text[1];

    llvm::ConstantInt *pointer =
        llvm::ConstantInt::get(context, llvm::APInt(8, value));

    llvm::Value *pointer_value = static_cast<llvm::Value *>(pointer);
    return pointer_value;
  }

  virtual antlrcpp::Any visitArray_construction(
      ProParser::Array_constructionContext *ctx) override {
    std::vector<llvm::Value *> items =
        std::any_cast<std::vector<llvm::Value *>>(
            visitExpr_list(ctx->expr_list()));

    // Create an array type
    llvm::Type *i32Ty = llvm::Type::getInt32Ty(context);
    llvm::ArrayType *arrayTy = llvm::ArrayType::get(i32Ty, items.size());

    // Create an alloca instruction
    llvm::AllocaInst *allocaInst =
        builder.CreateAlloca(arrayTy, nullptr, "array");

    // Store the items in the array
    for (int i = 0; i < items.size(); i++) {
      llvm::Value *index = llvm::ConstantInt::get(context, llvm::APInt(32, i));
      llvm::Value *gep = builder.CreateGEP(arrayTy, allocaInst, index);
      builder.CreateStore(items[i], gep);
    }

    // Load the array
    llvm::Value *value = builder.CreateLoad(arrayTy, allocaInst, "array");

    return value;
  }

  virtual antlrcpp::Any visitExpr_list(
      ProParser::Expr_listContext *ctx) override {
    cout << "DBG_A3\n";

    // llvm::Value vector
    std::vector<llvm::Value *> values;

    for (auto expr : ctx->expr()) {
      antlrcpp::Any result = visitExpr(expr);
      llvm::Value *value = std::any_cast<llvm::Value *>(result);
      cout << "DBG_A3.1\n";
      cout << "Value: " << value << endl;

      values.push_back(value);
    }
    cout << "DBG_A4\n";

    cout << "Values size: " << values.size() << endl;
    cout << "Values[0]: " << values[0] << endl;

    return values;
  }

  antlrcpp::Any visitIdExpr(ProParser::ExprContext *ctx) {
    std::string varName = ctx->ID()->getSymbol()->getText();

    // Look up the variable name in the map
    if (namedValues.count(varName)) {
      llvm::AllocaInst *allocaInst = namedValues[varName];

      // Load the value from the alloca instruction

      llvm::Value *loadInst =
          builder.CreateLoad(allocaInst->getAllocatedType(),
                             (llvm::Value *)allocaInst, llvm::Twine(varName));

      cout << "DBG_B1 Load inst: " << loadInst << endl;

      cout << "RET2\n";
      return loadInst;
    } else {
      // Handle error: variable name not found
      throw std::runtime_error("Variable name not found " + varName);
      cout << "RET3\n";
      return nullptr;
    }
  }
  antlrcpp::Any visitIntExpr(ProParser::ExprContext *ctx) {
    antlr4::tree::TerminalNode *terminalNode = ctx->INT();

    Token *token = terminalNode->getSymbol();
    string text = token->getText();
    int value = std::stoi(text);

    llvm::ConstantInt *constantInt =
        llvm::ConstantInt::get(context, llvm::APInt(32, value));

    llvm::ConstantInt *resultInt =
        std::any_cast<llvm::ConstantInt *>(constantInt);
    llvm::Value *resultVal = static_cast<llvm::Value *>(resultInt);
    return resultVal;
  }

  std::map<std::string, llvm::AllocaInst *> namedValues;
  std::map<std::string, llvm::Function *> functionProtos;

  virtual antlrcpp::Any visitAssignment(
      ProParser::AssignmentContext *ctx) override {
    // Parse the expression
    antlrcpp::Any result = visitExpr(ctx->expr());
    // Get the right-hand side of the assignment (value)
    llvm::Value *rhs = std::any_cast<llvm::Value *>(result);

    // Get the left-hand side of the assignment (variable name)
    // its null initially because we have to check if the variable already
    // exists
    std::string varName = ctx->ID()->getText();
    llvm::AllocaInst *lhs = nullptr;

    // Check if the variable already exists
    if (namedValues.count(varName)) {
      lhs = namedValues[varName];
    } else {
      // Make i32 type and i32 pointer type
      llvm::Type *i32Ty = llvm::Type::getInt32Ty(context);
      llvm::Type *i32PtrTy = llvm::PointerType::getUnqual(i32Ty);

      // Store the variable in the map and create an alloca instruction
      lhs = builder.CreateAlloca(i32PtrTy, nullptr, varName);
      namedValues[varName] = lhs;
    }

    // Create a store instruction
    llvm::StoreInst *storeInst = builder.CreateStore(rhs, lhs);

    return lhs;
  }

  llvm::Module *getModule() { return module.get(); }
};

int main(int argc, const char *argv[]) {
  // read file
  std::ifstream t("./prolang_examples/function_declaration.pr");
  std::string input_str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());

  cout << "Input: " << input_str << endl;

  ANTLRInputStream input(input_str);
  // Scan the input text for tokens
  ProLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  // Parse the tokens into a ast tree
  ProParser parser(&tokens);
  ProParser::ProgContext *tree = parser.prog();

  // print LISP-style tree
  cout << tree->toStringTree(&parser) << endl;

  // Create an instance of the IRGenerator
  IRGenerator irGenerator;

  // Walk down the tree and generate LLVM IR from the bottom up
  irGenerator.visitProg(tree);

  // Get the generated LLVM module
  llvm::Module *module = irGenerator.getModule();

  // Now you can do whatever you want with the module, e.g., print it to
  // stdout
  module->print(llvm::outs(), nullptr);

  // Write the generated LLVM IR to a file
  std::error_code EC;
  llvm::raw_fd_ostream dest("output.ll", EC);
  module->print(dest, nullptr);
  dest.flush();

  // compile with llc
  system("llc -o output.s output.ll");
  // link with gcc
  system("gcc -o output.bin output.s");

  return 0;
}

#include "ProBaseVisitor.h"
