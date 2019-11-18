
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\testparser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "testparserVisitor.h"


/**
 * This class provides an empty implementation of testparserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  testparserBaseVisitor : public testparserVisitor {
public:

  virtual antlrcpp::Any visitTest(testparser::TestContext *ctx) override {
    return visitChildren(ctx);
  }


};

