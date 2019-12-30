#include "ZsharpParser.h"

#include <fstream>

void ZsharpParser::SetupParser(std::unique_ptr<antlr4::ANTLRInputStream> stream)
{
    _stream = std::move(stream);
    _lexer = std::make_unique< zsharp_parserLexer>(_stream.get());
    _tokens = std::make_unique< antlr4::CommonTokenStream>(_lexer.get());
    _parser = std::make_unique<zsharp_parserParser>(_tokens.get());
}

zsharp_parserParser::FileContext* ZsharpParser::parseFile(const char* filePath)
{
    std::fstream stream;
    stream.open(filePath);

    SetupParser(std::make_unique<antlr4::ANTLRInputStream>(stream));

    zsharp_parserParser::FileContext* file = _parser->file();
    return file;
}

zsharp_parserParser::FileContext* ZsharpParser::parseFileText(const char* text)
{
    std::string str(text);

    SetupParser(std::make_unique<antlr4::ANTLRInputStream>(str));

    zsharp_parserParser::FileContext* file = _parser->file();
    return file;
}

zsharp_parserParser::SourceContext* ZsharpParser::parseText(const char* text)
{
    std::string str(text);

    SetupParser(std::make_unique<antlr4::ANTLRInputStream>(str));

    zsharp_parserParser::SourceContext* source = _parser->source();
    return source;
}

