
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\indent\indentParser.g4 by ANTLR 4.7.1


#include "indentParserListener.h"
#include "indentParserVisitor.h"

#include "indentParser.h"


using namespace antlrcpp;
using namespace antlr4;

indentParser::indentParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

indentParser::~indentParser() {
  delete _interpreter;
}

std::string indentParser::getGrammarFileName() const {
  return "indentParser.g4";
}

const std::vector<std::string>& indentParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& indentParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

indentParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* indentParser::StartContext::EOF() {
  return getToken(indentParser::EOF, 0);
}

std::vector<indentParser::LineContext *> indentParser::StartContext::line() {
  return getRuleContexts<indentParser::LineContext>();
}

indentParser::LineContext* indentParser::StartContext::line(size_t i) {
  return getRuleContext<indentParser::LineContext>(i);
}


size_t indentParser::StartContext::getRuleIndex() const {
  return indentParser::RuleStart;
}

void indentParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<indentParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void indentParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<indentParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any indentParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<indentParserVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

indentParser::StartContext* indentParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, indentParser::RuleStart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == indentParser::INDENT

    || _la == indentParser::EOL) {
      setState(4);
      line();
      setState(9);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(10);
    match(indentParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

indentParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* indentParser::LineContext::EOL() {
  return getToken(indentParser::EOL, 0);
}

std::vector<tree::TerminalNode *> indentParser::LineContext::INDENT() {
  return getTokens(indentParser::INDENT);
}

tree::TerminalNode* indentParser::LineContext::INDENT(size_t i) {
  return getToken(indentParser::INDENT, i);
}

std::vector<tree::TerminalNode *> indentParser::LineContext::TOK() {
  return getTokens(indentParser::TOK);
}

tree::TerminalNode* indentParser::LineContext::TOK(size_t i) {
  return getToken(indentParser::TOK, i);
}

std::vector<tree::TerminalNode *> indentParser::LineContext::DEDENT() {
  return getTokens(indentParser::DEDENT);
}

tree::TerminalNode* indentParser::LineContext::DEDENT(size_t i) {
  return getToken(indentParser::DEDENT, i);
}


size_t indentParser::LineContext::getRuleIndex() const {
  return indentParser::RuleLine;
}

void indentParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<indentParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void indentParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<indentParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any indentParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<indentParserVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

indentParser::LineContext* indentParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, indentParser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == indentParser::INDENT) {
      setState(12);
      match(indentParser::INDENT);
      setState(13);
      match(indentParser::TOK);
      setState(14);
      match(indentParser::DEDENT);
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(20);
    match(indentParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> indentParser::_decisionToDFA;
atn::PredictionContextCache indentParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN indentParser::_atn;
std::vector<uint16_t> indentParser::_serializedATN;

std::vector<std::string> indentParser::_ruleNames = {
  "start", "line"
};

std::vector<std::string> indentParser::_literalNames = {
  "", "", "", "'tok'"
};

std::vector<std::string> indentParser::_symbolicNames = {
  "", "INDENT", "DEDENT", "TOK", "EOL", "WS"
};

dfa::Vocabulary indentParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> indentParser::_tokenNames;

indentParser::Initializer::Initializer() {
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
    0x3, 0x7, 0x19, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x7, 
    0x2, 0x8, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xb, 0xb, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x12, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x15, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x4, 
    0x2, 0x4, 0x2, 0x2, 0x2, 0x18, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x8, 0x5, 0x4, 0x3, 0x2, 0x7, 0x6, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x9, 0xa, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x7, 0x2, 0x2, 0x3, 0xd, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xf, 0x7, 0x3, 0x2, 0x2, 0xf, 0x10, 0x7, 0x5, 0x2, 0x2, 
    0x10, 0x12, 0x7, 0x4, 0x2, 0x2, 0x11, 0xe, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x16, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x17, 0x7, 0x6, 0x2, 0x2, 0x17, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x9, 0x13, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

indentParser::Initializer indentParser::_init;
