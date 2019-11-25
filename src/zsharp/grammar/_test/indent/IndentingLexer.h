#pragma once
#include "antlr4-runtime.h"

class IndentingLexer : public antlr4::Lexer
{
public:
    IndentingLexer(antlr4::CharStream* input) : antlr4::Lexer(input), _indentSize(0)
    {}

private:
    int _indentSize;
};
