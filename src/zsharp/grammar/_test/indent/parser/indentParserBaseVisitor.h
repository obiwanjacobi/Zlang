
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\indent\indentParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "indentParserVisitor.h"


/**
 * This class provides an empty implementation of indentParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  indentParserBaseVisitor : public indentParserVisitor {
public:

  virtual antlrcpp::Any visitStart(indentParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(indentParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }


};

