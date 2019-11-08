#include "zsharp/grammar/ZsharpParser.h"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Specify a file to parse.";
        return 0;
    }

    ZsharpParser parser;
    auto tree = parser.parse(argv[1]);

    return 0;
}