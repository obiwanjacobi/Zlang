#pragma once

#include "parser/zsharp_parserLexer.h"
#include "parser/zsharp_parserParser.h"

#include "antlr4-runtime.h"

class ZsharpParser
{
public:
    zsharp_parserParser::FileContext* parseFile(const char* filePath);
    zsharp_parserParser::FileContext* parseFileText(const char* text);
    zsharp_parserParser::SourceContext* parseText(const char* text);

    bool hasErrors() const { return _parser->getNumberOfSyntaxErrors() > 0; }

private:
    void SetupParser(std::unique_ptr < antlr4::ANTLRInputStream> stream);

    std::unique_ptr<antlr4::ANTLRInputStream> _stream;
    std::unique_ptr<zsharp_parserLexer> _lexer;
    std::unique_ptr<antlr4::CommonTokenStream> _tokens;
    std::unique_ptr<zsharp_parserParser> _parser;
};

