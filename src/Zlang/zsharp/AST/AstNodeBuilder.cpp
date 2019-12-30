#include "AstNodeBuilder.h"
#include "AstFile.h"

#include "../grammar/parser/zsharp_parserParser.h"

antlrcpp::Any AstNodeBuilder::aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult)
{
    return nextResult;
}

antlrcpp::Any AstNodeBuilder::visitFile(zsharp_parserParser::FileContext* ctx) {
    auto file = std::make_unique<AstFile>(ctx);
    _current = file.get();

    auto any = base::visitFile(ctx);

    return std::move(file);
}

antlrcpp::Any AstNodeBuilder::visitSource(zsharp_parserParser::SourceContext* ctx)
{
    if (ctx->module_statement() != nullptr) {
        if (_current.is<AstFile*>()) {
            auto file = _current.as<AstFile*>();
            file->AddImport(ctx->module_statement()->statement_import());
            file->AddExport(ctx->module_statement()->statement_export());
        }
    }

    return base::visitSource(ctx);
}