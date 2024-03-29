
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1


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

std::vector<zsharp_parserParser::SourceContext *> zsharp_parserParser::FileContext::source() {
  return getRuleContexts<zsharp_parserParser::SourceContext>();
}

zsharp_parserParser::SourceContext* zsharp_parserParser::FileContext::source(size_t i) {
  return getRuleContext<zsharp_parserParser::SourceContext>(i);
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
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::MODULE)
      | (1ULL << zsharp_parserParser::IMPORT)
      | (1ULL << zsharp_parserParser::EXPORT)
      | (1ULL << zsharp_parserParser::COMMENT))) != 0) || ((((_la - 77) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 77)) & ((1ULL << (zsharp_parserParser::IDENTIFIERupper - 77))
      | (1ULL << (zsharp_parserParser::IDENTIFIERlower - 77))
      | (1ULL << (zsharp_parserParser::INDENT - 77))
      | (1ULL << (zsharp_parserParser::EOL - 77)))) != 0)) {
      setState(192);
      source();
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(198);
    match(zsharp_parserParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceContext ------------------------------------------------------------------

zsharp_parserParser::SourceContext::SourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Module_statementContext* zsharp_parserParser::SourceContext::module_statement() {
  return getRuleContext<zsharp_parserParser::Module_statementContext>(0);
}

zsharp_parserParser::Definition_topContext* zsharp_parserParser::SourceContext::definition_top() {
  return getRuleContext<zsharp_parserParser::Definition_topContext>(0);
}

zsharp_parserParser::CommentContext* zsharp_parserParser::SourceContext::comment() {
  return getRuleContext<zsharp_parserParser::CommentContext>(0);
}

zsharp_parserParser::Empty_lineContext* zsharp_parserParser::SourceContext::empty_line() {
  return getRuleContext<zsharp_parserParser::Empty_lineContext>(0);
}


size_t zsharp_parserParser::SourceContext::getRuleIndex() const {
  return zsharp_parserParser::RuleSource;
}

void zsharp_parserParser::SourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSource(this);
}

void zsharp_parserParser::SourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSource(this);
}


antlrcpp::Any zsharp_parserParser::SourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitSource(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::SourceContext* zsharp_parserParser::source() {
  SourceContext *_localctx = _tracker.createInstance<SourceContext>(_ctx, getState());
  enterRule(_localctx, 2, zsharp_parserParser::RuleSource);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(200);
      module_statement();
      break;
    }

    case 2: {
      setState(201);
      definition_top();
      break;
    }

    case 3: {
      setState(202);
      comment();
      break;
    }

    case 4: {
      setState(203);
      empty_line();
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

//----------------- CodeblockContext ------------------------------------------------------------------

zsharp_parserParser::CodeblockContext::CodeblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Flow_statementContext *> zsharp_parserParser::CodeblockContext::flow_statement() {
  return getRuleContexts<zsharp_parserParser::Flow_statementContext>();
}

zsharp_parserParser::Flow_statementContext* zsharp_parserParser::CodeblockContext::flow_statement(size_t i) {
  return getRuleContext<zsharp_parserParser::Flow_statementContext>(i);
}

std::vector<zsharp_parserParser::Variable_assignContext *> zsharp_parserParser::CodeblockContext::variable_assign() {
  return getRuleContexts<zsharp_parserParser::Variable_assignContext>();
}

zsharp_parserParser::Variable_assignContext* zsharp_parserParser::CodeblockContext::variable_assign(size_t i) {
  return getRuleContext<zsharp_parserParser::Variable_assignContext>(i);
}

std::vector<zsharp_parserParser::Function_callContext *> zsharp_parserParser::CodeblockContext::function_call() {
  return getRuleContexts<zsharp_parserParser::Function_callContext>();
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::CodeblockContext::function_call(size_t i) {
  return getRuleContext<zsharp_parserParser::Function_callContext>(i);
}

std::vector<zsharp_parserParser::DefinitionContext *> zsharp_parserParser::CodeblockContext::definition() {
  return getRuleContexts<zsharp_parserParser::DefinitionContext>();
}

zsharp_parserParser::DefinitionContext* zsharp_parserParser::CodeblockContext::definition(size_t i) {
  return getRuleContext<zsharp_parserParser::DefinitionContext>(i);
}

std::vector<zsharp_parserParser::CommentContext *> zsharp_parserParser::CodeblockContext::comment() {
  return getRuleContexts<zsharp_parserParser::CommentContext>();
}

zsharp_parserParser::CommentContext* zsharp_parserParser::CodeblockContext::comment(size_t i) {
  return getRuleContext<zsharp_parserParser::CommentContext>(i);
}

std::vector<zsharp_parserParser::Empty_lineContext *> zsharp_parserParser::CodeblockContext::empty_line() {
  return getRuleContexts<zsharp_parserParser::Empty_lineContext>();
}

zsharp_parserParser::Empty_lineContext* zsharp_parserParser::CodeblockContext::empty_line(size_t i) {
  return getRuleContext<zsharp_parserParser::Empty_lineContext>(i);
}


size_t zsharp_parserParser::CodeblockContext::getRuleIndex() const {
  return zsharp_parserParser::RuleCodeblock;
}

void zsharp_parserParser::CodeblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeblock(this);
}

void zsharp_parserParser::CodeblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeblock(this);
}


antlrcpp::Any zsharp_parserParser::CodeblockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitCodeblock(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::CodeblockContext* zsharp_parserParser::codeblock() {
  CodeblockContext *_localctx = _tracker.createInstance<CodeblockContext>(_ctx, getState());
  enterRule(_localctx, 4, zsharp_parserParser::RuleCodeblock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(212); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(212);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
              case 1: {
                setState(206);
                flow_statement();
                break;
              }

              case 2: {
                setState(207);
                variable_assign();
                break;
              }

              case 3: {
                setState(208);
                function_call();
                break;
              }

              case 4: {
                setState(209);
                definition();
                break;
              }

              case 5: {
                setState(210);
                comment();
                break;
              }

              case 6: {
                setState(211);
                empty_line();
                break;
              }

              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(214); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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
    setState(219);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::MODULE: {
        enterOuterAlt(_localctx, 1);
        setState(216);
        statement_module();
        break;
      }

      case zsharp_parserParser::IMPORT: {
        enterOuterAlt(_localctx, 2);
        setState(217);
        statement_import();
        break;
      }

      case zsharp_parserParser::EXPORT: {
        enterOuterAlt(_localctx, 3);
        setState(218);
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
    setState(222);
    identifier_module();
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Module_nameContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleModule_name);
        setState(224);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(225);
        match(zsharp_parserParser::DOT);
        setState(226);
        identifier_module(); 
      }
      setState(231);
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

tree::TerminalNode* zsharp_parserParser::Statement_moduleContext::MODULE() {
  return getToken(zsharp_parserParser::MODULE, 0);
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
    setState(232);
    match(zsharp_parserParser::MODULE);
    setState(233);
    match(zsharp_parserParser::SP);
    setState(234);
    module_name(0);
    setState(235);
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

tree::TerminalNode* zsharp_parserParser::Statement_importContext::IMPORT() {
  return getToken(zsharp_parserParser::IMPORT, 0);
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
    setState(237);
    match(zsharp_parserParser::IMPORT);
    setState(238);
    match(zsharp_parserParser::SP);
    setState(239);
    module_name(0);
    setState(240);
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

tree::TerminalNode* zsharp_parserParser::Statement_exportContext::EXPORT() {
  return getToken(zsharp_parserParser::EXPORT, 0);
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
    setState(242);
    match(zsharp_parserParser::EXPORT);
    setState(243);
    match(zsharp_parserParser::SP);
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(244);
      identifier_func();
      break;
    }

    case 2: {
      setState(245);
      identifier_type();
      break;
    }

    }
    setState(248);
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

zsharp_parserParser::Statement_elseifContext* zsharp_parserParser::Flow_statementContext::statement_elseif() {
  return getRuleContext<zsharp_parserParser::Statement_elseifContext>(0);
}

zsharp_parserParser::Statement_loopContext* zsharp_parserParser::Flow_statementContext::statement_loop() {
  return getRuleContext<zsharp_parserParser::Statement_loopContext>(0);
}

zsharp_parserParser::Statement_returnContext* zsharp_parserParser::Flow_statementContext::statement_return() {
  return getRuleContext<zsharp_parserParser::Statement_returnContext>(0);
}

zsharp_parserParser::Statement_breakContext* zsharp_parserParser::Flow_statementContext::statement_break() {
  return getRuleContext<zsharp_parserParser::Statement_breakContext>(0);
}

zsharp_parserParser::Statement_continueContext* zsharp_parserParser::Flow_statementContext::statement_continue() {
  return getRuleContext<zsharp_parserParser::Statement_continueContext>(0);
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
    setState(257);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(250);
      statement_if();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(251);
      statement_else();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(252);
      statement_elseif();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(253);
      statement_loop();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(254);
      statement_return();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(255);
      statement_break();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(256);
      statement_continue();
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

tree::TerminalNode* zsharp_parserParser::Statement_returnContext::RETURN() {
  return getToken(zsharp_parserParser::RETURN, 0);
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
    setState(259);
    indent();
    setState(260);
    match(zsharp_parserParser::RETURN);
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SP) {
      setState(261);
      match(zsharp_parserParser::SP);
      setState(262);
      expression_value();
    }
    setState(265);
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

tree::TerminalNode* zsharp_parserParser::Statement_ifContext::IF() {
  return getToken(zsharp_parserParser::IF, 0);
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

zsharp_parserParser::CodeblockContext* zsharp_parserParser::Statement_ifContext::codeblock() {
  return getRuleContext<zsharp_parserParser::CodeblockContext>(0);
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
    setState(267);
    indent();
    setState(268);
    match(zsharp_parserParser::IF);
    setState(269);
    match(zsharp_parserParser::SP);
    setState(270);
    expression_logic(0);
    setState(271);
    newline();
    setState(272);
    codeblock();
   
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

tree::TerminalNode* zsharp_parserParser::Statement_elseContext::ELSE() {
  return getToken(zsharp_parserParser::ELSE, 0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_elseContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::CodeblockContext* zsharp_parserParser::Statement_elseContext::codeblock() {
  return getRuleContext<zsharp_parserParser::CodeblockContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    indent();
    setState(275);
    match(zsharp_parserParser::ELSE);
    setState(276);
    newline();
    setState(277);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_elseifContext ------------------------------------------------------------------

zsharp_parserParser::Statement_elseifContext::Statement_elseifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_elseifContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_elseifContext::ELSE() {
  return getToken(zsharp_parserParser::ELSE, 0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Statement_elseifContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Statement_elseifContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Statement_elseifContext::IF() {
  return getToken(zsharp_parserParser::IF, 0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Statement_elseifContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_elseifContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::CodeblockContext* zsharp_parserParser::Statement_elseifContext::codeblock() {
  return getRuleContext<zsharp_parserParser::CodeblockContext>(0);
}


size_t zsharp_parserParser::Statement_elseifContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_elseif;
}

void zsharp_parserParser::Statement_elseifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_elseif(this);
}

void zsharp_parserParser::Statement_elseifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_elseif(this);
}


antlrcpp::Any zsharp_parserParser::Statement_elseifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_elseif(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_elseifContext* zsharp_parserParser::statement_elseif() {
  Statement_elseifContext *_localctx = _tracker.createInstance<Statement_elseifContext>(_ctx, getState());
  enterRule(_localctx, 24, zsharp_parserParser::RuleStatement_elseif);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    indent();
    setState(280);
    match(zsharp_parserParser::ELSE);
    setState(281);
    match(zsharp_parserParser::SP);
    setState(282);
    match(zsharp_parserParser::IF);
    setState(283);
    match(zsharp_parserParser::SP);
    setState(284);
    expression_logic(0);
    setState(285);
    newline();
    setState(286);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_breakContext ------------------------------------------------------------------

zsharp_parserParser::Statement_breakContext::Statement_breakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_breakContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_breakContext::BREAK() {
  return getToken(zsharp_parserParser::BREAK, 0);
}


size_t zsharp_parserParser::Statement_breakContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_break;
}

void zsharp_parserParser::Statement_breakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_break(this);
}

void zsharp_parserParser::Statement_breakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_break(this);
}


antlrcpp::Any zsharp_parserParser::Statement_breakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_break(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_breakContext* zsharp_parserParser::statement_break() {
  Statement_breakContext *_localctx = _tracker.createInstance<Statement_breakContext>(_ctx, getState());
  enterRule(_localctx, 26, zsharp_parserParser::RuleStatement_break);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    indent();
    setState(289);
    match(zsharp_parserParser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_continueContext ------------------------------------------------------------------

zsharp_parserParser::Statement_continueContext::Statement_continueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_continueContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Statement_continueContext::CONTINUE() {
  return getToken(zsharp_parserParser::CONTINUE, 0);
}


size_t zsharp_parserParser::Statement_continueContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_continue;
}

void zsharp_parserParser::Statement_continueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_continue(this);
}

void zsharp_parserParser::Statement_continueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_continue(this);
}


antlrcpp::Any zsharp_parserParser::Statement_continueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_continue(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_continueContext* zsharp_parserParser::statement_continue() {
  Statement_continueContext *_localctx = _tracker.createInstance<Statement_continueContext>(_ctx, getState());
  enterRule(_localctx, 28, zsharp_parserParser::RuleStatement_continue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    indent();
    setState(292);
    match(zsharp_parserParser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_loopContext ------------------------------------------------------------------

zsharp_parserParser::Statement_loopContext::Statement_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Statement_loopContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Statement_loopContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::CodeblockContext* zsharp_parserParser::Statement_loopContext::codeblock() {
  return getRuleContext<zsharp_parserParser::CodeblockContext>(0);
}

zsharp_parserParser::Statement_loop_infiniteContext* zsharp_parserParser::Statement_loopContext::statement_loop_infinite() {
  return getRuleContext<zsharp_parserParser::Statement_loop_infiniteContext>(0);
}

zsharp_parserParser::Statement_loop_whileContext* zsharp_parserParser::Statement_loopContext::statement_loop_while() {
  return getRuleContext<zsharp_parserParser::Statement_loop_whileContext>(0);
}


size_t zsharp_parserParser::Statement_loopContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_loop;
}

void zsharp_parserParser::Statement_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_loop(this);
}

void zsharp_parserParser::Statement_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_loop(this);
}


antlrcpp::Any zsharp_parserParser::Statement_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_loop(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_loopContext* zsharp_parserParser::statement_loop() {
  Statement_loopContext *_localctx = _tracker.createInstance<Statement_loopContext>(_ctx, getState());
  enterRule(_localctx, 30, zsharp_parserParser::RuleStatement_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    indent();
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(295);
      statement_loop_infinite();
      break;
    }

    case 2: {
      setState(296);
      statement_loop_while();
      break;
    }

    }
    setState(299);
    newline();
    setState(300);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_loop_infiniteContext ------------------------------------------------------------------

zsharp_parserParser::Statement_loop_infiniteContext::Statement_loop_infiniteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Statement_loop_infiniteContext::LOOP() {
  return getToken(zsharp_parserParser::LOOP, 0);
}


size_t zsharp_parserParser::Statement_loop_infiniteContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_loop_infinite;
}

void zsharp_parserParser::Statement_loop_infiniteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_loop_infinite(this);
}

void zsharp_parserParser::Statement_loop_infiniteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_loop_infinite(this);
}


antlrcpp::Any zsharp_parserParser::Statement_loop_infiniteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_loop_infinite(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_loop_infiniteContext* zsharp_parserParser::statement_loop_infinite() {
  Statement_loop_infiniteContext *_localctx = _tracker.createInstance<Statement_loop_infiniteContext>(_ctx, getState());
  enterRule(_localctx, 32, zsharp_parserParser::RuleStatement_loop_infinite);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(zsharp_parserParser::LOOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_loop_whileContext ------------------------------------------------------------------

zsharp_parserParser::Statement_loop_whileContext::Statement_loop_whileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Statement_loop_whileContext::LOOP() {
  return getToken(zsharp_parserParser::LOOP, 0);
}

tree::TerminalNode* zsharp_parserParser::Statement_loop_whileContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Statement_loop_whileContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
}


size_t zsharp_parserParser::Statement_loop_whileContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStatement_loop_while;
}

void zsharp_parserParser::Statement_loop_whileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_loop_while(this);
}

void zsharp_parserParser::Statement_loop_whileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_loop_while(this);
}


antlrcpp::Any zsharp_parserParser::Statement_loop_whileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStatement_loop_while(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Statement_loop_whileContext* zsharp_parserParser::statement_loop_while() {
  Statement_loop_whileContext *_localctx = _tracker.createInstance<Statement_loop_whileContext>(_ctx, getState());
  enterRule(_localctx, 34, zsharp_parserParser::RuleStatement_loop_while);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(zsharp_parserParser::LOOP);
    setState(305);
    match(zsharp_parserParser::SP);
    setState(306);
    expression_logic(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definition_topContext ------------------------------------------------------------------

zsharp_parserParser::Definition_topContext::Definition_topContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Function_def_exportContext* zsharp_parserParser::Definition_topContext::function_def_export() {
  return getRuleContext<zsharp_parserParser::Function_def_exportContext>(0);
}

zsharp_parserParser::Function_defContext* zsharp_parserParser::Definition_topContext::function_def() {
  return getRuleContext<zsharp_parserParser::Function_defContext>(0);
}

zsharp_parserParser::Enum_defContext* zsharp_parserParser::Definition_topContext::enum_def() {
  return getRuleContext<zsharp_parserParser::Enum_defContext>(0);
}

zsharp_parserParser::Struct_defContext* zsharp_parserParser::Definition_topContext::struct_def() {
  return getRuleContext<zsharp_parserParser::Struct_defContext>(0);
}

zsharp_parserParser::Type_defContext* zsharp_parserParser::Definition_topContext::type_def() {
  return getRuleContext<zsharp_parserParser::Type_defContext>(0);
}

zsharp_parserParser::Type_aliasContext* zsharp_parserParser::Definition_topContext::type_alias() {
  return getRuleContext<zsharp_parserParser::Type_aliasContext>(0);
}

zsharp_parserParser::Variable_def_topContext* zsharp_parserParser::Definition_topContext::variable_def_top() {
  return getRuleContext<zsharp_parserParser::Variable_def_topContext>(0);
}


size_t zsharp_parserParser::Definition_topContext::getRuleIndex() const {
  return zsharp_parserParser::RuleDefinition_top;
}

void zsharp_parserParser::Definition_topContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinition_top(this);
}

void zsharp_parserParser::Definition_topContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinition_top(this);
}


antlrcpp::Any zsharp_parserParser::Definition_topContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitDefinition_top(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Definition_topContext* zsharp_parserParser::definition_top() {
  Definition_topContext *_localctx = _tracker.createInstance<Definition_topContext>(_ctx, getState());
  enterRule(_localctx, 36, zsharp_parserParser::RuleDefinition_top);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
      function_def_export();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(309);
      function_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(310);
      enum_def();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(311);
      struct_def();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(312);
      type_def();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(313);
      type_alias();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(314);
      variable_def_top();
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

//----------------- DefinitionContext ------------------------------------------------------------------

zsharp_parserParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Variable_defContext* zsharp_parserParser::DefinitionContext::variable_def() {
  return getRuleContext<zsharp_parserParser::Variable_defContext>(0);
}


size_t zsharp_parserParser::DefinitionContext::getRuleIndex() const {
  return zsharp_parserParser::RuleDefinition;
}

void zsharp_parserParser::DefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinition(this);
}

void zsharp_parserParser::DefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinition(this);
}


antlrcpp::Any zsharp_parserParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::DefinitionContext* zsharp_parserParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 38, zsharp_parserParser::RuleDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    variable_def();
   
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

zsharp_parserParser::Expression_arithmeticContext* zsharp_parserParser::Expression_valueContext::expression_arithmetic() {
  return getRuleContext<zsharp_parserParser::Expression_arithmeticContext>(0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Expression_valueContext::expression_logic() {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(0);
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
  enterRule(_localctx, 40, zsharp_parserParser::RuleExpression_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(319);
      number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(320);
      string();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(321);
      expression_bool();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(322);
      expression_arithmetic(0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(323);
      expression_logic(0);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(324);
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
  enterRule(_localctx, 42, zsharp_parserParser::RuleComptime_expression_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        number();
        break;
      }

      case zsharp_parserParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(328);
        string();
        break;
      }

      case zsharp_parserParser::TRUE:
      case zsharp_parserParser::FALSE:
      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 3);
        setState(329);
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

//----------------- Expression_arithmeticContext ------------------------------------------------------------------

zsharp_parserParser::Expression_arithmeticContext::Expression_arithmeticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Expression_arithmeticContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

std::vector<zsharp_parserParser::Expression_arithmeticContext *> zsharp_parserParser::Expression_arithmeticContext::expression_arithmetic() {
  return getRuleContexts<zsharp_parserParser::Expression_arithmeticContext>();
}

zsharp_parserParser::Expression_arithmeticContext* zsharp_parserParser::Expression_arithmeticContext::expression_arithmetic(size_t i) {
  return getRuleContext<zsharp_parserParser::Expression_arithmeticContext>(i);
}

tree::TerminalNode* zsharp_parserParser::Expression_arithmeticContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

zsharp_parserParser::Operator_arithmetic_unaryContext* zsharp_parserParser::Expression_arithmeticContext::operator_arithmetic_unary() {
  return getRuleContext<zsharp_parserParser::Operator_arithmetic_unaryContext>(0);
}

zsharp_parserParser::Operator_bits_unaryContext* zsharp_parserParser::Expression_arithmeticContext::operator_bits_unary() {
  return getRuleContext<zsharp_parserParser::Operator_bits_unaryContext>(0);
}

zsharp_parserParser::Arithmetic_operandContext* zsharp_parserParser::Expression_arithmeticContext::arithmetic_operand() {
  return getRuleContext<zsharp_parserParser::Arithmetic_operandContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Expression_arithmeticContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Expression_arithmeticContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

zsharp_parserParser::Operator_arithmeticContext* zsharp_parserParser::Expression_arithmeticContext::operator_arithmetic() {
  return getRuleContext<zsharp_parserParser::Operator_arithmeticContext>(0);
}

zsharp_parserParser::Operator_bitsContext* zsharp_parserParser::Expression_arithmeticContext::operator_bits() {
  return getRuleContext<zsharp_parserParser::Operator_bitsContext>(0);
}


size_t zsharp_parserParser::Expression_arithmeticContext::getRuleIndex() const {
  return zsharp_parserParser::RuleExpression_arithmetic;
}

void zsharp_parserParser::Expression_arithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_arithmetic(this);
}

void zsharp_parserParser::Expression_arithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_arithmetic(this);
}


antlrcpp::Any zsharp_parserParser::Expression_arithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitExpression_arithmetic(this);
  else
    return visitor->visitChildren(this);
}


zsharp_parserParser::Expression_arithmeticContext* zsharp_parserParser::expression_arithmetic() {
   return expression_arithmetic(0);
}

zsharp_parserParser::Expression_arithmeticContext* zsharp_parserParser::expression_arithmetic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zsharp_parserParser::Expression_arithmeticContext *_localctx = _tracker.createInstance<Expression_arithmeticContext>(_ctx, parentState);
  zsharp_parserParser::Expression_arithmeticContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, zsharp_parserParser::RuleExpression_arithmetic, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::PARENopen: {
        setState(333);
        match(zsharp_parserParser::PARENopen);
        setState(334);
        expression_arithmetic(0);
        setState(335);
        match(zsharp_parserParser::PARENclose);
        break;
      }

      case zsharp_parserParser::MINUS_NEG: {
        setState(337);
        operator_arithmetic_unary();
        setState(338);
        expression_arithmetic(3);
        break;
      }

      case zsharp_parserParser::BIT_NOT: {
        setState(340);
        operator_bits_unary();
        setState(341);
        expression_arithmetic(2);
        break;
      }

      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER:
      case zsharp_parserParser::IDENTIFIERlower:
      case zsharp_parserParser::INDENT: {
        setState(343);
        arithmetic_operand();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(360);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(358);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Expression_arithmeticContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression_arithmetic);
          setState(346);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(347);
          match(zsharp_parserParser::SP);
          setState(348);
          operator_arithmetic();
          setState(349);
          match(zsharp_parserParser::SP);
          setState(350);
          expression_arithmetic(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Expression_arithmeticContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression_arithmetic);
          setState(352);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(353);
          match(zsharp_parserParser::SP);
          setState(354);
          operator_bits();
          setState(355);
          match(zsharp_parserParser::SP);
          setState(356);
          expression_arithmetic(6);
          break;
        }

        } 
      }
      setState(362);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Arithmetic_operandContext ------------------------------------------------------------------

zsharp_parserParser::Arithmetic_operandContext::Arithmetic_operandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Arithmetic_operandContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::Arithmetic_operandContext::variable_ref() {
  return getRuleContext<zsharp_parserParser::Variable_refContext>(0);
}

zsharp_parserParser::Function_callContext* zsharp_parserParser::Arithmetic_operandContext::function_call() {
  return getRuleContext<zsharp_parserParser::Function_callContext>(0);
}


size_t zsharp_parserParser::Arithmetic_operandContext::getRuleIndex() const {
  return zsharp_parserParser::RuleArithmetic_operand;
}

void zsharp_parserParser::Arithmetic_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_operand(this);
}

void zsharp_parserParser::Arithmetic_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_operand(this);
}


antlrcpp::Any zsharp_parserParser::Arithmetic_operandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_operand(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Arithmetic_operandContext* zsharp_parserParser::arithmetic_operand() {
  Arithmetic_operandContext *_localctx = _tracker.createInstance<Arithmetic_operandContext>(_ctx, getState());
  enterRule(_localctx, 46, zsharp_parserParser::RuleArithmetic_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(363);
        number();
        break;
      }

      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 2);
        setState(364);
        variable_ref();
        break;
      }

      case zsharp_parserParser::INDENT: {
        enterOuterAlt(_localctx, 3);
        setState(365);
        function_call();
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

tree::TerminalNode* zsharp_parserParser::Expression_logicContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

std::vector<zsharp_parserParser::Expression_logicContext *> zsharp_parserParser::Expression_logicContext::expression_logic() {
  return getRuleContexts<zsharp_parserParser::Expression_logicContext>();
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::Expression_logicContext::expression_logic(size_t i) {
  return getRuleContext<zsharp_parserParser::Expression_logicContext>(i);
}

tree::TerminalNode* zsharp_parserParser::Expression_logicContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

zsharp_parserParser::Operator_logic_unaryContext* zsharp_parserParser::Expression_logicContext::operator_logic_unary() {
  return getRuleContext<zsharp_parserParser::Operator_logic_unaryContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Expression_logicContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Expression_logicContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

zsharp_parserParser::Logic_operandContext* zsharp_parserParser::Expression_logicContext::logic_operand() {
  return getRuleContext<zsharp_parserParser::Logic_operandContext>(0);
}

zsharp_parserParser::Operator_logicContext* zsharp_parserParser::Expression_logicContext::operator_logic() {
  return getRuleContext<zsharp_parserParser::Operator_logicContext>(0);
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
   return expression_logic(0);
}

zsharp_parserParser::Expression_logicContext* zsharp_parserParser::expression_logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zsharp_parserParser::Expression_logicContext *_localctx = _tracker.createInstance<Expression_logicContext>(_ctx, parentState);
  zsharp_parserParser::Expression_logicContext *previousContext = _localctx;
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, zsharp_parserParser::RuleExpression_logic, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(369);
      match(zsharp_parserParser::PARENopen);
      setState(370);
      expression_logic(0);
      setState(371);
      match(zsharp_parserParser::PARENclose);
      break;
    }

    case 2: {
      setState(373);
      operator_logic_unary();
      setState(374);
      match(zsharp_parserParser::SP);
      setState(375);
      expression_logic(2);
      break;
    }

    case 3: {
      setState(377);
      logic_operand();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expression_logicContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression_logic);
        setState(380);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(381);
        match(zsharp_parserParser::SP);
        setState(382);
        operator_logic();
        setState(383);
        match(zsharp_parserParser::SP);
        setState(384);
        expression_logic(5); 
      }
      setState(390);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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
  enterRule(_localctx, 50, zsharp_parserParser::RuleLogic_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(391);
      expression_comparison(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(392);
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

tree::TerminalNode* zsharp_parserParser::Expression_comparisonContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

std::vector<zsharp_parserParser::Expression_comparisonContext *> zsharp_parserParser::Expression_comparisonContext::expression_comparison() {
  return getRuleContexts<zsharp_parserParser::Expression_comparisonContext>();
}

zsharp_parserParser::Expression_comparisonContext* zsharp_parserParser::Expression_comparisonContext::expression_comparison(size_t i) {
  return getRuleContext<zsharp_parserParser::Expression_comparisonContext>(i);
}

tree::TerminalNode* zsharp_parserParser::Expression_comparisonContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

zsharp_parserParser::Comparison_operandContext* zsharp_parserParser::Expression_comparisonContext::comparison_operand() {
  return getRuleContext<zsharp_parserParser::Comparison_operandContext>(0);
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
   return expression_comparison(0);
}

zsharp_parserParser::Expression_comparisonContext* zsharp_parserParser::expression_comparison(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zsharp_parserParser::Expression_comparisonContext *_localctx = _tracker.createInstance<Expression_comparisonContext>(_ctx, parentState);
  zsharp_parserParser::Expression_comparisonContext *previousContext = _localctx;
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, zsharp_parserParser::RuleExpression_comparison, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(401);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(396);
      match(zsharp_parserParser::PARENopen);
      setState(397);
      expression_comparison(0);
      setState(398);
      match(zsharp_parserParser::PARENclose);
      break;
    }

    case 2: {
      setState(400);
      comparison_operand();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(411);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expression_comparisonContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression_comparison);
        setState(403);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(404);
        match(zsharp_parserParser::SP);
        setState(405);
        operator_comparison();
        setState(406);
        match(zsharp_parserParser::SP);
        setState(407);
        expression_comparison(4); 
      }
      setState(413);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
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

zsharp_parserParser::Expression_arithmeticContext* zsharp_parserParser::Comparison_operandContext::expression_arithmetic() {
  return getRuleContext<zsharp_parserParser::Expression_arithmeticContext>(0);
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
  enterRule(_localctx, 54, zsharp_parserParser::RuleComparison_operand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(418);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(414);
      expression_arithmetic(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(415);
      function_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(416);
      variable_ref();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(417);
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

//----------------- Expression_boolContext ------------------------------------------------------------------

zsharp_parserParser::Expression_boolContext::Expression_boolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Literal_boolContext* zsharp_parserParser::Expression_boolContext::literal_bool() {
  return getRuleContext<zsharp_parserParser::Literal_boolContext>(0);
}

zsharp_parserParser::Variable_refContext* zsharp_parserParser::Expression_boolContext::variable_ref() {
  return getRuleContext<zsharp_parserParser::Variable_refContext>(0);
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
  enterRule(_localctx, 56, zsharp_parserParser::RuleExpression_bool);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::TRUE:
      case zsharp_parserParser::FALSE: {
        enterOuterAlt(_localctx, 1);
        setState(420);
        literal_bool();
        break;
      }

      case zsharp_parserParser::IDENTIFIERlower: {
        enterOuterAlt(_localctx, 2);
        setState(421);
        variable_ref();
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

//----------------- Function_callContext ------------------------------------------------------------------

zsharp_parserParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Function_callContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
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

zsharp_parserParser::NewlineContext* zsharp_parserParser::Function_callContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
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
  enterRule(_localctx, 58, zsharp_parserParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    indent();
    setState(425);
    identifier_func();
    setState(426);
    match(zsharp_parserParser::PARENopen);
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 26) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 26)) & ((1ULL << (zsharp_parserParser::TRUE - 26))
      | (1ULL << (zsharp_parserParser::FALSE - 26))
      | (1ULL << (zsharp_parserParser::NUMBERbin - 26))
      | (1ULL << (zsharp_parserParser::NUMBERoct - 26))
      | (1ULL << (zsharp_parserParser::NUMBERdec - 26))
      | (1ULL << (zsharp_parserParser::NUMBERdec_prefix - 26))
      | (1ULL << (zsharp_parserParser::NUMBERhex - 26))
      | (1ULL << (zsharp_parserParser::CHARACTER - 26))
      | (1ULL << (zsharp_parserParser::STRING - 26))
      | (1ULL << (zsharp_parserParser::MINUS_NEG - 26))
      | (1ULL << (zsharp_parserParser::NOT - 26))
      | (1ULL << (zsharp_parserParser::BIT_NOT - 26))
      | (1ULL << (zsharp_parserParser::PARENopen - 26))
      | (1ULL << (zsharp_parserParser::IDENTIFIERlower - 26))
      | (1ULL << (zsharp_parserParser::INDENT - 26)))) != 0)) {
      setState(427);
      function_parameter_uselist();
    }
    setState(430);
    match(zsharp_parserParser::PARENclose);
    setState(431);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_defContext ------------------------------------------------------------------

zsharp_parserParser::Function_defContext::Function_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_funcContext* zsharp_parserParser::Function_defContext::identifier_func() {
  return getRuleContext<zsharp_parserParser::Identifier_funcContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Function_defContext::PARENopen() {
  return getToken(zsharp_parserParser::PARENopen, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_defContext::PARENclose() {
  return getToken(zsharp_parserParser::PARENclose, 0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Function_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::CodeblockContext* zsharp_parserParser::Function_defContext::codeblock() {
  return getRuleContext<zsharp_parserParser::CodeblockContext>(0);
}

zsharp_parserParser::Function_parameter_listContext* zsharp_parserParser::Function_defContext::function_parameter_list() {
  return getRuleContext<zsharp_parserParser::Function_parameter_listContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Function_defContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}


size_t zsharp_parserParser::Function_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_def;
}

void zsharp_parserParser::Function_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_def(this);
}

void zsharp_parserParser::Function_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_def(this);
}


antlrcpp::Any zsharp_parserParser::Function_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_defContext* zsharp_parserParser::function_def() {
  Function_defContext *_localctx = _tracker.createInstance<Function_defContext>(_ctx, getState());
  enterRule(_localctx, 60, zsharp_parserParser::RuleFunction_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    identifier_func();
    setState(434);
    match(zsharp_parserParser::PARENopen);
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SELF

    || _la == zsharp_parserParser::IDENTIFIERlower) {
      setState(435);
      function_parameter_list();
    }
    setState(438);
    match(zsharp_parserParser::PARENclose);
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(439);
      type_ref_use();
    }
    setState(442);
    newline();
    setState(443);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_def_exportContext ------------------------------------------------------------------

zsharp_parserParser::Function_def_exportContext::Function_def_exportContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Function_def_exportContext::EXPORT() {
  return getToken(zsharp_parserParser::EXPORT, 0);
}

tree::TerminalNode* zsharp_parserParser::Function_def_exportContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Function_defContext* zsharp_parserParser::Function_def_exportContext::function_def() {
  return getRuleContext<zsharp_parserParser::Function_defContext>(0);
}


size_t zsharp_parserParser::Function_def_exportContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_def_export;
}

void zsharp_parserParser::Function_def_exportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_def_export(this);
}

void zsharp_parserParser::Function_def_exportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_def_export(this);
}


antlrcpp::Any zsharp_parserParser::Function_def_exportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_def_export(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_def_exportContext* zsharp_parserParser::function_def_export() {
  Function_def_exportContext *_localctx = _tracker.createInstance<Function_def_exportContext>(_ctx, getState());
  enterRule(_localctx, 62, zsharp_parserParser::RuleFunction_def_export);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    match(zsharp_parserParser::EXPORT);
    setState(446);
    match(zsharp_parserParser::SP);
    setState(447);
    function_def();
   
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

zsharp_parserParser::Function_parameter_selfContext* zsharp_parserParser::Function_parameter_listContext::function_parameter_self() {
  return getRuleContext<zsharp_parserParser::Function_parameter_selfContext>(0);
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
  enterRule(_localctx, 64, zsharp_parserParser::RuleFunction_parameter_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::IDENTIFIERlower: {
        setState(449);
        function_parameter();
        break;
      }

      case zsharp_parserParser::SELF: {
        setState(450);
        function_parameter_self();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(458);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zsharp_parserParser::COMMA) {
      setState(453);
      match(zsharp_parserParser::COMMA);
      setState(454);
      match(zsharp_parserParser::SP);
      setState(455);
      function_parameter();
      setState(460);
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

//----------------- Function_parameterContext ------------------------------------------------------------------

zsharp_parserParser::Function_parameterContext::Function_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_paramContext* zsharp_parserParser::Function_parameterContext::identifier_param() {
  return getRuleContext<zsharp_parserParser::Identifier_paramContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Function_parameterContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
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
  enterRule(_localctx, 66, zsharp_parserParser::RuleFunction_parameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    identifier_param();
    setState(462);
    type_ref_use();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_parameter_selfContext ------------------------------------------------------------------

zsharp_parserParser::Function_parameter_selfContext::Function_parameter_selfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Function_parameter_selfContext::SELF() {
  return getToken(zsharp_parserParser::SELF, 0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Function_parameter_selfContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}


size_t zsharp_parserParser::Function_parameter_selfContext::getRuleIndex() const {
  return zsharp_parserParser::RuleFunction_parameter_self;
}

void zsharp_parserParser::Function_parameter_selfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_parameter_self(this);
}

void zsharp_parserParser::Function_parameter_selfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_parameter_self(this);
}


antlrcpp::Any zsharp_parserParser::Function_parameter_selfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_parameter_self(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Function_parameter_selfContext* zsharp_parserParser::function_parameter_self() {
  Function_parameter_selfContext *_localctx = _tracker.createInstance<Function_parameter_selfContext>(_ctx, getState());
  enterRule(_localctx, 68, zsharp_parserParser::RuleFunction_parameter_self);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(464);
    match(zsharp_parserParser::SELF);
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(465);
      type_ref_use();
    }
   
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
  enterRule(_localctx, 70, zsharp_parserParser::RuleFunction_parameter_uselist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    function_param_use();
    setState(474);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zsharp_parserParser::COMMA) {
      setState(469);
      match(zsharp_parserParser::COMMA);
      setState(470);
      match(zsharp_parserParser::SP);
      setState(471);
      function_param_use();
      setState(476);
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
  enterRule(_localctx, 72, zsharp_parserParser::RuleFunction_param_use);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(477);
    expression_value();
    setState(483);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(478);
        match(zsharp_parserParser::COMMA);
        setState(479);
        match(zsharp_parserParser::SP);
        setState(480);
        expression_value(); 
      }
      setState(485);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
  enterRule(_localctx, 74, zsharp_parserParser::RuleVariable_ref);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    identifier_var();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_def_topContext ------------------------------------------------------------------

zsharp_parserParser::Variable_def_topContext::Variable_def_topContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Variable_def_topContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Variable_def_typedContext* zsharp_parserParser::Variable_def_topContext::variable_def_typed() {
  return getRuleContext<zsharp_parserParser::Variable_def_typedContext>(0);
}

zsharp_parserParser::Variable_def_typed_initContext* zsharp_parserParser::Variable_def_topContext::variable_def_typed_init() {
  return getRuleContext<zsharp_parserParser::Variable_def_typed_initContext>(0);
}

zsharp_parserParser::Variable_assign_autoContext* zsharp_parserParser::Variable_def_topContext::variable_assign_auto() {
  return getRuleContext<zsharp_parserParser::Variable_assign_autoContext>(0);
}


size_t zsharp_parserParser::Variable_def_topContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_def_top;
}

void zsharp_parserParser::Variable_def_topContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_def_top(this);
}

void zsharp_parserParser::Variable_def_topContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_def_top(this);
}


antlrcpp::Any zsharp_parserParser::Variable_def_topContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_def_top(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_def_topContext* zsharp_parserParser::variable_def_top() {
  Variable_def_topContext *_localctx = _tracker.createInstance<Variable_def_topContext>(_ctx, getState());
  enterRule(_localctx, 76, zsharp_parserParser::RuleVariable_def_top);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(488);
      variable_def_typed();
      break;
    }

    case 2: {
      setState(489);
      variable_def_typed_init();
      break;
    }

    case 3: {
      setState(490);
      variable_assign_auto();
      break;
    }

    }
    setState(493);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_defContext ------------------------------------------------------------------

zsharp_parserParser::Variable_defContext::Variable_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Variable_defContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Variable_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Variable_def_typedContext* zsharp_parserParser::Variable_defContext::variable_def_typed() {
  return getRuleContext<zsharp_parserParser::Variable_def_typedContext>(0);
}

zsharp_parserParser::Variable_def_typed_initContext* zsharp_parserParser::Variable_defContext::variable_def_typed_init() {
  return getRuleContext<zsharp_parserParser::Variable_def_typed_initContext>(0);
}

zsharp_parserParser::Variable_assign_autoContext* zsharp_parserParser::Variable_defContext::variable_assign_auto() {
  return getRuleContext<zsharp_parserParser::Variable_assign_autoContext>(0);
}


size_t zsharp_parserParser::Variable_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_def;
}

void zsharp_parserParser::Variable_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_def(this);
}

void zsharp_parserParser::Variable_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_def(this);
}


antlrcpp::Any zsharp_parserParser::Variable_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_defContext* zsharp_parserParser::variable_def() {
  Variable_defContext *_localctx = _tracker.createInstance<Variable_defContext>(_ctx, getState());
  enterRule(_localctx, 78, zsharp_parserParser::RuleVariable_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    indent();
    setState(499);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(496);
      variable_def_typed();
      break;
    }

    case 2: {
      setState(497);
      variable_def_typed_init();
      break;
    }

    case 3: {
      setState(498);
      variable_assign_auto();
      break;
    }

    }
    setState(501);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_def_typedContext ------------------------------------------------------------------

zsharp_parserParser::Variable_def_typedContext::Variable_def_typedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_varContext* zsharp_parserParser::Variable_def_typedContext::identifier_var() {
  return getRuleContext<zsharp_parserParser::Identifier_varContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Variable_def_typedContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}


size_t zsharp_parserParser::Variable_def_typedContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_def_typed;
}

void zsharp_parserParser::Variable_def_typedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_def_typed(this);
}

void zsharp_parserParser::Variable_def_typedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_def_typed(this);
}


antlrcpp::Any zsharp_parserParser::Variable_def_typedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_def_typed(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_def_typedContext* zsharp_parserParser::variable_def_typed() {
  Variable_def_typedContext *_localctx = _tracker.createInstance<Variable_def_typedContext>(_ctx, getState());
  enterRule(_localctx, 80, zsharp_parserParser::RuleVariable_def_typed);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    identifier_var();
    setState(504);
    type_ref_use();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_def_typed_initContext ------------------------------------------------------------------

zsharp_parserParser::Variable_def_typed_initContext::Variable_def_typed_initContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_varContext* zsharp_parserParser::Variable_def_typed_initContext::identifier_var() {
  return getRuleContext<zsharp_parserParser::Identifier_varContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Variable_def_typed_initContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Variable_def_typed_initContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Variable_def_typed_initContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Variable_def_typed_initContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

zsharp_parserParser::Expression_valueContext* zsharp_parserParser::Variable_def_typed_initContext::expression_value() {
  return getRuleContext<zsharp_parserParser::Expression_valueContext>(0);
}


size_t zsharp_parserParser::Variable_def_typed_initContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_def_typed_init;
}

void zsharp_parserParser::Variable_def_typed_initContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_def_typed_init(this);
}

void zsharp_parserParser::Variable_def_typed_initContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_def_typed_init(this);
}


antlrcpp::Any zsharp_parserParser::Variable_def_typed_initContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_def_typed_init(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_def_typed_initContext* zsharp_parserParser::variable_def_typed_init() {
  Variable_def_typed_initContext *_localctx = _tracker.createInstance<Variable_def_typed_initContext>(_ctx, getState());
  enterRule(_localctx, 82, zsharp_parserParser::RuleVariable_def_typed_init);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(506);
    identifier_var();
    setState(507);
    type_ref_use();
    setState(508);
    match(zsharp_parserParser::SP);
    setState(509);
    match(zsharp_parserParser::EQ_ASSIGN);
    setState(510);
    match(zsharp_parserParser::SP);
    setState(511);
    expression_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_assign_autoContext ------------------------------------------------------------------

zsharp_parserParser::Variable_assign_autoContext::Variable_assign_autoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_varContext* zsharp_parserParser::Variable_assign_autoContext::identifier_var() {
  return getRuleContext<zsharp_parserParser::Identifier_varContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Variable_assign_autoContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Variable_assign_autoContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Variable_assign_autoContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

zsharp_parserParser::Expression_valueContext* zsharp_parserParser::Variable_assign_autoContext::expression_value() {
  return getRuleContext<zsharp_parserParser::Expression_valueContext>(0);
}


size_t zsharp_parserParser::Variable_assign_autoContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_assign_auto;
}

void zsharp_parserParser::Variable_assign_autoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_assign_auto(this);
}

void zsharp_parserParser::Variable_assign_autoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_assign_auto(this);
}


antlrcpp::Any zsharp_parserParser::Variable_assign_autoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_assign_auto(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_assign_autoContext* zsharp_parserParser::variable_assign_auto() {
  Variable_assign_autoContext *_localctx = _tracker.createInstance<Variable_assign_autoContext>(_ctx, getState());
  enterRule(_localctx, 84, zsharp_parserParser::RuleVariable_assign_auto);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    identifier_var();
    setState(514);
    match(zsharp_parserParser::SP);
    setState(515);
    match(zsharp_parserParser::EQ_ASSIGN);
    setState(516);
    match(zsharp_parserParser::SP);
    setState(517);
    expression_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_assignContext ------------------------------------------------------------------

zsharp_parserParser::Variable_assignContext::Variable_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Variable_assignContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Variable_assign_autoContext* zsharp_parserParser::Variable_assignContext::variable_assign_auto() {
  return getRuleContext<zsharp_parserParser::Variable_assign_autoContext>(0);
}


size_t zsharp_parserParser::Variable_assignContext::getRuleIndex() const {
  return zsharp_parserParser::RuleVariable_assign;
}

void zsharp_parserParser::Variable_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_assign(this);
}

void zsharp_parserParser::Variable_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_assign(this);
}


antlrcpp::Any zsharp_parserParser::Variable_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitVariable_assign(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Variable_assignContext* zsharp_parserParser::variable_assign() {
  Variable_assignContext *_localctx = _tracker.createInstance<Variable_assignContext>(_ctx, getState());
  enterRule(_localctx, 86, zsharp_parserParser::RuleVariable_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    indent();
    setState(520);
    variable_assign_auto();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_defContext ------------------------------------------------------------------

zsharp_parserParser::Struct_defContext::Struct_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Struct_defContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Struct_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Struct_field_def_listContext* zsharp_parserParser::Struct_defContext::struct_field_def_list() {
  return getRuleContext<zsharp_parserParser::Struct_field_def_listContext>(0);
}

zsharp_parserParser::Type_param_listContext* zsharp_parserParser::Struct_defContext::type_param_list() {
  return getRuleContext<zsharp_parserParser::Type_param_listContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Struct_defContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}


size_t zsharp_parserParser::Struct_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_def;
}

void zsharp_parserParser::Struct_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_def(this);
}

void zsharp_parserParser::Struct_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_def(this);
}


antlrcpp::Any zsharp_parserParser::Struct_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_defContext* zsharp_parserParser::struct_def() {
  Struct_defContext *_localctx = _tracker.createInstance<Struct_defContext>(_ctx, getState());
  enterRule(_localctx, 88, zsharp_parserParser::RuleStruct_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    identifier_type();
    setState(524);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SMALL_ANGLEopen) {
      setState(523);
      type_param_list();
    }
    setState(527);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(526);
      type_ref_use();
    }

    setState(529);
    newline();
    setState(530);
    struct_field_def_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_field_def_listContext ------------------------------------------------------------------

zsharp_parserParser::Struct_field_def_listContext::Struct_field_def_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Struct_field_defContext *> zsharp_parserParser::Struct_field_def_listContext::struct_field_def() {
  return getRuleContexts<zsharp_parserParser::Struct_field_defContext>();
}

zsharp_parserParser::Struct_field_defContext* zsharp_parserParser::Struct_field_def_listContext::struct_field_def(size_t i) {
  return getRuleContext<zsharp_parserParser::Struct_field_defContext>(i);
}


size_t zsharp_parserParser::Struct_field_def_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_field_def_list;
}

void zsharp_parserParser::Struct_field_def_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_field_def_list(this);
}

void zsharp_parserParser::Struct_field_def_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_field_def_list(this);
}


antlrcpp::Any zsharp_parserParser::Struct_field_def_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_field_def_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_field_def_listContext* zsharp_parserParser::struct_field_def_list() {
  Struct_field_def_listContext *_localctx = _tracker.createInstance<Struct_field_def_listContext>(_ctx, getState());
  enterRule(_localctx, 90, zsharp_parserParser::RuleStruct_field_def_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(533); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(532);
              struct_field_def();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(535); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_field_defContext ------------------------------------------------------------------

zsharp_parserParser::Struct_field_defContext::Struct_field_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Struct_field_defContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Identifier_fieldContext* zsharp_parserParser::Struct_field_defContext::identifier_field() {
  return getRuleContext<zsharp_parserParser::Identifier_fieldContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Struct_field_defContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Struct_field_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}


size_t zsharp_parserParser::Struct_field_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleStruct_field_def;
}

void zsharp_parserParser::Struct_field_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_field_def(this);
}

void zsharp_parserParser::Struct_field_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_field_def(this);
}


antlrcpp::Any zsharp_parserParser::Struct_field_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitStruct_field_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Struct_field_defContext* zsharp_parserParser::struct_field_def() {
  Struct_field_defContext *_localctx = _tracker.createInstance<Struct_field_defContext>(_ctx, getState());
  enterRule(_localctx, 92, zsharp_parserParser::RuleStruct_field_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(537);
    indent();
    setState(538);
    identifier_field();
    setState(539);
    type_ref_use();
    setState(540);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_defContext ------------------------------------------------------------------

zsharp_parserParser::Enum_defContext::Enum_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Enum_defContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Enum_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Enum_option_def_listContext* zsharp_parserParser::Enum_defContext::enum_option_def_list() {
  return getRuleContext<zsharp_parserParser::Enum_option_def_listContext>(0);
}

zsharp_parserParser::Enum_option_def_listlineContext* zsharp_parserParser::Enum_defContext::enum_option_def_listline() {
  return getRuleContext<zsharp_parserParser::Enum_option_def_listlineContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Enum_defContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_defContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Enum_base_typeContext* zsharp_parserParser::Enum_defContext::enum_base_type() {
  return getRuleContext<zsharp_parserParser::Enum_base_typeContext>(0);
}


size_t zsharp_parserParser::Enum_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_def;
}

void zsharp_parserParser::Enum_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_def(this);
}

void zsharp_parserParser::Enum_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_def(this);
}


antlrcpp::Any zsharp_parserParser::Enum_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_defContext* zsharp_parserParser::enum_def() {
  Enum_defContext *_localctx = _tracker.createInstance<Enum_defContext>(_ctx, getState());
  enterRule(_localctx, 94, zsharp_parserParser::RuleEnum_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    identifier_type();
    setState(546);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COLON) {
      setState(543);
      match(zsharp_parserParser::COLON);
      setState(544);
      match(zsharp_parserParser::SP);
      setState(545);
      enum_base_type();
    }
    setState(548);
    newline();
    setState(551);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(549);
      enum_option_def_list();
      break;
    }

    case 2: {
      setState(550);
      enum_option_def_listline();
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

//----------------- Enum_option_def_listlineContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_def_listlineContext::Enum_option_def_listlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Enum_option_def_listlineContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

std::vector<zsharp_parserParser::Identifier_enumoptionContext *> zsharp_parserParser::Enum_option_def_listlineContext::identifier_enumoption() {
  return getRuleContexts<zsharp_parserParser::Identifier_enumoptionContext>();
}

zsharp_parserParser::Identifier_enumoptionContext* zsharp_parserParser::Enum_option_def_listlineContext::identifier_enumoption(size_t i) {
  return getRuleContext<zsharp_parserParser::Identifier_enumoptionContext>(i);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Enum_option_def_listlineContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Enum_option_def_listlineContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_def_listlineContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Enum_option_def_listlineContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_def_listlineContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}


size_t zsharp_parserParser::Enum_option_def_listlineContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_def_listline;
}

void zsharp_parserParser::Enum_option_def_listlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_def_listline(this);
}

void zsharp_parserParser::Enum_option_def_listlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_def_listline(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_def_listlineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_def_listline(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_def_listlineContext* zsharp_parserParser::enum_option_def_listline() {
  Enum_option_def_listlineContext *_localctx = _tracker.createInstance<Enum_option_def_listlineContext>(_ctx, getState());
  enterRule(_localctx, 96, zsharp_parserParser::RuleEnum_option_def_listline);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(553);
    indent();
    setState(560);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(554);
        identifier_enumoption();
        setState(555);
        match(zsharp_parserParser::COMMA);
        setState(556);
        match(zsharp_parserParser::SP); 
      }
      setState(562);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(563);
    identifier_enumoption();
    setState(565);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COMMA) {
      setState(564);
      match(zsharp_parserParser::COMMA);
    }
    setState(567);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_option_def_listContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_def_listContext::Enum_option_def_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Enum_option_defContext *> zsharp_parserParser::Enum_option_def_listContext::enum_option_def() {
  return getRuleContexts<zsharp_parserParser::Enum_option_defContext>();
}

zsharp_parserParser::Enum_option_defContext* zsharp_parserParser::Enum_option_def_listContext::enum_option_def(size_t i) {
  return getRuleContext<zsharp_parserParser::Enum_option_defContext>(i);
}

std::vector<zsharp_parserParser::NewlineContext *> zsharp_parserParser::Enum_option_def_listContext::newline() {
  return getRuleContexts<zsharp_parserParser::NewlineContext>();
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Enum_option_def_listContext::newline(size_t i) {
  return getRuleContext<zsharp_parserParser::NewlineContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Enum_option_def_listContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_def_listContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}


size_t zsharp_parserParser::Enum_option_def_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_def_list;
}

void zsharp_parserParser::Enum_option_def_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_def_list(this);
}

void zsharp_parserParser::Enum_option_def_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_def_list(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_def_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_def_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_def_listContext* zsharp_parserParser::enum_option_def_list() {
  Enum_option_def_listContext *_localctx = _tracker.createInstance<Enum_option_def_listContext>(_ctx, getState());
  enterRule(_localctx, 98, zsharp_parserParser::RuleEnum_option_def_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(575);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(569);
        enum_option_def();
        setState(570);
        match(zsharp_parserParser::COMMA);
        setState(571);
        newline(); 
      }
      setState(577);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
    setState(578);
    enum_option_def();
    setState(580);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COMMA) {
      setState(579);
      match(zsharp_parserParser::COMMA);
    }
    setState(582);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_option_defContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_defContext::Enum_option_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::IndentContext* zsharp_parserParser::Enum_option_defContext::indent() {
  return getRuleContext<zsharp_parserParser::IndentContext>(0);
}

zsharp_parserParser::Identifier_enumoptionContext* zsharp_parserParser::Enum_option_defContext::identifier_enumoption() {
  return getRuleContext<zsharp_parserParser::Identifier_enumoptionContext>(0);
}

zsharp_parserParser::Enum_option_valueContext* zsharp_parserParser::Enum_option_defContext::enum_option_value() {
  return getRuleContext<zsharp_parserParser::Enum_option_valueContext>(0);
}


size_t zsharp_parserParser::Enum_option_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_def;
}

void zsharp_parserParser::Enum_option_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_def(this);
}

void zsharp_parserParser::Enum_option_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_def(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_defContext* zsharp_parserParser::enum_option_def() {
  Enum_option_defContext *_localctx = _tracker.createInstance<Enum_option_defContext>(_ctx, getState());
  enterRule(_localctx, 100, zsharp_parserParser::RuleEnum_option_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(584);
    indent();
    setState(585);
    identifier_enumoption();
    setState(587);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SP) {
      setState(586);
      enum_option_value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_option_valueContext ------------------------------------------------------------------

zsharp_parserParser::Enum_option_valueContext::Enum_option_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Enum_option_valueContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_valueContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Enum_option_valueContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

zsharp_parserParser::Comptime_expression_valueContext* zsharp_parserParser::Enum_option_valueContext::comptime_expression_value() {
  return getRuleContext<zsharp_parserParser::Comptime_expression_valueContext>(0);
}


size_t zsharp_parserParser::Enum_option_valueContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_option_value;
}

void zsharp_parserParser::Enum_option_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_option_value(this);
}

void zsharp_parserParser::Enum_option_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_option_value(this);
}


antlrcpp::Any zsharp_parserParser::Enum_option_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_option_value(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_option_valueContext* zsharp_parserParser::enum_option_value() {
  Enum_option_valueContext *_localctx = _tracker.createInstance<Enum_option_valueContext>(_ctx, getState());
  enterRule(_localctx, 102, zsharp_parserParser::RuleEnum_option_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(zsharp_parserParser::SP);
    setState(590);
    match(zsharp_parserParser::EQ_ASSIGN);
    setState(591);
    match(zsharp_parserParser::SP);
    setState(592);
    comptime_expression_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_base_typeContext ------------------------------------------------------------------

zsharp_parserParser::Enum_base_typeContext::Enum_base_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_BitContext* zsharp_parserParser::Enum_base_typeContext::type_Bit() {
  return getRuleContext<zsharp_parserParser::Type_BitContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::STR() {
  return getToken(zsharp_parserParser::STR, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::F16() {
  return getToken(zsharp_parserParser::F16, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::F32() {
  return getToken(zsharp_parserParser::F32, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::I16() {
  return getToken(zsharp_parserParser::I16, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::I24() {
  return getToken(zsharp_parserParser::I24, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::I32() {
  return getToken(zsharp_parserParser::I32, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::I8() {
  return getToken(zsharp_parserParser::I8, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::U16() {
  return getToken(zsharp_parserParser::U16, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::U24() {
  return getToken(zsharp_parserParser::U24, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::U32() {
  return getToken(zsharp_parserParser::U32, 0);
}

tree::TerminalNode* zsharp_parserParser::Enum_base_typeContext::U8() {
  return getToken(zsharp_parserParser::U8, 0);
}


size_t zsharp_parserParser::Enum_base_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleEnum_base_type;
}

void zsharp_parserParser::Enum_base_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_base_type(this);
}

void zsharp_parserParser::Enum_base_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_base_type(this);
}


antlrcpp::Any zsharp_parserParser::Enum_base_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitEnum_base_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Enum_base_typeContext* zsharp_parserParser::enum_base_type() {
  Enum_base_typeContext *_localctx = _tracker.createInstance<Enum_base_typeContext>(_ctx, getState());
  enterRule(_localctx, 104, zsharp_parserParser::RuleEnum_base_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(606);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(594);
        type_Bit();
        break;
      }

      case zsharp_parserParser::STR: {
        enterOuterAlt(_localctx, 2);
        setState(595);
        match(zsharp_parserParser::STR);
        break;
      }

      case zsharp_parserParser::F16: {
        enterOuterAlt(_localctx, 3);
        setState(596);
        match(zsharp_parserParser::F16);
        break;
      }

      case zsharp_parserParser::F32: {
        enterOuterAlt(_localctx, 4);
        setState(597);
        match(zsharp_parserParser::F32);
        break;
      }

      case zsharp_parserParser::I16: {
        enterOuterAlt(_localctx, 5);
        setState(598);
        match(zsharp_parserParser::I16);
        break;
      }

      case zsharp_parserParser::I24: {
        enterOuterAlt(_localctx, 6);
        setState(599);
        match(zsharp_parserParser::I24);
        break;
      }

      case zsharp_parserParser::I32: {
        enterOuterAlt(_localctx, 7);
        setState(600);
        match(zsharp_parserParser::I32);
        break;
      }

      case zsharp_parserParser::I8: {
        enterOuterAlt(_localctx, 8);
        setState(601);
        match(zsharp_parserParser::I8);
        break;
      }

      case zsharp_parserParser::U16: {
        enterOuterAlt(_localctx, 9);
        setState(602);
        match(zsharp_parserParser::U16);
        break;
      }

      case zsharp_parserParser::U24: {
        enterOuterAlt(_localctx, 10);
        setState(603);
        match(zsharp_parserParser::U24);
        break;
      }

      case zsharp_parserParser::U32: {
        enterOuterAlt(_localctx, 11);
        setState(604);
        match(zsharp_parserParser::U32);
        break;
      }

      case zsharp_parserParser::U8: {
        enterOuterAlt(_localctx, 12);
        setState(605);
        match(zsharp_parserParser::U8);
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

//----------------- Type_defContext ------------------------------------------------------------------

zsharp_parserParser::Type_defContext::Type_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Type_defContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::Type_defContext::type_ref_use() {
  return getRuleContext<zsharp_parserParser::Type_ref_useContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Type_defContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

tree::TerminalNode* zsharp_parserParser::Type_defContext::UNUSED() {
  return getToken(zsharp_parserParser::UNUSED, 0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Type_defContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Type_param_listContext* zsharp_parserParser::Type_defContext::type_param_list() {
  return getRuleContext<zsharp_parserParser::Type_param_listContext>(0);
}


size_t zsharp_parserParser::Type_defContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_def;
}

void zsharp_parserParser::Type_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_def(this);
}

void zsharp_parserParser::Type_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_def(this);
}


antlrcpp::Any zsharp_parserParser::Type_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_def(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_defContext* zsharp_parserParser::type_def() {
  Type_defContext *_localctx = _tracker.createInstance<Type_defContext>(_ctx, getState());
  enterRule(_localctx, 106, zsharp_parserParser::RuleType_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(608);
    identifier_type();
    setState(610);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SMALL_ANGLEopen) {
      setState(609);
      type_param_list();
    }
    setState(612);
    type_ref_use();
    setState(613);
    match(zsharp_parserParser::SP);
    setState(614);
    match(zsharp_parserParser::UNUSED);
    setState(615);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_aliasContext ------------------------------------------------------------------

zsharp_parserParser::Type_aliasContext::Type_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Identifier_typeContext* zsharp_parserParser::Type_aliasContext::identifier_type() {
  return getRuleContext<zsharp_parserParser::Identifier_typeContext>(0);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Type_aliasContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Type_aliasContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}

tree::TerminalNode* zsharp_parserParser::Type_aliasContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

zsharp_parserParser::Type_refContext* zsharp_parserParser::Type_aliasContext::type_ref() {
  return getRuleContext<zsharp_parserParser::Type_refContext>(0);
}

zsharp_parserParser::NewlineContext* zsharp_parserParser::Type_aliasContext::newline() {
  return getRuleContext<zsharp_parserParser::NewlineContext>(0);
}

zsharp_parserParser::Type_param_listContext* zsharp_parserParser::Type_aliasContext::type_param_list() {
  return getRuleContext<zsharp_parserParser::Type_param_listContext>(0);
}


size_t zsharp_parserParser::Type_aliasContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_alias;
}

void zsharp_parserParser::Type_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_alias(this);
}

void zsharp_parserParser::Type_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_alias(this);
}


antlrcpp::Any zsharp_parserParser::Type_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_alias(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_aliasContext* zsharp_parserParser::type_alias() {
  Type_aliasContext *_localctx = _tracker.createInstance<Type_aliasContext>(_ctx, getState());
  enterRule(_localctx, 108, zsharp_parserParser::RuleType_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    identifier_type();
    setState(619);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::SMALL_ANGLEopen) {
      setState(618);
      type_param_list();
    }
    setState(621);
    match(zsharp_parserParser::SP);
    setState(622);
    match(zsharp_parserParser::EQ_ASSIGN);
    setState(623);
    match(zsharp_parserParser::SP);
    setState(624);
    type_ref();
    setState(625);
    newline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_ref_useContext ------------------------------------------------------------------

zsharp_parserParser::Type_ref_useContext::Type_ref_useContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_ref_useContext::COLON() {
  return getToken(zsharp_parserParser::COLON, 0);
}

tree::TerminalNode* zsharp_parserParser::Type_ref_useContext::SP() {
  return getToken(zsharp_parserParser::SP, 0);
}

zsharp_parserParser::Type_refContext* zsharp_parserParser::Type_ref_useContext::type_ref() {
  return getRuleContext<zsharp_parserParser::Type_refContext>(0);
}


size_t zsharp_parserParser::Type_ref_useContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_ref_use;
}

void zsharp_parserParser::Type_ref_useContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_ref_use(this);
}

void zsharp_parserParser::Type_ref_useContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_ref_use(this);
}


antlrcpp::Any zsharp_parserParser::Type_ref_useContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_ref_use(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_ref_useContext* zsharp_parserParser::type_ref_use() {
  Type_ref_useContext *_localctx = _tracker.createInstance<Type_ref_useContext>(_ctx, getState());
  enterRule(_localctx, 110, zsharp_parserParser::RuleType_ref_use);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(627);
    match(zsharp_parserParser::COLON);
    setState(628);
    match(zsharp_parserParser::SP);
    setState(629);
    type_ref();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_refContext ------------------------------------------------------------------

zsharp_parserParser::Type_refContext::Type_refContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Type_refContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Type_refContext::ERROR() {
  return getToken(zsharp_parserParser::ERROR, 0);
}

tree::TerminalNode* zsharp_parserParser::Type_refContext::QUESTION() {
  return getToken(zsharp_parserParser::QUESTION, 0);
}


size_t zsharp_parserParser::Type_refContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_ref;
}

void zsharp_parserParser::Type_refContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_ref(this);
}

void zsharp_parserParser::Type_refContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_ref(this);
}


antlrcpp::Any zsharp_parserParser::Type_refContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_ref(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_refContext* zsharp_parserParser::type_ref() {
  Type_refContext *_localctx = _tracker.createInstance<Type_refContext>(_ctx, getState());
  enterRule(_localctx, 112, zsharp_parserParser::RuleType_ref);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    type_name();
    setState(633);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::ERROR) {
      setState(632);
      match(zsharp_parserParser::ERROR);
    }
    setState(636);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::QUESTION) {
      setState(635);
      match(zsharp_parserParser::QUESTION);
    }
   
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

zsharp_parserParser::Type_param_listContext* zsharp_parserParser::Type_nameContext::type_param_list() {
  return getRuleContext<zsharp_parserParser::Type_param_listContext>(0);
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
  enterRule(_localctx, 114, zsharp_parserParser::RuleType_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(643);
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
      case zsharp_parserParser::BIT:
      case zsharp_parserParser::PTR: {
        enterOuterAlt(_localctx, 1);
        setState(638);
        known_types();
        break;
      }

      case zsharp_parserParser::IDENTIFIERupper: {
        enterOuterAlt(_localctx, 2);
        setState(639);
        identifier_type();
        setState(641);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zsharp_parserParser::SMALL_ANGLEopen) {
          setState(640);
          type_param_list();
        }
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

zsharp_parserParser::Type_PtrContext* zsharp_parserParser::Known_typesContext::type_Ptr() {
  return getRuleContext<zsharp_parserParser::Type_PtrContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::BOOL() {
  return getToken(zsharp_parserParser::BOOL, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::STR() {
  return getToken(zsharp_parserParser::STR, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::F16() {
  return getToken(zsharp_parserParser::F16, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::F32() {
  return getToken(zsharp_parserParser::F32, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::I16() {
  return getToken(zsharp_parserParser::I16, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::I24() {
  return getToken(zsharp_parserParser::I24, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::I32() {
  return getToken(zsharp_parserParser::I32, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::I8() {
  return getToken(zsharp_parserParser::I8, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::U16() {
  return getToken(zsharp_parserParser::U16, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::U24() {
  return getToken(zsharp_parserParser::U24, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::U32() {
  return getToken(zsharp_parserParser::U32, 0);
}

tree::TerminalNode* zsharp_parserParser::Known_typesContext::U8() {
  return getToken(zsharp_parserParser::U8, 0);
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
  enterRule(_localctx, 116, zsharp_parserParser::RuleKnown_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(659);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(645);
        type_Bit();
        break;
      }

      case zsharp_parserParser::PTR: {
        enterOuterAlt(_localctx, 2);
        setState(646);
        type_Ptr();
        break;
      }

      case zsharp_parserParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(647);
        match(zsharp_parserParser::BOOL);
        break;
      }

      case zsharp_parserParser::STR: {
        enterOuterAlt(_localctx, 4);
        setState(648);
        match(zsharp_parserParser::STR);
        break;
      }

      case zsharp_parserParser::F16: {
        enterOuterAlt(_localctx, 5);
        setState(649);
        match(zsharp_parserParser::F16);
        break;
      }

      case zsharp_parserParser::F32: {
        enterOuterAlt(_localctx, 6);
        setState(650);
        match(zsharp_parserParser::F32);
        break;
      }

      case zsharp_parserParser::I16: {
        enterOuterAlt(_localctx, 7);
        setState(651);
        match(zsharp_parserParser::I16);
        break;
      }

      case zsharp_parserParser::I24: {
        enterOuterAlt(_localctx, 8);
        setState(652);
        match(zsharp_parserParser::I24);
        break;
      }

      case zsharp_parserParser::I32: {
        enterOuterAlt(_localctx, 9);
        setState(653);
        match(zsharp_parserParser::I32);
        break;
      }

      case zsharp_parserParser::I8: {
        enterOuterAlt(_localctx, 10);
        setState(654);
        match(zsharp_parserParser::I8);
        break;
      }

      case zsharp_parserParser::U16: {
        enterOuterAlt(_localctx, 11);
        setState(655);
        match(zsharp_parserParser::U16);
        break;
      }

      case zsharp_parserParser::U24: {
        enterOuterAlt(_localctx, 12);
        setState(656);
        match(zsharp_parserParser::U24);
        break;
      }

      case zsharp_parserParser::U32: {
        enterOuterAlt(_localctx, 13);
        setState(657);
        match(zsharp_parserParser::U32);
        break;
      }

      case zsharp_parserParser::U8: {
        enterOuterAlt(_localctx, 14);
        setState(658);
        match(zsharp_parserParser::U8);
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

//----------------- Type_BitContext ------------------------------------------------------------------

zsharp_parserParser::Type_BitContext::Type_BitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_BitContext::BIT() {
  return getToken(zsharp_parserParser::BIT, 0);
}

zsharp_parserParser::Type_param_numberContext* zsharp_parserParser::Type_BitContext::type_param_number() {
  return getRuleContext<zsharp_parserParser::Type_param_numberContext>(0);
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
  enterRule(_localctx, 118, zsharp_parserParser::RuleType_Bit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(661);
    match(zsharp_parserParser::BIT);
    setState(662);
    type_param_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_PtrContext ------------------------------------------------------------------

zsharp_parserParser::Type_PtrContext::Type_PtrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_PtrContext::PTR() {
  return getToken(zsharp_parserParser::PTR, 0);
}

zsharp_parserParser::Type_param_type_useContext* zsharp_parserParser::Type_PtrContext::type_param_type_use() {
  return getRuleContext<zsharp_parserParser::Type_param_type_useContext>(0);
}


size_t zsharp_parserParser::Type_PtrContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_Ptr;
}

void zsharp_parserParser::Type_PtrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_Ptr(this);
}

void zsharp_parserParser::Type_PtrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_Ptr(this);
}


antlrcpp::Any zsharp_parserParser::Type_PtrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_Ptr(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_PtrContext* zsharp_parserParser::type_Ptr() {
  Type_PtrContext *_localctx = _tracker.createInstance<Type_PtrContext>(_ctx, getState());
  enterRule(_localctx, 120, zsharp_parserParser::RuleType_Ptr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(664);
    match(zsharp_parserParser::PTR);
    setState(665);
    type_param_type_use();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_param_numberContext ------------------------------------------------------------------

zsharp_parserParser::Type_param_numberContext::Type_param_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_param_numberContext::SMALL_ANGLEopen() {
  return getToken(zsharp_parserParser::SMALL_ANGLEopen, 0);
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Type_param_numberContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Type_param_numberContext::GREAT_ANGLEclose() {
  return getToken(zsharp_parserParser::GREAT_ANGLEclose, 0);
}


size_t zsharp_parserParser::Type_param_numberContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_param_number;
}

void zsharp_parserParser::Type_param_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_param_number(this);
}

void zsharp_parserParser::Type_param_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_param_number(this);
}


antlrcpp::Any zsharp_parserParser::Type_param_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_param_number(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_param_numberContext* zsharp_parserParser::type_param_number() {
  Type_param_numberContext *_localctx = _tracker.createInstance<Type_param_numberContext>(_ctx, getState());
  enterRule(_localctx, 122, zsharp_parserParser::RuleType_param_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    match(zsharp_parserParser::SMALL_ANGLEopen);
    setState(668);
    number();
    setState(669);
    match(zsharp_parserParser::GREAT_ANGLEclose);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_param_listContext ------------------------------------------------------------------

zsharp_parserParser::Type_param_listContext::Type_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_param_listContext::SMALL_ANGLEopen() {
  return getToken(zsharp_parserParser::SMALL_ANGLEopen, 0);
}

zsharp_parserParser::Type_param_name_listContext* zsharp_parserParser::Type_param_listContext::type_param_name_list() {
  return getRuleContext<zsharp_parserParser::Type_param_name_listContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Type_param_listContext::GREAT_ANGLEclose() {
  return getToken(zsharp_parserParser::GREAT_ANGLEclose, 0);
}


size_t zsharp_parserParser::Type_param_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_param_list;
}

void zsharp_parserParser::Type_param_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_param_list(this);
}

void zsharp_parserParser::Type_param_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_param_list(this);
}


antlrcpp::Any zsharp_parserParser::Type_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_param_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_param_listContext* zsharp_parserParser::type_param_list() {
  Type_param_listContext *_localctx = _tracker.createInstance<Type_param_listContext>(_ctx, getState());
  enterRule(_localctx, 124, zsharp_parserParser::RuleType_param_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(671);
    match(zsharp_parserParser::SMALL_ANGLEopen);
    setState(672);
    type_param_name_list();
    setState(673);
    match(zsharp_parserParser::GREAT_ANGLEclose);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_param_name_listContext ------------------------------------------------------------------

zsharp_parserParser::Type_param_name_listContext::Type_param_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zsharp_parserParser::Type_param_typeContext *> zsharp_parserParser::Type_param_name_listContext::type_param_type() {
  return getRuleContexts<zsharp_parserParser::Type_param_typeContext>();
}

zsharp_parserParser::Type_param_typeContext* zsharp_parserParser::Type_param_name_listContext::type_param_type(size_t i) {
  return getRuleContext<zsharp_parserParser::Type_param_typeContext>(i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Type_param_name_listContext::COMMA() {
  return getTokens(zsharp_parserParser::COMMA);
}

tree::TerminalNode* zsharp_parserParser::Type_param_name_listContext::COMMA(size_t i) {
  return getToken(zsharp_parserParser::COMMA, i);
}

std::vector<tree::TerminalNode *> zsharp_parserParser::Type_param_name_listContext::SP() {
  return getTokens(zsharp_parserParser::SP);
}

tree::TerminalNode* zsharp_parserParser::Type_param_name_listContext::SP(size_t i) {
  return getToken(zsharp_parserParser::SP, i);
}


size_t zsharp_parserParser::Type_param_name_listContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_param_name_list;
}

void zsharp_parserParser::Type_param_name_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_param_name_list(this);
}

void zsharp_parserParser::Type_param_name_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_param_name_list(this);
}


antlrcpp::Any zsharp_parserParser::Type_param_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_param_name_list(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_param_name_listContext* zsharp_parserParser::type_param_name_list() {
  Type_param_name_listContext *_localctx = _tracker.createInstance<Type_param_name_listContext>(_ctx, getState());
  enterRule(_localctx, 126, zsharp_parserParser::RuleType_param_name_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(675);
    type_param_type();
    setState(681);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zsharp_parserParser::COMMA) {
      setState(676);
      match(zsharp_parserParser::COMMA);
      setState(677);
      match(zsharp_parserParser::SP);
      setState(678);
      type_param_type();
      setState(683);
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

//----------------- Type_param_type_useContext ------------------------------------------------------------------

zsharp_parserParser::Type_param_type_useContext::Type_param_type_useContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Type_param_type_useContext::SMALL_ANGLEopen() {
  return getToken(zsharp_parserParser::SMALL_ANGLEopen, 0);
}

zsharp_parserParser::Type_param_typeContext* zsharp_parserParser::Type_param_type_useContext::type_param_type() {
  return getRuleContext<zsharp_parserParser::Type_param_typeContext>(0);
}

tree::TerminalNode* zsharp_parserParser::Type_param_type_useContext::GREAT_ANGLEclose() {
  return getToken(zsharp_parserParser::GREAT_ANGLEclose, 0);
}


size_t zsharp_parserParser::Type_param_type_useContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_param_type_use;
}

void zsharp_parserParser::Type_param_type_useContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_param_type_use(this);
}

void zsharp_parserParser::Type_param_type_useContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_param_type_use(this);
}


antlrcpp::Any zsharp_parserParser::Type_param_type_useContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_param_type_use(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_param_type_useContext* zsharp_parserParser::type_param_type_use() {
  Type_param_type_useContext *_localctx = _tracker.createInstance<Type_param_type_useContext>(_ctx, getState());
  enterRule(_localctx, 128, zsharp_parserParser::RuleType_param_type_use);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(684);
    match(zsharp_parserParser::SMALL_ANGLEopen);
    setState(685);
    type_param_type();
    setState(686);
    match(zsharp_parserParser::GREAT_ANGLEclose);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_param_typeContext ------------------------------------------------------------------

zsharp_parserParser::Type_param_typeContext::Type_param_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zsharp_parserParser::Type_nameContext* zsharp_parserParser::Type_param_typeContext::type_name() {
  return getRuleContext<zsharp_parserParser::Type_nameContext>(0);
}

zsharp_parserParser::NumberContext* zsharp_parserParser::Type_param_typeContext::number() {
  return getRuleContext<zsharp_parserParser::NumberContext>(0);
}


size_t zsharp_parserParser::Type_param_typeContext::getRuleIndex() const {
  return zsharp_parserParser::RuleType_param_type;
}

void zsharp_parserParser::Type_param_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_param_type(this);
}

void zsharp_parserParser::Type_param_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zsharp_parserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_param_type(this);
}


antlrcpp::Any zsharp_parserParser::Type_param_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zsharp_parserVisitor*>(visitor))
    return parserVisitor->visitType_param_type(this);
  else
    return visitor->visitChildren(this);
}

zsharp_parserParser::Type_param_typeContext* zsharp_parserParser::type_param_type() {
  Type_param_typeContext *_localctx = _tracker.createInstance<Type_param_typeContext>(_ctx, getState());
  enterRule(_localctx, 130, zsharp_parserParser::RuleType_param_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(690);
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
      case zsharp_parserParser::BIT:
      case zsharp_parserParser::PTR:
      case zsharp_parserParser::IDENTIFIERupper: {
        enterOuterAlt(_localctx, 1);
        setState(688);
        type_name();
        break;
      }

      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(689);
        number();
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
  enterRule(_localctx, 132, zsharp_parserParser::RuleIdentifier_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(692);
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
  enterRule(_localctx, 134, zsharp_parserParser::RuleIdentifier_var);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(694);
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
  enterRule(_localctx, 136, zsharp_parserParser::RuleIdentifier_param);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(696);
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
  enterRule(_localctx, 138, zsharp_parserParser::RuleIdentifier_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(698);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::IDENTIFIERupper

    || _la == zsharp_parserParser::IDENTIFIERlower)) {
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
  enterRule(_localctx, 140, zsharp_parserParser::RuleIdentifier_field);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::IDENTIFIERupper

    || _la == zsharp_parserParser::IDENTIFIERlower)) {
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
  enterRule(_localctx, 142, zsharp_parserParser::RuleIdentifier_enumoption);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(702);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::IDENTIFIERupper

    || _la == zsharp_parserParser::IDENTIFIERlower)) {
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
  enterRule(_localctx, 144, zsharp_parserParser::RuleIdentifier_module);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(704);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::IDENTIFIERupper

    || _la == zsharp_parserParser::IDENTIFIERlower)) {
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
  enterRule(_localctx, 146, zsharp_parserParser::RuleIdentifier_unused);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    match(zsharp_parserParser::UNUSED);
   
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
  enterRule(_localctx, 148, zsharp_parserParser::RuleLiteral_bool);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(708);
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
  enterRule(_localctx, 150, zsharp_parserParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(712);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin:
      case zsharp_parserParser::NUMBERoct:
      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix:
      case zsharp_parserParser::NUMBERhex:
      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 1);
        setState(710);
        number();
        break;
      }

      case zsharp_parserParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(711);
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

zsharp_parserParser::Number_binContext* zsharp_parserParser::NumberContext::number_bin() {
  return getRuleContext<zsharp_parserParser::Number_binContext>(0);
}

zsharp_parserParser::Number_octContext* zsharp_parserParser::NumberContext::number_oct() {
  return getRuleContext<zsharp_parserParser::Number_octContext>(0);
}

zsharp_parserParser::Number_decContext* zsharp_parserParser::NumberContext::number_dec() {
  return getRuleContext<zsharp_parserParser::Number_decContext>(0);
}

zsharp_parserParser::Number_hexContext* zsharp_parserParser::NumberContext::number_hex() {
  return getRuleContext<zsharp_parserParser::Number_hexContext>(0);
}

zsharp_parserParser::Number_charContext* zsharp_parserParser::NumberContext::number_char() {
  return getRuleContext<zsharp_parserParser::Number_charContext>(0);
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
  enterRule(_localctx, 152, zsharp_parserParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(719);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zsharp_parserParser::NUMBERbin: {
        enterOuterAlt(_localctx, 1);
        setState(714);
        number_bin();
        break;
      }

      case zsharp_parserParser::NUMBERoct: {
        enterOuterAlt(_localctx, 2);
        setState(715);
        number_oct();
        break;
      }

      case zsharp_parserParser::NUMBERdec:
      case zsharp_parserParser::NUMBERdec_prefix: {
        enterOuterAlt(_localctx, 3);
        setState(716);
        number_dec();
        break;
      }

      case zsharp_parserParser::NUMBERhex: {
        enterOuterAlt(_localctx, 4);
        setState(717);
        number_hex();
        break;
      }

      case zsharp_parserParser::CHARACTER: {
        enterOuterAlt(_localctx, 5);
        setState(718);
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
  enterRule(_localctx, 154, zsharp_parserParser::RuleNumber_bin);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(721);
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
  enterRule(_localctx, 156, zsharp_parserParser::RuleNumber_oct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(723);
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
  enterRule(_localctx, 158, zsharp_parserParser::RuleNumber_dec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
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
  enterRule(_localctx, 160, zsharp_parserParser::RuleNumber_hex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(727);
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
  enterRule(_localctx, 162, zsharp_parserParser::RuleNumber_char);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(729);
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

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::PLUS() {
  return getToken(zsharp_parserParser::PLUS, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::MINUS_NEG() {
  return getToken(zsharp_parserParser::MINUS_NEG, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::DIV() {
  return getToken(zsharp_parserParser::DIV, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::MOD() {
  return getToken(zsharp_parserParser::MOD, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::MULT() {
  return getToken(zsharp_parserParser::MULT, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmeticContext::POW() {
  return getToken(zsharp_parserParser::POW, 0);
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
  enterRule(_localctx, 164, zsharp_parserParser::RuleOperator_arithmetic);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(731);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::PLUS)
      | (1ULL << zsharp_parserParser::MINUS_NEG)
      | (1ULL << zsharp_parserParser::MULT)
      | (1ULL << zsharp_parserParser::DIV)
      | (1ULL << zsharp_parserParser::MOD)
      | (1ULL << zsharp_parserParser::POW))) != 0))) {
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

//----------------- Operator_arithmetic_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_arithmetic_unaryContext::Operator_arithmetic_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Operator_arithmetic_unaryContext::MINUS_NEG() {
  return getToken(zsharp_parserParser::MINUS_NEG, 0);
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
  enterRule(_localctx, 166, zsharp_parserParser::RuleOperator_arithmetic_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(733);
    match(zsharp_parserParser::MINUS_NEG);
   
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

tree::TerminalNode* zsharp_parserParser::Operator_logicContext::AND() {
  return getToken(zsharp_parserParser::AND, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_logicContext::OR() {
  return getToken(zsharp_parserParser::OR, 0);
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
  enterRule(_localctx, 168, zsharp_parserParser::RuleOperator_logic);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(735);
    _la = _input->LA(1);
    if (!(_la == zsharp_parserParser::AND

    || _la == zsharp_parserParser::OR)) {
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

//----------------- Operator_logic_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_logic_unaryContext::Operator_logic_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Operator_logic_unaryContext::NOT() {
  return getToken(zsharp_parserParser::NOT, 0);
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
  enterRule(_localctx, 170, zsharp_parserParser::RuleOperator_logic_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(737);
    match(zsharp_parserParser::NOT);
   
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

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::NEQ() {
  return getToken(zsharp_parserParser::NEQ, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::GREAT_ANGLEclose() {
  return getToken(zsharp_parserParser::GREAT_ANGLEclose, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::SMALL_ANGLEopen() {
  return getToken(zsharp_parserParser::SMALL_ANGLEopen, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::GREQ() {
  return getToken(zsharp_parserParser::GREQ, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_comparisonContext::SMEQ() {
  return getToken(zsharp_parserParser::SMEQ, 0);
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
  enterRule(_localctx, 172, zsharp_parserParser::RuleOperator_comparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::EQ_ASSIGN)
      | (1ULL << zsharp_parserParser::NEQ)
      | (1ULL << zsharp_parserParser::GREAT_ANGLEclose)
      | (1ULL << zsharp_parserParser::SMALL_ANGLEopen)
      | (1ULL << zsharp_parserParser::GREQ)
      | (1ULL << zsharp_parserParser::SMEQ))) != 0))) {
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

//----------------- Operator_bitsContext ------------------------------------------------------------------

zsharp_parserParser::Operator_bitsContext::Operator_bitsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_AND() {
  return getToken(zsharp_parserParser::BIT_AND, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_OR() {
  return getToken(zsharp_parserParser::BIT_OR, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_XOR() {
  return getToken(zsharp_parserParser::BIT_XOR, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_SHL() {
  return getToken(zsharp_parserParser::BIT_SHL, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_SHR() {
  return getToken(zsharp_parserParser::BIT_SHR, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_ROLL() {
  return getToken(zsharp_parserParser::BIT_ROLL, 0);
}

tree::TerminalNode* zsharp_parserParser::Operator_bitsContext::BIT_ROLR() {
  return getToken(zsharp_parserParser::BIT_ROLR, 0);
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
  enterRule(_localctx, 174, zsharp_parserParser::RuleOperator_bits);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zsharp_parserParser::BIT_AND)
      | (1ULL << zsharp_parserParser::BIT_OR)
      | (1ULL << zsharp_parserParser::BIT_XOR)
      | (1ULL << zsharp_parserParser::BIT_SHL)
      | (1ULL << zsharp_parserParser::BIT_SHR)
      | (1ULL << zsharp_parserParser::BIT_ROLL)
      | (1ULL << zsharp_parserParser::BIT_ROLR))) != 0))) {
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

//----------------- Operator_bits_unaryContext ------------------------------------------------------------------

zsharp_parserParser::Operator_bits_unaryContext::Operator_bits_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zsharp_parserParser::Operator_bits_unaryContext::BIT_NOT() {
  return getToken(zsharp_parserParser::BIT_NOT, 0);
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
  enterRule(_localctx, 176, zsharp_parserParser::RuleOperator_bits_unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(743);
    match(zsharp_parserParser::BIT_NOT);
   
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

tree::TerminalNode* zsharp_parserParser::Operator_assignmentContext::EQ_ASSIGN() {
  return getToken(zsharp_parserParser::EQ_ASSIGN, 0);
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
  enterRule(_localctx, 178, zsharp_parserParser::RuleOperator_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    match(zsharp_parserParser::EQ_ASSIGN);
   
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
  enterRule(_localctx, 180, zsharp_parserParser::RuleEmpty_line);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(748);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(747);
      match(zsharp_parserParser::INDENT);
    }
    setState(751); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(750);
              match(zsharp_parserParser::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(753); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
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

tree::TerminalNode* zsharp_parserParser::NewlineContext::INDENT() {
  return getToken(zsharp_parserParser::INDENT, 0);
}

tree::TerminalNode* zsharp_parserParser::NewlineContext::COMMENT() {
  return getToken(zsharp_parserParser::COMMENT, 0);
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
  enterRule(_localctx, 182, zsharp_parserParser::RuleNewline);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(756);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(755);
      match(zsharp_parserParser::INDENT);
    }
    setState(759);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::COMMENT) {
      setState(758);
      match(zsharp_parserParser::COMMENT);
    }
    setState(761);
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

tree::TerminalNode* zsharp_parserParser::CommentContext::INDENT() {
  return getToken(zsharp_parserParser::INDENT, 0);
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
  enterRule(_localctx, 184, zsharp_parserParser::RuleComment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(764);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zsharp_parserParser::INDENT) {
      setState(763);
      match(zsharp_parserParser::INDENT);
    }
    setState(766);
    match(zsharp_parserParser::COMMENT);
    setState(767);
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
  enterRule(_localctx, 186, zsharp_parserParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(769);
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
  enterRule(_localctx, 188, zsharp_parserParser::RuleCharacter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(771);
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
  enterRule(_localctx, 190, zsharp_parserParser::RuleIndent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(773);
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
    case 22: return expression_arithmeticSempred(dynamic_cast<Expression_arithmeticContext *>(context), predicateIndex);
    case 24: return expression_logicSempred(dynamic_cast<Expression_logicContext *>(context), predicateIndex);
    case 26: return expression_comparisonSempred(dynamic_cast<Expression_comparisonContext *>(context), predicateIndex);

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

bool zsharp_parserParser::expression_arithmeticSempred(Expression_arithmeticContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool zsharp_parserParser::expression_logicSempred(Expression_logicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool zsharp_parserParser::expression_comparisonSempred(Expression_comparisonContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);

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
  "file", "source", "codeblock", "module_statement", "module_name", "statement_module", 
  "statement_import", "statement_export", "flow_statement", "statement_return", 
  "statement_if", "statement_else", "statement_elseif", "statement_break", 
  "statement_continue", "statement_loop", "statement_loop_infinite", "statement_loop_while", 
  "definition_top", "definition", "expression_value", "comptime_expression_value", 
  "expression_arithmetic", "arithmetic_operand", "expression_logic", "logic_operand", 
  "expression_comparison", "comparison_operand", "expression_bool", "function_call", 
  "function_def", "function_def_export", "function_parameter_list", "function_parameter", 
  "function_parameter_self", "function_parameter_uselist", "function_param_use", 
  "variable_ref", "variable_def_top", "variable_def", "variable_def_typed", 
  "variable_def_typed_init", "variable_assign_auto", "variable_assign", 
  "struct_def", "struct_field_def_list", "struct_field_def", "enum_def", 
  "enum_option_def_listline", "enum_option_def_list", "enum_option_def", 
  "enum_option_value", "enum_base_type", "type_def", "type_alias", "type_ref_use", 
  "type_ref", "type_name", "known_types", "type_Bit", "type_Ptr", "type_param_number", 
  "type_param_list", "type_param_name_list", "type_param_type_use", "type_param_type", 
  "identifier_type", "identifier_var", "identifier_param", "identifier_func", 
  "identifier_field", "identifier_enumoption", "identifier_module", "identifier_unused", 
  "literal_bool", "literal", "number", "number_bin", "number_oct", "number_dec", 
  "number_hex", "number_char", "operator_arithmetic", "operator_arithmetic_unary", 
  "operator_logic", "operator_logic_unary", "operator_comparison", "operator_bits", 
  "operator_bits_unary", "operator_assignment", "empty_line", "newline", 
  "comment", "string", "character", "indent"
};

std::vector<std::string> zsharp_parserParser::_literalNames = {
  "", "'U8'", "'U16'", "'U24'", "'U32'", "'I8'", "'I16'", "'I24'", "'I32'", 
  "'F16'", "'F32'", "'Str'", "'Bool'", "'Bit'", "'Ptr'", "'module'", "'import'", 
  "'export'", "'loop'", "'break'", "'continue'", "'if'", "'else'", "'return'", 
  "'in'", "'self'", "'true'", "'false'", "", "", "", "", "", "", "", "", 
  "'_'", "'+'", "'-'", "'*'", "'/'", "'%'", "'**'", "'='", "'<>'", "'>'", 
  "'<'", "'>='", "'<='", "'and'", "'or'", "'not'", "'&'", "'|'", "'^'", 
  "'~'", "'<<'", "'>>'", "'|,'", "'>|'", "'&&'", "'['", "']'", "'('", "')'", 
  "'?'", "':'", "'.'", "'..'", "'...'", "','", "'#'", "'#!'", "'!'", "'\"'", 
  "'''", "'//'", "", "", "' '", "'\t'"
};

std::vector<std::string> zsharp_parserParser::_symbolicNames = {
  "", "U8", "U16", "U24", "U32", "I8", "I16", "I24", "I32", "F16", "F32", 
  "STR", "BOOL", "BIT", "PTR", "MODULE", "IMPORT", "EXPORT", "LOOP", "BREAK", 
  "CONTINUE", "IF", "ELSE", "RETURN", "IN", "SELF", "TRUE", "FALSE", "COMMENT", 
  "NUMBERbin", "NUMBERoct", "NUMBERdec", "NUMBERdec_prefix", "NUMBERhex", 
  "CHARACTER", "STRING", "UNUSED", "PLUS", "MINUS_NEG", "MULT", "DIV", "MOD", 
  "POW", "EQ_ASSIGN", "NEQ", "GREAT_ANGLEclose", "SMALL_ANGLEopen", "GREQ", 
  "SMEQ", "AND", "OR", "NOT", "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NOT", 
  "BIT_SHL", "BIT_SHR", "BIT_ROLL", "BIT_ROLR", "CONCAT", "SUBopen", "SUBclose", 
  "PARENopen", "PARENclose", "QUESTION", "COLON", "DOT", "RANGE", "SPREAD", 
  "COMMA", "META", "COMPTIME", "ERROR", "STR_QUOTE", "CHAR_QUOTE", "COMMENTstart", 
  "IDENTIFIERupper", "IDENTIFIERlower", "SP", "TAB", "INDENT", "EOL"
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
    0x3, 0x54, 0x30a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x3, 0x2, 0x7, 0x2, 0xc4, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0xc7, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xcf, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0xd7, 0xa, 0x4, 
    0xd, 0x4, 0xe, 0x4, 0xd8, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xde, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0xe6, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xe9, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0xf9, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x104, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x10a, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x12c, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x13e, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x148, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x14d, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x5, 0x18, 0x15b, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x169, 0xa, 0x18, 0xc, 0x18, 
    0xe, 0x18, 0x16c, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x171, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x17d, 
    0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x7, 0x1a, 0x185, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x188, 0xb, 
    0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x18c, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x194, 
    0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x7, 0x1c, 0x19c, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x19f, 0xb, 
    0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1a5, 
    0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1a9, 0xa, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1af, 0xa, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1b7, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1bb, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x22, 0x3, 0x22, 0x5, 0x22, 0x1c6, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x7, 0x22, 0x1cb, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1ce, 
    0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 
    0x24, 0x1d5, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x7, 0x25, 0x1db, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1de, 0xb, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x1e4, 0xa, 0x26, 
    0xc, 0x26, 0xe, 0x26, 0x1e7, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1ee, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1f6, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x20f, 0xa, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x212, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2f, 0x6, 0x2f, 0x218, 0xa, 0x2f, 0xd, 0x2f, 0xe, 0x2f, 0x219, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x225, 0xa, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x22a, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x231, 0xa, 0x32, 0xc, 0x32, 
    0xe, 0x32, 0x234, 0xb, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x238, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x7, 0x33, 0x240, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x243, 0xb, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x247, 0xa, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x24e, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x261, 0xa, 0x36, 
    0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x265, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x26e, 
    0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x5, 0x3a, 0x27c, 0xa, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x27f, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x284, 0xa, 0x3b, 0x5, 0x3b, 
    0x286, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x296, 0xa, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x2aa, 0xa, 0x41, 
    0xc, 0x41, 0xe, 0x41, 0x2ad, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x2b5, 0xa, 0x43, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x5, 
    0x4d, 0x2cb, 0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x5, 0x4e, 0x2d2, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 
    0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x5, 0x5c, 0x2ef, 
    0xa, 0x5c, 0x3, 0x5c, 0x6, 0x5c, 0x2f2, 0xa, 0x5c, 0xd, 0x5c, 0xe, 0x5c, 
    0x2f3, 0x3, 0x5d, 0x5, 0x5d, 0x2f7, 0xa, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 
    0x2fa, 0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x5, 0x5e, 0x2ff, 
    0xa, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 
    0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x2, 0x6, 0xa, 0x2e, 
    0x32, 0x36, 0x62, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
    0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 
    0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 
    0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
    0xbe, 0xc0, 0x2, 0x9, 0x3, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x1c, 0x1d, 0x3, 
    0x2, 0x21, 0x22, 0x3, 0x2, 0x27, 0x2c, 0x3, 0x2, 0x33, 0x34, 0x3, 0x2, 
    0x2d, 0x32, 0x4, 0x2, 0x36, 0x38, 0x3a, 0x3d, 0x2, 0x31d, 0x2, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0xce, 0x3, 0x2, 0x2, 0x2, 0x6, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xa, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe, 0xef, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0x12, 0x103, 0x3, 0x2, 0x2, 0x2, 0x14, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x119, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x125, 0x3, 0x2, 0x2, 0x2, 0x20, 0x128, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x130, 0x3, 0x2, 0x2, 0x2, 0x24, 0x132, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x28, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x147, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x170, 0x3, 0x2, 0x2, 0x2, 0x32, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x36, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1b3, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x1cf, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1e8, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1f1, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1fc, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x203, 0x3, 0x2, 0x2, 0x2, 0x58, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x217, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x21b, 0x3, 0x2, 0x2, 0x2, 0x60, 0x220, 0x3, 0x2, 0x2, 0x2, 0x62, 0x22b, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x241, 0x3, 0x2, 0x2, 0x2, 0x66, 0x24a, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x262, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x26b, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x275, 0x3, 0x2, 0x2, 0x2, 0x72, 0x279, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x285, 0x3, 0x2, 0x2, 0x2, 0x76, 0x295, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x297, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x29d, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2a5, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2b4, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2b8, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2bc, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x2c2, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2c6, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x2d1, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x2d5, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x2d9, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0x2db, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x2dd, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x2df, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0x2e3, 0x3, 0x2, 0x2, 0x2, 0xae, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x2e7, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x2eb, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x2f6, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x303, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0x305, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x307, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc4, 0x5, 0x4, 0x3, 0x2, 0xc3, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x2, 0x2, 0x3, 0xc9, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xcf, 0x5, 0x8, 0x5, 0x2, 0xcb, 0xcf, 0x5, 0x26, 0x14, 
    0x2, 0xcc, 0xcf, 0x5, 0xba, 0x5e, 0x2, 0xcd, 0xcf, 0x5, 0xb6, 0x5c, 
    0x2, 0xce, 0xca, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd7, 0x5, 0x12, 0xa, 0x2, 0xd1, 0xd7, 
    0x5, 0x58, 0x2d, 0x2, 0xd2, 0xd7, 0x5, 0x3c, 0x1f, 0x2, 0xd3, 0xd7, 
    0x5, 0x28, 0x15, 0x2, 0xd4, 0xd7, 0x5, 0xba, 0x5e, 0x2, 0xd5, 0xd7, 
    0x5, 0xb6, 0x5c, 0x2, 0xd6, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x7, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xde, 0x5, 0xc, 0x7, 0x2, 0xdb, 0xde, 0x5, 0xe, 0x8, 0x2, 0xdc, 0xde, 
    0x5, 0x10, 0x9, 0x2, 0xdd, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe0, 0x8, 0x6, 0x1, 0x2, 0xe0, 0xe1, 0x5, 0x92, 0x4a, 
    0x2, 0xe1, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0xc, 0x3, 0x2, 0x2, 
    0xe3, 0xe4, 0x7, 0x45, 0x2, 0x2, 0xe4, 0xe6, 0x5, 0x92, 0x4a, 0x2, 0xe5, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x11, 
    0x2, 0x2, 0xeb, 0xec, 0x7, 0x51, 0x2, 0x2, 0xec, 0xed, 0x5, 0xa, 0x6, 
    0x2, 0xed, 0xee, 0x5, 0xb8, 0x5d, 0x2, 0xee, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xf0, 0x7, 0x12, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x51, 0x2, 0x2, 0xf1, 
    0xf2, 0x5, 0xa, 0x6, 0x2, 0xf2, 0xf3, 0x5, 0xb8, 0x5d, 0x2, 0xf3, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x13, 0x2, 0x2, 0xf5, 0xf8, 0x7, 
    0x51, 0x2, 0x2, 0xf6, 0xf9, 0x5, 0x8c, 0x47, 0x2, 0xf7, 0xf9, 0x5, 0x86, 
    0x44, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0xb8, 0x5d, 0x2, 
    0xfb, 0x11, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x104, 0x5, 0x16, 0xc, 0x2, 0xfd, 
    0x104, 0x5, 0x18, 0xd, 0x2, 0xfe, 0x104, 0x5, 0x1a, 0xe, 0x2, 0xff, 
    0x104, 0x5, 0x20, 0x11, 0x2, 0x100, 0x104, 0x5, 0x14, 0xb, 0x2, 0x101, 
    0x104, 0x5, 0x1c, 0xf, 0x2, 0x102, 0x104, 0x5, 0x1e, 0x10, 0x2, 0x103, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0x103, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x103, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0xff, 0x3, 0x2, 0x2, 0x2, 0x103, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x13, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x5, 0xc0, 
    0x61, 0x2, 0x106, 0x109, 0x7, 0x19, 0x2, 0x2, 0x107, 0x108, 0x7, 0x51, 
    0x2, 0x2, 0x108, 0x10a, 0x5, 0x2a, 0x16, 0x2, 0x109, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10c, 0x5, 0xb8, 0x5d, 0x2, 0x10c, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10e, 0x5, 0xc0, 0x61, 0x2, 0x10e, 0x10f, 0x7, 0x17, 
    0x2, 0x2, 0x10f, 0x110, 0x7, 0x51, 0x2, 0x2, 0x110, 0x111, 0x5, 0x32, 
    0x1a, 0x2, 0x111, 0x112, 0x5, 0xb8, 0x5d, 0x2, 0x112, 0x113, 0x5, 0x6, 
    0x4, 0x2, 0x113, 0x17, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x5, 0xc0, 
    0x61, 0x2, 0x115, 0x116, 0x7, 0x18, 0x2, 0x2, 0x116, 0x117, 0x5, 0xb8, 
    0x5d, 0x2, 0x117, 0x118, 0x5, 0x6, 0x4, 0x2, 0x118, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11a, 0x5, 0xc0, 0x61, 0x2, 0x11a, 0x11b, 0x7, 0x18, 
    0x2, 0x2, 0x11b, 0x11c, 0x7, 0x51, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x17, 
    0x2, 0x2, 0x11d, 0x11e, 0x7, 0x51, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x32, 
    0x1a, 0x2, 0x11f, 0x120, 0x5, 0xb8, 0x5d, 0x2, 0x120, 0x121, 0x5, 0x6, 
    0x4, 0x2, 0x121, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x5, 0xc0, 
    0x61, 0x2, 0x123, 0x124, 0x7, 0x15, 0x2, 0x2, 0x124, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x126, 0x5, 0xc0, 0x61, 0x2, 0x126, 0x127, 0x7, 0x16, 
    0x2, 0x2, 0x127, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 0x5, 0xc0, 
    0x61, 0x2, 0x129, 0x12c, 0x5, 0x22, 0x12, 0x2, 0x12a, 0x12c, 0x5, 0x24, 
    0x13, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0xb8, 
    0x5d, 0x2, 0x12e, 0x12f, 0x5, 0x6, 0x4, 0x2, 0x12f, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x131, 0x7, 0x14, 0x2, 0x2, 0x131, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x133, 0x7, 0x14, 0x2, 0x2, 0x133, 0x134, 0x7, 0x51, 
    0x2, 0x2, 0x134, 0x135, 0x5, 0x32, 0x1a, 0x2, 0x135, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x13e, 0x5, 0x40, 0x21, 0x2, 0x137, 0x13e, 0x5, 0x3e, 
    0x20, 0x2, 0x138, 0x13e, 0x5, 0x60, 0x31, 0x2, 0x139, 0x13e, 0x5, 0x5a, 
    0x2e, 0x2, 0x13a, 0x13e, 0x5, 0x6c, 0x37, 0x2, 0x13b, 0x13e, 0x5, 0x6e, 
    0x38, 0x2, 0x13c, 0x13e, 0x5, 0x4e, 0x28, 0x2, 0x13d, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x27, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x5, 0x50, 
    0x29, 0x2, 0x140, 0x29, 0x3, 0x2, 0x2, 0x2, 0x141, 0x148, 0x5, 0x9a, 
    0x4e, 0x2, 0x142, 0x148, 0x5, 0xbc, 0x5f, 0x2, 0x143, 0x148, 0x5, 0x3a, 
    0x1e, 0x2, 0x144, 0x148, 0x5, 0x2e, 0x18, 0x2, 0x145, 0x148, 0x5, 0x32, 
    0x1a, 0x2, 0x146, 0x148, 0x5, 0x3c, 0x1f, 0x2, 0x147, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x142, 0x3, 0x2, 0x2, 0x2, 0x147, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x14d, 0x5, 0x9a, 0x4e, 0x2, 0x14a, 0x14d, 0x5, 0xbc, 0x5f, 
    0x2, 0x14b, 0x14d, 0x5, 0x3a, 0x1e, 0x2, 0x14c, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x8, 0x18, 0x1, 
    0x2, 0x14f, 0x150, 0x7, 0x41, 0x2, 0x2, 0x150, 0x151, 0x5, 0x2e, 0x18, 
    0x2, 0x151, 0x152, 0x7, 0x42, 0x2, 0x2, 0x152, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x154, 0x5, 0xa8, 0x55, 0x2, 0x154, 0x155, 0x5, 0x2e, 0x18, 
    0x5, 0x155, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x5, 0xb2, 0x5a, 
    0x2, 0x157, 0x158, 0x5, 0x2e, 0x18, 0x4, 0x158, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x159, 0x15b, 0x5, 0x30, 0x19, 0x2, 0x15a, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15d, 0xc, 0x8, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x51, 0x2, 
    0x2, 0x15e, 0x15f, 0x5, 0xa6, 0x54, 0x2, 0x15f, 0x160, 0x7, 0x51, 0x2, 
    0x2, 0x160, 0x161, 0x5, 0x2e, 0x18, 0x9, 0x161, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x163, 0xc, 0x7, 0x2, 0x2, 0x163, 0x164, 0x7, 0x51, 0x2, 
    0x2, 0x164, 0x165, 0x5, 0xb0, 0x59, 0x2, 0x165, 0x166, 0x7, 0x51, 0x2, 
    0x2, 0x166, 0x167, 0x5, 0x2e, 0x18, 0x8, 0x167, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x168, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x171, 0x5, 0x9a, 0x4e, 0x2, 
    0x16e, 0x171, 0x5, 0x4c, 0x27, 0x2, 0x16f, 0x171, 0x5, 0x3c, 0x1f, 0x2, 
    0x170, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x171, 0x31, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x173, 0x8, 0x1a, 0x1, 0x2, 0x173, 0x174, 0x7, 0x41, 0x2, 0x2, 0x174, 
    0x175, 0x5, 0x32, 0x1a, 0x2, 0x175, 0x176, 0x7, 0x42, 0x2, 0x2, 0x176, 
    0x17d, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x5, 0xac, 0x57, 0x2, 0x178, 
    0x179, 0x7, 0x51, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x32, 0x1a, 0x4, 0x17a, 
    0x17d, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 0x5, 0x34, 0x1b, 0x2, 0x17c, 
    0x172, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x186, 0x3, 0x2, 0x2, 0x2, 0x17e, 
    0x17f, 0xc, 0x6, 0x2, 0x2, 0x17f, 0x180, 0x7, 0x51, 0x2, 0x2, 0x180, 
    0x181, 0x5, 0xaa, 0x56, 0x2, 0x181, 0x182, 0x7, 0x51, 0x2, 0x2, 0x182, 
    0x183, 0x5, 0x32, 0x1a, 0x7, 0x183, 0x185, 0x3, 0x2, 0x2, 0x2, 0x184, 
    0x17e, 0x3, 0x2, 0x2, 0x2, 0x185, 0x188, 0x3, 0x2, 0x2, 0x2, 0x186, 
    0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 
    0x5, 0x36, 0x1c, 0x2, 0x18a, 0x18c, 0x5, 0x3a, 0x1e, 0x2, 0x18b, 0x189, 
    0x3, 0x2, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x18d, 0x18e, 0x8, 0x1c, 0x1, 0x2, 0x18e, 0x18f, 0x7, 
    0x41, 0x2, 0x2, 0x18f, 0x190, 0x5, 0x36, 0x1c, 0x2, 0x190, 0x191, 0x7, 
    0x42, 0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x194, 0x5, 
    0x38, 0x1d, 0x2, 0x193, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x193, 0x192, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0xc, 
    0x5, 0x2, 0x2, 0x196, 0x197, 0x7, 0x51, 0x2, 0x2, 0x197, 0x198, 0x5, 
    0xae, 0x58, 0x2, 0x198, 0x199, 0x7, 0x51, 0x2, 0x2, 0x199, 0x19a, 0x5, 
    0x36, 0x1c, 0x6, 0x19a, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x195, 0x3, 
    0x2, 0x2, 0x2, 0x19c, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a5, 0x5, 0x2e, 
    0x18, 0x2, 0x1a1, 0x1a5, 0x5, 0x3c, 0x1f, 0x2, 0x1a2, 0x1a5, 0x5, 0x4c, 
    0x27, 0x2, 0x1a3, 0x1a5, 0x5, 0x98, 0x4d, 0x2, 0x1a4, 0x1a0, 0x3, 0x2, 
    0x2, 0x2, 0x1a4, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 
    0x2, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a9, 0x5, 0x96, 0x4c, 0x2, 0x1a7, 0x1a9, 0x5, 0x4c, 0x27, 
    0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x5, 0xc0, 0x61, 
    0x2, 0x1ab, 0x1ac, 0x5, 0x8c, 0x47, 0x2, 0x1ac, 0x1ae, 0x7, 0x41, 0x2, 
    0x2, 0x1ad, 0x1af, 0x5, 0x48, 0x25, 0x2, 0x1ae, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1b1, 0x7, 0x42, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0xb8, 0x5d, 
    0x2, 0x1b2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x5, 0x8c, 0x47, 
    0x2, 0x1b4, 0x1b6, 0x7, 0x41, 0x2, 0x2, 0x1b5, 0x1b7, 0x5, 0x42, 0x22, 
    0x2, 0x1b6, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x7, 0x42, 0x2, 
    0x2, 0x1b9, 0x1bb, 0x5, 0x70, 0x39, 0x2, 0x1ba, 0x1b9, 0x3, 0x2, 0x2, 
    0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1bc, 0x1bd, 0x5, 0xb8, 0x5d, 0x2, 0x1bd, 0x1be, 0x5, 0x6, 0x4, 
    0x2, 0x1be, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x13, 0x2, 
    0x2, 0x1c0, 0x1c1, 0x7, 0x51, 0x2, 0x2, 0x1c1, 0x1c2, 0x5, 0x3e, 0x20, 
    0x2, 0x1c2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x5, 0x44, 0x23, 
    0x2, 0x1c4, 0x1c6, 0x5, 0x46, 0x24, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x1c8, 0x7, 0x48, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 0x51, 0x2, 
    0x2, 0x1c9, 0x1cb, 0x5, 0x44, 0x23, 0x2, 0x1ca, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1cb, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ca, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x5, 0x8a, 0x46, 0x2, 
    0x1d0, 0x1d1, 0x5, 0x70, 0x39, 0x2, 0x1d1, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x1d2, 0x1d4, 0x7, 0x1b, 0x2, 0x2, 0x1d3, 0x1d5, 0x5, 0x70, 0x39, 0x2, 
    0x1d4, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1dc, 0x5, 0x4a, 0x26, 0x2, 
    0x1d7, 0x1d8, 0x7, 0x48, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x51, 0x2, 0x2, 
    0x1d9, 0x1db, 0x5, 0x4a, 0x26, 0x2, 0x1da, 0x1d7, 0x3, 0x2, 0x2, 0x2, 
    0x1db, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1dc, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1de, 
    0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e5, 0x5, 0x2a, 0x16, 0x2, 0x1e0, 
    0x1e1, 0x7, 0x48, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x51, 0x2, 0x2, 0x1e2, 
    0x1e4, 0x5, 0x2a, 0x16, 0x2, 0x1e3, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
    0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
    0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x88, 0x45, 0x2, 0x1e9, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ee, 0x5, 0x52, 0x2a, 0x2, 0x1eb, 0x1ee, 
    0x5, 0x54, 0x2b, 0x2, 0x1ec, 0x1ee, 0x5, 0x56, 0x2c, 0x2, 0x1ed, 0x1ea, 
    0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ec, 
    0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 
    0x5, 0xb8, 0x5d, 0x2, 0x1f0, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f5, 
    0x5, 0xc0, 0x61, 0x2, 0x1f2, 0x1f6, 0x5, 0x52, 0x2a, 0x2, 0x1f3, 0x1f6, 
    0x5, 0x54, 0x2b, 0x2, 0x1f4, 0x1f6, 0x5, 0x56, 0x2c, 0x2, 0x1f5, 0x1f2, 
    0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f4, 
    0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 
    0x5, 0xb8, 0x5d, 0x2, 0x1f8, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 
    0x5, 0x88, 0x45, 0x2, 0x1fa, 0x1fb, 0x5, 0x70, 0x39, 0x2, 0x1fb, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 0x88, 0x45, 0x2, 0x1fd, 0x1fe, 
    0x5, 0x70, 0x39, 0x2, 0x1fe, 0x1ff, 0x7, 0x51, 0x2, 0x2, 0x1ff, 0x200, 
    0x7, 0x2d, 0x2, 0x2, 0x200, 0x201, 0x7, 0x51, 0x2, 0x2, 0x201, 0x202, 
    0x5, 0x2a, 0x16, 0x2, 0x202, 0x55, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 
    0x5, 0x88, 0x45, 0x2, 0x204, 0x205, 0x7, 0x51, 0x2, 0x2, 0x205, 0x206, 
    0x7, 0x2d, 0x2, 0x2, 0x206, 0x207, 0x7, 0x51, 0x2, 0x2, 0x207, 0x208, 
    0x5, 0x2a, 0x16, 0x2, 0x208, 0x57, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 
    0x5, 0xc0, 0x61, 0x2, 0x20a, 0x20b, 0x5, 0x56, 0x2c, 0x2, 0x20b, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x20c, 0x20e, 0x5, 0x86, 0x44, 0x2, 0x20d, 0x20f, 
    0x5, 0x7e, 0x40, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 
    0x3, 0x2, 0x2, 0x2, 0x20f, 0x211, 0x3, 0x2, 0x2, 0x2, 0x210, 0x212, 
    0x5, 0x70, 0x39, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 
    0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 
    0x5, 0xb8, 0x5d, 0x2, 0x214, 0x215, 0x5, 0x5c, 0x2f, 0x2, 0x215, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x216, 0x218, 0x5, 0x5e, 0x30, 0x2, 0x217, 0x216, 
    0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 
    0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x21b, 0x21c, 0x5, 0xc0, 0x61, 0x2, 0x21c, 0x21d, 0x5, 
    0x8e, 0x48, 0x2, 0x21d, 0x21e, 0x5, 0x70, 0x39, 0x2, 0x21e, 0x21f, 0x5, 
    0xb8, 0x5d, 0x2, 0x21f, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x220, 0x224, 0x5, 
    0x86, 0x44, 0x2, 0x221, 0x222, 0x7, 0x44, 0x2, 0x2, 0x222, 0x223, 0x7, 
    0x51, 0x2, 0x2, 0x223, 0x225, 0x5, 0x6a, 0x36, 0x2, 0x224, 0x221, 0x3, 
    0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x3, 
    0x2, 0x2, 0x2, 0x226, 0x229, 0x5, 0xb8, 0x5d, 0x2, 0x227, 0x22a, 0x5, 
    0x64, 0x33, 0x2, 0x228, 0x22a, 0x5, 0x62, 0x32, 0x2, 0x229, 0x227, 0x3, 
    0x2, 0x2, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x22b, 0x232, 0x5, 0xc0, 0x61, 0x2, 0x22c, 0x22d, 0x5, 0x90, 
    0x49, 0x2, 0x22d, 0x22e, 0x7, 0x48, 0x2, 0x2, 0x22e, 0x22f, 0x7, 0x51, 
    0x2, 0x2, 0x22f, 0x231, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x231, 0x234, 0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 
    0x2, 0x2, 0x232, 0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x235, 0x3, 0x2, 
    0x2, 0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x235, 0x237, 0x5, 0x90, 
    0x49, 0x2, 0x236, 0x238, 0x7, 0x48, 0x2, 0x2, 0x237, 0x236, 0x3, 0x2, 
    0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x3, 0x2, 
    0x2, 0x2, 0x239, 0x23a, 0x5, 0xb8, 0x5d, 0x2, 0x23a, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x23b, 0x23c, 0x5, 0x66, 0x34, 0x2, 0x23c, 0x23d, 0x7, 0x48, 
    0x2, 0x2, 0x23d, 0x23e, 0x5, 0xb8, 0x5d, 0x2, 0x23e, 0x240, 0x3, 0x2, 
    0x2, 0x2, 0x23f, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x240, 0x243, 0x3, 0x2, 
    0x2, 0x2, 0x241, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 0x3, 0x2, 
    0x2, 0x2, 0x242, 0x244, 0x3, 0x2, 0x2, 0x2, 0x243, 0x241, 0x3, 0x2, 
    0x2, 0x2, 0x244, 0x246, 0x5, 0x66, 0x34, 0x2, 0x245, 0x247, 0x7, 0x48, 
    0x2, 0x2, 0x246, 0x245, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x3, 0x2, 
    0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x5, 0xb8, 
    0x5d, 0x2, 0x249, 0x65, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x5, 0xc0, 
    0x61, 0x2, 0x24b, 0x24d, 0x5, 0x90, 0x49, 0x2, 0x24c, 0x24e, 0x5, 0x68, 
    0x35, 0x2, 0x24d, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x3, 0x2, 
    0x2, 0x2, 0x24e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x51, 
    0x2, 0x2, 0x250, 0x251, 0x7, 0x2d, 0x2, 0x2, 0x251, 0x252, 0x7, 0x51, 
    0x2, 0x2, 0x252, 0x253, 0x5, 0x2c, 0x17, 0x2, 0x253, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x254, 0x261, 0x5, 0x78, 0x3d, 0x2, 0x255, 0x261, 0x7, 0xd, 
    0x2, 0x2, 0x256, 0x261, 0x7, 0xb, 0x2, 0x2, 0x257, 0x261, 0x7, 0xc, 
    0x2, 0x2, 0x258, 0x261, 0x7, 0x8, 0x2, 0x2, 0x259, 0x261, 0x7, 0x9, 
    0x2, 0x2, 0x25a, 0x261, 0x7, 0xa, 0x2, 0x2, 0x25b, 0x261, 0x7, 0x7, 
    0x2, 0x2, 0x25c, 0x261, 0x7, 0x4, 0x2, 0x2, 0x25d, 0x261, 0x7, 0x5, 
    0x2, 0x2, 0x25e, 0x261, 0x7, 0x6, 0x2, 0x2, 0x25f, 0x261, 0x7, 0x3, 
    0x2, 0x2, 0x260, 0x254, 0x3, 0x2, 0x2, 0x2, 0x260, 0x255, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x256, 0x3, 0x2, 0x2, 0x2, 0x260, 0x257, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x258, 0x3, 0x2, 0x2, 0x2, 0x260, 0x259, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25d, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25f, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x262, 0x264, 0x5, 0x86, 
    0x44, 0x2, 0x263, 0x265, 0x5, 0x7e, 0x40, 0x2, 0x264, 0x263, 0x3, 0x2, 
    0x2, 0x2, 0x264, 0x265, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x3, 0x2, 
    0x2, 0x2, 0x266, 0x267, 0x5, 0x70, 0x39, 0x2, 0x267, 0x268, 0x7, 0x51, 
    0x2, 0x2, 0x268, 0x269, 0x7, 0x26, 0x2, 0x2, 0x269, 0x26a, 0x5, 0xb8, 
    0x5d, 0x2, 0x26a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26d, 0x5, 0x86, 
    0x44, 0x2, 0x26c, 0x26e, 0x5, 0x7e, 0x40, 0x2, 0x26d, 0x26c, 0x3, 0x2, 
    0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 0x3, 0x2, 
    0x2, 0x2, 0x26f, 0x270, 0x7, 0x51, 0x2, 0x2, 0x270, 0x271, 0x7, 0x2d, 
    0x2, 0x2, 0x271, 0x272, 0x7, 0x51, 0x2, 0x2, 0x272, 0x273, 0x5, 0x72, 
    0x3a, 0x2, 0x273, 0x274, 0x5, 0xb8, 0x5d, 0x2, 0x274, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x276, 0x7, 0x44, 0x2, 0x2, 0x276, 0x277, 0x7, 0x51, 
    0x2, 0x2, 0x277, 0x278, 0x5, 0x72, 0x3a, 0x2, 0x278, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x279, 0x27b, 0x5, 0x74, 0x3b, 0x2, 0x27a, 0x27c, 0x7, 0x4b, 
    0x2, 0x2, 0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0x3, 0x2, 
    0x2, 0x2, 0x27c, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27f, 0x7, 0x43, 
    0x2, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x3, 0x2, 
    0x2, 0x2, 0x27f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x280, 0x286, 0x5, 0x76, 
    0x3c, 0x2, 0x281, 0x283, 0x5, 0x86, 0x44, 0x2, 0x282, 0x284, 0x5, 0x7e, 
    0x40, 0x2, 0x283, 0x282, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x286, 0x3, 0x2, 0x2, 0x2, 0x285, 0x280, 0x3, 0x2, 
    0x2, 0x2, 0x285, 0x281, 0x3, 0x2, 0x2, 0x2, 0x286, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x287, 0x296, 0x5, 0x78, 0x3d, 0x2, 0x288, 0x296, 0x5, 0x7a, 0x3e, 
    0x2, 0x289, 0x296, 0x7, 0xe, 0x2, 0x2, 0x28a, 0x296, 0x7, 0xd, 0x2, 
    0x2, 0x28b, 0x296, 0x7, 0xb, 0x2, 0x2, 0x28c, 0x296, 0x7, 0xc, 0x2, 
    0x2, 0x28d, 0x296, 0x7, 0x8, 0x2, 0x2, 0x28e, 0x296, 0x7, 0x9, 0x2, 
    0x2, 0x28f, 0x296, 0x7, 0xa, 0x2, 0x2, 0x290, 0x296, 0x7, 0x7, 0x2, 
    0x2, 0x291, 0x296, 0x7, 0x4, 0x2, 0x2, 0x292, 0x296, 0x7, 0x5, 0x2, 
    0x2, 0x293, 0x296, 0x7, 0x6, 0x2, 0x2, 0x294, 0x296, 0x7, 0x3, 0x2, 
    0x2, 0x295, 0x287, 0x3, 0x2, 0x2, 0x2, 0x295, 0x288, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x289, 0x3, 0x2, 0x2, 0x2, 0x295, 0x28a, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x295, 0x28c, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x295, 0x28e, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x295, 0x290, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x291, 0x3, 0x2, 0x2, 0x2, 0x295, 0x292, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x293, 0x3, 0x2, 0x2, 0x2, 0x295, 0x294, 0x3, 0x2, 0x2, 
    0x2, 0x296, 0x77, 0x3, 0x2, 0x2, 0x2, 0x297, 0x298, 0x7, 0xf, 0x2, 0x2, 
    0x298, 0x299, 0x5, 0x7c, 0x3f, 0x2, 0x299, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x29b, 0x7, 0x10, 0x2, 0x2, 0x29b, 0x29c, 0x5, 0x82, 0x42, 0x2, 
    0x29c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x30, 0x2, 0x2, 
    0x29e, 0x29f, 0x5, 0x9a, 0x4e, 0x2, 0x29f, 0x2a0, 0x7, 0x2f, 0x2, 0x2, 
    0x2a0, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x7, 0x30, 0x2, 0x2, 
    0x2a2, 0x2a3, 0x5, 0x80, 0x41, 0x2, 0x2a3, 0x2a4, 0x7, 0x2f, 0x2, 0x2, 
    0x2a4, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2ab, 0x5, 0x84, 0x43, 0x2, 
    0x2a6, 0x2a7, 0x7, 0x48, 0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x51, 0x2, 0x2, 
    0x2a8, 0x2aa, 0x5, 0x84, 0x43, 0x2, 0x2a9, 0x2a6, 0x3, 0x2, 0x2, 0x2, 
    0x2aa, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a9, 0x3, 0x2, 0x2, 0x2, 
    0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0x30, 0x2, 0x2, 0x2af, 
    0x2b0, 0x5, 0x84, 0x43, 0x2, 0x2b0, 0x2b1, 0x7, 0x2f, 0x2, 0x2, 0x2b1, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b5, 0x5, 0x74, 0x3b, 0x2, 0x2b3, 
    0x2b5, 0x5, 0x9a, 0x4e, 0x2, 0x2b4, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
    0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 
    0x7, 0x4f, 0x2, 0x2, 0x2b7, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 
    0x7, 0x50, 0x2, 0x2, 0x2b9, 0x89, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 
    0x7, 0x50, 0x2, 0x2, 0x2bb, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 
    0x9, 0x2, 0x2, 0x2, 0x2bd, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x9, 
    0x2, 0x2, 0x2, 0x2bf, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x9, 0x2, 
    0x2, 0x2, 0x2c1, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x9, 0x2, 0x2, 
    0x2, 0x2c3, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x26, 0x2, 
    0x2, 0x2c5, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 0x9, 0x3, 0x2, 0x2, 
    0x2c7, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cb, 0x5, 0x9a, 0x4e, 0x2, 
    0x2c9, 0x2cb, 0x5, 0xbc, 0x5f, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 
    0x2ca, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
    0x2d2, 0x5, 0x9c, 0x4f, 0x2, 0x2cd, 0x2d2, 0x5, 0x9e, 0x50, 0x2, 0x2ce, 
    0x2d2, 0x5, 0xa0, 0x51, 0x2, 0x2cf, 0x2d2, 0x5, 0xa2, 0x52, 0x2, 0x2d0, 
    0x2d2, 0x5, 0xa4, 0x53, 0x2, 0x2d1, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d1, 
    0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d1, 
    0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d2, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x1f, 0x2, 0x2, 0x2d4, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x7, 0x20, 0x2, 0x2, 0x2d6, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x9, 0x4, 0x2, 0x2, 0x2d8, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x7, 0x23, 0x2, 0x2, 0x2da, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x5, 0xbe, 0x60, 0x2, 0x2dc, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x9, 0x5, 0x2, 0x2, 0x2de, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x28, 0x2, 0x2, 0x2e0, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x9, 0x6, 0x2, 0x2, 0x2e2, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x35, 0x2, 0x2, 0x2e4, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0x2e5, 0x2e6, 0x9, 0x7, 0x2, 0x2, 0x2e6, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0x2e7, 0x2e8, 0x9, 0x8, 0x2, 0x2, 0x2e8, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0x2e9, 0x2ea, 0x7, 0x39, 0x2, 0x2, 0x2ea, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0x2eb, 0x2ec, 0x7, 0x2d, 0x2, 0x2, 0x2ec, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0x2ed, 0x2ef, 0x7, 0x53, 0x2, 0x2, 0x2ee, 0x2ed, 0x3, 0x2, 0x2, 0x2, 
    0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
    0x2f0, 0x2f2, 0x7, 0x54, 0x2, 0x2, 0x2f1, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
    0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
    0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x2f5, 
    0x2f7, 0x7, 0x53, 0x2, 0x2, 0x2f6, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f6, 
    0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f8, 
    0x2fa, 0x7, 0x1e, 0x2, 0x2, 0x2f9, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f9, 
    0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fb, 
    0x2fc, 0x7, 0x54, 0x2, 0x2, 0x2fc, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2fd, 
    0x2ff, 0x7, 0x53, 0x2, 0x2, 0x2fe, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fe, 
    0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 0x2, 0x2, 0x300, 
    0x301, 0x7, 0x1e, 0x2, 0x2, 0x301, 0x302, 0x7, 0x54, 0x2, 0x2, 0x302, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x7, 0x25, 0x2, 0x2, 0x304, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x7, 0x24, 0x2, 0x2, 0x306, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x7, 0x53, 0x2, 0x2, 0x308, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0x3f, 0xc5, 0xce, 0xd6, 0xd8, 0xdd, 0xe7, 
    0xf8, 0x103, 0x109, 0x12b, 0x13d, 0x147, 0x14c, 0x15a, 0x168, 0x16a, 
    0x170, 0x17c, 0x186, 0x18b, 0x193, 0x19d, 0x1a4, 0x1a8, 0x1ae, 0x1b6, 
    0x1ba, 0x1c5, 0x1cc, 0x1d4, 0x1dc, 0x1e5, 0x1ed, 0x1f5, 0x20e, 0x211, 
    0x219, 0x224, 0x229, 0x232, 0x237, 0x241, 0x246, 0x24d, 0x260, 0x264, 
    0x26d, 0x27b, 0x27e, 0x283, 0x285, 0x295, 0x2ab, 0x2b4, 0x2ca, 0x2d1, 
    0x2ee, 0x2f3, 0x2f6, 0x2f9, 0x2fe, 
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
