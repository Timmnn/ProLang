
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
      "prog", "function_declaration", "expr_list", "expr", "assignment", 
      "statement", "function_call", "array_construction", "block"
    },
    std::vector<std::string>{
      "", "'('", "')'", "','", "'*'", "'/'", "'+'", "'-'", "'['", "']'", 
      "'{'", "'}'", "", "", "", "", "'='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "INT", "CHAR", "STRING", 
      "ID", "ASSIGN", "WS", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,18,91,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,1,0,4,0,20,8,0,11,0,12,0,21,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,2,1,2,1,2,5,2,35,8,2,10,2,12,2,38,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,49,8,3,1,3,1,3,1,3,5,3,54,8,3,10,3,12,3,57,9,3,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,3,5,66,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,76,8,
  	6,1,7,1,7,1,7,1,7,1,8,1,8,5,8,84,8,8,10,8,12,8,87,9,8,1,8,1,8,1,8,0,1,
  	6,9,0,2,4,6,8,10,12,14,16,0,1,1,0,4,7,94,0,19,1,0,0,0,2,25,1,0,0,0,4,
  	31,1,0,0,0,6,48,1,0,0,0,8,58,1,0,0,0,10,65,1,0,0,0,12,75,1,0,0,0,14,77,
  	1,0,0,0,16,81,1,0,0,0,18,20,3,10,5,0,19,18,1,0,0,0,20,21,1,0,0,0,21,19,
  	1,0,0,0,21,22,1,0,0,0,22,23,1,0,0,0,23,24,5,0,0,1,24,1,1,0,0,0,25,26,
  	5,15,0,0,26,27,5,15,0,0,27,28,5,1,0,0,28,29,5,2,0,0,29,30,3,16,8,0,30,
  	3,1,0,0,0,31,36,3,6,3,0,32,33,5,3,0,0,33,35,3,6,3,0,34,32,1,0,0,0,35,
  	38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,5,1,0,0,0,38,36,1,0,0,0,39,
  	40,6,3,-1,0,40,49,5,12,0,0,41,49,5,15,0,0,42,43,5,7,0,0,43,49,3,6,3,5,
  	44,49,3,12,6,0,45,49,3,14,7,0,46,49,5,13,0,0,47,49,5,14,0,0,48,39,1,0,
  	0,0,48,41,1,0,0,0,48,42,1,0,0,0,48,44,1,0,0,0,48,45,1,0,0,0,48,46,1,0,
  	0,0,48,47,1,0,0,0,49,55,1,0,0,0,50,51,10,8,0,0,51,52,7,0,0,0,52,54,3,
  	6,3,9,53,50,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,7,1,
  	0,0,0,57,55,1,0,0,0,58,59,5,15,0,0,59,60,5,16,0,0,60,61,3,6,3,0,61,9,
  	1,0,0,0,62,66,3,8,4,0,63,66,3,6,3,0,64,66,3,2,1,0,65,62,1,0,0,0,65,63,
  	1,0,0,0,65,64,1,0,0,0,66,11,1,0,0,0,67,68,5,15,0,0,68,69,5,1,0,0,69,76,
  	5,2,0,0,70,71,5,15,0,0,71,72,5,1,0,0,72,73,3,4,2,0,73,74,5,2,0,0,74,76,
  	1,0,0,0,75,67,1,0,0,0,75,70,1,0,0,0,76,13,1,0,0,0,77,78,5,8,0,0,78,79,
  	3,4,2,0,79,80,5,9,0,0,80,15,1,0,0,0,81,85,5,10,0,0,82,84,3,10,5,0,83,
  	82,1,0,0,0,84,87,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,88,1,0,0,0,87,
  	85,1,0,0,0,88,89,5,11,0,0,89,17,1,0,0,0,7,21,36,48,55,65,75,85
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
    setState(19); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(18);
      statement();
      setState(21); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 61824) != 0));
    setState(23);
    match(ProParser::EOF);
   
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
  enterRule(_localctx, 2, ProParser::RuleFunction_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(ProParser::ID);
    setState(26);
    match(ProParser::ID);
    setState(27);
    match(ProParser::T__0);
    setState(28);
    match(ProParser::T__1);
    setState(29);
    block();
   
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
  enterRule(_localctx, 4, ProParser::RuleExpr_list);
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
    setState(31);
    expr(0);
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProParser::T__2) {
      setState(32);
      match(ProParser::T__2);
      setState(33);
      expr(0);
      setState(38);
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

tree::TerminalNode* ProParser::ExprContext::ID() {
  return getToken(ProParser::ID, 0);
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

ProParser::Array_constructionContext* ProParser::ExprContext::array_construction() {
  return getRuleContext<ProParser::Array_constructionContext>(0);
}

tree::TerminalNode* ProParser::ExprContext::CHAR() {
  return getToken(ProParser::CHAR, 0);
}

tree::TerminalNode* ProParser::ExprContext::STRING() {
  return getToken(ProParser::STRING, 0);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, ProParser::RuleExpr, precedence);

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
    setState(48);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(40);
      match(ProParser::INT);
      break;
    }

    case 2: {
      setState(41);
      match(ProParser::ID);
      break;
    }

    case 3: {
      setState(42);
      match(ProParser::T__6);
      setState(43);
      expr(5);
      break;
    }

    case 4: {
      setState(44);
      function_call();
      break;
    }

    case 5: {
      setState(45);
      array_construction();
      break;
    }

    case 6: {
      setState(46);
      match(ProParser::CHAR);
      break;
    }

    case 7: {
      setState(47);
      match(ProParser::STRING);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(50);

        if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
        setState(51);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 240) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(52);
        expr(9); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
  enterRule(_localctx, 8, ProParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(ProParser::ID);
    setState(59);
    match(ProParser::ASSIGN);
    setState(60);
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
  enterRule(_localctx, 10, ProParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      expr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(64);
      function_declaration();
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
  enterRule(_localctx, 12, ProParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      match(ProParser::ID);
      setState(68);
      match(ProParser::T__0);
      setState(69);
      match(ProParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(70);
      match(ProParser::ID);
      setState(71);
      match(ProParser::T__0);
      setState(72);
      expr_list();
      setState(73);
      match(ProParser::T__1);
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
  enterRule(_localctx, 14, ProParser::RuleArray_construction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(ProParser::T__7);
    setState(78);
    expr_list();
    setState(79);
    match(ProParser::T__8);
   
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
  enterRule(_localctx, 16, ProParser::RuleBlock);
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
    setState(81);
    match(ProParser::T__9);
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 61824) != 0)) {
      setState(82);
      statement();
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
    match(ProParser::T__10);
   
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
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ProParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);

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
