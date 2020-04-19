#pragma once

#include "AstNode.h"
#include "AstFunction.h"
#include "AstSymbolTable.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFile : public AstNode, public AstSymbolTableSiteImpl, public AstCodeBlockSite
{
public:
    AstFile(std::string scopeName, zsharp_parserParser::FileContext* fileCtx)
        : AstNode(AstNodeType::File), AstSymbolTableSiteImpl(scopeName),
        _fileCtx(fileCtx)
    {
        auto codeBlock = std::make_shared<AstCodeBlock>(scopeName, nullptr, nullptr);
        SetCodeBlock(codeBlock);
    }

    const zsharp_parserParser::FileContext* getContext() const { return _fileCtx; }
    const std::vector<zsharp_parserParser::Statement_importContext*>& getImports() const { return _imports; }
    const std::vector<zsharp_parserParser::Statement_exportContext*>& getExports() const { return _exports; }
    
    const std::vector<std::shared_ptr<AstFunction>>& getFunctions() const { return _functions; }

    bool AddImport(zsharp_parserParser::Statement_importContext* importCtx);
    bool AddExport(zsharp_parserParser::Statement_exportContext* exportCtx);
    
    bool AddFunction(std::shared_ptr<AstFunction> function);

    void Accept(AstVisitor* visitor) override;

private:
    
    zsharp_parserParser::FileContext* _fileCtx;
    std::vector<zsharp_parserParser::Statement_importContext*> _imports;
    std::vector<zsharp_parserParser::Statement_exportContext*> _exports;
    std::vector<std::shared_ptr<AstFunction>> _functions;
};
