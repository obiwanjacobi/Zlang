#pragma once

#include "zsharp_parserLexer.h"
#include "zsharp_parserParser.h"

#include "antlr4-runtime.h"

class ZsharpParser
{
public:
    antlr4::tree::ParseTree* parse(const char* filePath);

private:
    std::unique_ptr<antlr4::ANTLRInputStream> _inputStream;
    std::unique_ptr<zsharp_parserLexer> _lexer;
    std::unique_ptr<antlr4::CommonTokenStream> _tokens;
    std::unique_ptr<zsharp_parserParser> _parser;
};

