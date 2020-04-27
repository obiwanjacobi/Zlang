#pragma once

#include "AstModule.h"
#include "AstFile.h"
#include "AstError.h"
#include "AstBuilderContext.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstBuilder : private AstBuilderContext
{
public:
    AstBuilder(int indent = 0)
        : AstBuilderContext(indent)
    {}

    void Build(zsharp_parserParser::FileContext* fileCtx);
    std::shared_ptr<AstFile> BuildFile(const std::string& moduleName, zsharp_parserParser::FileContext* fileCtx);

    const std::vector<std::shared_ptr<AstModule>>& getModules() const { return _modules; }

    bool hasErrors() const { return AstBuilderContext::hasErrors(); }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return AstBuilderContext::getErrors(); }

private:
    std::shared_ptr<AstModule> AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx);

    std::vector<std::shared_ptr<AstModule>> _modules;
};

