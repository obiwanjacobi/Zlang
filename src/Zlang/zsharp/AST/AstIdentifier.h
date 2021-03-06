#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include "../../Utils.h"
#include <memory>

enum class AstIdentifierType
{
    Unknown,
    Type,
    Variable,
    Parameter,
    Function,
    Field,
    EnumOption
};

class AstIdentifier : public AstNode
{
public:
    AstIdentifier(zsharp_parserParser::Identifier_typeContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(ctx), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_varContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(ctx),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_paramContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(ctx), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_funcContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(ctx), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_fieldContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(ctx), _enumOptCtx(nullptr)
    {}
    AstIdentifier(zsharp_parserParser::Identifier_enumoptionContext* ctx)
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(ctx)
    {}
    // Do not use (needed for make_shared)
    AstIdentifier()
        : AstNode(AstNodeType::Identifier),
        _typeCtx(nullptr), _varCtx(nullptr),
        _paramCtx(nullptr), _funcCtx(nullptr), _fieldCtx(nullptr), _enumOptCtx(nullptr)
    {}

    virtual const std::string getName() const;
    virtual const AstIdentifierType getType() const;

    void Accept(AstVisitor* visitor) override;

    virtual std::shared_ptr<AstIdentifier> Clone() const;
    
    virtual bool IsEqual(std::shared_ptr<AstIdentifier> that) const {
        if (!that) return false;
        return getName() == that->getName() && 
            getType() == that->getType();
    }

protected:
    void CopyTo(std::shared_ptr<AstIdentifier> target) const {
        target->_enumOptCtx = _enumOptCtx;
        target->_fieldCtx = _fieldCtx;
        target->_funcCtx = _funcCtx;
        target->_paramCtx = _paramCtx;
        target->_typeCtx = _typeCtx;
        target->_varCtx = _varCtx;
    }

private:
    zsharp_parserParser::Identifier_typeContext* _typeCtx;
    zsharp_parserParser::Identifier_varContext* _varCtx;
    zsharp_parserParser::Identifier_paramContext* _paramCtx;
    zsharp_parserParser::Identifier_funcContext* _funcCtx;
    zsharp_parserParser::Identifier_fieldContext* _fieldCtx;
    zsharp_parserParser::Identifier_enumoptionContext* _enumOptCtx;
};


class AstIdentifierIntrinsic : public AstIdentifier
{
public:
    AstIdentifierIntrinsic(const std::string name, AstIdentifierType type)
        : _name(name), _type(type)
    {}

    const std::string getName() const override { return _name; }
    const AstIdentifierType getType() const override { return _type; }

    std::shared_ptr<AstIdentifier> Clone() const override {
        return std::make_shared<AstIdentifierIntrinsic>(_name, _type);
    }

private:
    std::string _name;
    AstIdentifierType _type;
};


class AstSymbolEntry;

class AstIdentifierSite
{
public:
    virtual bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) {
        if (!_identifier && identifier) {
            _identifier = identifier;
            return true;
        }
        return false;
    }
    std::shared_ptr<AstIdentifier> getIdentifier() const { return _identifier; }

protected:
    // walk parents up and test for AstSymbolTableSite
    std::shared_ptr<AstSymbolEntry> AddSymbol(std::shared_ptr<AstIdentifier> identifier);

private:
    std::shared_ptr<AstIdentifier> _identifier;
};
