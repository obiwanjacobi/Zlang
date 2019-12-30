#pragma once

#include "AstModule.h"
#include "AstFile.h"

#include "../grammar/parser/zsharp_parserParser.h"

class AstBuilder
{
public:
    void Build(zsharp_parserParser::FileContext* fileCtx);
    std::unique_ptr<AstFile> BuildFile(zsharp_parserParser::FileContext* fileCtx);

private:
    AstModule* AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx);

    std::vector<std::unique_ptr<AstModule>> _modules;
};

