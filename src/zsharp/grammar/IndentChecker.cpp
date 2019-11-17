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
    auto l = ctx->getText().length();

    if (_indentSize == 0 && l > 0)
    {
        _indentSize = l;
    }

    /*if (l % _indentSize)
    {
        std::cout << "Irregular indentation at line: " << ctx->getStart()->getLine() << "\r\n";
    }*/

    if (_indent.top() != l / _indentSize)
    {
        std::cout << "Invalid indentation at line: " << ctx->getStart()->getLine() << "\r\n";
    }

    return nullptr;
}

// indent: 0
antlrcpp::Any IndentChecker::visitStatement_module(zsharp_parserParser::Statement_moduleContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitFunction_decl(zsharp_parserParser::Function_declContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitStruct_decl(zsharp_parserParser::Struct_declContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

antlrcpp::Any IndentChecker::visitEnum_decl(zsharp_parserParser::Enum_declContext* ctx)
{
    clearIndent();
    return visitChildren(ctx);
}

// indent: 1
antlrcpp::Any IndentChecker::visitStruct_field_decl(zsharp_parserParser::Struct_field_declContext* ctx)
{
    nextIndent();
    auto retval = visitChildren(ctx);
    _indent.pop();
    return retval;
}

antlrcpp::Any IndentChecker::visitEnum_option_decl(zsharp_parserParser::Enum_option_declContext* ctx)
{
    nextIndent();
    auto retval = visitChildren(ctx);
    _indent.pop();
    return retval;
}

// indent: relative
antlrcpp::Any IndentChecker::visitCodeblock(zsharp_parserParser::CodeblockContext* ctx)
{
    auto fn = dynamic_cast<zsharp_parserParser::Function_declContext*>(ctx->parent);
    auto ifstmt = dynamic_cast<zsharp_parserParser::Statement_ifContext*>(ctx->parent);
    auto elsestmt = dynamic_cast<zsharp_parserParser::Statement_elseContext*>(ctx->parent);

    if (fn || ifstmt || elsestmt)
    {
        nextIndent();
    }

    auto retval = visitChildren(ctx);
    if (ifstmt || elsestmt)
    {
        _indent.pop();
    }
    if (fn)
    {
        // reset
        clearIndent();
    }

    return retval;
}

antlrcpp::Any IndentChecker::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    auto retval = visitChildren(ctx);
    return retval;
}

antlrcpp::Any IndentChecker::visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx)
{
    auto retval = visitChildren(ctx);
    return retval;
}

antlrcpp::Any IndentChecker::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    // `else` is a child of `if` in the parse tree.
    // juggle the indent to re-align `else` with its parent `if`.
    int indent = _indent.top();
    _indent.pop();
    auto retval = visitChildren(ctx);
    _indent.push(indent);
    return retval;
}

antlrcpp::Any IndentChecker::visitVariable_decl(zsharp_parserParser::Variable_declContext* ctx)
{
    // `variable_decl` has optional indent
    if (ctx->indent() == nullptr && _indent.top() > 0)
    {
        std::cout << "Missing indentation at line: " << ctx->getStart()->getLine() << "\r\n";
    }

    auto retval = visitChildren(ctx);
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