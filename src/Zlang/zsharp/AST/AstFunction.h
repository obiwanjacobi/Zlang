#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstIdentifier.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFunctionParameter : public AstNode, public AstIdentifierSite
{
public:
    AstFunctionParameter(zsharp_parserParser::Function_parameterContext* ctx)
        : AstNode(AstNodeType::FunctionParameter), _paramCtx(ctx), _selfCtx(nullptr)
    {}
    AstFunctionParameter(zsharp_parserParser::Function_parameter_selfContext* ctx)
        : AstNode(AstNodeType::FunctionParameter), _paramCtx(nullptr), _selfCtx(ctx)
    {}

    // no identifier if true
    bool isSelf() const { return _selfCtx != nullptr; }

    const std::shared_ptr<AstIdentifier> getIdentifier() const { return _identifier; }
    bool AddIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

private:
    std::shared_ptr<AstIdentifier> _identifier;

    zsharp_parserParser::Function_parameterContext* _paramCtx;
    zsharp_parserParser::Function_parameter_selfContext* _selfCtx;
};

class AstFunction : public AstNode, public AstCodeBlockSite, public AstIdentifierSite
{
    friend class AstNodeBuilder;

public:
    AstFunction(zsharp_parserParser::Function_defContext* function)
        : AstNode(AstNodeType::Function), _function(function)
    {}

    zsharp_parserParser::Function_defContext* getContext() const { return _function; }

    bool AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) { 
        _codeblocks.push_back(codeBlock);
        return true;
    }
    const std::vector<std::shared_ptr<AstCodeBlock>>& getCodeBlocks() const { return _codeblocks; }

    const std::shared_ptr<AstIdentifier> getIdentifier() const { return _identifier; }
    bool AddIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

    const std::vector<std::shared_ptr<AstFunctionParameter>>& getParameters() const { return _parameters; }
    bool AddParameter(std::shared_ptr<AstFunctionParameter> param) {
        _parameters.push_back(param);
        param->setParent(this);
        return true;
    }

private:
    std::vector<std::shared_ptr<AstCodeBlock>> _codeblocks;
    std::shared_ptr<AstIdentifier> _identifier;
    std::vector<std::shared_ptr<AstFunctionParameter>> _parameters;

    zsharp_parserParser::Function_defContext* _function;
};
