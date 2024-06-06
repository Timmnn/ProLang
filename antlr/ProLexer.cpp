
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
      "T__9", "T__10", "INT", "CHAR", "STRING", "ESCAPE_SEQ", "ID", "ASSIGN", 
      "WS", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,18,104,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	4,11,63,8,11,11,11,12,11,64,1,12,1,12,1,12,1,12,1,13,1,13,1,13,5,13,74,
  	8,13,10,13,12,13,77,9,13,1,13,1,13,1,14,1,14,1,14,1,15,4,15,85,8,15,11,
  	15,12,15,86,1,16,1,16,1,17,4,17,92,8,17,11,17,12,17,93,1,17,1,17,1,18,
  	4,18,99,8,18,11,18,12,18,100,1,18,1,18,0,0,19,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,0,31,15,33,16,35,17,
  	37,18,1,0,7,1,0,48,57,4,0,32,32,44,44,65,90,97,122,2,0,34,34,92,92,6,
  	0,34,34,92,92,98,98,110,110,114,114,116,116,2,0,65,90,97,122,2,0,9,9,
  	32,32,2,0,10,10,13,13,108,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,31,1,
  	0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,41,1,0,0,
  	0,5,43,1,0,0,0,7,45,1,0,0,0,9,47,1,0,0,0,11,49,1,0,0,0,13,51,1,0,0,0,
  	15,53,1,0,0,0,17,55,1,0,0,0,19,57,1,0,0,0,21,59,1,0,0,0,23,62,1,0,0,0,
  	25,66,1,0,0,0,27,70,1,0,0,0,29,80,1,0,0,0,31,84,1,0,0,0,33,88,1,0,0,0,
  	35,91,1,0,0,0,37,98,1,0,0,0,39,40,5,40,0,0,40,2,1,0,0,0,41,42,5,41,0,
  	0,42,4,1,0,0,0,43,44,5,44,0,0,44,6,1,0,0,0,45,46,5,42,0,0,46,8,1,0,0,
  	0,47,48,5,47,0,0,48,10,1,0,0,0,49,50,5,43,0,0,50,12,1,0,0,0,51,52,5,45,
  	0,0,52,14,1,0,0,0,53,54,5,91,0,0,54,16,1,0,0,0,55,56,5,93,0,0,56,18,1,
  	0,0,0,57,58,5,123,0,0,58,20,1,0,0,0,59,60,5,125,0,0,60,22,1,0,0,0,61,
  	63,7,0,0,0,62,61,1,0,0,0,63,64,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,0,65,
  	24,1,0,0,0,66,67,5,39,0,0,67,68,7,1,0,0,68,69,5,39,0,0,69,26,1,0,0,0,
  	70,75,5,34,0,0,71,74,3,29,14,0,72,74,8,2,0,0,73,71,1,0,0,0,73,72,1,0,
  	0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,78,1,0,0,0,77,75,1,0,
  	0,0,78,79,5,34,0,0,79,28,1,0,0,0,80,81,5,92,0,0,81,82,7,3,0,0,82,30,1,
  	0,0,0,83,85,7,4,0,0,84,83,1,0,0,0,85,86,1,0,0,0,86,84,1,0,0,0,86,87,1,
  	0,0,0,87,32,1,0,0,0,88,89,5,61,0,0,89,34,1,0,0,0,90,92,7,5,0,0,91,90,
  	1,0,0,0,92,93,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,95,1,0,0,0,95,96,
  	6,17,0,0,96,36,1,0,0,0,97,99,7,6,0,0,98,97,1,0,0,0,99,100,1,0,0,0,100,
  	98,1,0,0,0,100,101,1,0,0,0,101,102,1,0,0,0,102,103,6,18,0,0,103,38,1,
  	0,0,0,7,0,64,73,75,86,93,100,1,6,0,0
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
