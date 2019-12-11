
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\testlexer.g4 by ANTLR 4.7.1


#include "testlexer.h"


using namespace antlr4;


testlexer::testlexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

testlexer::~testlexer() {
  delete _interpreter;
}

std::string testlexer::getGrammarFileName() const {
  return "testlexer.g4";
}

const std::vector<std::string>& testlexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& testlexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& testlexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& testlexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& testlexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> testlexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& testlexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> testlexer::_decisionToDFA;
atn::PredictionContextCache testlexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN testlexer::_atn;
std::vector<uint16_t> testlexer::_serializedATN;

std::vector<std::string> testlexer::_ruleNames = {
  u8"TOKEN"
};

std::vector<std::string> testlexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> testlexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> testlexer::_literalNames = {
  "", u8"'tok'"
};

std::vector<std::string> testlexer::_symbolicNames = {
  "", u8"TOKEN"
};

dfa::Vocabulary testlexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> testlexer::_tokenNames;

testlexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x3, 0x9, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x2, 0x2, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x3, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5, 0x6, 0x7, 
    0x76, 0x2, 0x2, 0x6, 0x7, 0x7, 0x71, 0x2, 0x2, 0x7, 0x8, 0x7, 0x6d, 
    0x2, 0x2, 0x8, 0x4, 0x3, 0x2, 0x2, 0x2, 0x3, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

testlexer::Initializer testlexer::_init;
