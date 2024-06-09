
// Generated from Pro.g4 by ANTLR 4.13.1


#include "ProListener.h"
#include "ProVisitor.h"

#include "ProParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ProParserStaticData final {
  ProParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProParserStaticData(const ProParserStaticData&) = delete;
  ProParserStaticData(ProParserStaticData&&) = delete;
  ProParserStaticData& operator=(const ProParserStaticData&) = delete;
  ProParserStaticData& operator=(ProParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag proParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ProParserStaticData *proParserStaticData = nullptr;

void proParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (proParserStaticData != nullptr) {
    return;
  }
#else
  assert(proParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProParserStaticData>(
    std::vector<std::string>{
      "prog", "array_access", "function_declaration", "parameter", "parameter_list", 
      "expr_list", "expr", "assignment", "statement", "return_statement", 
      "cast", "function_call", "block", "array_construction"
    },
    std::vector<std::string>{
      "", "'['", "']'", "'('", "')'", "':'", "','", "'*'", "'/'", "'+'", 
      "'-'", "'return'", "'{'", "'}'", "", "", "", "", "", "'='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "COMMENT", 
      "INT", "CHAR", "STRING", "ID", "ASSIGN", "WS", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,21,132,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,4,0,
  	30,8,0,11,0,12,0,31,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,45,
  	8,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,57,8,4,10,4,12,4,60,9,
  	4,1,5,1,5,1,5,5,5,65,8,5,10,5,12,5,68,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,3,6,81,8,6,1,6,1,6,1,6,5,6,86,8,6,10,6,12,6,89,9,6,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,99,8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,117,8,11,1,12,1,
  	12,5,12,121,8,12,10,12,12,12,124,9,12,1,12,1,12,1,13,1,13,1,13,1,13,1,
  	13,0,1,12,14,0,2,4,6,8,10,12,14,16,18,20,22,24,26,0,1,1,0,7,10,135,0,
  	29,1,0,0,0,2,35,1,0,0,0,4,40,1,0,0,0,6,49,1,0,0,0,8,53,1,0,0,0,10,61,
  	1,0,0,0,12,80,1,0,0,0,14,90,1,0,0,0,16,98,1,0,0,0,18,100,1,0,0,0,20,103,
  	1,0,0,0,22,116,1,0,0,0,24,118,1,0,0,0,26,127,1,0,0,0,28,30,3,16,8,0,29,
  	28,1,0,0,0,30,31,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,33,1,0,0,0,33,
  	34,5,0,0,1,34,1,1,0,0,0,35,36,5,18,0,0,36,37,5,1,0,0,37,38,5,15,0,0,38,
  	39,5,2,0,0,39,3,1,0,0,0,40,41,5,18,0,0,41,42,5,18,0,0,42,44,5,3,0,0,43,
  	45,3,8,4,0,44,43,1,0,0,0,44,45,1,0,0,0,45,46,1,0,0,0,46,47,5,4,0,0,47,
  	48,3,24,12,0,48,5,1,0,0,0,49,50,5,18,0,0,50,51,5,5,0,0,51,52,5,18,0,0,
  	52,7,1,0,0,0,53,58,3,6,3,0,54,55,5,6,0,0,55,57,3,6,3,0,56,54,1,0,0,0,
  	57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,9,1,0,0,0,60,58,1,0,0,0,
  	61,66,3,12,6,0,62,63,5,6,0,0,63,65,3,12,6,0,64,62,1,0,0,0,65,68,1,0,0,
  	0,66,64,1,0,0,0,66,67,1,0,0,0,67,11,1,0,0,0,68,66,1,0,0,0,69,70,6,6,-1,
  	0,70,81,5,15,0,0,71,72,5,10,0,0,72,81,3,12,6,8,73,81,3,22,11,0,74,81,
  	3,2,1,0,75,81,3,26,13,0,76,81,5,18,0,0,77,81,5,16,0,0,78,81,5,17,0,0,
  	79,81,3,20,10,0,80,69,1,0,0,0,80,71,1,0,0,0,80,73,1,0,0,0,80,74,1,0,0,
  	0,80,75,1,0,0,0,80,76,1,0,0,0,80,77,1,0,0,0,80,78,1,0,0,0,80,79,1,0,0,
  	0,81,87,1,0,0,0,82,83,10,10,0,0,83,84,7,0,0,0,84,86,3,12,6,11,85,82,1,
  	0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,13,1,0,0,0,89,87,1,
  	0,0,0,90,91,5,18,0,0,91,92,5,19,0,0,92,93,3,12,6,0,93,15,1,0,0,0,94,99,
  	3,14,7,0,95,99,3,12,6,0,96,99,3,4,2,0,97,99,3,18,9,0,98,94,1,0,0,0,98,
  	95,1,0,0,0,98,96,1,0,0,0,98,97,1,0,0,0,99,17,1,0,0,0,100,101,5,11,0,0,
  	101,102,3,12,6,0,102,19,1,0,0,0,103,104,5,3,0,0,104,105,5,18,0,0,105,
  	106,5,4,0,0,106,107,3,12,6,0,107,21,1,0,0,0,108,109,5,18,0,0,109,110,
  	5,3,0,0,110,117,5,4,0,0,111,112,5,18,0,0,112,113,5,3,0,0,113,114,3,10,
  	5,0,114,115,5,4,0,0,115,117,1,0,0,0,116,108,1,0,0,0,116,111,1,0,0,0,117,
  	23,1,0,0,0,118,122,5,12,0,0,119,121,3,16,8,0,120,119,1,0,0,0,121,124,
  	1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,125,1,0,0,0,124,122,1,0,0,
  	0,125,126,5,13,0,0,126,25,1,0,0,0,127,128,5,1,0,0,128,129,3,10,5,0,129,
  	130,5,2,0,0,130,27,1,0,0,0,9,31,44,58,66,80,87,98,116,122
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  proParserStaticData = staticData.release();
}

}

ProParser::ProParser(TokenStream *input) : ProParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ProParser::ProParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ProParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *proParserStaticData->atn, proParserStaticData->decisionToDFA, proParserStaticData->sharedContextCache, options);
}

ProParser::~ProParser() {
  delete _interpreter;
}

const atn::ATN& ProParser::getATN() const {
  return *proParserStaticData->atn;
}

std::string ProParser::getGrammarFileName() const {
  return "Pro.g4";
}

const std::vector<std::string>& ProParser::getRuleNames() const {
  return proParserStaticData->ruleNames;
}

const dfa::Vocabulary& ProParser::getVocabulary() const {
  return proParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ProParser::getSerializedATN() const {
  return proParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ProParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::ProgContext::EOF() {
  return getToken(ProParser::EOF, 0);
}

std::vector<ProParser::StatementContext *> ProParser::ProgContext::statement() {
  return getRuleContexts<ProParser::StatementContext>();
}

ProParser::StatementContext* ProParser::ProgContext::statement(size_t i) {
  return getRuleContext<ProParser::StatementContext>(i);
}


size_t ProParser::ProgContext::getRuleIndex() const {
  return ProParser::RuleProg;
}

void ProParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ProParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any ProParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ProParser::ProgContext* ProParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ProParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      statement();
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 494602) != 0));
    setState(33);
    match(ProParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_accessContext ------------------------------------------------------------------

ProParser::Array_accessContext::Array_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::Array_accessContext::ID() {
  return getToken(ProParser::ID, 0);
}

tree::TerminalNode* ProParser::Array_accessContext::INT() {
  return getToken(ProParser::INT, 0);
}


size_t ProParser::Array_accessContext::getRuleIndex() const {
  return ProParser::RuleArray_access;
}

void ProParser::Array_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_access(this);
}

void ProParser::Array_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_access(this);
}


std::any ProParser::Array_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitArray_access(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Array_accessContext* ProParser::array_access() {
  Array_accessContext *_localctx = _tracker.createInstance<Array_accessContext>(_ctx, getState());
  enterRule(_localctx, 2, ProParser::RuleArray_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(ProParser::ID);
    setState(36);
    match(ProParser::T__0);
    setState(37);
    match(ProParser::INT);
    setState(38);
    match(ProParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declarationContext ------------------------------------------------------------------

ProParser::Function_declarationContext::Function_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProParser::Function_declarationContext::ID() {
  return getTokens(ProParser::ID);
}

tree::TerminalNode* ProParser::Function_declarationContext::ID(size_t i) {
  return getToken(ProParser::ID, i);
}

ProParser::BlockContext* ProParser::Function_declarationContext::block() {
  return getRuleContext<ProParser::BlockContext>(0);
}

ProParser::Parameter_listContext* ProParser::Function_declarationContext::parameter_list() {
  return getRuleContext<ProParser::Parameter_listContext>(0);
}


size_t ProParser::Function_declarationContext::getRuleIndex() const {
  return ProParser::RuleFunction_declaration;
}

void ProParser::Function_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_declaration(this);
}

void ProParser::Function_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_declaration(this);
}


std::any ProParser::Function_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitFunction_declaration(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Function_declarationContext* ProParser::function_declaration() {
  Function_declarationContext *_localctx = _tracker.createInstance<Function_declarationContext>(_ctx, getState());
  enterRule(_localctx, 4, ProParser::RuleFunction_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(ProParser::ID);
    setState(41);
    match(ProParser::ID);
    setState(42);
    match(ProParser::T__2);
    setState(44);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ProParser::ID) {
      setState(43);
      parameter_list();
    }
    setState(46);
    match(ProParser::T__3);
    setState(47);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

ProParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProParser::ParameterContext::ID() {
  return getTokens(ProParser::ID);
}

tree::TerminalNode* ProParser::ParameterContext::ID(size_t i) {
  return getToken(ProParser::ID, i);
}


size_t ProParser::ParameterContext::getRuleIndex() const {
  return ProParser::RuleParameter;
}

void ProParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void ProParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any ProParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

ProParser::ParameterContext* ProParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 6, ProParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(ProParser::ID);
    setState(50);
    match(ProParser::T__4);
    setState(51);
    match(ProParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

ProParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProParser::ParameterContext *> ProParser::Parameter_listContext::parameter() {
  return getRuleContexts<ProParser::ParameterContext>();
}

ProParser::ParameterContext* ProParser::Parameter_listContext::parameter(size_t i) {
  return getRuleContext<ProParser::ParameterContext>(i);
}


size_t ProParser::Parameter_listContext::getRuleIndex() const {
  return ProParser::RuleParameter_list;
}

void ProParser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void ProParser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


std::any ProParser::Parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitParameter_list(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Parameter_listContext* ProParser::parameter_list() {
  Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 8, ProParser::RuleParameter_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    parameter();
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProParser::T__5) {
      setState(54);
      match(ProParser::T__5);
      setState(55);
      parameter();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_listContext ------------------------------------------------------------------

ProParser::Expr_listContext::Expr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProParser::ExprContext *> ProParser::Expr_listContext::expr() {
  return getRuleContexts<ProParser::ExprContext>();
}

ProParser::ExprContext* ProParser::Expr_listContext::expr(size_t i) {
  return getRuleContext<ProParser::ExprContext>(i);
}


size_t ProParser::Expr_listContext::getRuleIndex() const {
  return ProParser::RuleExpr_list;
}

void ProParser::Expr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_list(this);
}

void ProParser::Expr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_list(this);
}


std::any ProParser::Expr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitExpr_list(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Expr_listContext* ProParser::expr_list() {
  Expr_listContext *_localctx = _tracker.createInstance<Expr_listContext>(_ctx, getState());
  enterRule(_localctx, 10, ProParser::RuleExpr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    expr(0);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProParser::T__5) {
      setState(62);
      match(ProParser::T__5);
      setState(63);
      expr(0);
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ProParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::ExprContext::INT() {
  return getToken(ProParser::INT, 0);
}

std::vector<ProParser::ExprContext *> ProParser::ExprContext::expr() {
  return getRuleContexts<ProParser::ExprContext>();
}

ProParser::ExprContext* ProParser::ExprContext::expr(size_t i) {
  return getRuleContext<ProParser::ExprContext>(i);
}

ProParser::Function_callContext* ProParser::ExprContext::function_call() {
  return getRuleContext<ProParser::Function_callContext>(0);
}

ProParser::Array_accessContext* ProParser::ExprContext::array_access() {
  return getRuleContext<ProParser::Array_accessContext>(0);
}

ProParser::Array_constructionContext* ProParser::ExprContext::array_construction() {
  return getRuleContext<ProParser::Array_constructionContext>(0);
}

tree::TerminalNode* ProParser::ExprContext::ID() {
  return getToken(ProParser::ID, 0);
}

tree::TerminalNode* ProParser::ExprContext::CHAR() {
  return getToken(ProParser::CHAR, 0);
}

tree::TerminalNode* ProParser::ExprContext::STRING() {
  return getToken(ProParser::STRING, 0);
}

ProParser::CastContext* ProParser::ExprContext::cast() {
  return getRuleContext<ProParser::CastContext>(0);
}


size_t ProParser::ExprContext::getRuleIndex() const {
  return ProParser::RuleExpr;
}

void ProParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ProParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any ProParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


ProParser::ExprContext* ProParser::expr() {
   return expr(0);
}

ProParser::ExprContext* ProParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ProParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ProParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ProParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(70);
      match(ProParser::INT);
      break;
    }

    case 2: {
      setState(71);
      match(ProParser::T__9);
      setState(72);
      expr(8);
      break;
    }

    case 3: {
      setState(73);
      function_call();
      break;
    }

    case 4: {
      setState(74);
      array_access();
      break;
    }

    case 5: {
      setState(75);
      array_construction();
      break;
    }

    case 6: {
      setState(76);
      match(ProParser::ID);
      break;
    }

    case 7: {
      setState(77);
      match(ProParser::CHAR);
      break;
    }

    case 8: {
      setState(78);
      match(ProParser::STRING);
      break;
    }

    case 9: {
      setState(79);
      cast();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(82);

        if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
        setState(83);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1920) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(84);
        expr(11); 
      }
      setState(89);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ProParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::AssignmentContext::ID() {
  return getToken(ProParser::ID, 0);
}

tree::TerminalNode* ProParser::AssignmentContext::ASSIGN() {
  return getToken(ProParser::ASSIGN, 0);
}

ProParser::ExprContext* ProParser::AssignmentContext::expr() {
  return getRuleContext<ProParser::ExprContext>(0);
}


size_t ProParser::AssignmentContext::getRuleIndex() const {
  return ProParser::RuleAssignment;
}

void ProParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void ProParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any ProParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ProParser::AssignmentContext* ProParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, ProParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(ProParser::ID);
    setState(91);
    match(ProParser::ASSIGN);
    setState(92);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ProParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProParser::AssignmentContext* ProParser::StatementContext::assignment() {
  return getRuleContext<ProParser::AssignmentContext>(0);
}

ProParser::ExprContext* ProParser::StatementContext::expr() {
  return getRuleContext<ProParser::ExprContext>(0);
}

ProParser::Function_declarationContext* ProParser::StatementContext::function_declaration() {
  return getRuleContext<ProParser::Function_declarationContext>(0);
}

ProParser::Return_statementContext* ProParser::StatementContext::return_statement() {
  return getRuleContext<ProParser::Return_statementContext>(0);
}


size_t ProParser::StatementContext::getRuleIndex() const {
  return ProParser::RuleStatement;
}

void ProParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ProParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any ProParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ProParser::StatementContext* ProParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, ProParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(95);
      expr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(96);
      function_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(97);
      return_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

ProParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProParser::ExprContext* ProParser::Return_statementContext::expr() {
  return getRuleContext<ProParser::ExprContext>(0);
}


size_t ProParser::Return_statementContext::getRuleIndex() const {
  return ProParser::RuleReturn_statement;
}

void ProParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void ProParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


std::any ProParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Return_statementContext* ProParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, ProParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(ProParser::T__10);
    setState(101);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastContext ------------------------------------------------------------------

ProParser::CastContext::CastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::CastContext::ID() {
  return getToken(ProParser::ID, 0);
}

ProParser::ExprContext* ProParser::CastContext::expr() {
  return getRuleContext<ProParser::ExprContext>(0);
}


size_t ProParser::CastContext::getRuleIndex() const {
  return ProParser::RuleCast;
}

void ProParser::CastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCast(this);
}

void ProParser::CastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCast(this);
}


std::any ProParser::CastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitCast(this);
  else
    return visitor->visitChildren(this);
}

ProParser::CastContext* ProParser::cast() {
  CastContext *_localctx = _tracker.createInstance<CastContext>(_ctx, getState());
  enterRule(_localctx, 20, ProParser::RuleCast);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(ProParser::T__2);
    setState(104);
    match(ProParser::ID);
    setState(105);
    match(ProParser::T__3);
    setState(106);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

ProParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProParser::Function_callContext::ID() {
  return getToken(ProParser::ID, 0);
}

ProParser::Expr_listContext* ProParser::Function_callContext::expr_list() {
  return getRuleContext<ProParser::Expr_listContext>(0);
}


size_t ProParser::Function_callContext::getRuleIndex() const {
  return ProParser::RuleFunction_call;
}

void ProParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void ProParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}


std::any ProParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Function_callContext* ProParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 22, ProParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      match(ProParser::ID);
      setState(109);
      match(ProParser::T__2);
      setState(110);
      match(ProParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(ProParser::ID);
      setState(112);
      match(ProParser::T__2);
      setState(113);
      expr_list();
      setState(114);
      match(ProParser::T__3);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ProParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProParser::StatementContext *> ProParser::BlockContext::statement() {
  return getRuleContexts<ProParser::StatementContext>();
}

ProParser::StatementContext* ProParser::BlockContext::statement(size_t i) {
  return getRuleContext<ProParser::StatementContext>(i);
}


size_t ProParser::BlockContext::getRuleIndex() const {
  return ProParser::RuleBlock;
}

void ProParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void ProParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any ProParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ProParser::BlockContext* ProParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, ProParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(ProParser::T__11);
    setState(122);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 494602) != 0)) {
      setState(119);
      statement();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(125);
    match(ProParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_constructionContext ------------------------------------------------------------------

ProParser::Array_constructionContext::Array_constructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProParser::Expr_listContext* ProParser::Array_constructionContext::expr_list() {
  return getRuleContext<ProParser::Expr_listContext>(0);
}


size_t ProParser::Array_constructionContext::getRuleIndex() const {
  return ProParser::RuleArray_construction;
}

void ProParser::Array_constructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_construction(this);
}

void ProParser::Array_constructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_construction(this);
}


std::any ProParser::Array_constructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProVisitor*>(visitor))
    return parserVisitor->visitArray_construction(this);
  else
    return visitor->visitChildren(this);
}

ProParser::Array_constructionContext* ProParser::array_construction() {
  Array_constructionContext *_localctx = _tracker.createInstance<Array_constructionContext>(_ctx, getState());
  enterRule(_localctx, 26, ProParser::RuleArray_construction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(ProParser::T__0);
    setState(128);
    expr_list();
    setState(129);
    match(ProParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ProParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ProParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

void ProParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  proParserInitialize();
#else
  ::antlr4::internal::call_once(proParserOnceFlag, proParserInitialize);
#endif
}
