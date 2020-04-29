#pragma once

#include "AstNode.h"
#include "AstIdentifier.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>


class AstType : public AstNode, public AstIdentifierSite
{
public:
    zsharp_parserParser::Type_nameContext* getContext() const { return _context; }

    bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) override {
        if (AstIdentifierSite::SetIdentifier(identifier)) {
            identifier->setParent(this);
            return true;
        }
        return false;
    }

    virtual bool IsEqual(std::shared_ptr<AstType> that) const {
        if (!that) return false;
        return getIdentifier()->IsEqual(that->getIdentifier());
    }

protected:
    AstType()
        : AstNode(AstNodeType::Type), _context(nullptr)
    {}
    AstType(zsharp_parserParser::Type_nameContext* ctx)
        : AstNode(AstNodeType::Type), _context(ctx)
    {}
    AstType(std::shared_ptr<AstIdentifier> identifier)
        : AstNode(AstNodeType::Type), _context(nullptr)
    {
        bool success = SetIdentifier(identifier);
        guard(success);
    }

    static void Construct(std::shared_ptr<AstType> instance, zsharp_parserParser::Type_nameContext* ctx);

private:
    zsharp_parserParser::Type_nameContext* _context;
};


class AstTypeReference;

class AstTypeDefinition : public AstType
{
public:
    static std::shared_ptr<AstTypeDefinition> Create(zsharp_parserParser::Type_defContext* ctx);

    // Do not use (needed for std::make_shared)
    AstTypeDefinition(zsharp_parserParser::Type_defContext* ctx)
        : AstType(ctx->type_ref_use()->type_ref()->type_name()),
        _context(ctx)
    {}

    // can be null
    std::shared_ptr<AstTypeReference> getBaseType() const { return _baseType; }

    void Accept(AstVisitor* visitor) override;

protected:
    AstTypeDefinition(std::shared_ptr<AstIdentifier> identifier)
        : AstType(identifier),
        _context(nullptr)
    {}

private:
    zsharp_parserParser::Type_defContext* _context;
    std::shared_ptr<AstTypeReference> _baseType;
};

class AstNumeric;

class AstTypeReference : public AstType
{
public:
    static std::shared_ptr<AstTypeReference> Create(zsharp_parserParser::Type_ref_useContext* ctx);
    static std::shared_ptr<AstTypeReference> Create(std::shared_ptr<AstTypeReference> inferredFrom);
    static std::shared_ptr<AstTypeReference> Create(std::shared_ptr<AstNode> typeSource, std::shared_ptr<AstTypeDefinition> typeDef);

    // Do not use (needed for std::make_shared)
    AstTypeReference(zsharp_parserParser::Type_ref_useContext* ctx)
        : AstType(ctx->type_ref()->type_name()),
        _isOptional(ctx->type_ref()->QUESTION() != nullptr),
        _isError(ctx->type_ref()->ERROR() != nullptr)
    {}
    AstTypeReference(std::shared_ptr< AstTypeReference> inferredFrom)
        : AstType(inferredFrom->getContext()),
        _isOptional(inferredFrom->getIsOptional()),
        _isError(inferredFrom->getIsError()),
        _inferredType(inferredFrom)
    {}
    AstTypeReference()
        : AstType(),
        _isOptional(false),
        _isError(false)
    {}

    bool getIsOptional() const { return _isOptional; }
    bool getIsError() const { return _isError; }

    virtual bool IsEqual(std::shared_ptr<AstType> that) const {
        if (!AstType::IsEqual(that)) return false;
        auto typedThat = std::dynamic_pointer_cast<AstTypeReference>(that);
        if (!typedThat) return false;

        auto typeDef = getTypeDefinition();
        auto thatTypeDef = typedThat->getTypeDefinition();

        if (typeDef && thatTypeDef) {

            return
                typeDef->IsEqual(thatTypeDef) &&
                getIsError() == typedThat->getIsError() &&
                getIsOptional() == typedThat->getIsOptional();
        }
        return false;
    }

    bool setTypeDefinition(std::shared_ptr<AstTypeDefinition> typeDefinition) {
        if (!_typeDefinition && typeDefinition) {
            _typeDefinition = typeDefinition;
            _typeDefinition->setParent(this);
            return true;
        }
        return false;
    }
    std::shared_ptr<AstTypeDefinition> getTypeDefinition() const { return _typeDefinition; }

    bool setTypeInferredFrom(std::shared_ptr<AstTypeReference> type) {
        if (!_inferredType && type) {
            _inferredType = type;
            _inferredType->setParent(this);
            return true;
        }
        return false;
    }
    std::shared_ptr<AstTypeReference> getInferredType() const { return _inferredType; }

    bool setTypeSource(std::shared_ptr<AstNode> typeSource) {
        if (!_typeSource && typeSource) {
            _typeSource = typeSource;
            return true;
        }
        return false;
    }
    std::shared_ptr<AstNode> getTypeSource() const { return _typeSource; }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    std::shared_ptr<AstTypeDefinition> _typeDefinition;
    std::shared_ptr<AstTypeReference> _inferredType;
    std::shared_ptr<AstNode> _typeSource;

    bool _isOptional;
    bool _isError;
};

class AstSymbolTable;

class AstTypeIntrinsic : public AstTypeDefinition
{
public:
    // Do not use (needed for std::make_shared)
    AstTypeIntrinsic(std::shared_ptr<AstIdentifier> identifier)
        : AstTypeDefinition(identifier)
    {}

    static void AddAll(std::shared_ptr<AstSymbolTable> symbols);
};


class AstTypeReferenceSite
{
public:
    std::shared_ptr<AstTypeReference> getTypeReference() const { return _type; }
    virtual bool SetTypeReference(std::shared_ptr<AstTypeReference> type) {
        if (!_type && type) {
            _type = type;
            return true;
        }
        return false;
    }

private:
    std::shared_ptr<AstTypeReference> _type;
};
