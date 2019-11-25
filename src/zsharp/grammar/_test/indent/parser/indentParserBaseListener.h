
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\indent\indentParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "indentParserListener.h"


/**
 * This class provides an empty implementation of indentParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  indentParserBaseListener : public indentParserListener {
public:

  virtual void enterStart(indentParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(indentParser::StartContext * /*ctx*/) override { }

  virtual void enterLine(indentParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(indentParser::LineContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

