
// Generated from Pro.g4 by ANTLR 4.13.1


#include "ProLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ProLexerStaticData final {
  ProLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProLexerStaticData(const ProLexerStaticData&) = delete;
  ProLexerStaticData(ProLexerStaticData&&) = delete;
  ProLexerStaticData& operator=(const ProLexerStaticData&) = delete;
  ProLexerStaticData& operator=(ProLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag prolexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ProLexerStaticData *prolexerLexerStaticData = nullptr;

void prolexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (prolexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(prolexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "COMMENT", "INT", "CHAR", "STRING", 
      "ESCAPE_SEQ", "ID", "ASSIGN", "WS", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,21,130,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,
  	1,8,1,8,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,
  	1,13,1,13,1,13,1,13,5,13,81,8,13,10,13,12,13,84,9,13,1,13,1,13,1,14,4,
  	14,89,8,14,11,14,12,14,90,1,15,1,15,1,15,1,15,1,16,1,16,1,16,5,16,100,
  	8,16,10,16,12,16,103,9,16,1,16,1,16,1,17,1,17,1,17,1,18,4,18,111,8,18,
  	11,18,12,18,112,1,19,1,19,1,20,4,20,118,8,20,11,20,12,20,119,1,20,1,20,
  	1,21,4,21,125,8,21,11,21,12,21,126,1,21,1,21,0,0,22,1,1,3,2,5,3,7,4,9,
  	5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,
  	35,0,37,18,39,19,41,20,43,21,1,0,7,2,0,10,10,13,13,1,0,48,57,4,0,32,32,
  	44,44,65,90,97,122,2,0,34,34,92,92,6,0,34,34,92,92,98,98,110,110,114,
  	114,116,116,3,0,65,90,95,95,97,122,2,0,9,9,32,32,135,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,37,1,0,
  	0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,1,45,1,0,0,0,3,47,1,0,0,0,
  	5,49,1,0,0,0,7,51,1,0,0,0,9,53,1,0,0,0,11,55,1,0,0,0,13,57,1,0,0,0,15,
  	59,1,0,0,0,17,61,1,0,0,0,19,63,1,0,0,0,21,65,1,0,0,0,23,72,1,0,0,0,25,
  	74,1,0,0,0,27,76,1,0,0,0,29,88,1,0,0,0,31,92,1,0,0,0,33,96,1,0,0,0,35,
  	106,1,0,0,0,37,110,1,0,0,0,39,114,1,0,0,0,41,117,1,0,0,0,43,124,1,0,0,
  	0,45,46,5,91,0,0,46,2,1,0,0,0,47,48,5,93,0,0,48,4,1,0,0,0,49,50,5,40,
  	0,0,50,6,1,0,0,0,51,52,5,41,0,0,52,8,1,0,0,0,53,54,5,58,0,0,54,10,1,0,
  	0,0,55,56,5,44,0,0,56,12,1,0,0,0,57,58,5,42,0,0,58,14,1,0,0,0,59,60,5,
  	47,0,0,60,16,1,0,0,0,61,62,5,43,0,0,62,18,1,0,0,0,63,64,5,45,0,0,64,20,
  	1,0,0,0,65,66,5,114,0,0,66,67,5,101,0,0,67,68,5,116,0,0,68,69,5,117,0,
  	0,69,70,5,114,0,0,70,71,5,110,0,0,71,22,1,0,0,0,72,73,5,123,0,0,73,24,
  	1,0,0,0,74,75,5,125,0,0,75,26,1,0,0,0,76,77,5,47,0,0,77,78,5,47,0,0,78,
  	82,1,0,0,0,79,81,8,0,0,0,80,79,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,82,
  	83,1,0,0,0,83,85,1,0,0,0,84,82,1,0,0,0,85,86,6,13,0,0,86,28,1,0,0,0,87,
  	89,7,1,0,0,88,87,1,0,0,0,89,90,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,
  	30,1,0,0,0,92,93,5,39,0,0,93,94,7,2,0,0,94,95,5,39,0,0,95,32,1,0,0,0,
  	96,101,5,34,0,0,97,100,3,35,17,0,98,100,8,3,0,0,99,97,1,0,0,0,99,98,1,
  	0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,104,1,0,0,0,
  	103,101,1,0,0,0,104,105,5,34,0,0,105,34,1,0,0,0,106,107,5,92,0,0,107,
  	108,7,4,0,0,108,36,1,0,0,0,109,111,7,5,0,0,110,109,1,0,0,0,111,112,1,
  	0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,38,1,0,0,0,114,115,5,61,0,0,
  	115,40,1,0,0,0,116,118,7,6,0,0,117,116,1,0,0,0,118,119,1,0,0,0,119,117,
  	1,0,0,0,119,120,1,0,0,0,120,121,1,0,0,0,121,122,6,20,0,0,122,42,1,0,0,
  	0,123,125,7,0,0,0,124,123,1,0,0,0,125,126,1,0,0,0,126,124,1,0,0,0,126,
  	127,1,0,0,0,127,128,1,0,0,0,128,129,6,21,0,0,129,44,1,0,0,0,8,0,82,90,
  	99,101,112,119,126,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  prolexerLexerStaticData = staticData.release();
}

}

ProLexer::ProLexer(CharStream *input) : Lexer(input) {
  ProLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *prolexerLexerStaticData->atn, prolexerLexerStaticData->decisionToDFA, prolexerLexerStaticData->sharedContextCache);
}

ProLexer::~ProLexer() {
  delete _interpreter;
}

std::string ProLexer::getGrammarFileName() const {
  return "Pro.g4";
}

const std::vector<std::string>& ProLexer::getRuleNames() const {
  return prolexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ProLexer::getChannelNames() const {
  return prolexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ProLexer::getModeNames() const {
  return prolexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ProLexer::getVocabulary() const {
  return prolexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ProLexer::getSerializedATN() const {
  return prolexerLexerStaticData->serializedATN;
}

const atn::ATN& ProLexer::getATN() const {
  return *prolexerLexerStaticData->atn;
}




void ProLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  prolexerLexerInitialize();
#else
  ::antlr4::internal::call_once(prolexerLexerOnceFlag, prolexerLexerInitialize);
#endif
}
