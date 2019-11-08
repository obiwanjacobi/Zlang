#pragma once

#include "antlr4-runtime.h"

class ZsharpParser
{
public:
    antlr4::tree::ParseTree* parse(const char* filePath);
};

