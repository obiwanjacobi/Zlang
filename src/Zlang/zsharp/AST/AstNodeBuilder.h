#pragma once

#include "AstNode.h"

#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstNodeBuilder : public zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:
    AstNodeBuilder(std::string namespace_)
        : _namespace(namespace_)
    {}

    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    antlrcpp::Any visitFile(zsharp_parserParser::FileContext* ctx) override;
    antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) override;
    antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) override;
    antlrcpp::Any visitFunction_def(zsharp_parserParser::Function_defContext* ctx) override;

private:
    std::string ToQualifiedName(const std::string& name);

    std::string _namespace;
    antlrcpp::Any _current;
};

