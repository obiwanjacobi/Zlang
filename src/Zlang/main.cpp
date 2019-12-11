#include "zsharp/grammar/ZsharpParser.h"
#include "zsharp/grammar/IndentChecker.h"

#include <iostream>

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

    return 0;
}