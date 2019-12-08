#include "zsharp/grammar/ZsharpParser.h"
#include "zsharp/grammar/IndentChecker.h"

#include "zsharp/grammar/_test/indent/parser/indentLexer.h"
#include "zsharp/grammar/_test/indent/parser/indentParser.h"

#include <iostream>

void testIndent()
{
    std::fstream fileStream;
    fileStream.open("zsharp/grammar/_test/indent/indenttest.txt");
    
    auto stream = std::make_unique<antlr4::ANTLRInputStream>(fileStream);
    auto lexer = std::make_unique<indentLexer>(stream.get());
    auto tokens = std::make_unique<antlr4::CommonTokenStream>(lexer.get());
    auto parser = std::make_unique<indentParser>(tokens.get());
    
    indentParser::StartContext* start = parser->start();

    std::cout << start->getText();
}

void testZsharp(const char* filePath)
{
    ZsharpParser parser;
    auto file = parser.parse(filePath);

    IndentChecker checker;
    checker.walk(file);
}

int main(int argc, char **argv)
{
    testZsharp(argv[1]);
    //testIndent();

    return 0;
}