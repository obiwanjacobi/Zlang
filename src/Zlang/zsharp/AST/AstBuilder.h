#pragma once

#include "AstModule.h"
#include "AstFile.h"

#include "../grammar/parser/zsharp_parserParser.h"

class AstBuilder
{
public:
    void Build(zsharp_parserParser::FileContext* fileCtx);
    std::shared_ptr<AstFile> BuildFile(zsharp_parserParser::FileContext* fileCtx);

    const std::vector<std::shared_ptr<AstModule>>& getModules() const { return _modules; }

private:
    std::shared_ptr<AstModule> AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx);

    std::vector<std::shared_ptr<AstModule>> _modules;
};

