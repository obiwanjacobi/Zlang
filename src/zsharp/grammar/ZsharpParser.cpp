#include "ZsharpParser.h"

#include <fstream>

antlr4::tree::ParseTree* ZsharpParser::parse(const char* filePath)
{
    std::fstream stream;
    stream.open(filePath);
    
    _inputStream = std::make_unique<antlr4::ANTLRInputStream>(stream);
    _lexer = std::make_unique< zsharp_parserLexer>(_inputStream.get());
    _tokens = std::make_unique< antlr4::CommonTokenStream>(_lexer.get());
    _parser = std::make_unique<zsharp_parserParser>(_tokens.get());
    
    antlr4::tree::ParseTree* tree = _parser->file();
    return tree;
}
