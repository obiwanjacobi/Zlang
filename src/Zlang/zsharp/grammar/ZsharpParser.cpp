#include "ZsharpParser.h"

#include "IndentChecker.h"

#include <fstream>


zsharp_parserParser::FileContext* ZsharpParser::parse(const char* filePath)
{
    std::fstream stream;
    stream.open(filePath);
    
    _stream = std::make_unique<antlr4::ANTLRInputStream>(stream);
    _lexer = std::make_unique< zsharp_parserLexer>(_stream.get());
    _tokens = std::make_unique< antlr4::CommonTokenStream>(_lexer.get());
    _parser = std::make_unique<zsharp_parserParser>(_tokens.get());
    
    zsharp_parserParser::FileContext* file = _parser->file();
    return file;
}
