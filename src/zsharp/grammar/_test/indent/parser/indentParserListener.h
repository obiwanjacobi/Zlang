
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\_test\indent\indentParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "indentParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by indentParser.
 */
class  indentParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(indentParser::StartContext *ctx) = 0;
  virtual void exitStart(indentParser::StartContext *ctx) = 0;

  virtual void enterLine(indentParser::LineContext *ctx) = 0;
  virtual void exitLine(indentParser::LineContext *ctx) = 0;


};

