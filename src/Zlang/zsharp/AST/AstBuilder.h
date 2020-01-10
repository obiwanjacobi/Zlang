#pragma once

#include "AstModule.h"
#include "AstFile.h"
#include "AstError.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstBuilder
{
public:
    void Build(zsharp_parserParser::FileContext* fileCtx);
    std::shared_ptr<AstFile> BuildFile(std::string moduleName, zsharp_parserParser::FileContext* fileCtx);

    const std::vector<std::shared_ptr<AstModule>>& getModules() const { return _modules; }

    bool hasErrors() const { return _errors.size() > 0; }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return _errors; }

private:
    std::shared_ptr<AstModule> AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx);

    std::vector<std::shared_ptr<AstModule>> _modules;

    void AddErrors(std::vector<std::shared_ptr<AstError>> errors) { 
        _errors.insert(_errors.end(), errors.begin(), errors.end());
    }
    std::vector<std::shared_ptr<AstError>> _errors;
};

