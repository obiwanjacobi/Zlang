
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\testparser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "testparser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by testparser.
 */
class  testparserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTest(testparser::TestContext *ctx) = 0;
  virtual void exitTest(testparser::TestContext *ctx) = 0;


};

