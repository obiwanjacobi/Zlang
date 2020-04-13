#pragma once

#include "../grammar/parser/zsharp_parserParser.h"

class ParseTreeNavigator
{
public:
    zsharp_parserParser::Module_statementContext* ToModuleStatement(zsharp_parserParser::FileContext* fileCtx)
    {
        assert(fileCtx);

        for (zsharp_parserParser::SourceContext* src : fileCtx->source()) {
            auto modStat = src->module_statement();
            if (modStat) { 
                return modStat; 
            }
        }

        return nullptr;
    }

    zsharp_parserParser::Statement_moduleContext* ToStatementModule(zsharp_parserParser::FileContext* fileCtx)
    {
        auto moduleStatement = ToModuleStatement(fileCtx);

        if (moduleStatement) {
            return moduleStatement->statement_module();
        }

        return nullptr;
    }
};

