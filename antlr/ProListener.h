
// Generated from Pro.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ProParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ProParser.
 */
class  ProListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(ProParser::ProgContext *ctx) = 0;
  virtual void exitProg(ProParser::ProgContext *ctx) = 0;

  virtual void enterFunction_declaration(ProParser::Function_declarationContext *ctx) = 0;
  virtual void exitFunction_declaration(ProParser::Function_declarationContext *ctx) = 0;

  virtual void enterExpr_list(ProParser::Expr_listContext *ctx) = 0;
  virtual void exitExpr_list(ProParser::Expr_listContext *ctx) = 0;

  virtual void enterExpr(ProParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ProParser::ExprContext *ctx) = 0;

  virtual void enterAssignment(ProParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(ProParser::AssignmentContext *ctx) = 0;

  virtual void enterStatement(ProParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ProParser::StatementContext *ctx) = 0;

  virtual void enterFunction_call(ProParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(ProParser::Function_callContext *ctx) = 0;

  virtual void enterArray_construction(ProParser::Array_constructionContext *ctx) = 0;
  virtual void exitArray_construction(ProParser::Array_constructionContext *ctx) = 0;

  virtual void enterBlock(ProParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ProParser::BlockContext *ctx) = 0;


};

