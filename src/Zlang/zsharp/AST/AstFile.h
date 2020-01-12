#pragma once

#include "AstNode.h"
#include "AstFunction.h"
#include "AstSymbolTable.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFile : public AstNode
{
    friend class AstNodeBuilder;

public:
    AstFile(zsharp_parserParser::FileContext* fileCtx)
        : AstNode(AstNodeType::File), _fileCtx(fileCtx)
    {}

    const zsharp_parserParser::FileContext* getContext() const { return _fileCtx; }
    const std::vector<zsharp_parserParser::Statement_importContext*>& getImports() const { return _imports; }
    const std::vector<zsharp_parserParser::Statement_exportContext*>& getExports() const { return _exports; }
    
    const std::vector<std::shared_ptr<AstFunction>>& getFunctions() const { return _functions; }

protected:
    void AddImport(zsharp_parserParser::Statement_importContext* importCtx);
    void AddExport(zsharp_parserParser::Statement_exportContext* exportCtx);
    
    void AddFunction(std::shared_ptr<AstFunction> function);
    bool functionIsExport(const std::string& functionName) const;
    bool functionIsExport(std::shared_ptr<AstFunction> function);

    AstSymbolTable& getSymbols() { return _symbols; }

private:
    AstSymbolTable _symbols;
    zsharp_parserParser::FileContext* _fileCtx;
    std::vector<zsharp_parserParser::Statement_importContext*> _imports;
    std::vector<zsharp_parserParser::Statement_exportContext*> _exports;
    std::vector<std::shared_ptr<AstFunction>> _functions;
};

