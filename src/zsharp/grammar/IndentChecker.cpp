#include "IndentChecker.h"


void IndentChecker::walk (zsharp_parserParser::FileContext* file)
{
    auto any = file->accept(this);
}

antlrcpp::Any IndentChecker::aggregateResult(antlrcpp::Any /*aggregate*/, const antlrcpp::Any& nextResult) {
    return nextResult;
}

antlrcpp::Any IndentChecker::visitIndent(zsharp_parserParser::IndentContext* ctx)
{
    if (_ignore)
    {
        _ignore--;
        return nullptr;
    }


    auto l = ctx->getText().length();

    if (_indentSize == 0 && l > 0)
    {
        _indentSize = l;
    }

    if (_indent != l / _indentSize)
    {
        std::cout << "Invalid indentation at line: " << ctx->getStart()->getLine() << "\r\n";
    }
    
    return nullptr;
}

// indent: 0
antlrcpp::Any IndentChecker::visitStatement_module(zsharp_parserParser::Statement_moduleContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitFunction_decl(zsharp_parserParser::Function_declContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStruct_decl(zsharp_parserParser::Struct_declContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitEnum_decl(zsharp_parserParser::Enum_declContext* ctx)
{
    _indent = 0;
    return visitChildren(ctx);
}

// indent: 1
antlrcpp::Any IndentChecker::visitStruct_field_decl(zsharp_parserParser::Struct_field_declContext* ctx)
{
    _indent = 1;
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitEnum_option_decl(zsharp_parserParser::Enum_option_declContext* ctx)
{
    _indent = 1;
    return visitChildren(ctx);
}

// indent: relative
antlrcpp::Any IndentChecker::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    _indent++;
    auto retval = visitChildren(ctx);
    _indent--;
    return retval;
}

antlrcpp::Any IndentChecker::visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx)
{
    _indent++;
    auto retval = visitChildren(ctx);
    // _indent--;
    return retval;
}

antlrcpp::Any IndentChecker::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    _indent++;
    auto retval = visitChildren(ctx);
    // _indent--;
    return retval;
}

antlrcpp::Any IndentChecker::visitNewline(zsharp_parserParser::NewlineContext* ctx)
{
    // do not visit children
    return nullptr;
}

antlrcpp::Any IndentChecker::visitEmpty_line(zsharp_parserParser::Empty_lineContext* ctx)
{
    // do not visit children
    return nullptr;
}