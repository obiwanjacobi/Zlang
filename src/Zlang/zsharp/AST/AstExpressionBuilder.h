#pragma once

#include "AstExpression.h"

#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstExpressionBuilder : protected zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:

    std::shared_ptr<AstExpression> Build(zsharp_parserParser::Expression_valueContext* expressionValueCtx) {
        auto val = visitExpression_value(expressionValueCtx);

        if (val.is<std::shared_ptr<AstExpression>>()) {
            return val.as<std::shared_ptr<AstExpression>>();
        }

        return nullptr;
    }

    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

private:
};

