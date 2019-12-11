
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\testparser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "testparser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by testparser.
 */
class  testparserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by testparser.
   */
    virtual antlrcpp::Any visitTest(testparser::TestContext *context) = 0;


};

