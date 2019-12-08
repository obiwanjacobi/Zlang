#include "IndentingLexer.h"
#include "parser/indentLexer.h"

void IndentingLexer::emit(std::unique_ptr<antlr4::Token> newToken)
{
    antlr4::Lexer::setToken(std::move(newToken));
    _tokens.push_back(newToken.get());
}

std::unique_ptr<antlr4::Token> IndentingLexer::nextToken()
{
    HandleEndOfFile();

    auto next = antlr4::Lexer::nextToken();

    if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL) {
        // Keep track of the last token on the default channel.
        _lastToken = next.get();
    }

    if (_tokens.empty())
    {
        return next;
    }
    else
    {
        auto token = std::unique_ptr<antlr4::Token>(_tokens.at(0));
        _tokens.erase(_tokens.begin());
        return token;
    }
}

void IndentingLexer::HandleEndOfFile()
{
    if (antlr4::Lexer::_input->LA(1) == EOF && !_indents.empty()) {
        // Remove any trailing EOF tokens from our buffer.
        for (int i = _tokens.size() - 1; i >= 0; i--) {
            if (_tokens.at(i)->getType() == indentLexer::EOF) {
                _tokens.erase(_tokens.begin() + i);
            }
        }

        // First emit an extra line break that serves as the end of the statement.
        emit(commonToken(indentLexer::EOL, "\n"));

        // Now emit as much DEDENT tokens as needed.
        while (!_indents.empty()) {
            emit(createDedent());
            _indents.pop();
        }

        // Put the EOF back on the token stream.
        emit(commonToken(indentLexer::EOF, "<EOF>"));
    }
}

std::unique_ptr<antlr4::Token> IndentingLexer::createDedent()
{
    auto dedent = commonToken(indentLexer::DEDENT, "");
    dedent->setLine(_lastToken->getLine());
    return std::move(dedent);
}

std::unique_ptr<antlr4::CommonToken> IndentingLexer::commonToken(int tokenType, const std::string& text)
{
    size_t len = text.length();
    size_t charPos = getCharIndex();
    size_t stop = charPos - 1;
    size_t start = len == 0 ? stop : stop - len + 1;
    size_t line = getLine();

    std::pair<antlr4::TokenSource*, antlr4::CharStream*> source(this, this->_input);
    return _factory->create(source, tokenType, text, DEFAULT_TOKEN_CHANNEL, start, stop, line, charPos);
}