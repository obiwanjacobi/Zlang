#include "pch.h"
#include "Utils.h"
#include "../Zlang/zsharp/grammar/ZsharpParser.h"

bool ParserSmokeTest(const char* src)
{
    ZsharpParser parser;
    parser.parseText(src);
    return !parser.hasErrors();
}
