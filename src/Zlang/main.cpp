#include "zsharp/grammar/ZsharpParser.h"

#include <iostream>

void testZsharp(const char* filePath)
{
    ZsharpParser parser;
    auto file = parser.parseFile(filePath);
}

int main(int argc, char **argv)
{
    testZsharp(argv[1]);

    return 0;
}