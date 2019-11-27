#include "IndentingLexer.h"


void IndentingLexer::emit(std::unique_ptr<antlr4::Token> newToken)
{
    antlr4::Lexer::emit(std::move(newToken));
}
