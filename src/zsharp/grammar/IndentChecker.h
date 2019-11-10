#pragma once

#include "parser/zsharp_parserParser.h"
#include "parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class IndentChecker : private zsharp_parserBaseVisitor
{
public:
    IndentChecker() : _indent(0), _indentSize(0), _ignore(0) { }

    void walk (zsharp_parserParser::FileContext* file);

private:
    uint32_t _indentSize;
    uint32_t _indent;
    uint32_t _ignore;

    virtual antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    virtual antlrcpp::Any visitIndent(zsharp_parserParser::IndentContext* ctx) override;

    // indent: 0
    virtual antlrcpp::Any visitStatement_module(zsharp_parserParser::Statement_moduleContext* ctx) override;
    virtual antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) override;
    virtual antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) override;
    virtual antlrcpp::Any visitFunction_decl(zsharp_parserParser::Function_declContext* ctx) override;
    virtual antlrcpp::Any visitStruct_decl(zsharp_parserParser::Struct_declContext* ctx) override;
    virtual antlrcpp::Any visitEnum_decl(zsharp_parserParser::Enum_declContext* ctx) override;

    // indent: 1
    virtual antlrcpp::Any visitStruct_field_decl(zsharp_parserParser::Struct_field_declContext* ctx) override;
    virtual antlrcpp::Any visitEnum_option_decl(zsharp_parserParser::Enum_option_declContext* ctx) override;

    // indent: relative
    virtual antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx) override;
    virtual antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx) override;
    virtual antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx) override;

    // ignore
    virtual antlrcpp::Any visitNewline(zsharp_parserParser::NewlineContext* ctx) override;
    virtual antlrcpp::Any visitEmpty_line(zsharp_parserParser::Empty_lineContext* ctx) override;
};

