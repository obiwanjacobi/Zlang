#pragma once

#include "AstNumeric.h"

#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstNumericBuilder : protected zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:
    AstNumericBuilder()
        : _parent(nullptr)
    {}
    AstNumericBuilder(std::shared_ptr<AstNode> parent)
        : _parent(parent)
    {}
    
    std::shared_ptr<AstNumeric> Build(zsharp_parserParser::NumberContext* numberCtx) {
        auto val = visitNumber(numberCtx);
        if (val.is<std::shared_ptr<AstNumeric>>()) {
            return val.as<std::shared_ptr<AstNumeric>>();
        }
        return nullptr;
    }


    std::shared_ptr<AstNumeric> Test(antlr4::ParserRuleContext* ctx) {
        auto val = visit(ctx);
        if (val.is<std::shared_ptr<AstNumeric>>()) {
            return val.as<std::shared_ptr<AstNumeric>>();
        }
        return nullptr;
    }

protected:
    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;
    antlrcpp::Any visitNumber(zsharp_parserParser::NumberContext* ctx) override;
    antlrcpp::Any visitNumber_bin(zsharp_parserParser::Number_binContext* ctx) override;
    antlrcpp::Any visitNumber_oct(zsharp_parserParser::Number_octContext* ctx) override;
    antlrcpp::Any visitNumber_dec(zsharp_parserParser::Number_decContext* ctx) override;
    antlrcpp::Any visitNumber_hex(zsharp_parserParser::Number_hexContext* ctx) override;
    antlrcpp::Any visitNumber_char(zsharp_parserParser::Number_charContext* ctx) override;

private:
    std::shared_ptr<AstNode> _parent;
};

