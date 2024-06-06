#include <iostream>
#include <sstream>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}
// Forward declarations

enum class AstNodeType {
  prog,
  expr,
  eof,
  equal_sign,
  addition_sign,
  subtraction_sign,
  multiplication_sign,
  division_sign,
};

class AstNode {
 public:
  AstNodeType type;
  std::vector<AstNode> children;
  AstNode(AstNodeType type, std::vector<AstNode> children)
      : type(type), children(children) {}

  void codegen(llvm::IRBuilder<> &builder) {
    if (type == AstNodeType::prog) {
      codegen_prog(builder);
    } else if (type == AstNodeType::expr) {
      codegen_expr(builder);
    } else if (type == AstNodeType::eof) {
      codegen_eof(builder);
    }
  };

 private:
  void codegen_prog(llvm::IRBuilder<> &builder) {
    std::cout << "codegen_prog" << std::endl;
    for (auto &child : children) {
      child.codegen(builder);
    }
  }

  void codegen_expr(llvm::IRBuilder<> &builder) {
    std::cout << "codegen_expr" << std::endl;

    // Calculation (expr + expr)
    if (children.size() == 3 &&
        (children[1].type == AstNodeType::addition_sign ||
         children[1].type == AstNodeType::subtraction_sign ||
         children[1].type == AstNodeType::multiplication_sign ||
         children[1].type == AstNodeType::division_sign)) {
      codegen_expr_calculation(builder);
    }
    // Assignment (id = expr)
    else if (children.size() == 3 &&
             children[1].type == AstNodeType::equal_sign) {
      codegen_expr_assignment(builder);
    }
  }

  void codegen_eof(llvm::IRBuilder<> &builder) {
    std::cout << "codegen_eof" << std::endl;
  }

  void codegen_expr_calculation(llvm::IRBuilder<> &builder) {
    std::cout << "codegen_expr_calculation" << std::endl;
  }

  void codegen_expr_assignment(llvm::IRBuilder<> &builder) {
    std::cout << "codegen_expr_assignment" << std::endl;
  }

  // one codegen function for each type of node
};

std::vector<AstNode> parseAstChildrenString(std::string astChildrenString);

AstNode fromAstString(std::string astString) {
  std::cout << "fromAstString: " << astString << std::endl;
  std::string nodeType;
  std::string children_str;

  size_t pos = astString.find(' ');

  if (pos != std::string::npos) {
    nodeType = astString.substr(0, pos);
    // if is (ndoeType
    if (astString[0] == '(') {
      nodeType = nodeType.substr(1, nodeType.size() - 1);
    }
    children_str = astString.substr(pos + 1, astString.size() - pos - 2);
  } else {
    // no children
    children_str = "";
  }
  else {
    // single character
    nodeType = astString;
  }

  std::cout << "nodeType: " << nodeType << std::endl;
  std::cout << "children_str: " << children_str << std::endl;

  AstNodeType type;

  if (nodeType == "prog") {
    type = AstNodeType::prog;
  } else if (nodeType == "expr") {
    type = AstNodeType::expr;
  } else if (nodeType == "eof") {
    type = AstNodeType::eof;
  } else {
    std::cout << "xxxnodeType: " << nodeType << std::endl;
    throw std::runtime_error("Invalid AST string");
  }

  std::vector<AstNode> children;
  if (children_str.size() > 0) {
    children = parseAstChildrenString(children_str);
  } else {
    children = {};
  }

  return AstNode(type, children);
}

std::vector<AstNode> parseAstChildrenString(std::string astChildrenString) {
  // eg. "(expr 1) + (expr 2) * (expr 3)"
  std::vector<AstNode> astNodes;

  std::vector<std::string> astNodeStrings;

  // split by each " " with considering the parentheses
  int depth = 0;
  std::string currentString = "";
  for (char c : astChildrenString) {
    if (c == '(') {
      depth++;
    } else if (c == ')') {
      depth--;
    }

    if (c == ' ' && depth == 0) {
      astNodeStrings.push_back(currentString);
      currentString = "";
    } else {
      currentString += c;
    }
  }

  if (currentString.size() > 0) {
    astNodeStrings.push_back(currentString);
  }

  for (auto &astNodeString : astNodeStrings) {
    astNodes.push_back(fromAstString(astNodeString));
  }

  return astNodes;
}

void generateIR(std::string astString) {
  llvm::LLVMContext context;
  llvm::Module *module = new llvm::Module("top", context);
  llvm::IRBuilder<> builder(context);

  AstNode ast = fromAstString(astString);

  ast.codegen(builder);

  module->print(llvm::outs(), nullptr);
  delete module;
}

int main() {
  std::string astString =
      "(prog (expr (expr 1) + (expr (expr 2) * (expr 3))) <EOF>)";
  generateIR(astString);
  return 0;
}
