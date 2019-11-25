
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\indent\indentParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "indentParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by indentParser.
 */
class  indentParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by indentParser.
   */
    virtual antlrcpp::Any visitStart(indentParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitLine(indentParser::LineContext *context) = 0;


};

