#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstIdentifier.h"
#include "AstType.h"
#include "../grammar/parser/zsharp_parserParser.h"


class AstFunctionParameter : public AstNode, public AstIdentifierSite, public AstTypeReferenceSite
{
public:
    AstFunctionParameter(zsharp_parserParser::Function_parameterContext* ctx)
        : AstNode(AstNodeType::FunctionParameter), _paramCtx(ctx), _selfCtx(nullptr)
    {}
    AstFunctionParameter(zsharp_parserParser::Function_parameter_selfContext* ctx)
        : AstNode(AstNodeType::FunctionParameter), _paramCtx(nullptr), _selfCtx(ctx)
    {}

    // possible no identifier if true
    bool isSelf() const { return _selfCtx != nullptr; }

    bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

private:
    zsharp_parserParser::Function_parameterContext* _paramCtx;
    zsharp_parserParser::Function_parameter_selfContext* _selfCtx;
};


class AstFunction : public AstCodeBlockItem, public AstCodeBlockSite, public AstIdentifierSite,
    public AstSymbolTableSite, public AstTypeReferenceSite
{
public:
    AstFunction(zsharp_parserParser::Function_defContext* function)
        : AstCodeBlockItem(AstNodeType::Function), _context(function)
    {}

    zsharp_parserParser::Function_defContext* getContext() const { return _context; }

    bool SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) override;
    bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

    const std::vector<std::shared_ptr<AstFunctionParameter>>& getParameters() const { return _parameters; }
    bool AddParameter(std::shared_ptr<AstFunctionParameter> param) {
        if (param) {
            param->setParent(this);
            _parameters.push_back(param);
            return true;
        }
        return false;
    }

    std::shared_ptr<AstSymbolTable> getSymbols() const override;
    std::shared_ptr<AstSymbolEntry> AddSymbol(const std::string& symbolName,
        AstSymbolKind type, std::shared_ptr<AstNode> node) override;
private:
    std::vector<std::shared_ptr<AstFunctionParameter>> _parameters;

    zsharp_parserParser::Function_defContext* _context;

    void AddFunctionSymbols();
};
