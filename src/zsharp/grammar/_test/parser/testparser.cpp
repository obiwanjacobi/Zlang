
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\testparser.g4 by ANTLR 4.7.1


#include "testparserListener.h"
#include "testparserVisitor.h"

#include "testparser.h"


using namespace antlrcpp;
using namespace antlr4;

testparser::testparser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

testparser::~testparser() {
  delete _interpreter;
}

std::string testparser::getGrammarFileName() const {
  return "testparser.g4";
}

const std::vector<std::string>& testparser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& testparser::getVocabulary() const {
  return _vocabulary;
}


//----------------- TestContext ------------------------------------------------------------------

testparser::TestContext::TestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> testparser::TestContext::TOKEN() {
  return getTokens(testparser::TOKEN);
}

tree::TerminalNode* testparser::TestContext::TOKEN(size_t i) {
  return getToken(testparser::TOKEN, i);
}


size_t testparser::TestContext::getRuleIndex() const {
  return testparser::RuleTest;
}

void testparser::TestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testparserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTest(this);
}

void testparser::TestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testparserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTest(this);
}


antlrcpp::Any testparser::TestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<testparserVisitor*>(visitor))
    return parserVisitor->visitTest(this);
  else
    return visitor->visitChildren(this);
}

testparser::TestContext* testparser::test() {
  TestContext *_localctx = _tracker.createInstance<TestContext>(_ctx, getState());
  enterRule(_localctx, 0, testparser::RuleTest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2);
    match(testparser::TOKEN);
    setState(6);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == testparser::TOKEN) {
      setState(3);
      match(testparser::TOKEN);
      setState(8);
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

// Static vars and initialization.
std::vector<dfa::DFA> testparser::_decisionToDFA;
atn::PredictionContextCache testparser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN testparser::_atn;
std::vector<uint16_t> testparser::_serializedATN;

std::vector<std::string> testparser::_ruleNames = {
  "test"
};

std::vector<std::string> testparser::_literalNames = {
  "", "'tok'"
};

std::vector<std::string> testparser::_symbolicNames = {
  "", "TOKEN"
};

dfa::Vocabulary testparser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> testparser::_tokenNames;

testparser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3, 0xc, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x7, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xa, 0xb, 0x2, 0x3, 0x2, 0x2, 0x2, 0x3, 
    0x2, 0x2, 0x2, 0x2, 0xb, 0x2, 0x4, 0x3, 0x2, 0x2, 0x2, 0x4, 0x8, 0x7, 
    0x3, 0x2, 0x2, 0x5, 0x7, 0x7, 0x3, 0x2, 0x2, 0x6, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x7, 0xa, 0x3, 0x2, 0x2, 0x2, 0x8, 0x6, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 0x3, 0x3, 0x2, 0x2, 0x2, 0xa, 0x8, 0x3, 
    0x2, 0x2, 0x2, 0x3, 0x8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

testparser::Initializer testparser::_init;
