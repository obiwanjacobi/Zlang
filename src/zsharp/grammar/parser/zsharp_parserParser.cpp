
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1


#include "zsharp_parserListener.h"
#include "zsharp_parserVisitor.h"

#include "zsharp_parserParser.h"


using namespace antlrcpp;
using namespace antlr4;

zsharp_parserParser::zsharp_parserParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

zsharp_parserParser::~zsharp_parserParser() {
  delete _interpreter;
}

std::string zsharp_parserParser::getGrammarFileName() const {
  return "zsharp_parser.g4";
}

const std::vector<std::string>& zsharp_parserParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& zsharp_parserParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

zsharp_parserParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::FileContext::EOF() {
  return getToken(zsharp_parserParser::EOF, 0);
}

std::vector<zsharp_parserParser::CodeContext *> zsharp_parserParser::FileContext::code() {
  return getRuleContexts<zsharp_parserParser::CodeContext>();
}

zsharp_parserParser::CodeContext* zsharp_parserParser::FileContext::code(size_t i) {
  return getRuleContext<zsharp_parserParser::CodeContext>(i);
}

std::vector<zsharp_parserParser::Empty_lineContext *> zsharp_parserParser::FileContext::empty_line() {
  return getRuleContexts<zsharp_parserParser::Empty_lineContext>();
}

zsharp_parserParser::Empty_lineContext* zsharp_parserParser::FileContext::empty_line(size_t i) {
  return getRuleContext<zsharp_parserParser::Empty_lineContext>(i);
}


size_t zsharp_parserParser::FileContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFile;
}

void zsharp_parserParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void zsharp_parserParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any zsharp_parserParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::FileContext* zsharp_parserParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, zsharp_parserParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::MODULE)
      | (1ULL << zsharp_parserParser::IMPORT)
      | (1ULL << zsharp_parserParser::EXPORT)
      | (1ULL << zsharp_parserParser::BREAK)
      | (1ULL << zsharp_parserParser::CONTINUE)
      | (1ULL << zsharp_parserParser::IDENTIFIERupper)
      | (1ULL << zsharp_parserParser::IDENTIFIERlower)
      | (1ULL << zsharp_parserParser::IDENTIFIERmixed)
      | (1ULL << zsharp_parserParser::COMMENT))) != 0) || _la == zsharp_parserParser::INDENT

    || _la == zsharp_parserParser::EOL) {
      setState(250);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(248);
        code();
        break;
      }

      case 2: {
        setState(249);
        empty_line();
        break;
      }

      }
      setState(254);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(255);
    match(zsharp_parserParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeContext ------------------------------------------------------------------

zsharp_parserParser::CodeContext::CodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::StatementContext* zsharp_parserParser::CodeContext::statement() {
  return getRuleContext<zsharp_parserParser::StatementContext>(0);
}

zsharp_parserParser::CommentContext* zsharp_parserParser::CodeContext::comment() {
  return getRuleContext<zsharp_parserParser::CommentContext>(0);
}


size_t zsharp_parserParser::CodeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleCode;
}

void zsharp_parserParser::CodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCode(this);
}

void zsharp_parserParser::CodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCode(this);
}


antlrcpp::Any zsharp_parserParser::CodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitCode(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::CodeContext* zsharp_parserParser::code() {
  CodeContext *_localctx = _tracker.createInstance<CodeContext>(_ctx, getState());
  enterRule(_localctx, 2, zsharp_parserParser::RuleCode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(258);
      comment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

zsharp_parserParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Module_statementContext* zsharp_parserParser::StatementContext::module_statement() {
  return getRuleContext<zsharp_parserParser::Module_statementContext>(0);
}

zsharp_parserParser::Flow_statementContext* zsharp_parserParser::StatementContext::flow_statement() {
  return getRuleContext<zsharp_parserParser::Flow_statementContext>(0);
}

zsharp_parserParser::DeclarationContext* zsharp_parserParser::StatementContext::declaration() {
  return getRuleContext<zsharp_parserParser::DeclarationContext>(0);
}


size_t zsharp_parserParser::StatementContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement;
}

void zsharp_parserParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void zsharp_parserParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any zsharp_parserParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::StatementContext* zsharp_parserParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, zsharp_parserParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(261);
      module_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(262);
      flow_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(263);
      declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_statementContext ------------------------------------------------------------------

zsharp_parserParser::Module_statementContext::Module_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Statement_moduleContext* zsharp_parserParser::Module_statementContext::statement_module() {
  return getRuleContext<zsharp_parserParser::Statement_moduleContext>(0);
}

zsharp_parserParser::Statement_importContext* zsharp_parserParser::Module_statementContext::statement_import() {
  return getRuleContext<zsharp_parserParser::Statement_importContext>(0);
}

zsharp_parserParser::Statement_exportContext* zsharp_parserParser::Module_statementContext::statement_export() {
  return getRuleContext<zsharp_parserParser::Statement_exportContext>(0);
}


size_t zsharp_parserParser::Module_statementContext::getRuleIndex() const {
  return zsharp_parserParser::RuleModule_statement;
}

void zsharp_parserParser::Module_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_statement(this);
}

void zsharp_parserParser::Module_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_statement(this);
}


antlrcpp::Any zsharp_parserParser::Module_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitModule_statement(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Module_statementContext* zsharp_parserParser::module_statement() {
  Module_statementContext *_localctx = _tracker.createInstance<Module_statementContext>(_ctx, getState());
  enterRule(_localctx, 6, zsharp_parserParser::RuleModule_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::MODULE: {
        enterOuterAlt(_localctx, 1);
        setState(266);
        statement_module();
        break;
      }

      case zsharp_parserParser::IMPORT: {
        enterOuterAlt(_localctx, 2);
        setState(267);
        statement_import();
        break;
      }

      case zsharp_parserParser::EXPORT: {
        enterOuterAlt(_localctx, 3);
        setState(268);
        statement_export();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_nameContext ------------------------------------------------------------------

zsharp_parserParser::Module_nameContext::Module_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_moduleContext* zsharp_parserParser::Module_nameContext::identifier_module() {
  return getRuleContext<zsharp_parserParser::Identifier_moduleContext>(0);
}

zsharp_parserParser::Module_nameContext* zsharp_parserParser::Module_nameContext::module_name() {
  return getRuleContext<zsharp_parserParser::Module_nameContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Module_nameContext::DOT() {
  return getToken(zsharp_parserParser::DOT, 0);
}


size_t zsharp_parserParser::Module_nameContext::getRuleIndex() const {
  return zsharp_parserParser::RuleModule_name;
}

void zsharp_parserParser::Module_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_name(this);
}

void zsharp_parserParser::Module_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_name(this);
}


antlrcpp::Any zsharp_parserParser::Module_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitModule_name(this);
  else
    return visitor->visitChildren(this);
}


zsharp_parserParser::Module_nameContext* zsharp_parserParser::module_name() {
   return module_name(0);
}

zsharp_parserParser::Module_nameContext* zsharp_parserParser::module_name(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zsharp_parserParser::Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, parentState);
  zsharp_parserParser::Module_nameContext *previousContext = _localctx;
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, zsharp_parserParser::RuleModule_name, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(272);
    identifier_module();
    _ctx->stop = _input->LT(-1);
    setState(279);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Module_nameContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleModule_name);
        setState(274);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(275);
        match(zsharp_parserParser::DOT);
        setState(276);
        identifier_module(); 
      }
      setState(281);
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

//----------------- Statement_moduleContext ------------------------------------------------------------------

zsharp_parserParser::Statement_moduleContext::Statement_moduleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Keyword_moduleContext* zsharp_parserParser::Statement_moduleContext::keyword_module() {
  return getRuleContext<zsharp_parserParser::Keyword_moduleContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_moduleContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Module_nameContext* zsharp_parserParser::Statement_moduleContext::module_name() {
  return getRuleContext<zsharp_parserParser::Module_nameContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_moduleContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}


size_t zsharp_parserParser::Statement_moduleContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_module;
}

void zsharp_parserParser::Statement_moduleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_module(this);
}

void zsharp_parserParser::Statement_moduleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_module(this);
}


antlrcpp::Any zsharp_parserParser::Statement_moduleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_module(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_moduleContext* zsharp_parserParser::statement_module() {
  Statement_moduleContext *_localctx = _tracker.createInstance<Statement_moduleContext>(_ctx, getState());
  enterRule(_localctx, 10, zsharp_parserParser::RuleStatement_module);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    keyword_module();
    setState(283);
    match(zsharp_parserParser::SP);
    setState(284);
    module_name(0);
    setState(285);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_importContext ------------------------------------------------------------------

zsharp_parserParser::Statement_importContext::Statement_importContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Keyword_importContext* zsharp_parserParser::Statement_importContext::keyword_import() {
  return getRuleContext<zsharp_parserParser::Keyword_importContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_importContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Module_nameContext* zsharp_parserParser::Statement_importContext::module_name() {
  return getRuleContext<zsharp_parserParser::Module_nameContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_importContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}


size_t zsharp_parserParser::Statement_importContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_import;
}

void zsharp_parserParser::Statement_importContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_import(this);
}

void zsharp_parserParser::Statement_importContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_import(this);
}


antlrcpp::Any zsharp_parserParser::Statement_importContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_import(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_importContext* zsharp_parserParser::statement_import() {
  Statement_importContext *_localctx = _tracker.createInstance<Statement_importContext>(_ctx, getState());
  enterRule(_localctx, 12, zsharp_parserParser::RuleStatement_import);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    keyword_import();
    setState(288);
    match(zsharp_parserParser::SP);
    setState(289);
    module_name(0);
    setState(290);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_exportContext ------------------------------------------------------------------

zsharp_parserParser::Statement_exportContext::Statement_exportContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Keyword_exportContext* zsharp_parserParser::Statement_exportContext::keyword_export() {
  return getRuleContext<zsharp_parserParser::Keyword_exportContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_exportContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_exportContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Identifier_funcContext* zsharp_parserParser::Statement_exportContext::identifier_func() {
  return getRuleContext<zsharp_parserParser::Identifier_funcContext>(0);
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Statement_exportContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}


size_t zsharp_parserParser::Statement_exportContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_export;
}

void zsharp_parserParser::Statement_exportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_export(this);
}

void zsharp_parserParser::Statement_exportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_export(this);
}


antlrcpp::Any zsharp_parserParser::Statement_exportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_export(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_exportContext* zsharp_parserParser::statement_export() {
  Statement_exportContext *_localctx = _tracker.createInstance<Statement_exportContext>(_ctx, getState());
  enterRule(_localctx, 14, zsharp_parserParser::RuleStatement_export);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    keyword_export();
    setState(293);
    match(zsharp_parserParser::SP);
    setState(296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(294);
      identifier_func();
      break;
    }

    case 2: {
      setState(295);
      identifier_type();
      break;
    }

    }
    setState(298);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Flow_statementContext ------------------------------------------------------------------

zsharp_parserParser::Flow_statementContext::Flow_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Statement_ifContext* zsharp_parserParser::Flow_statementContext::statement_if() {
  return getRuleContext<zsharp_parserParser::Statement_ifContext>(0);
}

zsharp_parserParser::Statement_elseContext* zsharp_parserParser::Flow_statementContext::statement_else() {
  return getRuleContext<zsharp_parserParser::Statement_elseContext>(0);
}

zsharp_parserParser::Keyword_breakContext* zsharp_parserParser::Flow_statementContext::keyword_break() {
  return getRuleContext<zsharp_parserParser::Keyword_breakContext>(0);
}

zsharp_parserParser::Keyword_continueContext* zsharp_parserParser::Flow_statementContext::keyword_continue() {
  return getRuleContext<zsharp_parserParser::Keyword_continueContext>(0);
}

zsharp_parserParser::Statement_returnContext* zsharp_parserParser::Flow_statementContext::statement_return() {
  return getRuleContext<zsharp_parserParser::Statement_returnContext>(0);
}


size_t zsharp_parserParser::Flow_statementContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFlow_statement;
}

void zsharp_parserParser::Flow_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlow_statement(this);
}

void zsharp_parserParser::Flow_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlow_statement(this);
}


antlrcpp::Any zsharp_parserParser::Flow_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFlow_statement(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Flow_statementContext* zsharp_parserParser::flow_statement() {
  Flow_statementContext *_localctx = _tracker.createInstance<Flow_statementContext>(_ctx, getState());
  enterRule(_localctx, 16, zsharp_parserParser::RuleFlow_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(300);
      statement_if();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(301);
      statement_else();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(302);
      keyword_break();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(303);
      keyword_continue();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(304);
      statement_return();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_returnContext ------------------------------------------------------------------

zsharp_parserParser::Statement_returnContext::Statement_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_returnContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Keyword_returnContext* zsharp_parserParser::Statement_returnContext::keyword_return() {
  return getRuleContext<zsharp_parserParser::Keyword_returnContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_returnContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_returnContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Expression_valueContext* zsharp_parserParser::Statement_returnContext::expression_value() {
  return getRuleContext<zsharp_parserParser::Expression_valueContext>(0);
}


size_t zsharp_parserParser::Statement_returnContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_return;
}

void zsharp_parserParser::Statement_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_return(this);
}

void zsharp_parserParser::Statement_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_return(this);
}


antlrcpp::Any zsharp_parserParser::Statement_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_return(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_returnContext* zsharp_parserParser::statement_return() {
  Statement_returnContext *_localctx = _tracker.createInstance<Statement_returnContext>(_ctx, getState());
  enterRule(_localctx, 18, zsharp_parserParser::RuleStatement_return);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    indent();
    setState(308);
    keyword_return();
    setState(311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SP) {
      setState(309);
      match(zsharp_parserParser::SP);
      setState(310);
      expression_value();
    }
    setState(313);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_ifContext ------------------------------------------------------------------

zsharp_parserParser::Statement_ifContext::Statement_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_ifContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Keyword_ifContext* zsharp_parserParser::Statement_ifContext::keyword_if() {
  return getRuleContext<zsharp_parserParser::Keyword_ifContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_ifContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Statement_ifContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_ifContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}


size_t zsharp_parserParser::Statement_ifContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_if;
}

void zsharp_parserParser::Statement_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_if(this);
}

void zsharp_parserParser::Statement_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_if(this);
}


antlrcpp::Any zsharp_parserParser::Statement_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_if(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_ifContext* zsharp_parserParser::statement_if() {
  Statement_ifContext *_localctx = _tracker.createInstance<Statement_ifContext>(_ctx, getState());
  enterRule(_localctx, 20, zsharp_parserParser::RuleStatement_if);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    indent();
    setState(316);
    keyword_if();
    setState(317);
    match(zsharp_parserParser::SP);
    setState(318);
    expression_logic();
    setState(319);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_elseContext ------------------------------------------------------------------

zsharp_parserParser::Statement_elseContext::Statement_elseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_elseContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Keyword_elseContext* zsharp_parserParser::Statement_elseContext::keyword_else() {
  return getRuleContext<zsharp_parserParser::Keyword_elseContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_elseContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Keyword_ifContext* zsharp_parserParser::Statement_elseContext::keyword_if() {
  return getRuleContext<zsharp_parserParser::Keyword_ifContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_elseContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Statement_elseContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
}


size_t zsharp_parserParser::Statement_elseContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_else;
}

void zsharp_parserParser::Statement_elseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_else(this);
}

void zsharp_parserParser::Statement_elseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_else(this);
}


antlrcpp::Any zsharp_parserParser::Statement_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_else(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_elseContext* zsharp_parserParser::statement_else() {
  Statement_elseContext *_localctx = _tracker.createInstance<Statement_elseContext>(_ctx, getState());
  enterRule(_localctx, 22, zsharp_parserParser::RuleStatement_else);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    indent();
    setState(322);
    keyword_else();
    setState(327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::IF) {
      setState(323);
      keyword_if();
      setState(324);
      match(zsharp_parserParser::SP);
      setState(325);
      expression_logic();
    }
    setState(329);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

zsharp_parserParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Function_declContext* zsharp_parserParser::DeclarationContext::function_decl() {
  return getRuleContext<zsharp_parserParser::Function_declContext>(0);
}

zsharp_parserParser::Enum_declContext* zsharp_parserParser::DeclarationContext::enum_decl() {
  return getRuleContext<zsharp_parserParser::Enum_declContext>(0);
}

zsharp_parserParser::Struct_declContext* zsharp_parserParser::DeclarationContext::struct_decl() {
  return getRuleContext<zsharp_parserParser::Struct_declContext>(0);
}


size_t zsharp_parserParser::DeclarationContext::getRuleIndex() const {
  return zsharp_parserParser::RuleDeclaration;
}

void zsharp_parserParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void zsharp_parserParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any zsharp_parserParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::DeclarationContext* zsharp_parserParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, zsharp_parserParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(331);
      function_decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      enum_decl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(333);
      struct_decl();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_valueContext ------------------------------------------------------------------

zsharp_parserParser::Expression_valueContext::Expression_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Expression_valueContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}

zsharp_parserParser::StringContext* zsharp_parserParser::Expression_valueContext::string() {
  return getRuleContext<zsharp_parserParser::StringContext>(0);
}

zsharp_parserParser::Expression_boolContext* zsharp_parserParser::Expression_valueContext::expression_bool() {
  return getRuleContext<zsharp_parserParser::Expression_boolContext>(0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Expression_valueContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
}

zsharp_parserParser::Expression_bitwiseContext* zsharp_parserParser::Expression_valueContext::expression_bitwise() {
  return getRuleContext<zsharp_parserParser::Expression_bitwiseContext>(0);
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::Expression_valueContext::function_call() {
  return getRuleContext<zsharp_parserParser::Function_callContext>(0);
}


size_t zsharp_parserParser::Expression_valueContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_value;
}

void zsharp_parserParser::Expression_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_value(this);
}

void zsharp_parserParser::Expression_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_value(this);
}


antlrcpp::Any zsharp_parserParser::Expression_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_value(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Expression_valueContext* zsharp_parserParser::expression_value() {
  Expression_valueContext *_localctx = _tracker.createInstance<Expression_valueContext>(_ctx, getState());
  enterRule(_localctx, 26, zsharp_parserParser::RuleExpression_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(336);
      number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(337);
      string();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(338);
      expression_bool();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(339);
      expression_logic();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(340);
      expression_bitwise();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(341);
      function_call();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comptime_expression_valueContext ------------------------------------------------------------------

zsharp_parserParser::Comptime_expression_valueContext::Comptime_expression_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Comptime_expression_valueContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}

zsharp_parserParser::StringContext* zsharp_parserParser::Comptime_expression_valueContext::string() {
  return getRuleContext<zsharp_parserParser::StringContext>(0);
}

zsharp_parserParser::Expression_boolContext* zsharp_parserParser::Comptime_expression_valueContext::expression_bool() {
  return getRuleContext<zsharp_parserParser::Expression_boolContext>(0);
}


size_t zsharp_parserParser::Comptime_expression_valueContext::getRuleIndex() const {
  return zsharp_parserParser::RuleComptime_expression_value;
}

void zsharp_parserParser::Comptime_expression_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComptime_expression_value(this);
}

void zsharp_parserParser::Comptime_expression_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComptime_expression_value(this);
}


antlrcpp::Any zsharp_parserParser::Comptime_expression_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitComptime_expression_value(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Comptime_expression_valueContext* zsharp_parserParser::comptime_expression_value() {
  Comptime_expression_valueContext *_localctx = _tracker.createInstance<Comptime_expression_valueContext>(_ctx, getState());
  enterRule(_localctx, 28, zsharp_parserParser::RuleComptime_expression_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(347);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(344);
        number();
        break;
      }

      case zsharp_parserParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(345);
        string();
        break;
      }

      case zsharp_parserParser::TRUE:
      case zsharp_parserParser::FALSE:
      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 3);
        setState(346);
        expression_bool();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_logicContext ------------------------------------------------------------------

zsharp_parserParser::Expression_logicContext::Expression_logicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Logic_operandContext *> zsharp_parserParser::Expression_logicContext::logic_operand() {
  return getRuleContexts<zsharp_parserParser::Logic_operandContext>();
}

zsharp_parserParser::Logic_operandContext* zsharp_parserParser::Expression_logicContext::logic_operand(size_t i) {
  return getRuleContext<zsharp_parserParser::Logic_operandContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Expression_logicContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Expression_logicContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

zsharp_parserParser::Operator_logicContext* zsharp_parserParser::Expression_logicContext::operator_logic() {
  return getRuleContext<zsharp_parserParser::Operator_logicContext>(0);
}

zsharp_parserParser::Operator_logic_unaryContext* zsharp_parserParser::Expression_logicContext::operator_logic_unary() {
  return getRuleContext<zsharp_parserParser::Operator_logic_unaryContext>(0);
}


size_t zsharp_parserParser::Expression_logicContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_logic;
}

void zsharp_parserParser::Expression_logicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_logic(this);
}

void zsharp_parserParser::Expression_logicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_logic(this);
}


antlrcpp::Any zsharp_parserParser::Expression_logicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_logic(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::expression_logic() {
  Expression_logicContext *_localctx = _tracker.createInstance<Expression_logicContext>(_ctx, getState());
  enterRule(_localctx, 30, zsharp_parserParser::RuleExpression_logic);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(361);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(349);
      logic_operand();
      setState(350);
      match(zsharp_parserParser::SP);
      setState(351);
      operator_logic();
      setState(352);
      match(zsharp_parserParser::SP);
      setState(353);
      logic_operand();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == zsharp_parserParser::NOT) {
        setState(355);
        operator_logic_unary();
        setState(356);
        match(zsharp_parserParser::SP);
      }
      setState(360);
      logic_operand();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_operandContext ------------------------------------------------------------------

zsharp_parserParser::Logic_operandContext::Logic_operandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Expression_comparisonContext* zsharp_parserParser::Logic_operandContext::expression_comparison() {
  return getRuleContext<zsharp_parserParser::Expression_comparisonContext>(0);
}

zsharp_parserParser::Expression_boolContext* zsharp_parserParser::Logic_operandContext::expression_bool() {
  return getRuleContext<zsharp_parserParser::Expression_boolContext>(0);
}


size_t zsharp_parserParser::Logic_operandContext::getRuleIndex() const {
  return zsharp_parserParser::RuleLogic_operand;
}

void zsharp_parserParser::Logic_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_operand(this);
}

void zsharp_parserParser::Logic_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_operand(this);
}


antlrcpp::Any zsharp_parserParser::Logic_operandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitLogic_operand(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Logic_operandContext* zsharp_parserParser::logic_operand() {
  Logic_operandContext *_localctx = _tracker.createInstance<Logic_operandContext>(_ctx, getState());
  enterRule(_localctx, 32, zsharp_parserParser::RuleLogic_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(363);
      expression_comparison();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(364);
      expression_bool();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_comparisonContext ------------------------------------------------------------------

zsharp_parserParser::Expression_comparisonContext::Expression_comparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Comparison_operandContext *> zsharp_parserParser::Expression_comparisonContext::comparison_operand() {
  return getRuleContexts<zsharp_parserParser::Comparison_operandContext>();
}

zsharp_parserParser::Comparison_operandContext* zsharp_parserParser::Expression_comparisonContext::comparison_operand(size_t i) {
  return getRuleContext<zsharp_parserParser::Comparison_operandContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Expression_comparisonContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Expression_comparisonContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

zsharp_parserParser::Operator_comparisonContext* zsharp_parserParser::Expression_comparisonContext::operator_comparison() {
  return getRuleContext<zsharp_parserParser::Operator_comparisonContext>(0);
}


size_t zsharp_parserParser::Expression_comparisonContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_comparison;
}

void zsharp_parserParser::Expression_comparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_comparison(this);
}

void zsharp_parserParser::Expression_comparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_comparison(this);
}


antlrcpp::Any zsharp_parserParser::Expression_comparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_comparison(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Expression_comparisonContext* zsharp_parserParser::expression_comparison() {
  Expression_comparisonContext *_localctx = _tracker.createInstance<Expression_comparisonContext>(_ctx, getState());
  enterRule(_localctx, 34, zsharp_parserParser::RuleExpression_comparison);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    comparison_operand();
    setState(368);
    match(zsharp_parserParser::SP);
    setState(369);
    operator_comparison();
    setState(370);
    match(zsharp_parserParser::SP);
    setState(371);
    comparison_operand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comparison_operandContext ------------------------------------------------------------------

zsharp_parserParser::Comparison_operandContext::Comparison_operandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Expression_bitwiseContext* zsharp_parserParser::Comparison_operandContext::expression_bitwise() {
  return getRuleContext<zsharp_parserParser::Expression_bitwiseContext>(0);
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::Comparison_operandContext::function_call() {
  return getRuleContext<zsharp_parserParser::Function_callContext>(0);
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::Comparison_operandContext::variable_ref() {
  return getRuleContext<zsharp_parserParser::Variable_refContext>(0);
}

zsharp_parserParser::LiteralContext* zsharp_parserParser::Comparison_operandContext::literal() {
  return getRuleContext<zsharp_parserParser::LiteralContext>(0);
}


size_t zsharp_parserParser::Comparison_operandContext::getRuleIndex() const {
  return zsharp_parserParser::RuleComparison_operand;
}

void zsharp_parserParser::Comparison_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison_operand(this);
}

void zsharp_parserParser::Comparison_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison_operand(this);
}


antlrcpp::Any zsharp_parserParser::Comparison_operandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitComparison_operand(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Comparison_operandContext* zsharp_parserParser::comparison_operand() {
  Comparison_operandContext *_localctx = _tracker.createInstance<Comparison_operandContext>(_ctx, getState());
  enterRule(_localctx, 36, zsharp_parserParser::RuleComparison_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(373);
      expression_bitwise();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(374);
      function_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(375);
      variable_ref();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(376);
      literal();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_bitwiseContext ------------------------------------------------------------------

zsharp_parserParser::Expression_bitwiseContext::Expression_bitwiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Bitwise_operandContext *> zsharp_parserParser::Expression_bitwiseContext::bitwise_operand() {
  return getRuleContexts<zsharp_parserParser::Bitwise_operandContext>();
}

zsharp_parserParser::Bitwise_operandContext* zsharp_parserParser::Expression_bitwiseContext::bitwise_operand(size_t i) {
  return getRuleContext<zsharp_parserParser::Bitwise_operandContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Expression_bitwiseContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Expression_bitwiseContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

zsharp_parserParser::Operator_bitsContext* zsharp_parserParser::Expression_bitwiseContext::operator_bits() {
  return getRuleContext<zsharp_parserParser::Operator_bitsContext>(0);
}

zsharp_parserParser::Operator_bits_unaryContext* zsharp_parserParser::Expression_bitwiseContext::operator_bits_unary() {
  return getRuleContext<zsharp_parserParser::Operator_bits_unaryContext>(0);
}


size_t zsharp_parserParser::Expression_bitwiseContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_bitwise;
}

void zsharp_parserParser::Expression_bitwiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_bitwise(this);
}

void zsharp_parserParser::Expression_bitwiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_bitwise(this);
}


antlrcpp::Any zsharp_parserParser::Expression_bitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_bitwise(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Expression_bitwiseContext* zsharp_parserParser::expression_bitwise() {
  Expression_bitwiseContext *_localctx = _tracker.createInstance<Expression_bitwiseContext>(_ctx, getState());
  enterRule(_localctx, 38, zsharp_parserParser::RuleExpression_bitwise);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::IDENTIFIERupper:
      case zsharp_parserParser::IDENTIFIERlower:
      case zsharp_parserParser::IDENTIFIERmixed:
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(379);
        bitwise_operand();
        setState(380);
        match(zsharp_parserParser::SP);
        setState(381);
        operator_bits();
        setState(382);
        match(zsharp_parserParser::SP);
        setState(383);
        bitwise_operand();
        break;
      }

      case zsharp_parserParser::BIT_NOT: {
        enterOuterAlt(_localctx, 2);
        setState(385);
        operator_bits_unary();
        setState(386);
        bitwise_operand();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bitwise_operandContext ------------------------------------------------------------------

zsharp_parserParser::Bitwise_operandContext::Bitwise_operandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::Bitwise_operandContext::function_call() {
  return getRuleContext<zsharp_parserParser::Function_callContext>(0);
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::Bitwise_operandContext::variable_ref() {
  return getRuleContext<zsharp_parserParser::Variable_refContext>(0);
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Bitwise_operandContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}


size_t zsharp_parserParser::Bitwise_operandContext::getRuleIndex() const {
  return zsharp_parserParser::RuleBitwise_operand;
}

void zsharp_parserParser::Bitwise_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise_operand(this);
}

void zsharp_parserParser::Bitwise_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise_operand(this);
}


antlrcpp::Any zsharp_parserParser::Bitwise_operandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitBitwise_operand(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Bitwise_operandContext* zsharp_parserParser::bitwise_operand() {
  Bitwise_operandContext *_localctx = _tracker.createInstance<Bitwise_operandContext>(_ctx, getState());
  enterRule(_localctx, 40, zsharp_parserParser::RuleBitwise_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(390);
      function_call();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(391);
      variable_ref();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(392);
      number();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_boolContext ------------------------------------------------------------------

zsharp_parserParser::Expression_boolContext::Expression_boolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Literal_boolContext* zsharp_parserParser::Expression_boolContext::literal_bool() {
  return getRuleContext<zsharp_parserParser::Literal_boolContext>(0);
}

zsharp_parserParser::Identifier_boolContext* zsharp_parserParser::Expression_boolContext::identifier_bool() {
  return getRuleContext<zsharp_parserParser::Identifier_boolContext>(0);
}


size_t zsharp_parserParser::Expression_boolContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_bool;
}

void zsharp_parserParser::Expression_boolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_bool(this);
}

void zsharp_parserParser::Expression_boolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_bool(this);
}


antlrcpp::Any zsharp_parserParser::Expression_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_bool(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Expression_boolContext* zsharp_parserParser::expression_bool() {
  Expression_boolContext *_localctx = _tracker.createInstance<Expression_boolContext>(_ctx, getState());
  enterRule(_localctx, 42, zsharp_parserParser::RuleExpression_bool);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(397);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::TRUE:
      case zsharp_parserParser::FALSE: {
        enterOuterAlt(_localctx, 1);
        setState(395);
        literal_bool();
        break;
      }

      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 2);
        setState(396);
        identifier_bool();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_boolContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_boolContext::Identifier_boolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::Identifier_boolContext::variable_ref() {
  return getRuleContext<zsharp_parserParser::Variable_refContext>(0);
}

zsharp_parserParser::Parameter_refContext* zsharp_parserParser::Identifier_boolContext::parameter_ref() {
  return getRuleContext<zsharp_parserParser::Parameter_refContext>(0);
}


size_t zsharp_parserParser::Identifier_boolContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_bool;
}

void zsharp_parserParser::Identifier_boolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_bool(this);
}

void zsharp_parserParser::Identifier_boolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_bool(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_bool(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_boolContext* zsharp_parserParser::identifier_bool() {
  Identifier_boolContext *_localctx = _tracker.createInstance<Identifier_boolContext>(_ctx, getState());
  enterRule(_localctx, 44, zsharp_parserParser::RuleIdentifier_bool);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(401);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(399);
      variable_ref();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(400);
      parameter_ref();
      break;
    }

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

zsharp_parserParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_funcContext* zsharp_parserParser::Function_callContext::identifier_func() {
  return getRuleContext<zsharp_parserParser::Identifier_funcContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Function_callContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_callContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

zsharp_parserParser::Function_parameter_uselistContext* zsharp_parserParser::Function_callContext::function_parameter_uselist() {
  return getRuleContext<zsharp_parserParser::Function_parameter_uselistContext>(0);
}


size_t zsharp_parserParser::Function_callContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_call;
}

void zsharp_parserParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void zsharp_parserParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}


antlrcpp::Any zsharp_parserParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 46, zsharp_parserParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    identifier_func();
    setState(404);
    match(zsharp_parserParser::PARENopen);
    setState(406);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (zsharp_parserParser::TRUE - 25))
      | (1ULL << (zsharp_parserParser::FALSE - 25))
      | (1ULL << (zsharp_parserParser::IDENTIFIERupper - 25))
      | (1ULL << (zsharp_parserParser::IDENTIFIERlower - 25))
      | (1ULL << (zsharp_parserParser::IDENTIFIERmixed - 25))
      | (1ULL << (zsharp_parserParser::NUMBERbin - 25))
      | (1ULL << (zsharp_parserParser::NUMBERoct - 25))
      | (1ULL << (zsharp_parserParser::NUMBERdec - 25))
      | (1ULL << (zsharp_parserParser::NUMBERdec_prefix - 25))
      | (1ULL << (zsharp_parserParser::NUMBERhex - 25))
      | (1ULL << (zsharp_parserParser::CHARACTER - 25))
      | (1ULL << (zsharp_parserParser::STRING - 25))
      | (1ULL << (zsharp_parserParser::NOT - 25))
      | (1ULL << (zsharp_parserParser::BIT_NOT - 25))
      | (1ULL << (zsharp_parserParser::COMMA - 25)))) != 0)) {
      setState(405);
      function_parameter_uselist();
    }
    setState(408);
    match(zsharp_parserParser::PARENclose);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declContext ------------------------------------------------------------------

zsharp_parserParser::Function_declContext::Function_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_funcContext* zsharp_parserParser::Function_declContext::identifier_func() {
  return getRuleContext<zsharp_parserParser::Identifier_funcContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Function_declContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_declContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_declContext::EOL() {
  return getToken(zsharp_parserParser::EOL, 0);
}

zsharp_parserParser::CodeContext* zsharp_parserParser::Function_declContext::code() {
  return getRuleContext<zsharp_parserParser::CodeContext>(0);
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Function_declContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Function_parameter_listContext* zsharp_parserParser::Function_declContext::function_parameter_list() {
  return getRuleContext<zsharp_parserParser::Function_parameter_listContext>(0);
}

zsharp_parserParser::Function_typeContext* zsharp_parserParser::Function_declContext::function_type() {
  return getRuleContext<zsharp_parserParser::Function_typeContext>(0);
}


size_t zsharp_parserParser::Function_declContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_decl;
}

void zsharp_parserParser::Function_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_decl(this);
}

void zsharp_parserParser::Function_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_decl(this);
}


antlrcpp::Any zsharp_parserParser::Function_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_decl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_declContext* zsharp_parserParser::function_decl() {
  Function_declContext *_localctx = _tracker.createInstance<Function_declContext>(_ctx, getState());
  enterRule(_localctx, 48, zsharp_parserParser::RuleFunction_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(410);
      indent();
    }
    setState(413);
    identifier_func();
    setState(414);
    match(zsharp_parserParser::PARENopen);
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::IDENTIFIERlower

    || _la == zsharp_parserParser::COMMA) {
      setState(415);
      function_parameter_list();
    }
    setState(418);
    match(zsharp_parserParser::PARENclose);
    setState(420);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(419);
      function_type();
    }
    setState(422);
    match(zsharp_parserParser::EOL);
    setState(423);
    code();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_parameter_listContext ------------------------------------------------------------------

zsharp_parserParser::Function_parameter_listContext::Function_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Function_parameterContext *> zsharp_parserParser::Function_parameter_listContext::function_parameter() {
  return getRuleContexts<zsharp_parserParser::Function_parameterContext>();
}

zsharp_parserParser::Function_parameterContext* zsharp_parserParser::Function_parameter_listContext::function_parameter(size_t i) {
  return getRuleContext<zsharp_parserParser::Function_parameterContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_parameter_listContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Function_parameter_listContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_parameter_listContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Function_parameter_listContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}


size_t zsharp_parserParser::Function_parameter_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_parameter_list;
}

void zsharp_parserParser::Function_parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_parameter_list(this);
}

void zsharp_parserParser::Function_parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_parameter_list(this);
}


antlrcpp::Any zsharp_parserParser::Function_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_parameter_listContext* zsharp_parserParser::function_parameter_list() {
  Function_parameter_listContext *_localctx = _tracker.createInstance<Function_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 50, zsharp_parserParser::RuleFunction_parameter_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 1);
        setState(425);
        function_parameter();
        break;
      }

      case zsharp_parserParser::COMMA: {
        enterOuterAlt(_localctx, 2);
        setState(429); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(426);
          match(zsharp_parserParser::COMMA);
          setState(427);
          match(zsharp_parserParser::SP);
          setState(428);
          function_parameter();
          setState(431); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == zsharp_parserParser::COMMA);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_parameterContext ------------------------------------------------------------------

zsharp_parserParser::Function_parameterContext::Function_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_paramContext* zsharp_parserParser::Function_parameterContext::identifier_param() {
  return getRuleContext<zsharp_parserParser::Identifier_paramContext>(0);
}

zsharp_parserParser::Function_typeContext* zsharp_parserParser::Function_parameterContext::function_type() {
  return getRuleContext<zsharp_parserParser::Function_typeContext>(0);
}


size_t zsharp_parserParser::Function_parameterContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_parameter;
}

void zsharp_parserParser::Function_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_parameter(this);
}

void zsharp_parserParser::Function_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_parameter(this);
}


antlrcpp::Any zsharp_parserParser::Function_parameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_parameter(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_parameterContext* zsharp_parserParser::function_parameter() {
  Function_parameterContext *_localctx = _tracker.createInstance<Function_parameterContext>(_ctx, getState());
  enterRule(_localctx, 52, zsharp_parserParser::RuleFunction_parameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    identifier_param();
    setState(436);
    function_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_typeContext ------------------------------------------------------------------

zsharp_parserParser::Function_typeContext::Function_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Function_typeContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_typeContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Type_anyContext* zsharp_parserParser::Function_typeContext::type_any() {
  return getRuleContext<zsharp_parserParser::Type_anyContext>(0);
}


size_t zsharp_parserParser::Function_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_type;
}

void zsharp_parserParser::Function_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_type(this);
}

void zsharp_parserParser::Function_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_type(this);
}


antlrcpp::Any zsharp_parserParser::Function_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_typeContext* zsharp_parserParser::function_type() {
  Function_typeContext *_localctx = _tracker.createInstance<Function_typeContext>(_ctx, getState());
  enterRule(_localctx, 54, zsharp_parserParser::RuleFunction_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(zsharp_parserParser::COLON);
    setState(439);
    match(zsharp_parserParser::SP);
    setState(440);
    type_any();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_parameter_uselistContext ------------------------------------------------------------------

zsharp_parserParser::Function_parameter_uselistContext::Function_parameter_uselistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Function_param_useContext *> zsharp_parserParser::Function_parameter_uselistContext::function_param_use() {
  return getRuleContexts<zsharp_parserParser::Function_param_useContext>();
}

zsharp_parserParser::Function_param_useContext* zsharp_parserParser::Function_parameter_uselistContext::function_param_use(size_t i) {
  return getRuleContext<zsharp_parserParser::Function_param_useContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_parameter_uselistContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Function_parameter_uselistContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_parameter_uselistContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Function_parameter_uselistContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}


size_t zsharp_parserParser::Function_parameter_uselistContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_parameter_uselist;
}

void zsharp_parserParser::Function_parameter_uselistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_parameter_uselist(this);
}

void zsharp_parserParser::Function_parameter_uselistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_parameter_uselist(this);
}


antlrcpp::Any zsharp_parserParser::Function_parameter_uselistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_parameter_uselist(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_parameter_uselistContext* zsharp_parserParser::function_parameter_uselist() {
  Function_parameter_uselistContext *_localctx = _tracker.createInstance<Function_parameter_uselistContext>(_ctx, getState());
  enterRule(_localctx, 56, zsharp_parserParser::RuleFunction_parameter_uselist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(450);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(442);
      function_param_use();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(446); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(443);
        match(zsharp_parserParser::COMMA);
        setState(444);
        match(zsharp_parserParser::SP);
        setState(445);
        function_param_use();
        setState(448); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == zsharp_parserParser::COMMA);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_param_useContext ------------------------------------------------------------------

zsharp_parserParser::Function_param_useContext::Function_param_useContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Expression_valueContext *> zsharp_parserParser::Function_param_useContext::expression_value() {
  return getRuleContexts<zsharp_parserParser::Expression_valueContext>();
}

zsharp_parserParser::Expression_valueContext* zsharp_parserParser::Function_param_useContext::expression_value(size_t i) {
  return getRuleContext<zsharp_parserParser::Expression_valueContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_param_useContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Function_param_useContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Function_param_useContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Function_param_useContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}


size_t zsharp_parserParser::Function_param_useContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_param_use;
}

void zsharp_parserParser::Function_param_useContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_param_use(this);
}

void zsharp_parserParser::Function_param_useContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_param_use(this);
}


antlrcpp::Any zsharp_parserParser::Function_param_useContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_param_use(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_param_useContext* zsharp_parserParser::function_param_use() {
  Function_param_useContext *_localctx = _tracker.createInstance<Function_param_useContext>(_ctx, getState());
  enterRule(_localctx, 58, zsharp_parserParser::RuleFunction_param_use);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(460);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::TRUE:
      case zsharp_parserParser::FALSE:
      case zsharp_parserParser::IDENTIFIERupper:
      case zsharp_parserParser::IDENTIFIERlower:
      case zsharp_parserParser::IDENTIFIERmixed:
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER:
      case zsharp_parserParser::STRING:
      case zsharp_parserParser::NOT:
      case zsharp_parserParser::BIT_NOT: {
        enterOuterAlt(_localctx, 1);
        setState(452);
        expression_value();
        break;
      }

      case zsharp_parserParser::COMMA: {
        enterOuterAlt(_localctx, 2);
        setState(456); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(453);
                  match(zsharp_parserParser::COMMA);
                  setState(454);
                  match(zsharp_parserParser::SP);
                  setState(455);
                  expression_value();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(458); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_refContext ------------------------------------------------------------------

zsharp_parserParser::Variable_refContext::Variable_refContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_varContext* zsharp_parserParser::Variable_refContext::identifier_var() {
  return getRuleContext<zsharp_parserParser::Identifier_varContext>(0);
}


size_t zsharp_parserParser::Variable_refContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_ref;
}

void zsharp_parserParser::Variable_refContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_ref(this);
}

void zsharp_parserParser::Variable_refContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_ref(this);
}


antlrcpp::Any zsharp_parserParser::Variable_refContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_ref(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::variable_ref() {
  Variable_refContext *_localctx = _tracker.createInstance<Variable_refContext>(_ctx, getState());
  enterRule(_localctx, 60, zsharp_parserParser::RuleVariable_ref);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    identifier_var();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_refContext ------------------------------------------------------------------

zsharp_parserParser::Parameter_refContext::Parameter_refContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_paramContext* zsharp_parserParser::Parameter_refContext::identifier_param() {
  return getRuleContext<zsharp_parserParser::Identifier_paramContext>(0);
}


size_t zsharp_parserParser::Parameter_refContext::getRuleIndex() const {
  return zsharp_parserParser::RuleParameter_ref;
}

void zsharp_parserParser::Parameter_refContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_ref(this);
}

void zsharp_parserParser::Parameter_refContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_ref(this);
}


antlrcpp::Any zsharp_parserParser::Parameter_refContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitParameter_ref(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Parameter_refContext* zsharp_parserParser::parameter_ref() {
  Parameter_refContext *_localctx = _tracker.createInstance<Parameter_refContext>(_ctx, getState());
  enterRule(_localctx, 62, zsharp_parserParser::RuleParameter_ref);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(464);
    identifier_param();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_declContext ------------------------------------------------------------------

zsharp_parserParser::Struct_declContext::Struct_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Struct_declContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Struct_declContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Struct_field_decl_listContext* zsharp_parserParser::Struct_declContext::struct_field_decl_list() {
  return getRuleContext<zsharp_parserParser::Struct_field_decl_listContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Struct_declContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Struct_declContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Type_anyContext* zsharp_parserParser::Struct_declContext::type_any() {
  return getRuleContext<zsharp_parserParser::Type_anyContext>(0);
}


size_t zsharp_parserParser::Struct_declContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_decl;
}

void zsharp_parserParser::Struct_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_decl(this);
}

void zsharp_parserParser::Struct_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_decl(this);
}


antlrcpp::Any zsharp_parserParser::Struct_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_decl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_declContext* zsharp_parserParser::struct_decl() {
  Struct_declContext *_localctx = _tracker.createInstance<Struct_declContext>(_ctx, getState());
  enterRule(_localctx, 64, zsharp_parserParser::RuleStruct_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    identifier_type();
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(467);
      match(zsharp_parserParser::COLON);
      setState(468);
      match(zsharp_parserParser::SP);
      setState(469);
      type_any();
    }
    setState(472);
    newline();
    setState(473);
    struct_field_decl_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_field_decl_listContext ------------------------------------------------------------------

zsharp_parserParser::Struct_field_decl_listContext::Struct_field_decl_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Struct_field_declContext *> zsharp_parserParser::Struct_field_decl_listContext::struct_field_decl() {
  return getRuleContexts<zsharp_parserParser::Struct_field_declContext>();
}

zsharp_parserParser::Struct_field_declContext* zsharp_parserParser::Struct_field_decl_listContext::struct_field_decl(size_t i) {
  return getRuleContext<zsharp_parserParser::Struct_field_declContext>(i);
}


size_t zsharp_parserParser::Struct_field_decl_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_field_decl_list;
}

void zsharp_parserParser::Struct_field_decl_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_field_decl_list(this);
}

void zsharp_parserParser::Struct_field_decl_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_field_decl_list(this);
}


antlrcpp::Any zsharp_parserParser::Struct_field_decl_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_field_decl_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_field_decl_listContext* zsharp_parserParser::struct_field_decl_list() {
  Struct_field_decl_listContext *_localctx = _tracker.createInstance<Struct_field_decl_listContext>(_ctx, getState());
  enterRule(_localctx, 66, zsharp_parserParser::RuleStruct_field_decl_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(476); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(475);
              struct_field_decl();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(478); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_field_declContext ------------------------------------------------------------------

zsharp_parserParser::Struct_field_declContext::Struct_field_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Struct_field_declContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Identifier_fieldContext* zsharp_parserParser::Struct_field_declContext::identifier_field() {
  return getRuleContext<zsharp_parserParser::Identifier_fieldContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Struct_field_declContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Struct_field_declContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Type_anyContext* zsharp_parserParser::Struct_field_declContext::type_any() {
  return getRuleContext<zsharp_parserParser::Type_anyContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Struct_field_declContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}


size_t zsharp_parserParser::Struct_field_declContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_field_decl;
}

void zsharp_parserParser::Struct_field_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_field_decl(this);
}

void zsharp_parserParser::Struct_field_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_field_decl(this);
}


antlrcpp::Any zsharp_parserParser::Struct_field_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_field_decl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_field_declContext* zsharp_parserParser::struct_field_decl() {
  Struct_field_declContext *_localctx = _tracker.createInstance<Struct_field_declContext>(_ctx, getState());
  enterRule(_localctx, 68, zsharp_parserParser::RuleStruct_field_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    indent();
    setState(481);
    identifier_field();
    setState(482);
    match(zsharp_parserParser::COLON);
    setState(483);
    match(zsharp_parserParser::SP);
    setState(484);
    type_any();
    setState(485);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_declContext ------------------------------------------------------------------

zsharp_parserParser::Enum_declContext::Enum_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Enum_declContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Enum_declContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Enum_option_decl_listContext* zsharp_parserParser::Enum_declContext::enum_option_decl_list() {
  return getRuleContext<zsharp_parserParser::Enum_option_decl_listContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Enum_declContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_declContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Enum_base_typesContext* zsharp_parserParser::Enum_declContext::enum_base_types() {
  return getRuleContext<zsharp_parserParser::Enum_base_typesContext>(0);
}


size_t zsharp_parserParser::Enum_declContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_decl;
}

void zsharp_parserParser::Enum_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_decl(this);
}

void zsharp_parserParser::Enum_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_decl(this);
}


antlrcpp::Any zsharp_parserParser::Enum_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_decl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_declContext* zsharp_parserParser::enum_decl() {
  Enum_declContext *_localctx = _tracker.createInstance<Enum_declContext>(_ctx, getState());
  enterRule(_localctx, 70, zsharp_parserParser::RuleEnum_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    identifier_type();
    setState(491);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(488);
      match(zsharp_parserParser::COLON);
      setState(489);
      match(zsharp_parserParser::SP);
      setState(490);
      enum_base_types();
    }
    setState(493);
    newline();
    setState(494);
    enum_option_decl_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_option_decl_listContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_decl_listContext::Enum_option_decl_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Enum_option_declContext *> zsharp_parserParser::Enum_option_decl_listContext::enum_option_decl() {
  return getRuleContexts<zsharp_parserParser::Enum_option_declContext>();
}

zsharp_parserParser::Enum_option_declContext* zsharp_parserParser::Enum_option_decl_listContext::enum_option_decl(size_t i) {
  return getRuleContext<zsharp_parserParser::Enum_option_declContext>(i);
}


size_t zsharp_parserParser::Enum_option_decl_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_decl_list;
}

void zsharp_parserParser::Enum_option_decl_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_decl_list(this);
}

void zsharp_parserParser::Enum_option_decl_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_decl_list(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_decl_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_decl_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_decl_listContext* zsharp_parserParser::enum_option_decl_list() {
  Enum_option_decl_listContext *_localctx = _tracker.createInstance<Enum_option_decl_listContext>(_ctx, getState());
  enterRule(_localctx, 72, zsharp_parserParser::RuleEnum_option_decl_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(497); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(496);
              enum_option_decl();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(499); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_option_declContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_declContext::Enum_option_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Enum_option_declContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Identifier_enumoptionContext* zsharp_parserParser::Enum_option_declContext::identifier_enumoption() {
  return getRuleContext<zsharp_parserParser::Identifier_enumoptionContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Enum_option_declContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Enum_option_declContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_declContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_declContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

zsharp_parserParser::Comptime_expression_valueContext* zsharp_parserParser::Enum_option_declContext::comptime_expression_value() {
  return getRuleContext<zsharp_parserParser::Comptime_expression_valueContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_declContext::COMMA() {
  return getToken(zsharp_parserParser::COMMA, 0);
}


size_t zsharp_parserParser::Enum_option_declContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_decl;
}

void zsharp_parserParser::Enum_option_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_decl(this);
}

void zsharp_parserParser::Enum_option_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_decl(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_decl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_declContext* zsharp_parserParser::enum_option_decl() {
  Enum_option_declContext *_localctx = _tracker.createInstance<Enum_option_declContext>(_ctx, getState());
  enterRule(_localctx, 74, zsharp_parserParser::RuleEnum_option_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    indent();
    setState(502);
    identifier_enumoption();
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SP) {
      setState(503);
      match(zsharp_parserParser::SP);
      setState(504);
      match(zsharp_parserParser::EQ_ASSIGN);
      setState(505);
      match(zsharp_parserParser::SP);
      setState(506);
      comptime_expression_value();
    }
    setState(510);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COMMA) {
      setState(509);
      match(zsharp_parserParser::COMMA);
    }
    setState(512);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_base_typesContext ------------------------------------------------------------------

zsharp_parserParser::Enum_base_typesContext::Enum_base_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_BitContext* zsharp_parserParser::Enum_base_typesContext::type_Bit() {
  return getRuleContext<zsharp_parserParser::Type_BitContext>(0);
}

zsharp_parserParser::Type_StrContext* zsharp_parserParser::Enum_base_typesContext::type_Str() {
  return getRuleContext<zsharp_parserParser::Type_StrContext>(0);
}

zsharp_parserParser::Type_F16Context* zsharp_parserParser::Enum_base_typesContext::type_F16() {
  return getRuleContext<zsharp_parserParser::Type_F16Context>(0);
}

zsharp_parserParser::Type_F32Context* zsharp_parserParser::Enum_base_typesContext::type_F32() {
  return getRuleContext<zsharp_parserParser::Type_F32Context>(0);
}

zsharp_parserParser::Type_I16Context* zsharp_parserParser::Enum_base_typesContext::type_I16() {
  return getRuleContext<zsharp_parserParser::Type_I16Context>(0);
}

zsharp_parserParser::Type_I24Context* zsharp_parserParser::Enum_base_typesContext::type_I24() {
  return getRuleContext<zsharp_parserParser::Type_I24Context>(0);
}

zsharp_parserParser::Type_I32Context* zsharp_parserParser::Enum_base_typesContext::type_I32() {
  return getRuleContext<zsharp_parserParser::Type_I32Context>(0);
}

zsharp_parserParser::Type_I8Context* zsharp_parserParser::Enum_base_typesContext::type_I8() {
  return getRuleContext<zsharp_parserParser::Type_I8Context>(0);
}

zsharp_parserParser::Type_U16Context* zsharp_parserParser::Enum_base_typesContext::type_U16() {
  return getRuleContext<zsharp_parserParser::Type_U16Context>(0);
}

zsharp_parserParser::Type_U24Context* zsharp_parserParser::Enum_base_typesContext::type_U24() {
  return getRuleContext<zsharp_parserParser::Type_U24Context>(0);
}

zsharp_parserParser::Type_U32Context* zsharp_parserParser::Enum_base_typesContext::type_U32() {
  return getRuleContext<zsharp_parserParser::Type_U32Context>(0);
}

zsharp_parserParser::Type_U8Context* zsharp_parserParser::Enum_base_typesContext::type_U8() {
  return getRuleContext<zsharp_parserParser::Type_U8Context>(0);
}


size_t zsharp_parserParser::Enum_base_typesContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_base_types;
}

void zsharp_parserParser::Enum_base_typesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_base_types(this);
}

void zsharp_parserParser::Enum_base_typesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_base_types(this);
}


antlrcpp::Any zsharp_parserParser::Enum_base_typesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_base_types(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_base_typesContext* zsharp_parserParser::enum_base_types() {
  Enum_base_typesContext *_localctx = _tracker.createInstance<Enum_base_typesContext>(_ctx, getState());
  enterRule(_localctx, 76, zsharp_parserParser::RuleEnum_base_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(526);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(514);
        type_Bit();
        break;
      }

      case zsharp_parserParser::STR: {
        enterOuterAlt(_localctx, 2);
        setState(515);
        type_Str();
        break;
      }

      case zsharp_parserParser::F16: {
        enterOuterAlt(_localctx, 3);
        setState(516);
        type_F16();
        break;
      }

      case zsharp_parserParser::F32: {
        enterOuterAlt(_localctx, 4);
        setState(517);
        type_F32();
        break;
      }

      case zsharp_parserParser::I16: {
        enterOuterAlt(_localctx, 5);
        setState(518);
        type_I16();
        break;
      }

      case zsharp_parserParser::I24: {
        enterOuterAlt(_localctx, 6);
        setState(519);
        type_I24();
        break;
      }

      case zsharp_parserParser::I32: {
        enterOuterAlt(_localctx, 7);
        setState(520);
        type_I32();
        break;
      }

      case zsharp_parserParser::I8: {
        enterOuterAlt(_localctx, 8);
        setState(521);
        type_I8();
        break;
      }

      case zsharp_parserParser::U16: {
        enterOuterAlt(_localctx, 9);
        setState(522);
        type_U16();
        break;
      }

      case zsharp_parserParser::U24: {
        enterOuterAlt(_localctx, 10);
        setState(523);
        type_U24();
        break;
      }

      case zsharp_parserParser::U32: {
        enterOuterAlt(_localctx, 11);
        setState(524);
        type_U32();
        break;
      }

      case zsharp_parserParser::U8: {
        enterOuterAlt(_localctx, 12);
        setState(525);
        type_U8();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_anyContext ------------------------------------------------------------------

zsharp_parserParser::Type_anyContext::Type_anyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Type_anyContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

zsharp_parserParser::Optional_typeContext* zsharp_parserParser::Type_anyContext::optional_type() {
  return getRuleContext<zsharp_parserParser::Optional_typeContext>(0);
}

zsharp_parserParser::Error_typeContext* zsharp_parserParser::Type_anyContext::error_type() {
  return getRuleContext<zsharp_parserParser::Error_typeContext>(0);
}

zsharp_parserParser::Optional_error_typeContext* zsharp_parserParser::Type_anyContext::optional_error_type() {
  return getRuleContext<zsharp_parserParser::Optional_error_typeContext>(0);
}


size_t zsharp_parserParser::Type_anyContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_any;
}

void zsharp_parserParser::Type_anyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_any(this);
}

void zsharp_parserParser::Type_anyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_any(this);
}


antlrcpp::Any zsharp_parserParser::Type_anyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_any(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_anyContext* zsharp_parserParser::type_any() {
  Type_anyContext *_localctx = _tracker.createInstance<Type_anyContext>(_ctx, getState());
  enterRule(_localctx, 78, zsharp_parserParser::RuleType_any);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(532);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(528);
      type_name();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(529);
      optional_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(530);
      error_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(531);
      optional_error_type();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_typeContext ------------------------------------------------------------------

zsharp_parserParser::Optional_typeContext::Optional_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Optional_typeContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Optional_typeContext::QUESTION() {
  return getToken(zsharp_parserParser::QUESTION, 0);
}


size_t zsharp_parserParser::Optional_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOptional_type;
}

void zsharp_parserParser::Optional_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptional_type(this);
}

void zsharp_parserParser::Optional_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptional_type(this);
}


antlrcpp::Any zsharp_parserParser::Optional_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOptional_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Optional_typeContext* zsharp_parserParser::optional_type() {
  Optional_typeContext *_localctx = _tracker.createInstance<Optional_typeContext>(_ctx, getState());
  enterRule(_localctx, 80, zsharp_parserParser::RuleOptional_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(534);
    type_name();
    setState(535);
    match(zsharp_parserParser::QUESTION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Error_typeContext ------------------------------------------------------------------

zsharp_parserParser::Error_typeContext::Error_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Error_typeContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Error_typeContext::ERROR() {
  return getToken(zsharp_parserParser::ERROR, 0);
}


size_t zsharp_parserParser::Error_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleError_type;
}

void zsharp_parserParser::Error_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError_type(this);
}

void zsharp_parserParser::Error_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError_type(this);
}


antlrcpp::Any zsharp_parserParser::Error_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitError_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Error_typeContext* zsharp_parserParser::error_type() {
  Error_typeContext *_localctx = _tracker.createInstance<Error_typeContext>(_ctx, getState());
  enterRule(_localctx, 82, zsharp_parserParser::RuleError_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(537);
    type_name();
    setState(538);
    match(zsharp_parserParser::ERROR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_error_typeContext ------------------------------------------------------------------

zsharp_parserParser::Optional_error_typeContext::Optional_error_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Optional_error_typeContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Optional_error_typeContext::ERROR() {
  return getToken(zsharp_parserParser::ERROR, 0);
}

tree::TerminalNode* zsharp_parserParser::Optional_error_typeContext::QUESTION() {
  return getToken(zsharp_parserParser::QUESTION, 0);
}


size_t zsharp_parserParser::Optional_error_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOptional_error_type;
}

void zsharp_parserParser::Optional_error_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptional_error_type(this);
}

void zsharp_parserParser::Optional_error_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptional_error_type(this);
}


antlrcpp::Any zsharp_parserParser::Optional_error_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOptional_error_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Optional_error_typeContext* zsharp_parserParser::optional_error_type() {
  Optional_error_typeContext *_localctx = _tracker.createInstance<Optional_error_typeContext>(_ctx, getState());
  enterRule(_localctx, 84, zsharp_parserParser::RuleOptional_error_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    type_name();
    setState(541);
    match(zsharp_parserParser::ERROR);
    setState(542);
    match(zsharp_parserParser::QUESTION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

zsharp_parserParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Known_typesContext* zsharp_parserParser::Type_nameContext::known_types() {
  return getRuleContext<zsharp_parserParser::Known_typesContext>(0);
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Type_nameContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}


size_t zsharp_parserParser::Type_nameContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_name;
}

void zsharp_parserParser::Type_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_name(this);
}

void zsharp_parserParser::Type_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_name(this);
}


antlrcpp::Any zsharp_parserParser::Type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_name(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 86, zsharp_parserParser::RuleType_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(546);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::U8:
      case zsharp_parserParser::U16:
      case zsharp_parserParser::U24:
      case zsharp_parserParser::U32:
      case zsharp_parserParser::I8:
      case zsharp_parserParser::I16:
      case zsharp_parserParser::I24:
      case zsharp_parserParser::I32:
      case zsharp_parserParser::F16:
      case zsharp_parserParser::F32:
      case zsharp_parserParser::STR:
      case zsharp_parserParser::BOOL:
      case zsharp_parserParser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(544);
        known_types();
        break;
      }

      case zsharp_parserParser::IDENTIFIERupper: {
        enterOuterAlt(_localctx, 2);
        setState(545);
        identifier_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Known_typesContext ------------------------------------------------------------------

zsharp_parserParser::Known_typesContext::Known_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_BitContext* zsharp_parserParser::Known_typesContext::type_Bit() {
  return getRuleContext<zsharp_parserParser::Type_BitContext>(0);
}

zsharp_parserParser::Type_BoolContext* zsharp_parserParser::Known_typesContext::type_Bool() {
  return getRuleContext<zsharp_parserParser::Type_BoolContext>(0);
}

zsharp_parserParser::Type_StrContext* zsharp_parserParser::Known_typesContext::type_Str() {
  return getRuleContext<zsharp_parserParser::Type_StrContext>(0);
}

zsharp_parserParser::Type_F16Context* zsharp_parserParser::Known_typesContext::type_F16() {
  return getRuleContext<zsharp_parserParser::Type_F16Context>(0);
}

zsharp_parserParser::Type_F32Context* zsharp_parserParser::Known_typesContext::type_F32() {
  return getRuleContext<zsharp_parserParser::Type_F32Context>(0);
}

zsharp_parserParser::Type_I16Context* zsharp_parserParser::Known_typesContext::type_I16() {
  return getRuleContext<zsharp_parserParser::Type_I16Context>(0);
}

zsharp_parserParser::Type_I24Context* zsharp_parserParser::Known_typesContext::type_I24() {
  return getRuleContext<zsharp_parserParser::Type_I24Context>(0);
}

zsharp_parserParser::Type_I32Context* zsharp_parserParser::Known_typesContext::type_I32() {
  return getRuleContext<zsharp_parserParser::Type_I32Context>(0);
}

zsharp_parserParser::Type_I8Context* zsharp_parserParser::Known_typesContext::type_I8() {
  return getRuleContext<zsharp_parserParser::Type_I8Context>(0);
}

zsharp_parserParser::Type_U16Context* zsharp_parserParser::Known_typesContext::type_U16() {
  return getRuleContext<zsharp_parserParser::Type_U16Context>(0);
}

zsharp_parserParser::Type_U24Context* zsharp_parserParser::Known_typesContext::type_U24() {
  return getRuleContext<zsharp_parserParser::Type_U24Context>(0);
}

zsharp_parserParser::Type_U32Context* zsharp_parserParser::Known_typesContext::type_U32() {
  return getRuleContext<zsharp_parserParser::Type_U32Context>(0);
}

zsharp_parserParser::Type_U8Context* zsharp_parserParser::Known_typesContext::type_U8() {
  return getRuleContext<zsharp_parserParser::Type_U8Context>(0);
}


size_t zsharp_parserParser::Known_typesContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKnown_types;
}

void zsharp_parserParser::Known_typesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKnown_types(this);
}

void zsharp_parserParser::Known_typesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKnown_types(this);
}


antlrcpp::Any zsharp_parserParser::Known_typesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKnown_types(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Known_typesContext* zsharp_parserParser::known_types() {
  Known_typesContext *_localctx = _tracker.createInstance<Known_typesContext>(_ctx, getState());
  enterRule(_localctx, 88, zsharp_parserParser::RuleKnown_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(561);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(548);
        type_Bit();
        break;
      }

      case zsharp_parserParser::BOOL: {
        enterOuterAlt(_localctx, 2);
        setState(549);
        type_Bool();
        break;
      }

      case zsharp_parserParser::STR: {
        enterOuterAlt(_localctx, 3);
        setState(550);
        type_Str();
        break;
      }

      case zsharp_parserParser::F16: {
        enterOuterAlt(_localctx, 4);
        setState(551);
        type_F16();
        break;
      }

      case zsharp_parserParser::F32: {
        enterOuterAlt(_localctx, 5);
        setState(552);
        type_F32();
        break;
      }

      case zsharp_parserParser::I16: {
        enterOuterAlt(_localctx, 6);
        setState(553);
        type_I16();
        break;
      }

      case zsharp_parserParser::I24: {
        enterOuterAlt(_localctx, 7);
        setState(554);
        type_I24();
        break;
      }

      case zsharp_parserParser::I32: {
        enterOuterAlt(_localctx, 8);
        setState(555);
        type_I32();
        break;
      }

      case zsharp_parserParser::I8: {
        enterOuterAlt(_localctx, 9);
        setState(556);
        type_I8();
        break;
      }

      case zsharp_parserParser::U16: {
        enterOuterAlt(_localctx, 10);
        setState(557);
        type_U16();
        break;
      }

      case zsharp_parserParser::U24: {
        enterOuterAlt(_localctx, 11);
        setState(558);
        type_U24();
        break;
      }

      case zsharp_parserParser::U32: {
        enterOuterAlt(_localctx, 12);
        setState(559);
        type_U32();
        break;
      }

      case zsharp_parserParser::U8: {
        enterOuterAlt(_localctx, 13);
        setState(560);
        type_U8();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_U8Context ------------------------------------------------------------------

zsharp_parserParser::Type_U8Context::Type_U8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_U8Context::U8() {
  return getToken(zsharp_parserParser::U8, 0);
}


size_t zsharp_parserParser::Type_U8Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_U8;
}

void zsharp_parserParser::Type_U8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_U8(this);
}

void zsharp_parserParser::Type_U8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_U8(this);
}


antlrcpp::Any zsharp_parserParser::Type_U8Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_U8(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_U8Context* zsharp_parserParser::type_U8() {
  Type_U8Context *_localctx = _tracker.createInstance<Type_U8Context>(_ctx, getState());
  enterRule(_localctx, 90, zsharp_parserParser::RuleType_U8);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(563);
    match(zsharp_parserParser::U8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_U16Context ------------------------------------------------------------------

zsharp_parserParser::Type_U16Context::Type_U16Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_U16Context::U16() {
  return getToken(zsharp_parserParser::U16, 0);
}


size_t zsharp_parserParser::Type_U16Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_U16;
}

void zsharp_parserParser::Type_U16Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_U16(this);
}

void zsharp_parserParser::Type_U16Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_U16(this);
}


antlrcpp::Any zsharp_parserParser::Type_U16Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_U16(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_U16Context* zsharp_parserParser::type_U16() {
  Type_U16Context *_localctx = _tracker.createInstance<Type_U16Context>(_ctx, getState());
  enterRule(_localctx, 92, zsharp_parserParser::RuleType_U16);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(zsharp_parserParser::U16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_U24Context ------------------------------------------------------------------

zsharp_parserParser::Type_U24Context::Type_U24Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_U24Context::U24() {
  return getToken(zsharp_parserParser::U24, 0);
}


size_t zsharp_parserParser::Type_U24Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_U24;
}

void zsharp_parserParser::Type_U24Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_U24(this);
}

void zsharp_parserParser::Type_U24Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_U24(this);
}


antlrcpp::Any zsharp_parserParser::Type_U24Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_U24(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_U24Context* zsharp_parserParser::type_U24() {
  Type_U24Context *_localctx = _tracker.createInstance<Type_U24Context>(_ctx, getState());
  enterRule(_localctx, 94, zsharp_parserParser::RuleType_U24);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(567);
    match(zsharp_parserParser::U24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_U32Context ------------------------------------------------------------------

zsharp_parserParser::Type_U32Context::Type_U32Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_U32Context::U32() {
  return getToken(zsharp_parserParser::U32, 0);
}


size_t zsharp_parserParser::Type_U32Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_U32;
}

void zsharp_parserParser::Type_U32Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_U32(this);
}

void zsharp_parserParser::Type_U32Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_U32(this);
}


antlrcpp::Any zsharp_parserParser::Type_U32Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_U32(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_U32Context* zsharp_parserParser::type_U32() {
  Type_U32Context *_localctx = _tracker.createInstance<Type_U32Context>(_ctx, getState());
  enterRule(_localctx, 96, zsharp_parserParser::RuleType_U32);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    match(zsharp_parserParser::U32);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_I8Context ------------------------------------------------------------------

zsharp_parserParser::Type_I8Context::Type_I8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_I8Context::I8() {
  return getToken(zsharp_parserParser::I8, 0);
}


size_t zsharp_parserParser::Type_I8Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_I8;
}

void zsharp_parserParser::Type_I8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_I8(this);
}

void zsharp_parserParser::Type_I8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_I8(this);
}


antlrcpp::Any zsharp_parserParser::Type_I8Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_I8(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_I8Context* zsharp_parserParser::type_I8() {
  Type_I8Context *_localctx = _tracker.createInstance<Type_I8Context>(_ctx, getState());
  enterRule(_localctx, 98, zsharp_parserParser::RuleType_I8);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(571);
    match(zsharp_parserParser::I8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_I16Context ------------------------------------------------------------------

zsharp_parserParser::Type_I16Context::Type_I16Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_I16Context::I16() {
  return getToken(zsharp_parserParser::I16, 0);
}


size_t zsharp_parserParser::Type_I16Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_I16;
}

void zsharp_parserParser::Type_I16Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_I16(this);
}

void zsharp_parserParser::Type_I16Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_I16(this);
}


antlrcpp::Any zsharp_parserParser::Type_I16Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_I16(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_I16Context* zsharp_parserParser::type_I16() {
  Type_I16Context *_localctx = _tracker.createInstance<Type_I16Context>(_ctx, getState());
  enterRule(_localctx, 100, zsharp_parserParser::RuleType_I16);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(zsharp_parserParser::I16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_I24Context ------------------------------------------------------------------

zsharp_parserParser::Type_I24Context::Type_I24Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_I24Context::I24() {
  return getToken(zsharp_parserParser::I24, 0);
}


size_t zsharp_parserParser::Type_I24Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_I24;
}

void zsharp_parserParser::Type_I24Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_I24(this);
}

void zsharp_parserParser::Type_I24Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_I24(this);
}


antlrcpp::Any zsharp_parserParser::Type_I24Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_I24(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_I24Context* zsharp_parserParser::type_I24() {
  Type_I24Context *_localctx = _tracker.createInstance<Type_I24Context>(_ctx, getState());
  enterRule(_localctx, 102, zsharp_parserParser::RuleType_I24);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(zsharp_parserParser::I24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_I32Context ------------------------------------------------------------------

zsharp_parserParser::Type_I32Context::Type_I32Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_I32Context::I32() {
  return getToken(zsharp_parserParser::I32, 0);
}


size_t zsharp_parserParser::Type_I32Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_I32;
}

void zsharp_parserParser::Type_I32Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_I32(this);
}

void zsharp_parserParser::Type_I32Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_I32(this);
}


antlrcpp::Any zsharp_parserParser::Type_I32Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_I32(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_I32Context* zsharp_parserParser::type_I32() {
  Type_I32Context *_localctx = _tracker.createInstance<Type_I32Context>(_ctx, getState());
  enterRule(_localctx, 104, zsharp_parserParser::RuleType_I32);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    match(zsharp_parserParser::I32);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_F16Context ------------------------------------------------------------------

zsharp_parserParser::Type_F16Context::Type_F16Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_F16Context::F16() {
  return getToken(zsharp_parserParser::F16, 0);
}


size_t zsharp_parserParser::Type_F16Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_F16;
}

void zsharp_parserParser::Type_F16Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_F16(this);
}

void zsharp_parserParser::Type_F16Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_F16(this);
}


antlrcpp::Any zsharp_parserParser::Type_F16Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_F16(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_F16Context* zsharp_parserParser::type_F16() {
  Type_F16Context *_localctx = _tracker.createInstance<Type_F16Context>(_ctx, getState());
  enterRule(_localctx, 106, zsharp_parserParser::RuleType_F16);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    match(zsharp_parserParser::F16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_F32Context ------------------------------------------------------------------

zsharp_parserParser::Type_F32Context::Type_F32Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_F32Context::F32() {
  return getToken(zsharp_parserParser::F32, 0);
}


size_t zsharp_parserParser::Type_F32Context::getRuleIndex() const {
  return zsharp_parserParser::RuleType_F32;
}

void zsharp_parserParser::Type_F32Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_F32(this);
}

void zsharp_parserParser::Type_F32Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_F32(this);
}


antlrcpp::Any zsharp_parserParser::Type_F32Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_F32(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_F32Context* zsharp_parserParser::type_F32() {
  Type_F32Context *_localctx = _tracker.createInstance<Type_F32Context>(_ctx, getState());
  enterRule(_localctx, 108, zsharp_parserParser::RuleType_F32);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(zsharp_parserParser::F32);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_StrContext ------------------------------------------------------------------

zsharp_parserParser::Type_StrContext::Type_StrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_StrContext::STR() {
  return getToken(zsharp_parserParser::STR, 0);
}


size_t zsharp_parserParser::Type_StrContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_Str;
}

void zsharp_parserParser::Type_StrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_Str(this);
}

void zsharp_parserParser::Type_StrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_Str(this);
}


antlrcpp::Any zsharp_parserParser::Type_StrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_Str(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_StrContext* zsharp_parserParser::type_Str() {
  Type_StrContext *_localctx = _tracker.createInstance<Type_StrContext>(_ctx, getState());
  enterRule(_localctx, 110, zsharp_parserParser::RuleType_Str);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(583);
    match(zsharp_parserParser::STR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_BoolContext ------------------------------------------------------------------

zsharp_parserParser::Type_BoolContext::Type_BoolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_BoolContext::BOOL() {
  return getToken(zsharp_parserParser::BOOL, 0);
}


size_t zsharp_parserParser::Type_BoolContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_Bool;
}

void zsharp_parserParser::Type_BoolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_Bool(this);
}

void zsharp_parserParser::Type_BoolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_Bool(this);
}


antlrcpp::Any zsharp_parserParser::Type_BoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_Bool(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_BoolContext* zsharp_parserParser::type_Bool() {
  Type_BoolContext *_localctx = _tracker.createInstance<Type_BoolContext>(_ctx, getState());
  enterRule(_localctx, 112, zsharp_parserParser::RuleType_Bool);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    match(zsharp_parserParser::BOOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_BitContext ------------------------------------------------------------------

zsharp_parserParser::Type_BitContext::Type_BitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_BitContext::BIT() {
  return getToken(zsharp_parserParser::BIT, 0);
}


size_t zsharp_parserParser::Type_BitContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_Bit;
}

void zsharp_parserParser::Type_BitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_Bit(this);
}

void zsharp_parserParser::Type_BitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_Bit(this);
}


antlrcpp::Any zsharp_parserParser::Type_BitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_Bit(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_BitContext* zsharp_parserParser::type_Bit() {
  Type_BitContext *_localctx = _tracker.createInstance<Type_BitContext>(_ctx, getState());
  enterRule(_localctx, 114, zsharp_parserParser::RuleType_Bit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    match(zsharp_parserParser::BIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_typeContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_typeContext::Identifier_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_typeContext::IDENTIFIERupper() {
  return getToken(zsharp_parserParser::IDENTIFIERupper, 0);
}


size_t zsharp_parserParser::Identifier_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_type;
}

void zsharp_parserParser::Identifier_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_type(this);
}

void zsharp_parserParser::Identifier_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_type(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::identifier_type() {
  Identifier_typeContext *_localctx = _tracker.createInstance<Identifier_typeContext>(_ctx, getState());
  enterRule(_localctx, 116, zsharp_parserParser::RuleIdentifier_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(zsharp_parserParser::IDENTIFIERupper);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_varContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_varContext::Identifier_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_varContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_varContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_var;
}

void zsharp_parserParser::Identifier_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_var(this);
}

void zsharp_parserParser::Identifier_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_var(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_var(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_varContext* zsharp_parserParser::identifier_var() {
  Identifier_varContext *_localctx = _tracker.createInstance<Identifier_varContext>(_ctx, getState());
  enterRule(_localctx, 118, zsharp_parserParser::RuleIdentifier_var);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(591);
    match(zsharp_parserParser::IDENTIFIERlower);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_paramContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_paramContext::Identifier_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_paramContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_paramContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_param;
}

void zsharp_parserParser::Identifier_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_param(this);
}

void zsharp_parserParser::Identifier_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_param(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_param(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_paramContext* zsharp_parserParser::identifier_param() {
  Identifier_paramContext *_localctx = _tracker.createInstance<Identifier_paramContext>(_ctx, getState());
  enterRule(_localctx, 120, zsharp_parserParser::RuleIdentifier_param);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(zsharp_parserParser::IDENTIFIERlower);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_funcContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_funcContext::Identifier_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_funcContext::IDENTIFIERmixed() {
  return getToken(zsharp_parserParser::IDENTIFIERmixed, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_funcContext::IDENTIFIERupper() {
  return getToken(zsharp_parserParser::IDENTIFIERupper, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_funcContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_funcContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_func;
}

void zsharp_parserParser::Identifier_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_func(this);
}

void zsharp_parserParser::Identifier_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_func(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_func(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_funcContext* zsharp_parserParser::identifier_func() {
  Identifier_funcContext *_localctx = _tracker.createInstance<Identifier_funcContext>(_ctx, getState());
  enterRule(_localctx, 122, zsharp_parserParser::RuleIdentifier_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::IDENTIFIERupper)
      | (1ULL << zsharp_parserParser::IDENTIFIERlower)
      | (1ULL << zsharp_parserParser::IDENTIFIERmixed))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_fieldContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_fieldContext::Identifier_fieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_fieldContext::IDENTIFIERmixed() {
  return getToken(zsharp_parserParser::IDENTIFIERmixed, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_fieldContext::IDENTIFIERupper() {
  return getToken(zsharp_parserParser::IDENTIFIERupper, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_fieldContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_fieldContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_field;
}

void zsharp_parserParser::Identifier_fieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_field(this);
}

void zsharp_parserParser::Identifier_fieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_field(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_fieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_field(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_fieldContext* zsharp_parserParser::identifier_field() {
  Identifier_fieldContext *_localctx = _tracker.createInstance<Identifier_fieldContext>(_ctx, getState());
  enterRule(_localctx, 124, zsharp_parserParser::RuleIdentifier_field);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::IDENTIFIERupper)
      | (1ULL << zsharp_parserParser::IDENTIFIERlower)
      | (1ULL << zsharp_parserParser::IDENTIFIERmixed))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_enumoptionContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_enumoptionContext::Identifier_enumoptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_enumoptionContext::IDENTIFIERmixed() {
  return getToken(zsharp_parserParser::IDENTIFIERmixed, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_enumoptionContext::IDENTIFIERupper() {
  return getToken(zsharp_parserParser::IDENTIFIERupper, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_enumoptionContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_enumoptionContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_enumoption;
}

void zsharp_parserParser::Identifier_enumoptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_enumoption(this);
}

void zsharp_parserParser::Identifier_enumoptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_enumoption(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_enumoptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_enumoption(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_enumoptionContext* zsharp_parserParser::identifier_enumoption() {
  Identifier_enumoptionContext *_localctx = _tracker.createInstance<Identifier_enumoptionContext>(_ctx, getState());
  enterRule(_localctx, 126, zsharp_parserParser::RuleIdentifier_enumoption);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::IDENTIFIERupper)
      | (1ULL << zsharp_parserParser::IDENTIFIERlower)
      | (1ULL << zsharp_parserParser::IDENTIFIERmixed))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_moduleContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_moduleContext::Identifier_moduleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_moduleContext::IDENTIFIERmixed() {
  return getToken(zsharp_parserParser::IDENTIFIERmixed, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_moduleContext::IDENTIFIERupper() {
  return getToken(zsharp_parserParser::IDENTIFIERupper, 0);
}

tree::TerminalNode* zsharp_parserParser::Identifier_moduleContext::IDENTIFIERlower() {
  return getToken(zsharp_parserParser::IDENTIFIERlower, 0);
}


size_t zsharp_parserParser::Identifier_moduleContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_module;
}

void zsharp_parserParser::Identifier_moduleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_module(this);
}

void zsharp_parserParser::Identifier_moduleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_module(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_moduleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_module(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_moduleContext* zsharp_parserParser::identifier_module() {
  Identifier_moduleContext *_localctx = _tracker.createInstance<Identifier_moduleContext>(_ctx, getState());
  enterRule(_localctx, 128, zsharp_parserParser::RuleIdentifier_module);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::IDENTIFIERupper)
      | (1ULL << zsharp_parserParser::IDENTIFIERlower)
      | (1ULL << zsharp_parserParser::IDENTIFIERmixed))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_unusedContext ------------------------------------------------------------------

zsharp_parserParser::Identifier_unusedContext::Identifier_unusedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Identifier_unusedContext::UNUSED() {
  return getToken(zsharp_parserParser::UNUSED, 0);
}


size_t zsharp_parserParser::Identifier_unusedContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIdentifier_unused;
}

void zsharp_parserParser::Identifier_unusedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_unused(this);
}

void zsharp_parserParser::Identifier_unusedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_unused(this);
}


antlrcpp::Any zsharp_parserParser::Identifier_unusedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIdentifier_unused(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Identifier_unusedContext* zsharp_parserParser::identifier_unused() {
  Identifier_unusedContext *_localctx = _tracker.createInstance<Identifier_unusedContext>(_ctx, getState());
  enterRule(_localctx, 130, zsharp_parserParser::RuleIdentifier_unused);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(603);
    match(zsharp_parserParser::UNUSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_moduleContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_moduleContext::Keyword_moduleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_moduleContext::MODULE() {
  return getToken(zsharp_parserParser::MODULE, 0);
}


size_t zsharp_parserParser::Keyword_moduleContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_module;
}

void zsharp_parserParser::Keyword_moduleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_module(this);
}

void zsharp_parserParser::Keyword_moduleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_module(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_moduleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_module(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_moduleContext* zsharp_parserParser::keyword_module() {
  Keyword_moduleContext *_localctx = _tracker.createInstance<Keyword_moduleContext>(_ctx, getState());
  enterRule(_localctx, 132, zsharp_parserParser::RuleKeyword_module);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    match(zsharp_parserParser::MODULE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_importContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_importContext::Keyword_importContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_importContext::IMPORT() {
  return getToken(zsharp_parserParser::IMPORT, 0);
}


size_t zsharp_parserParser::Keyword_importContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_import;
}

void zsharp_parserParser::Keyword_importContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_import(this);
}

void zsharp_parserParser::Keyword_importContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_import(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_importContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_import(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_importContext* zsharp_parserParser::keyword_import() {
  Keyword_importContext *_localctx = _tracker.createInstance<Keyword_importContext>(_ctx, getState());
  enterRule(_localctx, 134, zsharp_parserParser::RuleKeyword_import);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    match(zsharp_parserParser::IMPORT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_exportContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_exportContext::Keyword_exportContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_exportContext::EXPORT() {
  return getToken(zsharp_parserParser::EXPORT, 0);
}


size_t zsharp_parserParser::Keyword_exportContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_export;
}

void zsharp_parserParser::Keyword_exportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_export(this);
}

void zsharp_parserParser::Keyword_exportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_export(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_exportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_export(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_exportContext* zsharp_parserParser::keyword_export() {
  Keyword_exportContext *_localctx = _tracker.createInstance<Keyword_exportContext>(_ctx, getState());
  enterRule(_localctx, 136, zsharp_parserParser::RuleKeyword_export);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    match(zsharp_parserParser::EXPORT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_loopContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_loopContext::Keyword_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_loopContext::LOOP() {
  return getToken(zsharp_parserParser::LOOP, 0);
}


size_t zsharp_parserParser::Keyword_loopContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_loop;
}

void zsharp_parserParser::Keyword_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_loop(this);
}

void zsharp_parserParser::Keyword_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_loop(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_loop(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_loopContext* zsharp_parserParser::keyword_loop() {
  Keyword_loopContext *_localctx = _tracker.createInstance<Keyword_loopContext>(_ctx, getState());
  enterRule(_localctx, 138, zsharp_parserParser::RuleKeyword_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    match(zsharp_parserParser::LOOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_breakContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_breakContext::Keyword_breakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_breakContext::BREAK() {
  return getToken(zsharp_parserParser::BREAK, 0);
}


size_t zsharp_parserParser::Keyword_breakContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_break;
}

void zsharp_parserParser::Keyword_breakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_break(this);
}

void zsharp_parserParser::Keyword_breakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_break(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_breakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_break(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_breakContext* zsharp_parserParser::keyword_break() {
  Keyword_breakContext *_localctx = _tracker.createInstance<Keyword_breakContext>(_ctx, getState());
  enterRule(_localctx, 140, zsharp_parserParser::RuleKeyword_break);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
    match(zsharp_parserParser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_continueContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_continueContext::Keyword_continueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_continueContext::CONTINUE() {
  return getToken(zsharp_parserParser::CONTINUE, 0);
}


size_t zsharp_parserParser::Keyword_continueContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_continue;
}

void zsharp_parserParser::Keyword_continueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_continue(this);
}

void zsharp_parserParser::Keyword_continueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_continue(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_continueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_continue(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_continueContext* zsharp_parserParser::keyword_continue() {
  Keyword_continueContext *_localctx = _tracker.createInstance<Keyword_continueContext>(_ctx, getState());
  enterRule(_localctx, 142, zsharp_parserParser::RuleKeyword_continue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    match(zsharp_parserParser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_ifContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_ifContext::Keyword_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_ifContext::IF() {
  return getToken(zsharp_parserParser::IF, 0);
}


size_t zsharp_parserParser::Keyword_ifContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_if;
}

void zsharp_parserParser::Keyword_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_if(this);
}

void zsharp_parserParser::Keyword_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_if(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_if(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_ifContext* zsharp_parserParser::keyword_if() {
  Keyword_ifContext *_localctx = _tracker.createInstance<Keyword_ifContext>(_ctx, getState());
  enterRule(_localctx, 144, zsharp_parserParser::RuleKeyword_if);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    match(zsharp_parserParser::IF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_elseContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_elseContext::Keyword_elseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_elseContext::ELSE() {
  return getToken(zsharp_parserParser::ELSE, 0);
}


size_t zsharp_parserParser::Keyword_elseContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_else;
}

void zsharp_parserParser::Keyword_elseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_else(this);
}

void zsharp_parserParser::Keyword_elseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_else(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_else(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_elseContext* zsharp_parserParser::keyword_else() {
  Keyword_elseContext *_localctx = _tracker.createInstance<Keyword_elseContext>(_ctx, getState());
  enterRule(_localctx, 146, zsharp_parserParser::RuleKeyword_else);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    match(zsharp_parserParser::ELSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_returnContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_returnContext::Keyword_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_returnContext::RETURN() {
  return getToken(zsharp_parserParser::RETURN, 0);
}


size_t zsharp_parserParser::Keyword_returnContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_return;
}

void zsharp_parserParser::Keyword_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_return(this);
}

void zsharp_parserParser::Keyword_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_return(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_return(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_returnContext* zsharp_parserParser::keyword_return() {
  Keyword_returnContext *_localctx = _tracker.createInstance<Keyword_returnContext>(_ctx, getState());
  enterRule(_localctx, 148, zsharp_parserParser::RuleKeyword_return);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    match(zsharp_parserParser::RETURN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_inContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_inContext::Keyword_inContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_inContext::IN() {
  return getToken(zsharp_parserParser::IN, 0);
}


size_t zsharp_parserParser::Keyword_inContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_in;
}

void zsharp_parserParser::Keyword_inContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_in(this);
}

void zsharp_parserParser::Keyword_inContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_in(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_inContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_in(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_inContext* zsharp_parserParser::keyword_in() {
  Keyword_inContext *_localctx = _tracker.createInstance<Keyword_inContext>(_ctx, getState());
  enterRule(_localctx, 150, zsharp_parserParser::RuleKeyword_in);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    match(zsharp_parserParser::IN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Keyword_selfContext ------------------------------------------------------------------

zsharp_parserParser::Keyword_selfContext::Keyword_selfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Keyword_selfContext::SELF() {
  return getToken(zsharp_parserParser::SELF, 0);
}


size_t zsharp_parserParser::Keyword_selfContext::getRuleIndex() const {
  return zsharp_parserParser::RuleKeyword_self;
}

void zsharp_parserParser::Keyword_selfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword_self(this);
}

void zsharp_parserParser::Keyword_selfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword_self(this);
}


antlrcpp::Any zsharp_parserParser::Keyword_selfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitKeyword_self(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Keyword_selfContext* zsharp_parserParser::keyword_self() {
  Keyword_selfContext *_localctx = _tracker.createInstance<Keyword_selfContext>(_ctx, getState());
  enterRule(_localctx, 152, zsharp_parserParser::RuleKeyword_self);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    match(zsharp_parserParser::SELF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_boolContext ------------------------------------------------------------------

zsharp_parserParser::Literal_boolContext::Literal_boolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Literal_boolContext::TRUE() {
  return getToken(zsharp_parserParser::TRUE, 0);
}

tree::TerminalNode* zsharp_parserParser::Literal_boolContext::FALSE() {
  return getToken(zsharp_parserParser::FALSE, 0);
}


size_t zsharp_parserParser::Literal_boolContext::getRuleIndex() const {
  return zsharp_parserParser::RuleLiteral_bool;
}

void zsharp_parserParser::Literal_boolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_bool(this);
}

void zsharp_parserParser::Literal_boolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_bool(this);
}


antlrcpp::Any zsharp_parserParser::Literal_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitLiteral_bool(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Literal_boolContext* zsharp_parserParser::literal_bool() {
  Literal_boolContext *_localctx = _tracker.createInstance<Literal_boolContext>(_ctx, getState());
  enterRule(_localctx, 154, zsharp_parserParser::RuleLiteral_bool);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(627);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::TRUE

    || _la == zsharp_parserParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

zsharp_parserParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::NumberContext* zsharp_parserParser::LiteralContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}

zsharp_parserParser::StringContext* zsharp_parserParser::LiteralContext::string() {
  return getRuleContext<zsharp_parserParser::StringContext>(0);
}


size_t zsharp_parserParser::LiteralContext::getRuleIndex() const {
  return zsharp_parserParser::RuleLiteral;
}

void zsharp_parserParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void zsharp_parserParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any zsharp_parserParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::LiteralContext* zsharp_parserParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 156, zsharp_parserParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(631);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(629);
        number();
        break;
      }

      case zsharp_parserParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(630);
        string();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

zsharp_parserParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Number_unsignedContext* zsharp_parserParser::NumberContext::number_unsigned() {
  return getRuleContext<zsharp_parserParser::Number_unsignedContext>(0);
}


size_t zsharp_parserParser::NumberContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber;
}

void zsharp_parserParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void zsharp_parserParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any zsharp_parserParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::NumberContext* zsharp_parserParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 158, zsharp_parserParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(633);
    number_unsigned();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_unsignedContext ------------------------------------------------------------------

zsharp_parserParser::Number_unsignedContext::Number_unsignedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Number_binContext* zsharp_parserParser::Number_unsignedContext::number_bin() {
  return getRuleContext<zsharp_parserParser::Number_binContext>(0);
}

zsharp_parserParser::Number_octContext* zsharp_parserParser::Number_unsignedContext::number_oct() {
  return getRuleContext<zsharp_parserParser::Number_octContext>(0);
}

zsharp_parserParser::Number_decContext* zsharp_parserParser::Number_unsignedContext::number_dec() {
  return getRuleContext<zsharp_parserParser::Number_decContext>(0);
}

zsharp_parserParser::Number_hexContext* zsharp_parserParser::Number_unsignedContext::number_hex() {
  return getRuleContext<zsharp_parserParser::Number_hexContext>(0);
}

zsharp_parserParser::Number_charContext* zsharp_parserParser::Number_unsignedContext::number_char() {
  return getRuleContext<zsharp_parserParser::Number_charContext>(0);
}


size_t zsharp_parserParser::Number_unsignedContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_unsigned;
}

void zsharp_parserParser::Number_unsignedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_unsigned(this);
}

void zsharp_parserParser::Number_unsignedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_unsigned(this);
}


antlrcpp::Any zsharp_parserParser::Number_unsignedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_unsigned(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_unsignedContext* zsharp_parserParser::number_unsigned() {
  Number_unsignedContext *_localctx = _tracker.createInstance<Number_unsignedContext>(_ctx, getState());
  enterRule(_localctx, 160, zsharp_parserParser::RuleNumber_unsigned);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(640);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin: {
        enterOuterAlt(_localctx, 1);
        setState(635);
        number_bin();
        break;
      }

      case zsharp_parserParser::NUMBERoct: {
        enterOuterAlt(_localctx, 2);
        setState(636);
        number_oct();
        break;
      }

      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix: {
        enterOuterAlt(_localctx, 3);
        setState(637);
        number_dec();
        break;
      }

      case zsharp_parserParser::NUMBERhex: {
        enterOuterAlt(_localctx, 4);
        setState(638);
        number_hex();
        break;
      }

      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 5);
        setState(639);
        number_char();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_binContext ------------------------------------------------------------------

zsharp_parserParser::Number_binContext::Number_binContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Number_binContext::NUMBERbin() {
  return getToken(zsharp_parserParser::NUMBERbin, 0);
}


size_t zsharp_parserParser::Number_binContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_bin;
}

void zsharp_parserParser::Number_binContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_bin(this);
}

void zsharp_parserParser::Number_binContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_bin(this);
}


antlrcpp::Any zsharp_parserParser::Number_binContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_bin(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_binContext* zsharp_parserParser::number_bin() {
  Number_binContext *_localctx = _tracker.createInstance<Number_binContext>(_ctx, getState());
  enterRule(_localctx, 162, zsharp_parserParser::RuleNumber_bin);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    match(zsharp_parserParser::NUMBERbin);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_octContext ------------------------------------------------------------------

zsharp_parserParser::Number_octContext::Number_octContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Number_octContext::NUMBERoct() {
  return getToken(zsharp_parserParser::NUMBERoct, 0);
}


size_t zsharp_parserParser::Number_octContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_oct;
}

void zsharp_parserParser::Number_octContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_oct(this);
}

void zsharp_parserParser::Number_octContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_oct(this);
}


antlrcpp::Any zsharp_parserParser::Number_octContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_oct(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_octContext* zsharp_parserParser::number_oct() {
  Number_octContext *_localctx = _tracker.createInstance<Number_octContext>(_ctx, getState());
  enterRule(_localctx, 164, zsharp_parserParser::RuleNumber_oct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    match(zsharp_parserParser::NUMBERoct);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_decContext ------------------------------------------------------------------

zsharp_parserParser::Number_decContext::Number_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Number_decContext::NUMBERdec() {
  return getToken(zsharp_parserParser::NUMBERdec, 0);
}

tree::TerminalNode* zsharp_parserParser::Number_decContext::NUMBERdec_prefix() {
  return getToken(zsharp_parserParser::NUMBERdec_prefix, 0);
}


size_t zsharp_parserParser::Number_decContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_dec;
}

void zsharp_parserParser::Number_decContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_dec(this);
}

void zsharp_parserParser::Number_decContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_dec(this);
}


antlrcpp::Any zsharp_parserParser::Number_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_dec(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_decContext* zsharp_parserParser::number_dec() {
  Number_decContext *_localctx = _tracker.createInstance<Number_decContext>(_ctx, getState());
  enterRule(_localctx, 166, zsharp_parserParser::RuleNumber_dec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(646);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::NUMBERdec

    || _la == zsharp_parserParser::NUMBERdec_prefix)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_hexContext ------------------------------------------------------------------

zsharp_parserParser::Number_hexContext::Number_hexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Number_hexContext::NUMBERhex() {
  return getToken(zsharp_parserParser::NUMBERhex, 0);
}


size_t zsharp_parserParser::Number_hexContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_hex;
}

void zsharp_parserParser::Number_hexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_hex(this);
}

void zsharp_parserParser::Number_hexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_hex(this);
}


antlrcpp::Any zsharp_parserParser::Number_hexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_hex(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_hexContext* zsharp_parserParser::number_hex() {
  Number_hexContext *_localctx = _tracker.createInstance<Number_hexContext>(_ctx, getState());
  enterRule(_localctx, 168, zsharp_parserParser::RuleNumber_hex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(648);
    match(zsharp_parserParser::NUMBERhex);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_charContext ------------------------------------------------------------------

zsharp_parserParser::Number_charContext::Number_charContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::CharacterContext* zsharp_parserParser::Number_charContext::character() {
  return getRuleContext<zsharp_parserParser::CharacterContext>(0);
}


size_t zsharp_parserParser::Number_charContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNumber_char;
}

void zsharp_parserParser::Number_charContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_char(this);
}

void zsharp_parserParser::Number_charContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_char(this);
}


antlrcpp::Any zsharp_parserParser::Number_charContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNumber_char(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Number_charContext* zsharp_parserParser::number_char() {
  Number_charContext *_localctx = _tracker.createInstance<Number_charContext>(_ctx, getState());
  enterRule(_localctx, 170, zsharp_parserParser::RuleNumber_char);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(650);
    character();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_arithmeticContext ------------------------------------------------------------------

zsharp_parserParser::Operator_arithmeticContext::Operator_arithmeticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_plusContext* zsharp_parserParser::Operator_arithmeticContext::op_plus() {
  return getRuleContext<zsharp_parserParser::Op_plusContext>(0);
}

zsharp_parserParser::Op_minus_negContext* zsharp_parserParser::Operator_arithmeticContext::op_minus_neg() {
  return getRuleContext<zsharp_parserParser::Op_minus_negContext>(0);
}

zsharp_parserParser::Op_divContext* zsharp_parserParser::Operator_arithmeticContext::op_div() {
  return getRuleContext<zsharp_parserParser::Op_divContext>(0);
}

zsharp_parserParser::Op_modContext* zsharp_parserParser::Operator_arithmeticContext::op_mod() {
  return getRuleContext<zsharp_parserParser::Op_modContext>(0);
}

zsharp_parserParser::Op_multContext* zsharp_parserParser::Operator_arithmeticContext::op_mult() {
  return getRuleContext<zsharp_parserParser::Op_multContext>(0);
}

zsharp_parserParser::Op_powContext* zsharp_parserParser::Operator_arithmeticContext::op_pow() {
  return getRuleContext<zsharp_parserParser::Op_powContext>(0);
}


size_t zsharp_parserParser::Operator_arithmeticContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_arithmetic;
}

void zsharp_parserParser::Operator_arithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_arithmetic(this);
}

void zsharp_parserParser::Operator_arithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_arithmetic(this);
}


antlrcpp::Any zsharp_parserParser::Operator_arithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_arithmetic(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_arithmeticContext* zsharp_parserParser::operator_arithmetic() {
  Operator_arithmeticContext *_localctx = _tracker.createInstance<Operator_arithmeticContext>(_ctx, getState());
  enterRule(_localctx, 172, zsharp_parserParser::RuleOperator_arithmetic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(658);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(652);
        op_plus();
        break;
      }

      case zsharp_parserParser::MINUS_NEG: {
        enterOuterAlt(_localctx, 2);
        setState(653);
        op_minus_neg();
        break;
      }

      case zsharp_parserParser::DIV: {
        enterOuterAlt(_localctx, 3);
        setState(654);
        op_div();
        break;
      }

      case zsharp_parserParser::MOD: {
        enterOuterAlt(_localctx, 4);
        setState(655);
        op_mod();
        break;
      }

      case zsharp_parserParser::MULT: {
        enterOuterAlt(_localctx, 5);
        setState(656);
        op_mult();
        break;
      }

      case zsharp_parserParser::POW: {
        enterOuterAlt(_localctx, 6);
        setState(657);
        op_pow();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_arithmetic_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_arithmetic_unaryContext::Operator_arithmetic_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_minus_negContext* zsharp_parserParser::Operator_arithmetic_unaryContext::op_minus_neg() {
  return getRuleContext<zsharp_parserParser::Op_minus_negContext>(0);
}


size_t zsharp_parserParser::Operator_arithmetic_unaryContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_arithmetic_unary;
}

void zsharp_parserParser::Operator_arithmetic_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_arithmetic_unary(this);
}

void zsharp_parserParser::Operator_arithmetic_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_arithmetic_unary(this);
}


antlrcpp::Any zsharp_parserParser::Operator_arithmetic_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_arithmetic_unary(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_arithmetic_unaryContext* zsharp_parserParser::operator_arithmetic_unary() {
  Operator_arithmetic_unaryContext *_localctx = _tracker.createInstance<Operator_arithmetic_unaryContext>(_ctx, getState());
  enterRule(_localctx, 174, zsharp_parserParser::RuleOperator_arithmetic_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(660);
    op_minus_neg();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_logicContext ------------------------------------------------------------------

zsharp_parserParser::Operator_logicContext::Operator_logicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_andContext* zsharp_parserParser::Operator_logicContext::op_and() {
  return getRuleContext<zsharp_parserParser::Op_andContext>(0);
}

zsharp_parserParser::Op_orContext* zsharp_parserParser::Operator_logicContext::op_or() {
  return getRuleContext<zsharp_parserParser::Op_orContext>(0);
}


size_t zsharp_parserParser::Operator_logicContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_logic;
}

void zsharp_parserParser::Operator_logicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_logic(this);
}

void zsharp_parserParser::Operator_logicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_logic(this);
}


antlrcpp::Any zsharp_parserParser::Operator_logicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_logic(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_logicContext* zsharp_parserParser::operator_logic() {
  Operator_logicContext *_localctx = _tracker.createInstance<Operator_logicContext>(_ctx, getState());
  enterRule(_localctx, 176, zsharp_parserParser::RuleOperator_logic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(664);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::AND: {
        enterOuterAlt(_localctx, 1);
        setState(662);
        op_and();
        break;
      }

      case zsharp_parserParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(663);
        op_or();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_logic_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_logic_unaryContext::Operator_logic_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_notContext* zsharp_parserParser::Operator_logic_unaryContext::op_not() {
  return getRuleContext<zsharp_parserParser::Op_notContext>(0);
}


size_t zsharp_parserParser::Operator_logic_unaryContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_logic_unary;
}

void zsharp_parserParser::Operator_logic_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_logic_unary(this);
}

void zsharp_parserParser::Operator_logic_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_logic_unary(this);
}


antlrcpp::Any zsharp_parserParser::Operator_logic_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_logic_unary(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_logic_unaryContext* zsharp_parserParser::operator_logic_unary() {
  Operator_logic_unaryContext *_localctx = _tracker.createInstance<Operator_logic_unaryContext>(_ctx, getState());
  enterRule(_localctx, 178, zsharp_parserParser::RuleOperator_logic_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    op_not();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_comparisonContext ------------------------------------------------------------------

zsharp_parserParser::Operator_comparisonContext::Operator_comparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_eq_assignContext* zsharp_parserParser::Operator_comparisonContext::op_eq_assign() {
  return getRuleContext<zsharp_parserParser::Op_eq_assignContext>(0);
}

zsharp_parserParser::Op_neqContext* zsharp_parserParser::Operator_comparisonContext::op_neq() {
  return getRuleContext<zsharp_parserParser::Op_neqContext>(0);
}

zsharp_parserParser::Op_greatContext* zsharp_parserParser::Operator_comparisonContext::op_great() {
  return getRuleContext<zsharp_parserParser::Op_greatContext>(0);
}

zsharp_parserParser::Op_smallContext* zsharp_parserParser::Operator_comparisonContext::op_small() {
  return getRuleContext<zsharp_parserParser::Op_smallContext>(0);
}

zsharp_parserParser::Op_greqContext* zsharp_parserParser::Operator_comparisonContext::op_greq() {
  return getRuleContext<zsharp_parserParser::Op_greqContext>(0);
}

zsharp_parserParser::Op_smeqContext* zsharp_parserParser::Operator_comparisonContext::op_smeq() {
  return getRuleContext<zsharp_parserParser::Op_smeqContext>(0);
}


size_t zsharp_parserParser::Operator_comparisonContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_comparison;
}

void zsharp_parserParser::Operator_comparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_comparison(this);
}

void zsharp_parserParser::Operator_comparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_comparison(this);
}


antlrcpp::Any zsharp_parserParser::Operator_comparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_comparison(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_comparisonContext* zsharp_parserParser::operator_comparison() {
  Operator_comparisonContext *_localctx = _tracker.createInstance<Operator_comparisonContext>(_ctx, getState());
  enterRule(_localctx, 180, zsharp_parserParser::RuleOperator_comparison);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(674);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::EQ_ASSIGN: {
        enterOuterAlt(_localctx, 1);
        setState(668);
        op_eq_assign();
        break;
      }

      case zsharp_parserParser::NEQ: {
        enterOuterAlt(_localctx, 2);
        setState(669);
        op_neq();
        break;
      }

      case zsharp_parserParser::GREAT_ANGLEclose: {
        enterOuterAlt(_localctx, 3);
        setState(670);
        op_great();
        break;
      }

      case zsharp_parserParser::SMALL_ANGLEopen: {
        enterOuterAlt(_localctx, 4);
        setState(671);
        op_small();
        break;
      }

      case zsharp_parserParser::GREQ: {
        enterOuterAlt(_localctx, 5);
        setState(672);
        op_greq();
        break;
      }

      case zsharp_parserParser::SMEQ: {
        enterOuterAlt(_localctx, 6);
        setState(673);
        op_smeq();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_bitsContext ------------------------------------------------------------------

zsharp_parserParser::Operator_bitsContext::Operator_bitsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_bit_andContext* zsharp_parserParser::Operator_bitsContext::op_bit_and() {
  return getRuleContext<zsharp_parserParser::Op_bit_andContext>(0);
}

zsharp_parserParser::Op_bit_orContext* zsharp_parserParser::Operator_bitsContext::op_bit_or() {
  return getRuleContext<zsharp_parserParser::Op_bit_orContext>(0);
}

zsharp_parserParser::Op_bit_xorContext* zsharp_parserParser::Operator_bitsContext::op_bit_xor() {
  return getRuleContext<zsharp_parserParser::Op_bit_xorContext>(0);
}

zsharp_parserParser::Op_bit_shlContext* zsharp_parserParser::Operator_bitsContext::op_bit_shl() {
  return getRuleContext<zsharp_parserParser::Op_bit_shlContext>(0);
}

zsharp_parserParser::Op_bit_shrContext* zsharp_parserParser::Operator_bitsContext::op_bit_shr() {
  return getRuleContext<zsharp_parserParser::Op_bit_shrContext>(0);
}

zsharp_parserParser::Op_bit_rollContext* zsharp_parserParser::Operator_bitsContext::op_bit_roll() {
  return getRuleContext<zsharp_parserParser::Op_bit_rollContext>(0);
}

zsharp_parserParser::Op_bit_rolrContext* zsharp_parserParser::Operator_bitsContext::op_bit_rolr() {
  return getRuleContext<zsharp_parserParser::Op_bit_rolrContext>(0);
}


size_t zsharp_parserParser::Operator_bitsContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_bits;
}

void zsharp_parserParser::Operator_bitsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_bits(this);
}

void zsharp_parserParser::Operator_bitsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_bits(this);
}


antlrcpp::Any zsharp_parserParser::Operator_bitsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_bits(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_bitsContext* zsharp_parserParser::operator_bits() {
  Operator_bitsContext *_localctx = _tracker.createInstance<Operator_bitsContext>(_ctx, getState());
  enterRule(_localctx, 182, zsharp_parserParser::RuleOperator_bits);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(683);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::BIT_AND: {
        enterOuterAlt(_localctx, 1);
        setState(676);
        op_bit_and();
        break;
      }

      case zsharp_parserParser::BIT_OR: {
        enterOuterAlt(_localctx, 2);
        setState(677);
        op_bit_or();
        break;
      }

      case zsharp_parserParser::BIT_XOR: {
        enterOuterAlt(_localctx, 3);
        setState(678);
        op_bit_xor();
        break;
      }

      case zsharp_parserParser::BIT_SHL: {
        enterOuterAlt(_localctx, 4);
        setState(679);
        op_bit_shl();
        break;
      }

      case zsharp_parserParser::BIT_SHR: {
        enterOuterAlt(_localctx, 5);
        setState(680);
        op_bit_shr();
        break;
      }

      case zsharp_parserParser::BIT_ROLL: {
        enterOuterAlt(_localctx, 6);
        setState(681);
        op_bit_roll();
        break;
      }

      case zsharp_parserParser::BIT_ROLR: {
        enterOuterAlt(_localctx, 7);
        setState(682);
        op_bit_rolr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_bits_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_bits_unaryContext::Operator_bits_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_bit_notContext* zsharp_parserParser::Operator_bits_unaryContext::op_bit_not() {
  return getRuleContext<zsharp_parserParser::Op_bit_notContext>(0);
}


size_t zsharp_parserParser::Operator_bits_unaryContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_bits_unary;
}

void zsharp_parserParser::Operator_bits_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_bits_unary(this);
}

void zsharp_parserParser::Operator_bits_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_bits_unary(this);
}


antlrcpp::Any zsharp_parserParser::Operator_bits_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_bits_unary(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_bits_unaryContext* zsharp_parserParser::operator_bits_unary() {
  Operator_bits_unaryContext *_localctx = _tracker.createInstance<Operator_bits_unaryContext>(_ctx, getState());
  enterRule(_localctx, 184, zsharp_parserParser::RuleOperator_bits_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(685);
    op_bit_not();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_assignmentContext ------------------------------------------------------------------

zsharp_parserParser::Operator_assignmentContext::Operator_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Op_eq_assignContext* zsharp_parserParser::Operator_assignmentContext::op_eq_assign() {
  return getRuleContext<zsharp_parserParser::Op_eq_assignContext>(0);
}


size_t zsharp_parserParser::Operator_assignmentContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOperator_assignment;
}

void zsharp_parserParser::Operator_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_assignment(this);
}

void zsharp_parserParser::Operator_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_assignment(this);
}


antlrcpp::Any zsharp_parserParser::Operator_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOperator_assignment(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Operator_assignmentContext* zsharp_parserParser::operator_assignment() {
  Operator_assignmentContext *_localctx = _tracker.createInstance<Operator_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 186, zsharp_parserParser::RuleOperator_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(687);
    op_eq_assign();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_plusContext ------------------------------------------------------------------

zsharp_parserParser::Op_plusContext::Op_plusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_plusContext::PLUS() {
  return getToken(zsharp_parserParser::PLUS, 0);
}


size_t zsharp_parserParser::Op_plusContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_plus;
}

void zsharp_parserParser::Op_plusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_plus(this);
}

void zsharp_parserParser::Op_plusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_plus(this);
}


antlrcpp::Any zsharp_parserParser::Op_plusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_plus(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_plusContext* zsharp_parserParser::op_plus() {
  Op_plusContext *_localctx = _tracker.createInstance<Op_plusContext>(_ctx, getState());
  enterRule(_localctx, 188, zsharp_parserParser::RuleOp_plus);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(689);
    match(zsharp_parserParser::PLUS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_minus_negContext ------------------------------------------------------------------

zsharp_parserParser::Op_minus_negContext::Op_minus_negContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_minus_negContext::MINUS_NEG() {
  return getToken(zsharp_parserParser::MINUS_NEG, 0);
}


size_t zsharp_parserParser::Op_minus_negContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_minus_neg;
}

void zsharp_parserParser::Op_minus_negContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_minus_neg(this);
}

void zsharp_parserParser::Op_minus_negContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_minus_neg(this);
}


antlrcpp::Any zsharp_parserParser::Op_minus_negContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_minus_neg(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_minus_negContext* zsharp_parserParser::op_minus_neg() {
  Op_minus_negContext *_localctx = _tracker.createInstance<Op_minus_negContext>(_ctx, getState());
  enterRule(_localctx, 190, zsharp_parserParser::RuleOp_minus_neg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(691);
    match(zsharp_parserParser::MINUS_NEG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_multContext ------------------------------------------------------------------

zsharp_parserParser::Op_multContext::Op_multContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_multContext::MULT() {
  return getToken(zsharp_parserParser::MULT, 0);
}


size_t zsharp_parserParser::Op_multContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_mult;
}

void zsharp_parserParser::Op_multContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_mult(this);
}

void zsharp_parserParser::Op_multContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_mult(this);
}


antlrcpp::Any zsharp_parserParser::Op_multContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_mult(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_multContext* zsharp_parserParser::op_mult() {
  Op_multContext *_localctx = _tracker.createInstance<Op_multContext>(_ctx, getState());
  enterRule(_localctx, 192, zsharp_parserParser::RuleOp_mult);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(693);
    match(zsharp_parserParser::MULT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_divContext ------------------------------------------------------------------

zsharp_parserParser::Op_divContext::Op_divContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_divContext::DIV() {
  return getToken(zsharp_parserParser::DIV, 0);
}


size_t zsharp_parserParser::Op_divContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_div;
}

void zsharp_parserParser::Op_divContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_div(this);
}

void zsharp_parserParser::Op_divContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_div(this);
}


antlrcpp::Any zsharp_parserParser::Op_divContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_div(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_divContext* zsharp_parserParser::op_div() {
  Op_divContext *_localctx = _tracker.createInstance<Op_divContext>(_ctx, getState());
  enterRule(_localctx, 194, zsharp_parserParser::RuleOp_div);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    match(zsharp_parserParser::DIV);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_modContext ------------------------------------------------------------------

zsharp_parserParser::Op_modContext::Op_modContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_modContext::MOD() {
  return getToken(zsharp_parserParser::MOD, 0);
}


size_t zsharp_parserParser::Op_modContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_mod;
}

void zsharp_parserParser::Op_modContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_mod(this);
}

void zsharp_parserParser::Op_modContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_mod(this);
}


antlrcpp::Any zsharp_parserParser::Op_modContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_mod(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_modContext* zsharp_parserParser::op_mod() {
  Op_modContext *_localctx = _tracker.createInstance<Op_modContext>(_ctx, getState());
  enterRule(_localctx, 196, zsharp_parserParser::RuleOp_mod);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(697);
    match(zsharp_parserParser::MOD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_powContext ------------------------------------------------------------------

zsharp_parserParser::Op_powContext::Op_powContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_powContext::POW() {
  return getToken(zsharp_parserParser::POW, 0);
}


size_t zsharp_parserParser::Op_powContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_pow;
}

void zsharp_parserParser::Op_powContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_pow(this);
}

void zsharp_parserParser::Op_powContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_pow(this);
}


antlrcpp::Any zsharp_parserParser::Op_powContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_pow(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_powContext* zsharp_parserParser::op_pow() {
  Op_powContext *_localctx = _tracker.createInstance<Op_powContext>(_ctx, getState());
  enterRule(_localctx, 198, zsharp_parserParser::RuleOp_pow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(699);
    match(zsharp_parserParser::POW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_eq_assignContext ------------------------------------------------------------------

zsharp_parserParser::Op_eq_assignContext::Op_eq_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_eq_assignContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}


size_t zsharp_parserParser::Op_eq_assignContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_eq_assign;
}

void zsharp_parserParser::Op_eq_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_eq_assign(this);
}

void zsharp_parserParser::Op_eq_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_eq_assign(this);
}


antlrcpp::Any zsharp_parserParser::Op_eq_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_eq_assign(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_eq_assignContext* zsharp_parserParser::op_eq_assign() {
  Op_eq_assignContext *_localctx = _tracker.createInstance<Op_eq_assignContext>(_ctx, getState());
  enterRule(_localctx, 200, zsharp_parserParser::RuleOp_eq_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(701);
    match(zsharp_parserParser::EQ_ASSIGN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_neqContext ------------------------------------------------------------------

zsharp_parserParser::Op_neqContext::Op_neqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_neqContext::NEQ() {
  return getToken(zsharp_parserParser::NEQ, 0);
}


size_t zsharp_parserParser::Op_neqContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_neq;
}

void zsharp_parserParser::Op_neqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_neq(this);
}

void zsharp_parserParser::Op_neqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_neq(this);
}


antlrcpp::Any zsharp_parserParser::Op_neqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_neq(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_neqContext* zsharp_parserParser::op_neq() {
  Op_neqContext *_localctx = _tracker.createInstance<Op_neqContext>(_ctx, getState());
  enterRule(_localctx, 202, zsharp_parserParser::RuleOp_neq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    match(zsharp_parserParser::NEQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_greatContext ------------------------------------------------------------------

zsharp_parserParser::Op_greatContext::Op_greatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_greatContext::GREAT_ANGLEclose() {
  return getToken(zsharp_parserParser::GREAT_ANGLEclose, 0);
}


size_t zsharp_parserParser::Op_greatContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_great;
}

void zsharp_parserParser::Op_greatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_great(this);
}

void zsharp_parserParser::Op_greatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_great(this);
}


antlrcpp::Any zsharp_parserParser::Op_greatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_great(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_greatContext* zsharp_parserParser::op_great() {
  Op_greatContext *_localctx = _tracker.createInstance<Op_greatContext>(_ctx, getState());
  enterRule(_localctx, 204, zsharp_parserParser::RuleOp_great);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(705);
    match(zsharp_parserParser::GREAT_ANGLEclose);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_smallContext ------------------------------------------------------------------

zsharp_parserParser::Op_smallContext::Op_smallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_smallContext::SMALL_ANGLEopen() {
  return getToken(zsharp_parserParser::SMALL_ANGLEopen, 0);
}


size_t zsharp_parserParser::Op_smallContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_small;
}

void zsharp_parserParser::Op_smallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_small(this);
}

void zsharp_parserParser::Op_smallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_small(this);
}


antlrcpp::Any zsharp_parserParser::Op_smallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_small(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_smallContext* zsharp_parserParser::op_small() {
  Op_smallContext *_localctx = _tracker.createInstance<Op_smallContext>(_ctx, getState());
  enterRule(_localctx, 206, zsharp_parserParser::RuleOp_small);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(zsharp_parserParser::SMALL_ANGLEopen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_greqContext ------------------------------------------------------------------

zsharp_parserParser::Op_greqContext::Op_greqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_greqContext::GREQ() {
  return getToken(zsharp_parserParser::GREQ, 0);
}


size_t zsharp_parserParser::Op_greqContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_greq;
}

void zsharp_parserParser::Op_greqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_greq(this);
}

void zsharp_parserParser::Op_greqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_greq(this);
}


antlrcpp::Any zsharp_parserParser::Op_greqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_greq(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_greqContext* zsharp_parserParser::op_greq() {
  Op_greqContext *_localctx = _tracker.createInstance<Op_greqContext>(_ctx, getState());
  enterRule(_localctx, 208, zsharp_parserParser::RuleOp_greq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(709);
    match(zsharp_parserParser::GREQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_smeqContext ------------------------------------------------------------------

zsharp_parserParser::Op_smeqContext::Op_smeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_smeqContext::SMEQ() {
  return getToken(zsharp_parserParser::SMEQ, 0);
}


size_t zsharp_parserParser::Op_smeqContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_smeq;
}

void zsharp_parserParser::Op_smeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_smeq(this);
}

void zsharp_parserParser::Op_smeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_smeq(this);
}


antlrcpp::Any zsharp_parserParser::Op_smeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_smeq(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_smeqContext* zsharp_parserParser::op_smeq() {
  Op_smeqContext *_localctx = _tracker.createInstance<Op_smeqContext>(_ctx, getState());
  enterRule(_localctx, 210, zsharp_parserParser::RuleOp_smeq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(711);
    match(zsharp_parserParser::SMEQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_andContext ------------------------------------------------------------------

zsharp_parserParser::Op_andContext::Op_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_andContext::AND() {
  return getToken(zsharp_parserParser::AND, 0);
}


size_t zsharp_parserParser::Op_andContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_and;
}

void zsharp_parserParser::Op_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_and(this);
}

void zsharp_parserParser::Op_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_and(this);
}


antlrcpp::Any zsharp_parserParser::Op_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_and(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_andContext* zsharp_parserParser::op_and() {
  Op_andContext *_localctx = _tracker.createInstance<Op_andContext>(_ctx, getState());
  enterRule(_localctx, 212, zsharp_parserParser::RuleOp_and);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(713);
    match(zsharp_parserParser::AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_orContext ------------------------------------------------------------------

zsharp_parserParser::Op_orContext::Op_orContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_orContext::OR() {
  return getToken(zsharp_parserParser::OR, 0);
}


size_t zsharp_parserParser::Op_orContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_or;
}

void zsharp_parserParser::Op_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_or(this);
}

void zsharp_parserParser::Op_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_or(this);
}


antlrcpp::Any zsharp_parserParser::Op_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_or(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_orContext* zsharp_parserParser::op_or() {
  Op_orContext *_localctx = _tracker.createInstance<Op_orContext>(_ctx, getState());
  enterRule(_localctx, 214, zsharp_parserParser::RuleOp_or);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(715);
    match(zsharp_parserParser::OR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_notContext ------------------------------------------------------------------

zsharp_parserParser::Op_notContext::Op_notContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_notContext::NOT() {
  return getToken(zsharp_parserParser::NOT, 0);
}


size_t zsharp_parserParser::Op_notContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_not;
}

void zsharp_parserParser::Op_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_not(this);
}

void zsharp_parserParser::Op_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_not(this);
}


antlrcpp::Any zsharp_parserParser::Op_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_not(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_notContext* zsharp_parserParser::op_not() {
  Op_notContext *_localctx = _tracker.createInstance<Op_notContext>(_ctx, getState());
  enterRule(_localctx, 216, zsharp_parserParser::RuleOp_not);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    match(zsharp_parserParser::NOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_andContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_andContext::Op_bit_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_andContext::BIT_AND() {
  return getToken(zsharp_parserParser::BIT_AND, 0);
}


size_t zsharp_parserParser::Op_bit_andContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_and;
}

void zsharp_parserParser::Op_bit_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_and(this);
}

void zsharp_parserParser::Op_bit_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_and(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_and(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_andContext* zsharp_parserParser::op_bit_and() {
  Op_bit_andContext *_localctx = _tracker.createInstance<Op_bit_andContext>(_ctx, getState());
  enterRule(_localctx, 218, zsharp_parserParser::RuleOp_bit_and);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(719);
    match(zsharp_parserParser::BIT_AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_orContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_orContext::Op_bit_orContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_orContext::BIT_OR() {
  return getToken(zsharp_parserParser::BIT_OR, 0);
}


size_t zsharp_parserParser::Op_bit_orContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_or;
}

void zsharp_parserParser::Op_bit_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_or(this);
}

void zsharp_parserParser::Op_bit_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_or(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_or(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_orContext* zsharp_parserParser::op_bit_or() {
  Op_bit_orContext *_localctx = _tracker.createInstance<Op_bit_orContext>(_ctx, getState());
  enterRule(_localctx, 220, zsharp_parserParser::RuleOp_bit_or);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(721);
    match(zsharp_parserParser::BIT_OR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_xorContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_xorContext::Op_bit_xorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_xorContext::BIT_XOR() {
  return getToken(zsharp_parserParser::BIT_XOR, 0);
}


size_t zsharp_parserParser::Op_bit_xorContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_xor;
}

void zsharp_parserParser::Op_bit_xorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_xor(this);
}

void zsharp_parserParser::Op_bit_xorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_xor(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_xorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_xor(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_xorContext* zsharp_parserParser::op_bit_xor() {
  Op_bit_xorContext *_localctx = _tracker.createInstance<Op_bit_xorContext>(_ctx, getState());
  enterRule(_localctx, 222, zsharp_parserParser::RuleOp_bit_xor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(723);
    match(zsharp_parserParser::BIT_XOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_notContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_notContext::Op_bit_notContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_notContext::BIT_NOT() {
  return getToken(zsharp_parserParser::BIT_NOT, 0);
}


size_t zsharp_parserParser::Op_bit_notContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_not;
}

void zsharp_parserParser::Op_bit_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_not(this);
}

void zsharp_parserParser::Op_bit_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_not(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_not(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_notContext* zsharp_parserParser::op_bit_not() {
  Op_bit_notContext *_localctx = _tracker.createInstance<Op_bit_notContext>(_ctx, getState());
  enterRule(_localctx, 224, zsharp_parserParser::RuleOp_bit_not);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    match(zsharp_parserParser::BIT_NOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_shlContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_shlContext::Op_bit_shlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_shlContext::BIT_SHL() {
  return getToken(zsharp_parserParser::BIT_SHL, 0);
}


size_t zsharp_parserParser::Op_bit_shlContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_shl;
}

void zsharp_parserParser::Op_bit_shlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_shl(this);
}

void zsharp_parserParser::Op_bit_shlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_shl(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_shlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_shl(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_shlContext* zsharp_parserParser::op_bit_shl() {
  Op_bit_shlContext *_localctx = _tracker.createInstance<Op_bit_shlContext>(_ctx, getState());
  enterRule(_localctx, 226, zsharp_parserParser::RuleOp_bit_shl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(727);
    match(zsharp_parserParser::BIT_SHL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_shrContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_shrContext::Op_bit_shrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_shrContext::BIT_SHR() {
  return getToken(zsharp_parserParser::BIT_SHR, 0);
}


size_t zsharp_parserParser::Op_bit_shrContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_shr;
}

void zsharp_parserParser::Op_bit_shrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_shr(this);
}

void zsharp_parserParser::Op_bit_shrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_shr(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_shrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_shr(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_shrContext* zsharp_parserParser::op_bit_shr() {
  Op_bit_shrContext *_localctx = _tracker.createInstance<Op_bit_shrContext>(_ctx, getState());
  enterRule(_localctx, 228, zsharp_parserParser::RuleOp_bit_shr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(729);
    match(zsharp_parserParser::BIT_SHR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_rollContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_rollContext::Op_bit_rollContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_rollContext::BIT_ROLL() {
  return getToken(zsharp_parserParser::BIT_ROLL, 0);
}


size_t zsharp_parserParser::Op_bit_rollContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_roll;
}

void zsharp_parserParser::Op_bit_rollContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_roll(this);
}

void zsharp_parserParser::Op_bit_rollContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_roll(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_rollContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_roll(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_rollContext* zsharp_parserParser::op_bit_roll() {
  Op_bit_rollContext *_localctx = _tracker.createInstance<Op_bit_rollContext>(_ctx, getState());
  enterRule(_localctx, 230, zsharp_parserParser::RuleOp_bit_roll);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(731);
    match(zsharp_parserParser::BIT_ROLL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_bit_rolrContext ------------------------------------------------------------------

zsharp_parserParser::Op_bit_rolrContext::Op_bit_rolrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_bit_rolrContext::BIT_ROLR() {
  return getToken(zsharp_parserParser::BIT_ROLR, 0);
}


size_t zsharp_parserParser::Op_bit_rolrContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_bit_rolr;
}

void zsharp_parserParser::Op_bit_rolrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_bit_rolr(this);
}

void zsharp_parserParser::Op_bit_rolrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_bit_rolr(this);
}


antlrcpp::Any zsharp_parserParser::Op_bit_rolrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_bit_rolr(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_bit_rolrContext* zsharp_parserParser::op_bit_rolr() {
  Op_bit_rolrContext *_localctx = _tracker.createInstance<Op_bit_rolrContext>(_ctx, getState());
  enterRule(_localctx, 232, zsharp_parserParser::RuleOp_bit_rolr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(733);
    match(zsharp_parserParser::BIT_ROLR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_concatContext ------------------------------------------------------------------

zsharp_parserParser::Op_concatContext::Op_concatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Op_concatContext::CONCAT() {
  return getToken(zsharp_parserParser::CONCAT, 0);
}


size_t zsharp_parserParser::Op_concatContext::getRuleIndex() const {
  return zsharp_parserParser::RuleOp_concat;
}

void zsharp_parserParser::Op_concatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_concat(this);
}

void zsharp_parserParser::Op_concatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_concat(this);
}


antlrcpp::Any zsharp_parserParser::Op_concatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitOp_concat(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Op_concatContext* zsharp_parserParser::op_concat() {
  Op_concatContext *_localctx = _tracker.createInstance<Op_concatContext>(_ctx, getState());
  enterRule(_localctx, 234, zsharp_parserParser::RuleOp_concat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(735);
    match(zsharp_parserParser::CONCAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Empty_lineContext ------------------------------------------------------------------

zsharp_parserParser::Empty_lineContext::Empty_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Empty_lineContext::INDENT() {
  return getToken(zsharp_parserParser::INDENT, 0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Empty_lineContext::EOL() {
  return getTokens(zsharp_parserParser::EOL);
}

tree::TerminalNode* zsharp_parserParser::Empty_lineContext::EOL(size_t i) {
  return getToken(zsharp_parserParser::EOL, i);
}


size_t zsharp_parserParser::Empty_lineContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEmpty_line;
}

void zsharp_parserParser::Empty_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty_line(this);
}

void zsharp_parserParser::Empty_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty_line(this);
}


antlrcpp::Any zsharp_parserParser::Empty_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEmpty_line(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Empty_lineContext* zsharp_parserParser::empty_line() {
  Empty_lineContext *_localctx = _tracker.createInstance<Empty_lineContext>(_ctx, getState());
  enterRule(_localctx, 236, zsharp_parserParser::RuleEmpty_line);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(738);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(737);
      match(zsharp_parserParser::INDENT);
    }
    setState(741); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(740);
              match(zsharp_parserParser::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(743); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewlineContext ------------------------------------------------------------------

zsharp_parserParser::NewlineContext::NewlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::NewlineContext::EOL() {
  return getToken(zsharp_parserParser::EOL, 0);
}

tree::TerminalNode* zsharp_parserParser::NewlineContext::COMMENT() {
  return getToken(zsharp_parserParser::COMMENT, 0);
}

zsharp_parserParser::IndentContext* zsharp_parserParser::NewlineContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}


size_t zsharp_parserParser::NewlineContext::getRuleIndex() const {
  return zsharp_parserParser::RuleNewline;
}

void zsharp_parserParser::NewlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewline(this);
}

void zsharp_parserParser::NewlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewline(this);
}


antlrcpp::Any zsharp_parserParser::NewlineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitNewline(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::newline() {
  NewlineContext *_localctx = _tracker.createInstance<NewlineContext>(_ctx, getState());
  enterRule(_localctx, 238, zsharp_parserParser::RuleNewline);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(749);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COMMENT

    || _la == zsharp_parserParser::INDENT) {
      setState(746);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == zsharp_parserParser::INDENT) {
        setState(745);
        indent();
      }
      setState(748);
      match(zsharp_parserParser::COMMENT);
    }
    setState(751);
    match(zsharp_parserParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

zsharp_parserParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::CommentContext::COMMENT() {
  return getToken(zsharp_parserParser::COMMENT, 0);
}

tree::TerminalNode* zsharp_parserParser::CommentContext::EOL() {
  return getToken(zsharp_parserParser::EOL, 0);
}

zsharp_parserParser::IndentContext* zsharp_parserParser::CommentContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}


size_t zsharp_parserParser::CommentContext::getRuleIndex() const {
  return zsharp_parserParser::RuleComment;
}

void zsharp_parserParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void zsharp_parserParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}


antlrcpp::Any zsharp_parserParser::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::CommentContext* zsharp_parserParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 240, zsharp_parserParser::RuleComment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(754);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(753);
      indent();
    }
    setState(756);
    match(zsharp_parserParser::COMMENT);
    setState(757);
    match(zsharp_parserParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

zsharp_parserParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::StringContext::STRING() {
  return getToken(zsharp_parserParser::STRING, 0);
}


size_t zsharp_parserParser::StringContext::getRuleIndex() const {
  return zsharp_parserParser::RuleString;
}

void zsharp_parserParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void zsharp_parserParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any zsharp_parserParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::StringContext* zsharp_parserParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 242, zsharp_parserParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(759);
    match(zsharp_parserParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterContext ------------------------------------------------------------------

zsharp_parserParser::CharacterContext::CharacterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::CharacterContext::CHARACTER() {
  return getToken(zsharp_parserParser::CHARACTER, 0);
}


size_t zsharp_parserParser::CharacterContext::getRuleIndex() const {
  return zsharp_parserParser::RuleCharacter;
}

void zsharp_parserParser::CharacterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharacter(this);
}

void zsharp_parserParser::CharacterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharacter(this);
}


antlrcpp::Any zsharp_parserParser::CharacterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitCharacter(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::CharacterContext* zsharp_parserParser::character() {
  CharacterContext *_localctx = _tracker.createInstance<CharacterContext>(_ctx, getState());
  enterRule(_localctx, 244, zsharp_parserParser::RuleCharacter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(761);
    match(zsharp_parserParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndentContext ------------------------------------------------------------------

zsharp_parserParser::IndentContext::IndentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::IndentContext::INDENT() {
  return getToken(zsharp_parserParser::INDENT, 0);
}


size_t zsharp_parserParser::IndentContext::getRuleIndex() const {
  return zsharp_parserParser::RuleIndent;
}

void zsharp_parserParser::IndentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndent(this);
}

void zsharp_parserParser::IndentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndent(this);
}


antlrcpp::Any zsharp_parserParser::IndentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitIndent(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::IndentContext* zsharp_parserParser::indent() {
  IndentContext *_localctx = _tracker.createInstance<IndentContext>(_ctx, getState());
  enterRule(_localctx, 246, zsharp_parserParser::RuleIndent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(763);
    match(zsharp_parserParser::INDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool zsharp_parserParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return module_nameSempred(dynamic_cast<Module_nameContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool zsharp_parserParser::module_nameSempred(Module_nameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> zsharp_parserParser::_decisionToDFA;
atn::PredictionContextCache zsharp_parserParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN zsharp_parserParser::_atn;
std::vector<uint16_t> zsharp_parserParser::_serializedATN;

std::vector<std::string> zsharp_parserParser::_ruleNames = {
  "file", "code", "statement", "module_statement", "module_name", "statement_module", 
  "statement_import", "statement_export", "flow_statement", "statement_return", 
  "statement_if", "statement_else", "declaration", "expression_value", "comptime_expression_value", 
  "expression_logic", "logic_operand", "expression_comparison", "comparison_operand", 
  "expression_bitwise", "bitwise_operand", "expression_bool", "identifier_bool", 
  "function_call", "function_decl", "function_parameter_list", "function_parameter", 
  "function_type", "function_parameter_uselist", "function_param_use", "variable_ref", 
  "parameter_ref", "struct_decl", "struct_field_decl_list", "struct_field_decl", 
  "enum_decl", "enum_option_decl_list", "enum_option_decl", "enum_base_types", 
  "type_any", "optional_type", "error_type", "optional_error_type", "type_name", 
  "known_types", "type_U8", "type_U16", "type_U24", "type_U32", "type_I8", 
  "type_I16", "type_I24", "type_I32", "type_F16", "type_F32", "type_Str", 
  "type_Bool", "type_Bit", "identifier_type", "identifier_var", "identifier_param", 
  "identifier_func", "identifier_field", "identifier_enumoption", "identifier_module", 
  "identifier_unused", "keyword_module", "keyword_import", "keyword_export", 
  "keyword_loop", "keyword_break", "keyword_continue", "keyword_if", "keyword_else", 
  "keyword_return", "keyword_in", "keyword_self", "literal_bool", "literal", 
  "number", "number_unsigned", "number_bin", "number_oct", "number_dec", 
  "number_hex", "number_char", "operator_arithmetic", "operator_arithmetic_unary", 
  "operator_logic", "operator_logic_unary", "operator_comparison", "operator_bits", 
  "operator_bits_unary", "operator_assignment", "op_plus", "op_minus_neg", 
  "op_mult", "op_div", "op_mod", "op_pow", "op_eq_assign", "op_neq", "op_great", 
  "op_small", "op_greq", "op_smeq", "op_and", "op_or", "op_not", "op_bit_and", 
  "op_bit_or", "op_bit_xor", "op_bit_not", "op_bit_shl", "op_bit_shr", "op_bit_roll", 
  "op_bit_rolr", "op_concat", "empty_line", "newline", "comment", "string", 
  "character", "indent"
};

std::vector<std::string> zsharp_parserParser::_literalNames = {
  "", "'U8'", "'U16'", "'U24'", "'U32'", "'I8'", "'I16'", "'I24'", "'I32'", 
  "'F16'", "'F32'", "'Str'", "'Bool'", "'Bit'", "'module'", "'import'", 
  "'export'", "'loop'", "'break'", "'continue'", "'if'", "'else'", "'return'", 
  "'in'", "'self'", "'true'", "'false'", "", "", "", "", "", "", "", "", 
  "", "", "", "'_'", "'+'", "'-'", "'*'", "'/'", "'%'", "'**'", "'='", "'<>'", 
  "'>'", "'<'", "'>='", "'<='", "'and'", "'or'", "'not'", "'&'", "'|'", 
  "'^'", "'~'", "'<<'", "'>>'", "'|,'", "'>|'", "'&&'", "'['", "']'", "'('", 
  "')'", "'?'", "':'", "'.'", "'..'", "'...'", "','", "'#'", "'#!'", "'!'", 
  "'\"'", "'''", "'//'", "' '", "'\t'"
};

std::vector<std::string> zsharp_parserParser::_symbolicNames = {
  "", "U8", "U16", "U24", "U32", "I8", "I16", "I24", "I32", "F16", "F32", 
  "STR", "BOOL", "BIT", "MODULE", "IMPORT", "EXPORT", "LOOP", "BREAK", "CONTINUE", 
  "IF", "ELSE", "RETURN", "IN", "SELF", "TRUE", "FALSE", "IDENTIFIERupper", 
  "IDENTIFIERlower", "IDENTIFIERmixed", "COMMENT", "NUMBERbin", "NUMBERoct", 
  "NUMBERdec", "NUMBERdec_prefix", "NUMBERhex", "CHARACTER", "STRING", "UNUSED", 
  "PLUS", "MINUS_NEG", "MULT", "DIV", "MOD", "POW", "EQ_ASSIGN", "NEQ", 
  "GREAT_ANGLEclose", "SMALL_ANGLEopen", "GREQ", "SMEQ", "AND", "OR", "NOT", 
  "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NOT", "BIT_SHL", "BIT_SHR", "BIT_ROLL", 
  "BIT_ROLR", "CONCAT", "SUBopen", "SUBclose", "PARENopen", "PARENclose", 
  "QUESTION", "COLON", "DOT", "RANGE", "SPREAD", "COMMA", "META", "COMPTIME", 
  "ERROR", "STR_QUOTE", "CHAR_QUOTE", "COMMENTstart", "SP", "TAB", "INDENT", 
  "EOL"
};

dfa::Vocabulary zsharp_parserParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> zsharp_parserParser::_tokenNames;

zsharp_parserParser::Initializer::Initializer() {
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
    0x3, 0x54, 0x300, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 
    0x9, 0x70, 0x4, 0x71, 0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 
    0x73, 0x4, 0x74, 0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 
    0x4, 0x77, 0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 
    0x7a, 0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
    0x9, 0x7d, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xfd, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x100, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x106, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x10b, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x110, 0xa, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x118, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x11b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x12b, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x134, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x13a, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x14a, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x151, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x159, 0xa, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x15e, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0x169, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x16c, 0xa, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x170, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x17c, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x5, 0x15, 0x187, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x18c, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x190, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x194, 0xa, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x199, 0xa, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x5, 0x1a, 0x19e, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x5, 0x1a, 0x1a3, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0x1a7, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x1b0, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 
    0x1b1, 0x5, 0x1b, 0x1b4, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x6, 0x1e, 0x1c1, 0xa, 0x1e, 0xd, 0x1e, 0xe, 0x1e, 
    0x1c2, 0x5, 0x1e, 0x1c5, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x6, 0x1f, 0x1cb, 0xa, 0x1f, 0xd, 0x1f, 0xe, 0x1f, 0x1cc, 
    0x5, 0x1f, 0x1cf, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x1d9, 0xa, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x6, 0x23, 0x1df, 0xa, 0x23, 
    0xd, 0x23, 0xe, 0x23, 0x1e0, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x5, 0x25, 0x1ee, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x6, 0x26, 0x1f4, 0xa, 0x26, 0xd, 0x26, 0xe, 0x26, 0x1f5, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
    0x27, 0x1fe, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x201, 0xa, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x5, 0x28, 0x211, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x217, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x225, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x234, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x27a, 
    0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
    0x52, 0x3, 0x52, 0x5, 0x52, 0x283, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 
    0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x5, 0x58, 0x295, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 
    0x3, 0x5a, 0x5, 0x5a, 0x29b, 0xa, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x2a5, 
    0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 
    0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x2ae, 0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 
    0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 
    0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 
    0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 
    0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 0x3, 
    0x6f, 0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 
    0x3, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 0x3, 0x74, 0x3, 0x75, 0x3, 
    0x75, 0x3, 0x76, 0x3, 0x76, 0x3, 0x77, 0x3, 0x77, 0x3, 0x78, 0x5, 0x78, 
    0x2e5, 0xa, 0x78, 0x3, 0x78, 0x6, 0x78, 0x2e8, 0xa, 0x78, 0xd, 0x78, 
    0xe, 0x78, 0x2e9, 0x3, 0x79, 0x5, 0x79, 0x2ed, 0xa, 0x79, 0x3, 0x79, 
    0x5, 0x79, 0x2f0, 0xa, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x7a, 0x5, 0x7a, 
    0x2f5, 0xa, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7b, 0x3, 0x7b, 
    0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x2, 0x3, 0xa, 
    0x7e, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
    0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 
    0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 
    0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 
    0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 
    0xf2, 0xf4, 0xf6, 0xf8, 0x2, 0x5, 0x3, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x1b, 
    0x1c, 0x3, 0x2, 0x23, 0x24, 0x2, 0x2ec, 0x2, 0xfe, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x105, 0x3, 0x2, 0x2, 0x2, 0x6, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x111, 0x3, 0x2, 0x2, 0x2, 0xc, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x121, 0x3, 0x2, 0x2, 0x2, 0x10, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x133, 0x3, 0x2, 0x2, 0x2, 0x14, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x150, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x16f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x171, 0x3, 0x2, 0x2, 0x2, 0x26, 0x17b, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x186, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x18b, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x195, 0x3, 0x2, 0x2, 0x2, 0x32, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x1ce, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1d2, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1de, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1e9, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1f7, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x210, 0x3, 0x2, 0x2, 0x2, 0x50, 0x216, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x218, 0x3, 0x2, 0x2, 0x2, 0x54, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x21e, 0x3, 0x2, 0x2, 0x2, 0x58, 0x224, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x233, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x235, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x237, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x239, 0x3, 0x2, 0x2, 0x2, 0x62, 0x23b, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x66, 0x23f, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x241, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x243, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x245, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x247, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x249, 0x3, 0x2, 0x2, 0x2, 0x72, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x74, 0x24d, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x78, 0x251, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x253, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x255, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x257, 0x3, 0x2, 0x2, 0x2, 0x80, 0x259, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x84, 0x25d, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x88, 0x261, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x263, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x265, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x267, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x269, 0x3, 0x2, 0x2, 0x2, 0x92, 0x26b, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x96, 0x26f, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x271, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x273, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x275, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x279, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x27b, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x282, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x284, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x286, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x288, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x28a, 0x3, 0x2, 0x2, 0x2, 0xac, 0x28c, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x294, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x296, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x29a, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x29c, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x2ad, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0x2af, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0x2b3, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x2b7, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x2bb, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0xca, 0x2bf, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0xce, 0x2c3, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x2c7, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0xd8, 
    0x2cd, 0x3, 0x2, 0x2, 0x2, 0xda, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x2d1, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x2d5, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x2d9, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0x2db, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x2dd, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0x2df, 0x3, 0x2, 0x2, 0x2, 0xec, 0x2e1, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0x2f4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x2fb, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x5, 
    0x4, 0x3, 0x2, 0xfb, 0xfd, 0x5, 0xee, 0x78, 0x2, 0xfc, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x101, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0x7, 0x2, 0x2, 0x3, 0x102, 0x3, 0x3, 0x2, 0x2, 0x2, 0x103, 0x106, 
    0x5, 0x6, 0x4, 0x2, 0x104, 0x106, 0x5, 0xf2, 0x7a, 0x2, 0x105, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x10b, 0x5, 0x8, 0x5, 0x2, 0x108, 0x10b, 0x5, 
    0x12, 0xa, 0x2, 0x109, 0x10b, 0x5, 0x1a, 0xe, 0x2, 0x10a, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x110, 0x5, 0xc, 
    0x7, 0x2, 0x10d, 0x110, 0x5, 0xe, 0x8, 0x2, 0x10e, 0x110, 0x5, 0x10, 
    0x9, 0x2, 0x10f, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x112, 0x8, 0x6, 0x1, 0x2, 0x112, 0x113, 0x5, 0x82, 0x42, 
    0x2, 0x113, 0x119, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0xc, 0x3, 0x2, 
    0x2, 0x115, 0x116, 0x7, 0x47, 0x2, 0x2, 0x116, 0x118, 0x5, 0x82, 0x42, 
    0x2, 0x117, 0x114, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11d, 0x5, 0x86, 0x44, 0x2, 0x11d, 0x11e, 0x7, 0x51, 0x2, 0x2, 
    0x11e, 0x11f, 0x5, 0xa, 0x6, 0x2, 0x11f, 0x120, 0x5, 0xf0, 0x79, 0x2, 
    0x120, 0xd, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x5, 0x88, 0x45, 0x2, 
    0x122, 0x123, 0x7, 0x51, 0x2, 0x2, 0x123, 0x124, 0x5, 0xa, 0x6, 0x2, 
    0x124, 0x125, 0x5, 0xf0, 0x79, 0x2, 0x125, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x126, 0x127, 0x5, 0x8a, 0x46, 0x2, 0x127, 0x12a, 0x7, 0x51, 0x2, 0x2, 
    0x128, 0x12b, 0x5, 0x7c, 0x3f, 0x2, 0x129, 0x12b, 0x5, 0x76, 0x3c, 0x2, 
    0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x5, 0xf0, 0x79, 0x2, 
    0x12d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x134, 0x5, 0x16, 0xc, 0x2, 
    0x12f, 0x134, 0x5, 0x18, 0xd, 0x2, 0x130, 0x134, 0x5, 0x8e, 0x48, 0x2, 
    0x131, 0x134, 0x5, 0x90, 0x49, 0x2, 0x132, 0x134, 0x5, 0x14, 0xb, 0x2, 
    0x133, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x130, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x13, 0x3, 0x2, 0x2, 0x2, 0x135, 
    0x136, 0x5, 0xf8, 0x7d, 0x2, 0x136, 0x139, 0x5, 0x96, 0x4c, 0x2, 0x137, 
    0x138, 0x7, 0x51, 0x2, 0x2, 0x138, 0x13a, 0x5, 0x1c, 0xf, 0x2, 0x139, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0xf0, 0x79, 0x2, 0x13c, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x5, 0xf8, 0x7d, 0x2, 0x13e, 
    0x13f, 0x5, 0x92, 0x4a, 0x2, 0x13f, 0x140, 0x7, 0x51, 0x2, 0x2, 0x140, 
    0x141, 0x5, 0x20, 0x11, 0x2, 0x141, 0x142, 0x5, 0xf0, 0x79, 0x2, 0x142, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x5, 0xf8, 0x7d, 0x2, 0x144, 
    0x149, 0x5, 0x94, 0x4b, 0x2, 0x145, 0x146, 0x5, 0x92, 0x4a, 0x2, 0x146, 
    0x147, 0x7, 0x51, 0x2, 0x2, 0x147, 0x148, 0x5, 0x20, 0x11, 0x2, 0x148, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x149, 0x145, 0x3, 0x2, 0x2, 0x2, 0x149, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 
    0x14c, 0x5, 0xf0, 0x79, 0x2, 0x14c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x14d, 
    0x151, 0x5, 0x32, 0x1a, 0x2, 0x14e, 0x151, 0x5, 0x48, 0x25, 0x2, 0x14f, 
    0x151, 0x5, 0x42, 0x22, 0x2, 0x150, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x152, 0x159, 0x5, 0xa0, 0x51, 0x2, 0x153, 
    0x159, 0x5, 0xf4, 0x7b, 0x2, 0x154, 0x159, 0x5, 0x2c, 0x17, 0x2, 0x155, 
    0x159, 0x5, 0x20, 0x11, 0x2, 0x156, 0x159, 0x5, 0x28, 0x15, 0x2, 0x157, 
    0x159, 0x5, 0x30, 0x19, 0x2, 0x158, 0x152, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x158, 0x154, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15e, 
    0x5, 0xa0, 0x51, 0x2, 0x15b, 0x15e, 0x5, 0xf4, 0x7b, 0x2, 0x15c, 0x15e, 
    0x5, 0x2c, 0x17, 0x2, 0x15d, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x22, 0x12, 0x2, 0x160, 0x161, 0x7, 
    0x51, 0x2, 0x2, 0x161, 0x162, 0x5, 0xb2, 0x5a, 0x2, 0x162, 0x163, 0x7, 
    0x51, 0x2, 0x2, 0x163, 0x164, 0x5, 0x22, 0x12, 0x2, 0x164, 0x16c, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x166, 0x5, 0xb4, 0x5b, 0x2, 0x166, 0x167, 0x7, 
    0x51, 0x2, 0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 0x2, 0x168, 0x165, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16c, 0x5, 0x22, 0x12, 0x2, 0x16b, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x16b, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x170, 0x5, 0x24, 0x13, 0x2, 0x16e, 0x170, 0x5, 0x2c, 
    0x17, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x23, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x5, 0x26, 
    0x14, 0x2, 0x172, 0x173, 0x7, 0x51, 0x2, 0x2, 0x173, 0x174, 0x5, 0xb6, 
    0x5c, 0x2, 0x174, 0x175, 0x7, 0x51, 0x2, 0x2, 0x175, 0x176, 0x5, 0x26, 
    0x14, 0x2, 0x176, 0x25, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17c, 0x5, 0x28, 
    0x15, 0x2, 0x178, 0x17c, 0x5, 0x30, 0x19, 0x2, 0x179, 0x17c, 0x5, 0x3e, 
    0x20, 0x2, 0x17a, 0x17c, 0x5, 0x9e, 0x50, 0x2, 0x17b, 0x177, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x17d, 0x17e, 0x5, 0x2a, 0x16, 0x2, 0x17e, 0x17f, 0x7, 0x51, 0x2, 
    0x2, 0x17f, 0x180, 0x5, 0xb8, 0x5d, 0x2, 0x180, 0x181, 0x7, 0x51, 0x2, 
    0x2, 0x181, 0x182, 0x5, 0x2a, 0x16, 0x2, 0x182, 0x187, 0x3, 0x2, 0x2, 
    0x2, 0x183, 0x184, 0x5, 0xba, 0x5e, 0x2, 0x184, 0x185, 0x5, 0x2a, 0x16, 
    0x2, 0x185, 0x187, 0x3, 0x2, 0x2, 0x2, 0x186, 0x17d, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x183, 0x3, 0x2, 0x2, 0x2, 0x187, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x18c, 0x5, 0x30, 0x19, 0x2, 0x189, 0x18c, 0x5, 0x3e, 0x20, 0x2, 
    0x18a, 0x18c, 0x5, 0xa0, 0x51, 0x2, 0x18b, 0x188, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 
    0x18c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x5, 0x9c, 0x4f, 0x2, 
    0x18e, 0x190, 0x5, 0x2e, 0x18, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 
    0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x194, 0x5, 0x3e, 0x20, 0x2, 0x192, 0x194, 0x5, 0x40, 0x21, 0x2, 0x193, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 0x7c, 0x3f, 0x2, 0x196, 
    0x198, 0x7, 0x43, 0x2, 0x2, 0x197, 0x199, 0x5, 0x3a, 0x1e, 0x2, 0x198, 
    0x197, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x44, 0x2, 0x2, 0x19b, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0xf8, 0x7d, 0x2, 0x19d, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x5, 0x7c, 0x3f, 0x2, 0x1a0, 
    0x1a2, 0x7, 0x43, 0x2, 0x2, 0x1a1, 0x1a3, 0x5, 0x34, 0x1b, 0x2, 0x1a2, 
    0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
    0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a6, 0x7, 0x44, 0x2, 0x2, 0x1a5, 
    0x1a7, 0x5, 0x38, 0x1d, 0x2, 0x1a6, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
    0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 
    0x1a9, 0x7, 0x54, 0x2, 0x2, 0x1a9, 0x1aa, 0x5, 0x4, 0x3, 0x2, 0x1aa, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1b4, 0x5, 0x36, 0x1c, 0x2, 0x1ac, 
    0x1ad, 0x7, 0x4a, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x51, 0x2, 0x2, 0x1ae, 
    0x1b0, 0x5, 0x36, 0x1c, 0x2, 0x1af, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b0, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b4, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x5, 0x7a, 0x3e, 0x2, 0x1b6, 
    0x1b7, 0x5, 0x38, 0x1d, 0x2, 0x1b7, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
    0x1b9, 0x7, 0x46, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x51, 0x2, 0x2, 0x1ba, 
    0x1bb, 0x5, 0x50, 0x29, 0x2, 0x1bb, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1c5, 0x5, 0x3c, 0x1f, 0x2, 0x1bd, 0x1be, 0x7, 0x4a, 0x2, 0x2, 0x1be, 
    0x1bf, 0x7, 0x51, 0x2, 0x2, 0x1bf, 0x1c1, 0x5, 0x3c, 0x1f, 0x2, 0x1c0, 
    0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1cf, 
    0x5, 0x1c, 0xf, 0x2, 0x1c7, 0x1c8, 0x7, 0x4a, 0x2, 0x2, 0x1c8, 0x1c9, 
    0x7, 0x51, 0x2, 0x2, 0x1c9, 0x1cb, 0x5, 0x1c, 0xf, 0x2, 0x1ca, 0x1c7, 
    0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ca, 
    0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cf, 
    0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1ca, 
    0x3, 0x2, 0x2, 0x2, 0x1cf, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x5, 
    0x78, 0x3d, 0x2, 0x1d1, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x5, 
    0x7a, 0x3e, 0x2, 0x1d3, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d8, 0x5, 
    0x76, 0x3c, 0x2, 0x1d5, 0x1d6, 0x7, 0x46, 0x2, 0x2, 0x1d6, 0x1d7, 0x7, 
    0x51, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 0x50, 0x29, 0x2, 0x1d8, 0x1d5, 0x3, 
    0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 
    0x2, 0x2, 0x2, 0x1da, 0x1db, 0x5, 0xf0, 0x79, 0x2, 0x1db, 0x1dc, 0x5, 
    0x44, 0x23, 0x2, 0x1dc, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1df, 0x5, 
    0x46, 0x24, 0x2, 0x1de, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 
    0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 
    0x2, 0x2, 0x2, 0x1e1, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x5, 0xf8, 
    0x7d, 0x2, 0x1e3, 0x1e4, 0x5, 0x7e, 0x40, 0x2, 0x1e4, 0x1e5, 0x7, 0x46, 
    0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x51, 0x2, 0x2, 0x1e6, 0x1e7, 0x5, 0x50, 
    0x29, 0x2, 0x1e7, 0x1e8, 0x5, 0xf0, 0x79, 0x2, 0x1e8, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1ed, 0x5, 0x76, 0x3c, 0x2, 0x1ea, 0x1eb, 0x7, 0x46, 
    0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x51, 0x2, 0x2, 0x1ec, 0x1ee, 0x5, 0x4e, 
    0x28, 0x2, 0x1ed, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x3, 0x2, 
    0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x5, 0xf0, 
    0x79, 0x2, 0x1f0, 0x1f1, 0x5, 0x4a, 0x26, 0x2, 0x1f1, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x1f2, 0x1f4, 0x5, 0x4c, 0x27, 0x2, 0x1f3, 0x1f2, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 
    0x2, 0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x1f7, 0x1f8, 0x5, 0xf8, 0x7d, 0x2, 0x1f8, 0x1fd, 0x5, 0x80, 0x41, 
    0x2, 0x1f9, 0x1fa, 0x7, 0x51, 0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x2f, 0x2, 
    0x2, 0x1fb, 0x1fc, 0x7, 0x51, 0x2, 0x2, 0x1fc, 0x1fe, 0x5, 0x1e, 0x10, 
    0x2, 0x1fd, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 
    0x2, 0x1fe, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 0x7, 0x4a, 0x2, 
    0x2, 0x200, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x5, 0xf0, 0x79, 
    0x2, 0x203, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x204, 0x211, 0x5, 0x74, 0x3b, 
    0x2, 0x205, 0x211, 0x5, 0x70, 0x39, 0x2, 0x206, 0x211, 0x5, 0x6c, 0x37, 
    0x2, 0x207, 0x211, 0x5, 0x6e, 0x38, 0x2, 0x208, 0x211, 0x5, 0x66, 0x34, 
    0x2, 0x209, 0x211, 0x5, 0x68, 0x35, 0x2, 0x20a, 0x211, 0x5, 0x6a, 0x36, 
    0x2, 0x20b, 0x211, 0x5, 0x64, 0x33, 0x2, 0x20c, 0x211, 0x5, 0x5e, 0x30, 
    0x2, 0x20d, 0x211, 0x5, 0x60, 0x31, 0x2, 0x20e, 0x211, 0x5, 0x62, 0x32, 
    0x2, 0x20f, 0x211, 0x5, 0x5c, 0x2f, 0x2, 0x210, 0x204, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x205, 0x3, 0x2, 0x2, 0x2, 0x210, 0x206, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x207, 0x3, 0x2, 0x2, 0x2, 0x210, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x209, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20c, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 
    0x2, 0x210, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x212, 0x217, 0x5, 0x58, 0x2d, 0x2, 0x213, 0x217, 0x5, 0x52, 0x2a, 0x2, 
    0x214, 0x217, 0x5, 0x54, 0x2b, 0x2, 0x215, 0x217, 0x5, 0x56, 0x2c, 0x2, 
    0x216, 0x212, 0x3, 0x2, 0x2, 0x2, 0x216, 0x213, 0x3, 0x2, 0x2, 0x2, 
    0x216, 0x214, 0x3, 0x2, 0x2, 0x2, 0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x51, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x5, 0x58, 0x2d, 0x2, 
    0x219, 0x21a, 0x7, 0x45, 0x2, 0x2, 0x21a, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x21c, 0x5, 0x58, 0x2d, 0x2, 0x21c, 0x21d, 0x7, 0x4d, 0x2, 0x2, 
    0x21d, 0x55, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x5, 0x58, 0x2d, 0x2, 
    0x21f, 0x220, 0x7, 0x4d, 0x2, 0x2, 0x220, 0x221, 0x7, 0x45, 0x2, 0x2, 
    0x221, 0x57, 0x3, 0x2, 0x2, 0x2, 0x222, 0x225, 0x5, 0x5a, 0x2e, 0x2, 
    0x223, 0x225, 0x5, 0x76, 0x3c, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x59, 0x3, 0x2, 0x2, 0x2, 0x226, 
    0x234, 0x5, 0x74, 0x3b, 0x2, 0x227, 0x234, 0x5, 0x72, 0x3a, 0x2, 0x228, 
    0x234, 0x5, 0x70, 0x39, 0x2, 0x229, 0x234, 0x5, 0x6c, 0x37, 0x2, 0x22a, 
    0x234, 0x5, 0x6e, 0x38, 0x2, 0x22b, 0x234, 0x5, 0x66, 0x34, 0x2, 0x22c, 
    0x234, 0x5, 0x68, 0x35, 0x2, 0x22d, 0x234, 0x5, 0x6a, 0x36, 0x2, 0x22e, 
    0x234, 0x5, 0x64, 0x33, 0x2, 0x22f, 0x234, 0x5, 0x5e, 0x30, 0x2, 0x230, 
    0x234, 0x5, 0x60, 0x31, 0x2, 0x231, 0x234, 0x5, 0x62, 0x32, 0x2, 0x232, 
    0x234, 0x5, 0x5c, 0x2f, 0x2, 0x233, 0x226, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x233, 0x228, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x233, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x22b, 0x3, 0x2, 0x2, 0x2, 0x233, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x22d, 0x3, 0x2, 0x2, 0x2, 0x233, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x22f, 0x3, 0x2, 0x2, 0x2, 0x233, 0x230, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0x7, 0x3, 0x2, 0x2, 0x236, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x7, 0x4, 0x2, 0x2, 0x238, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x5, 0x2, 0x2, 0x23a, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x23b, 0x23c, 0x7, 0x6, 0x2, 0x2, 0x23c, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x23d, 0x23e, 0x7, 0x7, 0x2, 0x2, 0x23e, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x240, 0x7, 0x8, 0x2, 0x2, 0x240, 0x67, 0x3, 0x2, 0x2, 0x2, 0x241, 
    0x242, 0x7, 0x9, 0x2, 0x2, 0x242, 0x69, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 
    0x7, 0xa, 0x2, 0x2, 0x244, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x7, 
    0xb, 0x2, 0x2, 0x246, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x7, 0xc, 
    0x2, 0x2, 0x248, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x7, 0xd, 0x2, 
    0x2, 0x24a, 0x71, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x7, 0xe, 0x2, 0x2, 
    0x24c, 0x73, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x7, 0xf, 0x2, 0x2, 0x24e, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x1d, 0x2, 0x2, 0x250, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x7, 0x1e, 0x2, 0x2, 0x252, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x1e, 0x2, 0x2, 0x254, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x9, 0x2, 0x2, 0x2, 0x256, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x9, 0x2, 0x2, 0x2, 0x258, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x259, 0x25a, 0x9, 0x2, 0x2, 0x2, 0x25a, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x25b, 0x25c, 0x9, 0x2, 0x2, 0x2, 0x25c, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x25d, 0x25e, 0x7, 0x28, 0x2, 0x2, 0x25e, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x25f, 0x260, 0x7, 0x10, 0x2, 0x2, 0x260, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x261, 0x262, 0x7, 0x11, 0x2, 0x2, 0x262, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x263, 0x264, 0x7, 0x12, 0x2, 0x2, 0x264, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x265, 0x266, 0x7, 0x13, 0x2, 0x2, 0x266, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x267, 0x268, 0x7, 0x14, 0x2, 0x2, 0x268, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x269, 0x26a, 0x7, 0x15, 0x2, 0x2, 0x26a, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x26b, 0x26c, 0x7, 0x16, 0x2, 0x2, 0x26c, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x26d, 0x26e, 0x7, 0x17, 0x2, 0x2, 0x26e, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x26f, 0x270, 0x7, 0x18, 0x2, 0x2, 0x270, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x271, 0x272, 0x7, 0x19, 0x2, 0x2, 0x272, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x273, 0x274, 0x7, 0x1a, 0x2, 0x2, 0x274, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x275, 0x276, 0x9, 0x3, 0x2, 0x2, 0x276, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x27a, 0x5, 0xa0, 0x51, 0x2, 0x278, 0x27a, 0x5, 0xf4, 0x7b, 0x2, 
    0x279, 0x277, 0x3, 0x2, 0x2, 0x2, 0x279, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x27a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0x5, 0xa2, 0x52, 0x2, 
    0x27c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x283, 0x5, 0xa4, 0x53, 0x2, 
    0x27e, 0x283, 0x5, 0xa6, 0x54, 0x2, 0x27f, 0x283, 0x5, 0xa8, 0x55, 0x2, 
    0x280, 0x283, 0x5, 0xaa, 0x56, 0x2, 0x281, 0x283, 0x5, 0xac, 0x57, 0x2, 
    0x282, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x282, 0x27e, 0x3, 0x2, 0x2, 0x2, 
    0x282, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x282, 0x280, 0x3, 0x2, 0x2, 0x2, 
    0x282, 0x281, 0x3, 0x2, 0x2, 0x2, 0x283, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x284, 
    0x285, 0x7, 0x21, 0x2, 0x2, 0x285, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x286, 
    0x287, 0x7, 0x22, 0x2, 0x2, 0x287, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x288, 
    0x289, 0x9, 0x4, 0x2, 0x2, 0x289, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 
    0x7, 0x25, 0x2, 0x2, 0x28b, 0xab, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 
    0x5, 0xf6, 0x7c, 0x2, 0x28d, 0xad, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x295, 
    0x5, 0xbe, 0x60, 0x2, 0x28f, 0x295, 0x5, 0xc0, 0x61, 0x2, 0x290, 0x295, 
    0x5, 0xc4, 0x63, 0x2, 0x291, 0x295, 0x5, 0xc6, 0x64, 0x2, 0x292, 0x295, 
    0x5, 0xc2, 0x62, 0x2, 0x293, 0x295, 0x5, 0xc8, 0x65, 0x2, 0x294, 0x28e, 
    0x3, 0x2, 0x2, 0x2, 0x294, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x294, 0x290, 
    0x3, 0x2, 0x2, 0x2, 0x294, 0x291, 0x3, 0x2, 0x2, 0x2, 0x294, 0x292, 
    0x3, 0x2, 0x2, 0x2, 0x294, 0x293, 0x3, 0x2, 0x2, 0x2, 0x295, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x296, 0x297, 0x5, 0xc0, 0x61, 0x2, 0x297, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0x298, 0x29b, 0x5, 0xd6, 0x6c, 0x2, 0x299, 0x29b, 0x5, 
    0xd8, 0x6d, 0x2, 0x29a, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x299, 0x3, 
    0x2, 0x2, 0x2, 0x29b, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x5, 0xda, 
    0x6e, 0x2, 0x29d, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x2a5, 0x5, 0xca, 
    0x66, 0x2, 0x29f, 0x2a5, 0x5, 0xcc, 0x67, 0x2, 0x2a0, 0x2a5, 0x5, 0xce, 
    0x68, 0x2, 0x2a1, 0x2a5, 0x5, 0xd0, 0x69, 0x2, 0x2a2, 0x2a5, 0x5, 0xd2, 
    0x6a, 0x2, 0x2a3, 0x2a5, 0x5, 0xd4, 0x6b, 0x2, 0x2a4, 0x29e, 0x3, 0x2, 
    0x2, 0x2, 0x2a4, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a0, 0x3, 0x2, 
    0x2, 0x2, 0x2a4, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0x2a4, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x2a6, 0x2ae, 0x5, 0xdc, 0x6f, 0x2, 0x2a7, 0x2ae, 0x5, 0xde, 0x70, 
    0x2, 0x2a8, 0x2ae, 0x5, 0xe0, 0x71, 0x2, 0x2a9, 0x2ae, 0x5, 0xe4, 0x73, 
    0x2, 0x2aa, 0x2ae, 0x5, 0xe6, 0x74, 0x2, 0x2ab, 0x2ae, 0x5, 0xe8, 0x75, 
    0x2, 0x2ac, 0x2ae, 0x5, 0xea, 0x76, 0x2, 0x2ad, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0x2ad, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2a8, 0x3, 0x2, 0x2, 
    0x2, 0x2ad, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2aa, 0x3, 0x2, 0x2, 
    0x2, 0x2ad, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ac, 0x3, 0x2, 0x2, 
    0x2, 0x2ae, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x5, 0xe2, 0x72, 
    0x2, 0x2b0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x5, 0xca, 0x66, 
    0x2, 0x2b2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b4, 0x7, 0x29, 0x2, 
    0x2, 0x2b4, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x7, 0x2a, 0x2, 
    0x2, 0x2b6, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x7, 0x2b, 0x2, 
    0x2, 0x2b8, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x7, 0x2c, 0x2, 
    0x2, 0x2ba, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x2d, 0x2, 
    0x2, 0x2bc, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x7, 0x2e, 0x2, 
    0x2, 0x2be, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x7, 0x2f, 0x2, 
    0x2, 0x2c0, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0x30, 0x2, 
    0x2, 0x2c2, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x7, 0x31, 0x2, 
    0x2, 0x2c4, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x32, 0x2, 
    0x2, 0x2c6, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 0x7, 0x33, 0x2, 
    0x2, 0x2c8, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x34, 0x2, 
    0x2, 0x2ca, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x7, 0x35, 0x2, 
    0x2, 0x2cc, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x36, 0x2, 
    0x2, 0x2ce, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x37, 0x2, 
    0x2, 0x2d0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0x7, 0x38, 0x2, 
    0x2, 0x2d2, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x39, 0x2, 
    0x2, 0x2d4, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x7, 0x3a, 0x2, 
    0x2, 0x2d6, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x7, 0x3b, 0x2, 
    0x2, 0x2d8, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x7, 0x3c, 0x2, 
    0x2, 0x2da, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x7, 0x3d, 0x2, 
    0x2, 0x2dc, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x7, 0x3e, 0x2, 
    0x2, 0x2de, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x3f, 0x2, 
    0x2, 0x2e0, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x40, 0x2, 
    0x2, 0x2e2, 0xed, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e5, 0x7, 0x53, 0x2, 
    0x2, 0x2e4, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x3, 0x2, 0x2, 
    0x2, 0x2e5, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e8, 0x7, 0x54, 0x2, 
    0x2, 0x2e7, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x3, 0x2, 0x2, 
    0x2, 0x2e9, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ea, 0x3, 0x2, 0x2, 
    0x2, 0x2ea, 0xef, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ed, 0x5, 0xf8, 0x7d, 
    0x2, 0x2ec, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x3, 0x2, 0x2, 
    0x2, 0x2ed, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2f0, 0x7, 0x20, 0x2, 
    0x2, 0x2ef, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x3, 0x2, 0x2, 
    0x2, 0x2f0, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x54, 0x2, 
    0x2, 0x2f2, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f5, 0x5, 0xf8, 0x7d, 
    0x2, 0x2f4, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x3, 0x2, 0x2, 
    0x2, 0x2f5, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x7, 0x20, 0x2, 
    0x2, 0x2f7, 0x2f8, 0x7, 0x54, 0x2, 0x2, 0x2f8, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0x2f9, 0x2fa, 0x7, 0x27, 0x2, 0x2, 0x2fa, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0x2fb, 0x2fc, 0x7, 0x26, 0x2, 0x2, 0x2fc, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0x2fd, 0x2fe, 0x7, 0x53, 0x2, 0x2, 0x2fe, 0xf9, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0xfc, 0xfe, 0x105, 0x10a, 0x10f, 0x119, 0x12a, 0x133, 0x139, 
    0x149, 0x150, 0x158, 0x15d, 0x168, 0x16b, 0x16f, 0x17b, 0x186, 0x18b, 
    0x18f, 0x193, 0x198, 0x19d, 0x1a2, 0x1a6, 0x1b1, 0x1b3, 0x1c2, 0x1c4, 
    0x1cc, 0x1ce, 0x1d8, 0x1e0, 0x1ed, 0x1f5, 0x1fd, 0x200, 0x210, 0x216, 
    0x224, 0x233, 0x279, 0x282, 0x294, 0x29a, 0x2a4, 0x2ad, 0x2e4, 0x2e9, 
    0x2ec, 0x2ef, 0x2f4, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

zsharp_parserParser::Initializer zsharp_parserParser::_init;
