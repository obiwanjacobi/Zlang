#include "zsharp/grammar/ZsharpParser.h"
#include "zsharp/grammar/IndentChecker.h"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Specify a file to parse.";
        return 0;
    }

    ZsharpParser parser;
    auto file = parser.parse(argv[1]);

    IndentChecker checker;
    checker.walk(file);

    return 0;
}