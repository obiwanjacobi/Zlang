#pragma once

#include <grammar\parser\zsharp_parserLexer.h>
#include <grammar\parser\zsharp_parserParser.h>

#include "antlr4-runtime.h"

class ZsharpParser
{
public:
    zsharp_parserParser::FileContext* parse(const char* filePath);

private:
    std::unique_ptr<antlr4::ANTLRInputStream> _stream;
    std::unique_ptr<zsharp_parserLexer> _lexer;
    std::unique_ptr<antlr4::CommonTokenStream> _tokens;
    std::unique_ptr<zsharp_parserParser> _parser;
};

