#pragma once

#include "AstNode.h"
#include "AstFile.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstModule : public AstNode
{
    friend class AstBuilder;

public:
    AstModule() : AstNode(AstNodeType::Module, nullptr)
    {}

    const std::string& getName() const { return _name; }
    
    // files linked to this module
    const std::vector<std::unique_ptr<AstFile>>& getFiles() const { return _files; }

protected:
    void AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx);
    void AddFile(std::unique_ptr<AstFile> file);

private:
    std::vector<zsharp_parserParser::Statement_moduleContext*> _fileModules;
    std::vector<std::unique_ptr<AstFile>> _files;

    std::string _name;
};

