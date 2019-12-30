#pragma once

#include "../grammar/parser/zsharp_parserParser.h"

class ParseTreeNavigator
{
public:
    zsharp_parserParser::Module_statementContext* ToModuleStatement(zsharp_parserParser::FileContext* fileCtx)
    {
        assert(fileCtx != nullptr);

        for (zsharp_parserParser::SourceContext* src : fileCtx->source()) {
            auto modStat = src->module_statement();
            if (modStat != nullptr) { return modStat; }
        }

        return nullptr;
    }

    zsharp_parserParser::Statement_moduleContext* ToStatementModule(zsharp_parserParser::FileContext* fileCtx)
    {
        auto moduleStatement = ToModuleStatement(fileCtx);

        if (moduleStatement != nullptr) {
            return moduleStatement->statement_module();
        }

        return nullptr;
    }
};

