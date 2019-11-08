#include "ZsharpParser.h"

#include "zsharp_parserLexer.h"
#include "zsharp_parserParser.h"

#include <fstream>

antlr4::tree::ParseTree* ZsharpParser::parse(const char* filePath)
{
    std::string buffer;
    std::fstream stream;
    stream.open(filePath);
    
    antlr4::ANTLRInputStream inputStream(stream);

    zsharp_parserLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);

    zsharp_parserParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.file();
    return tree;
}
