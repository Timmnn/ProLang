
// Generated from Pro.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ProVisitor.h"


/**
 * This class provides an empty implementation of ProVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ProBaseVisitor : public ProVisitor {
public:

  virtual std::any visitProg(ProParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_declaration(ProParser::Function_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_list(ProParser::Expr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(ProParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(ProParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ProParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call(ProParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_construction(ProParser::Array_constructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ProParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }


};

