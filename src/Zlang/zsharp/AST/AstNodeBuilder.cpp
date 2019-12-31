#include "AstNodeBuilder.h"
#include "AstFile.h"

#include "../grammar/parser/zsharp_parserParser.h"
#include "AstFunction.h"

antlrcpp::Any AstNodeBuilder::aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult)
{
    return nextResult;
}

antlrcpp::Any AstNodeBuilder::visitFile(zsharp_parserParser::FileContext* ctx) {
    auto file = std::make_shared<AstFile>(ctx);
    _current = file.get();

    auto any = base::visitFile(ctx);

    return file;
}

antlrcpp::Any AstNodeBuilder::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) {
    if (_current.is<AstFile*>()) {
        auto file = _current.as<AstFile*>();
        file->AddImport(ctx);
    }

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) {
    if (_current.is<AstFile*>()) {
        auto file = _current.as<AstFile*>();
        file->AddExport(ctx);
    }

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitFunction_def(zsharp_parserParser::Function_defContext* ctx)
{
    if (_current.is<AstFile*>()) {
        auto file = _current.as<AstFile*>();
        auto function = std::make_shared<AstFunction>(ctx);

        file->AddFunction(function);
    }

    return nullptr;
}