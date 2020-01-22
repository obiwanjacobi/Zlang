#pragma once

#include "AstNode.h"
#include "AstFunction.h"
#include "AstSymbolTable.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFile : public AstNode, public AstSymbolTableSite
{
    friend class AstNodeBuilder;

public:
    AstFile(zsharp_parserParser::FileContext* fileCtx)
        : AstNode(AstNodeType::File), _fileCtx(fileCtx)
    {
        _symbols = std::make_shared<AstSymbolTable>();
    }

    const zsharp_parserParser::FileContext* getContext() const { return _fileCtx; }
    const std::vector<zsharp_parserParser::Statement_importContext*>& getImports() const { return _imports; }
    const std::vector<zsharp_parserParser::Statement_exportContext*>& getExports() const { return _exports; }
    
    const std::vector<std::shared_ptr<AstFunction>>& getFunctions() const { return _functions; }

    std::shared_ptr<AstSymbolTable> getSymbols() override { return _symbols; }
    std::shared_ptr<AstSymbolEntry> SetSymbol(const std::string& ns, const std::string& symbolName,
        AstSymbolType type, std::shared_ptr<AstNode> node) override
    {
        return _symbols->AddSymbol(ns, symbolName, type, node);
    }

protected:
    void AddImport(zsharp_parserParser::Statement_importContext* importCtx);
    void AddExport(zsharp_parserParser::Statement_exportContext* exportCtx);
    
    void AddFunction(std::shared_ptr<AstFunction> function);

private:
    std::shared_ptr<AstSymbolTable> _symbols;
    zsharp_parserParser::FileContext* _fileCtx;
    std::vector<zsharp_parserParser::Statement_importContext*> _imports;
    std::vector<zsharp_parserParser::Statement_exportContext*> _exports;
    std::vector<std::shared_ptr<AstFunction>> _functions;
};

