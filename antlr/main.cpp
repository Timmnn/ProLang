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

struct Param {
  std::string name;
  llvm::Type *type;
};

template <class C, typename T>
bool contains(C &&c, T e) {
  return find(begin(c), end(c), e) != end(c);
};

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
    visitChildren(ctx);

    // Create a return instruction
    builder.CreateRetVoid();

    return nullptr;
  }

  virtual antlrcpp::Any visitExpr(ProParser::ExprContext *ctx) override {
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
      return visitCharExpr(ctx);
    }

    // Check if the expression is a string
    if (ctx->STRING() != nullptr) {
      return visitStringExpr(ctx);
    }

    if (ctx->function_call() != nullptr) {
      return visitFunction_call(ctx->function_call());
    }

    // is calculation (when 2nd child is in ['+', '-', '*', '/'])
    if (ctx->children.size() == 3 &&
        contains<std::vector<std::string>, std::string>(
            {"+", "-", "*", "/"}, ctx->children[1]->getText())) {
      return visitCalculationExpression(ctx);
    }

    if (ctx->cast() != nullptr) {
      return visitCast(ctx->cast());
    }

    if (ctx->array_access() != nullptr) {
      return visitArray_access(ctx->array_access());
    }

    throw std::runtime_error("Expression type not handled " + ctx->getText());
    return nullptr;
  }

  antlrcpp::Any visitArray_access(ProParser::Array_accessContext *ctx) {
    const std::string varName = ctx->ID()->getText();
    const std::string index = ctx->INT()->getText();

    llvm::Value *value = namedValues["main"][varName].value;

    llvm::Type *t = value->getType();

    llvm::Value *indexValue =
        llvm::ConstantInt::get(context, llvm::APInt(32, 0));

    llvm::Value *gep = builder.CreateGEP(t, value, indexValue);

    llvm::Value *loadInst = builder.CreateLoad(t, gep, "array");

    return value;
  }

  void printValueTypes(llvm::Value *value) {
    llvm::Type::TypeID typeID = value->getType()->getTypeID();

    std::string typeName;
    switch (typeID) {
      case llvm::Type::VoidTyID:
        typeName = "void";
        break;
      case llvm::Type::HalfTyID:
        typeName = "half";
        break;
      case llvm::Type::FloatTyID:
        typeName = "float";
        break;
      case llvm::Type::DoubleTyID:
        typeName = "double";
        break;
      case llvm::Type::X86_FP80TyID:
        typeName = "x86_fp80";
        break;
      case llvm::Type::FP128TyID:
        typeName = "fp128";
        break;
      case llvm::Type::PPC_FP128TyID:
        typeName = "ppc_fp128";
        break;
      case llvm::Type::IntegerTyID:
        typeName = "integer";
        break;
      // Add more cases as needed...
      default:
        typeName = "unknown";
    }

    std::cout << "value type: " << typeName << std::endl;
  }

  antlrcpp::Any visitCast(ProParser::CastContext *ctx) override {
    throw std::runtime_error("Cast not implemented");
  }

  antlrcpp::Any visitCalculationExpression(ProParser::ExprContext *ctx) {
    llvm::Value *lhs = std::any_cast<llvm::Value *>(visitExpr(ctx->expr(0)));
    llvm::Value *rhs = std::any_cast<llvm::Value *>(visitExpr(ctx->expr(1)));

    std::string op = ctx->children[1]->getText();

    if (op == "+") {
      return builder.CreateAdd(lhs, rhs);
    }

    if (op == "-") {
      return builder.CreateSub(lhs, rhs);
    }

    if (op == "*") {
      return builder.CreateMul(lhs, rhs);
    }

    if (op == "/") {
      return builder.CreateSDiv(lhs, rhs);
    }

    throw std::runtime_error("Operator not handled");
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

    if (ctx->return_statement() != nullptr) {
      return visitReturn_statement(ctx->return_statement());
    }

    throw std::runtime_error("Statement type not handled");
    return nullptr;
  }

  virtual antlrcpp::Any visitReturn_statement(
      ProParser::Return_statementContext *ctx) override {
    llvm::Value *value = nullptr;

    if (ctx->expr() != nullptr) {
      value = std::any_cast<llvm::Value *>(visitExpr(ctx->expr()));
    }

    builder.CreateRet(value);

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

  virtual antlrcpp::Any visitParameter_list(
      ProParser::Parameter_listContext *ctx) override {
    std::vector<Param> paramList;

    // one parametter_list can have multiple parameters
    for (auto parameter : ctx->parameter()) {
      Param param = std::any_cast<Param>(visitParameter(parameter));
      paramList.push_back(param);
    }

    return paramList;
  }

  virtual antlrcpp::Any visitParameter(
      ProParser::ParameterContext *ctx) override {
    // get current block
    llvm::BasicBlock *currentBlock = builder.GetInsertBlock();

    // Get the parameter name
    std::string name = ctx->ID(0)->getSymbol()->getText();

    std::string type = ctx->ID(1)->getSymbol()->getText();

    llvm::Type *paramType;

    if (type == "int") {
      paramType = llvm::Type::getInt32Ty(context);
    } else if (type == "char") {
      paramType = llvm::Type::getInt8Ty(context);
    }
    if (type == "string") {
      paramType = llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context));
    }

    return Param{name, paramType};
  }

  virtual antlrcpp::Any visitFunction_declaration(
      ProParser::Function_declarationContext *ctx) override {
    // Get return type from first token
    std::string returnType = ctx->ID(0)->getSymbol()->getText();

    std::string funcName = ctx->ID(1)->getSymbol()->getText();

    std::vector<Param> paramList = std::any_cast<std::vector<Param>>(
        visitParameter_list(ctx->parameter_list()));

    std::vector<llvm::Type *> paramTypes = {};

    for (auto param : paramList) {
      paramTypes.push_back(param.type);
    }

    // Create a new basic block for the function
    string returnTypeName = ctx->ID(0)->getSymbol()->getText();

    llvm::Type *returnTypeTy;

    if (returnTypeName == "int") {
      returnTypeTy = llvm::Type::getInt32Ty(context);
    } else if (returnTypeName == "char") {
      returnTypeTy = llvm::Type::getInt8Ty(context);
    } else if (returnTypeName == "void") {
      returnTypeTy = llvm::Type::getVoidTy(context);
    } else {
      throw std::runtime_error("Return type not handled");
    }

    llvm::FunctionType *funcType =
        llvm::FunctionType::get(returnTypeTy,  // Return type
                                paramTypes,    // Parameter types
                                false  // Whether the function is variadic
        );

    // create new block from function body
    llvm::Function *function = llvm::Function::Create(
        funcType, llvm::Function::ExternalLinkage, funcName, module.get());

    // name the arguments
    llvm::Function::arg_iterator argsValues = function->arg_begin();
    for (auto &param : paramList) {
      llvm::Value *arg = argsValues++;
      arg->setName(param.name);
      namedValues[funcName][param.name] = {(llvm::AllocaInst *)arg, true};
    }

    llvm::BasicBlock *basicBlock =
        llvm::BasicBlock::Create(context, funcName, function);

    // Save the current insertion point
    llvm::BasicBlock *currentBlock = builder.GetInsertBlock();

    // Set the newly created block as the current block of execution
    builder.SetInsertPoint(basicBlock);

    // Visit the function's body

    visitBlock(ctx->block());

    // Add a return statement at the end of the function

    if (returnTypeName == "int") {
      builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));
    } else if (returnTypeName == "char") {
      builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(8, 0)));
    } else if (returnTypeName == "void") {
      builder.CreateRetVoid();
    } else {
      throw std::runtime_error("Return type not handled");
    }

    // Restore the previous insertion point
    builder.SetInsertPoint(currentBlock);

    // Save the function prototype

    functionProtos[funcName] = function;

    return nullptr;
  }

  virtual antlrcpp::Any visitBlock(ProParser::BlockContext *ctx) override {
    // store previous insertion point

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
        //
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

    llvm::Value *value = builder.CreateLoad(arrayTy, allocaInst, "array");

    return value;
  }

  virtual antlrcpp::Any visitExpr_list(
      ProParser::Expr_listContext *ctx) override {
    // llvm::Value vector
    std::vector<llvm::Value *> values;

    for (auto expr : ctx->expr()) {
      antlrcpp::Any result = visitExpr(expr);
      llvm::Value *value = std::any_cast<llvm::Value *>(result);

      values.push_back(value);
    }

    return values;
  }

  llvm::Function *getCurrentBlock() {
    llvm::Function *function = builder.GetInsertBlock()->getParent();
    return function;
  }

  string getFunctionName() {
    llvm::Function *function = getCurrentBlock();
    std::string functionName = static_cast<std::string>(function->getName());
    return functionName;
  }

  antlrcpp::Any visitIdExpr(ProParser::ExprContext *ctx) {
    std::string varName = ctx->ID()->getSymbol()->getText();

    if (namedValues.size() == 0) {
      throw std::runtime_error("No blocks found");
      return nullptr;
    }

    string functionName = getFunctionName();

    if (namedValues[functionName].count(varName)) {
      llvm::Value *value = namedValues[functionName][varName].value;

      llvm::Type *t = value->getType();

      llvm::Twine twine = llvm::Twine(varName);
      if (!builder.GetInsertBlock()) {
        throw std::runtime_error("builder is not properly initialized");
      }

      llvm::Value *loadInst = builder.CreateLoad(t, value, twine);

      return loadInst;
    } else {
      throw std::runtime_error("Variable name not found " + varName);
      return nullptr;
    }
  }

  antlrcpp::Any visitIntExpr(ProParser::ExprContext *ctx) {
    antlr4::tree::TerminalNode *terminalNode = ctx->INT();

    Token *token = terminalNode->getSymbol();
    string text = token->getText();
    int value = stoi(text);

    llvm::ConstantInt *pointer =
        llvm::ConstantInt::get(context, llvm::APInt(32, value));

    llvm::Value *pointer_value = static_cast<llvm::Value *>(pointer);
    return pointer_value;
  }

  struct NamedValue {
    llvm::Value *value;
    bool isFunctionParameter;
  };

  // map of maps to store variables namedValues[blockName][varName]
  std::map<std::string, std::map<std::string, NamedValue>> namedValues = {
      {"main", {}}};
  std::map<std::string, llvm::Function *> functionProtos;

  virtual antlrcpp::Any visitAssignment(
      ProParser::AssignmentContext *ctx) override {
    // Evaluate the right-hand side of the assignment

    // print the expression

    antlrcpp::Any result = visitExpr(ctx->expr());
    llvm::Value *rhs = std::any_cast<llvm::Value *>(result);

    // Check rhs type

    // Get the variable name
    std::string varName = ctx->ID()->getText();
    llvm::Value *lhs = nullptr;

    // Get the current function
    llvm::Function *function = getCurrentBlock();
    std::string functionName = static_cast<std::string>(function->getName());

    // Check if the variable already exists
    if (namedValues[functionName].count(varName)) {
      lhs = namedValues[functionName][varName].value;
    } else {
      // Get the type of the variable

      llvm::Type *type = rhs->getType();

      // Store the variable in the map and create an alloca instruction
      lhs = builder.CreateAlloca(type, nullptr, varName);
      namedValues[functionName][varName] = {lhs, false};
    }

    // Create a store instruction
    llvm::StoreInst *storeInst = builder.CreateStore(rhs, lhs);

    return lhs;
  }

  llvm::Module *getModule() { return module.get(); }
};

int main(int argc, const char *argv[]) {
  // read file
  std::ifstream t("./prolang_examples/array_indexing.pr");
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
