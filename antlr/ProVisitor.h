
// Generated from Pro.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ProParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ProParser.
 */
class  ProVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ProParser.
   */
    virtual std::any visitProg(ProParser::ProgContext *context) = 0;

    virtual std::any visitFunction_declaration(ProParser::Function_declarationContext *context) = 0;

    virtual std::any visitExpr_list(ProParser::Expr_listContext *context) = 0;

    virtual std::any visitExpr(ProParser::ExprContext *context) = 0;

    virtual std::any visitAssignment(ProParser::AssignmentContext *context) = 0;

    virtual std::any visitStatement(ProParser::StatementContext *context) = 0;

    virtual std::any visitFunction_call(ProParser::Function_callContext *context) = 0;

    virtual std::any visitArray_construction(ProParser::Array_constructionContext *context) = 0;

    virtual std::any visitBlock(ProParser::BlockContext *context) = 0;


};

