
// Generated from Pro.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ProListener.h"


/**
 * This class provides an empty implementation of ProListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ProBaseListener : public ProListener {
public:

  virtual void enterProg(ProParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(ProParser::ProgContext * /*ctx*/) override { }

  virtual void enterArray_access(ProParser::Array_accessContext * /*ctx*/) override { }
  virtual void exitArray_access(ProParser::Array_accessContext * /*ctx*/) override { }

  virtual void enterFunction_declaration(ProParser::Function_declarationContext * /*ctx*/) override { }
  virtual void exitFunction_declaration(ProParser::Function_declarationContext * /*ctx*/) override { }

  virtual void enterParameter(ProParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(ProParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameter_list(ProParser::Parameter_listContext * /*ctx*/) override { }
  virtual void exitParameter_list(ProParser::Parameter_listContext * /*ctx*/) override { }

  virtual void enterExpr_list(ProParser::Expr_listContext * /*ctx*/) override { }
  virtual void exitExpr_list(ProParser::Expr_listContext * /*ctx*/) override { }

  virtual void enterExpr(ProParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ProParser::ExprContext * /*ctx*/) override { }

  virtual void enterAssignment(ProParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(ProParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterStatement(ProParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ProParser::StatementContext * /*ctx*/) override { }

  virtual void enterReturn_statement(ProParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(ProParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterCast(ProParser::CastContext * /*ctx*/) override { }
  virtual void exitCast(ProParser::CastContext * /*ctx*/) override { }

  virtual void enterFunction_call(ProParser::Function_callContext * /*ctx*/) override { }
  virtual void exitFunction_call(ProParser::Function_callContext * /*ctx*/) override { }

  virtual void enterBlock(ProParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ProParser::BlockContext * /*ctx*/) override { }

  virtual void enterArray_construction(ProParser::Array_constructionContext * /*ctx*/) override { }
  virtual void exitArray_construction(ProParser::Array_constructionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

