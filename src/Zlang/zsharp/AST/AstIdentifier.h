#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include "../../Utils.h"
#include <memory>

class AstIdentifier;

class AstIdentifierSite
{
public:
    virtual bool AddIdentifier(std::shared_ptr<AstIdentifier> identifier) = 0;

protected:
    // AddSymbol()
    // walk parents up and test for AstIdentifierSite
    // concat all identifiers - what if there are more than one on that site??
    // find AstFile and add resulting Symbol
};

class AstIdentifier : public AstNode
{
public:
    AstIdentifier(zsharp_parserParser::Identifier_boolContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(ctx), _typeCtx(nullptr), _varCtx(nullptr), 
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {
        guard(_boolCtx->variable_ref());
        guard(_boolCtx->variable_ref()->identifier_var());
    }
    AstIdentifier(zsharp_parserParser::Identifier_typeContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(ctx), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_varContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(nullptr), _varCtx(ctx),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_paramContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(ctx), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_funcContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(ctx), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_fieldContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(ctx), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_enumoptionContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _boolCtx(nullptr), _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(ctx)
    {}

    const std::string getName() const;

private:
    zsharp_parserParser::Identifier_boolContext* _boolCtx;
    zsharp_parserParser::Identifier_typeContext* _typeCtx;
    zsharp_parserParser::Identifier_varContext* _varCtx;
    zsharp_parserParser::Identifier_paramContext* _paramCtx;
    zsharp_parserParser::Identifier_funcContext* _funcCtx;
    zsharp_parserParser::Identifier_fieldContext* _fieldCtx;
    zsharp_parserParser::Identifier_enumoptionContext* _enumOptCtx;
};
