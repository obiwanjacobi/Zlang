
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\Zlang\zsharp\grammar\_test\testparser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "testparserListener.h"


/**
 * This class provides an empty implementation of testparserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  testparserBaseListener : public testparserListener {
public:

  virtual void enterTest(testparser::TestContext * /*ctx*/) override { }
  virtual void exitTest(testparser::TestContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

