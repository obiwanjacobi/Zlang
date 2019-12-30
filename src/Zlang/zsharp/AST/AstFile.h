#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFile : public AstNode
{
    friend class AstNodeBuilder;

public:
    AstFile(zsharp_parserParser::FileContext* fileCtx)
        : AstNode(AstNodeType::File, nullptr), _fileCtx(fileCtx)
    {}

    const std::vector<zsharp_parserParser::Statement_importContext*>& getImports() const { return _imports; }
    const std::vector<zsharp_parserParser::Statement_exportContext*>& getExports() const { return _exports; }

protected:
    void AddImport(zsharp_parserParser::Statement_importContext* importCtx);
    void AddExport(zsharp_parserParser::Statement_exportContext* exportCtx);

private:
    zsharp_parserParser::FileContext* _fileCtx;
    std::vector<zsharp_parserParser::Statement_importContext*> _imports;
    std::vector<zsharp_parserParser::Statement_exportContext*> _exports;
};

