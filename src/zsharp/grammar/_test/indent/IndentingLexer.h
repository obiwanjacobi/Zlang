#pragma once
#include "antlr4-runtime.h"

class IndentingLexer : public antlr4::Lexer
{
public:
    IndentingLexer(antlr4::CharStream* input) 
        : antlr4::Lexer(input), _indentSize(0), _lastToken(nullptr)
    {}

    virtual void emit(std::unique_ptr<antlr4::Token> newToken) override;
    virtual std::unique_ptr<antlr4::Token> nextToken() override;

    void HandleEndOfFile();

private:
    std::unique_ptr<antlr4::Token> createDedent();
    std::unique_ptr<antlr4::CommonToken> commonToken(int tokenType, const std::string& text);

private:
    int _indentSize;
    antlr4::Token* _lastToken;
    std::stack<int> _indents;
    std::vector<antlr4::Token*> _tokens;
};
