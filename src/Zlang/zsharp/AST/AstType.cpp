#include "AstType.h"
#include "AstVisitor.h"
#include "AstSymbolTable.h"

static const std::shared_ptr<AstIdentifierIntrinsic> U8   = std::make_shared<AstIdentifierIntrinsic>("U8", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U16  = std::make_shared<AstIdentifierIntrinsic>("U16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U24  = std::make_shared<AstIdentifierIntrinsic>("U24", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U32  = std::make_shared<AstIdentifierIntrinsic>("U32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I8   = std::make_shared<AstIdentifierIntrinsic>("I8", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I16  = std::make_shared<AstIdentifierIntrinsic>("I16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I24  = std::make_shared<AstIdentifierIntrinsic>("I24", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I32  = std::make_shared<AstIdentifierIntrinsic>("I32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> F16  = std::make_shared<AstIdentifierIntrinsic>("F16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> F32  = std::make_shared<AstIdentifierIntrinsic>("F32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> Str  = std::make_shared<AstIdentifierIntrinsic>("Str", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> Bool = std::make_shared<AstIdentifierIntrinsic>("Bool", AstIdentifierType::Type);


static const std::shared_ptr<AstTypeIntrinsic> TypeU8   = std::make_shared<AstTypeIntrinsic>(U8);
static const std::shared_ptr<AstTypeIntrinsic> TypeU16  = std::make_shared<AstTypeIntrinsic>(U16);
static const std::shared_ptr<AstTypeIntrinsic> TypeU24  = std::make_shared<AstTypeIntrinsic>(U24);
static const std::shared_ptr<AstTypeIntrinsic> TypeU32  = std::make_shared<AstTypeIntrinsic>(U32);
static const std::shared_ptr<AstTypeIntrinsic> TypeI8   = std::make_shared<AstTypeIntrinsic>(I8);
static const std::shared_ptr<AstTypeIntrinsic> TypeI16  = std::make_shared<AstTypeIntrinsic>(I16);
static const std::shared_ptr<AstTypeIntrinsic> TypeI24  = std::make_shared<AstTypeIntrinsic>(I24);
static const std::shared_ptr<AstTypeIntrinsic> TypeI32  = std::make_shared<AstTypeIntrinsic>(I32);
static const std::shared_ptr<AstTypeIntrinsic> TypeF16  = std::make_shared<AstTypeIntrinsic>(F16);
static const std::shared_ptr<AstTypeIntrinsic> TypeF32  = std::make_shared<AstTypeIntrinsic>(F32);
static const std::shared_ptr<AstTypeIntrinsic> TypeStr  = std::make_shared<AstTypeIntrinsic>(Str);
static const std::shared_ptr<AstTypeIntrinsic> TypeBool = std::make_shared<AstTypeIntrinsic>(Bool);


void AstTypeReference::Accept(AstVisitor* visitor) {
    visitor->VisitTypeReference(this);
}
void AstTypeReference::VisitChildren(AstVisitor* visitor) {
    getIdentifier()->Accept(visitor);
}

void AstTypeDefinition::Accept(AstVisitor* visitor) {
    visitor->VisitTypeDefinition(this);
}

std::shared_ptr<AstIdentifier> SelectKnownIdentifier(zsharp_parserParser::Known_typesContext* ctx)
{
    if (!ctx) return nullptr;
    //if (ctx->type_Bit()) return Bit;
    //if (ctx->type_Ptr()) return Ptr;

    std::shared_ptr<AstIdentifier> identifier;

    if (ctx->BOOL()) identifier = Bool;
    if (ctx->STR()) identifier = Str;
    if (ctx->F16()) identifier = F16;
    if (ctx->F32()) identifier = F32;
    if (ctx->I8()) identifier = I8;
    if (ctx->I16()) identifier = I16;
    if (ctx->I24()) identifier = I24;
    if (ctx->I32()) identifier = I32;
    if (ctx->U8()) identifier = U8;
    if (ctx->U16()) identifier = U16;
    if (ctx->U24()) identifier = U24;
    if (ctx->U32()) identifier = U32;

    if (identifier) {
        return identifier->Clone();
    }

    return nullptr;
}

std::shared_ptr<AstTypeDefinition> SelectKnownTypeDefinition(zsharp_parserParser::Known_typesContext* ctx)
{
    if (!ctx) return nullptr;
    //if (ctx->type_Bit()) return TypeBit;
    //if (ctx->type_Ptr()) return TypePtr;

    if (ctx->BOOL()) return TypeBool;
    if (ctx->STR()) return TypeStr;
    if (ctx->F16()) return TypeF16;
    if (ctx->F32()) return TypeF32;
    if (ctx->I8()) return TypeI8;
    if (ctx->I16()) return TypeI16;
    if (ctx->I24()) return TypeI24;
    if (ctx->I32()) return TypeI32;
    if (ctx->U8()) return TypeU8;
    if (ctx->U16()) return TypeU16;
    if (ctx->U24()) return TypeU24;
    if (ctx->U32()) return TypeU32;

    return nullptr;
}

void AstType::Construct(std::shared_ptr<AstType> instance, zsharp_parserParser::Type_nameContext* ctx)
{
    std::shared_ptr<AstIdentifier> identifier;

    auto idCtx = ctx->identifier_type();
    if (idCtx) {
        identifier = std::make_shared<AstIdentifier>(idCtx);
        // TODO: type parameters ctx->type_param_list()
    }
    else {
        auto knownCtx = ctx->known_types();
        identifier = SelectKnownIdentifier(knownCtx);
    }

    guard(identifier && "Identifier failed.");
    bool success = instance->SetIdentifier(identifier);
    guard(success && "SetIdentifier() failed");
}


std::shared_ptr<AstTypeDefinition> AstTypeDefinition::Create(zsharp_parserParser::Type_defContext* ctx)
{
    auto typeDef = std::make_shared<AstTypeDefinition>(ctx);
    typeDef->_baseType = AstTypeReference::Create(ctx->type_ref_use());
    
    auto identifier = std::make_shared<AstIdentifier>(ctx->identifier_type());
    typeDef->SetIdentifier(identifier);

    // TODO: type parameters: ctx->type_param_list()
    return typeDef;
}


std::shared_ptr<AstTypeReference> AstTypeReference::Create(zsharp_parserParser::Type_ref_useContext* ctx)
{
    guard(ctx && "AstTypeReference::Create is passed a nullptr");
    auto typeRef = std::make_shared<AstTypeReference>(ctx);
    AstType::Construct(typeRef, ctx->type_ref()->type_name());
    return typeRef;
}
std::shared_ptr<AstTypeReference> AstTypeReference::Create(std::shared_ptr<AstTypeReference> inferredFrom)
{
    guard(inferredFrom && "AstTypeReference::Create on AstTypeReference is passed a nullptr");
    auto typeRef = std::make_shared<AstTypeReference>(inferredFrom);
    auto identifier = inferredFrom->getIdentifier()->Clone();
    typeRef->SetIdentifier(identifier);
    bool success = typeRef->setTypeDefinition(inferredFrom->getTypeDefinition());
    guard(success && "AstTypeReference.Create setTypeDefinition (inferred) failed.");

    return typeRef;
}
std::shared_ptr<AstTypeReference> AstTypeReference::Create(std::shared_ptr<AstNode> typeSource, std::shared_ptr<AstTypeDefinition> typeDef)
{
    guard(typeDef && "AstTypeReference::Create on AstTypeReference is passed a nullptr");
    auto typeRef = std::make_shared<AstTypeReference>();
    auto identifier = typeDef->getIdentifier()->Clone();
    
    bool success = typeRef->SetIdentifier(identifier);
    guard(success && "AstTypeReference.Create SetIdentifier failed.");

    success = typeRef->setTypeDefinition(typeDef);
    guard(success && "AstTypeReference.Create SetTypeDefinition failed.");

    success = typeRef->setTypeSource(std::static_pointer_cast<AstNode>(typeSource));
    guard(success && "AstTypeReference.Create SetTypeSource failed.");

    return typeRef;
}

void AddIntrinsicSymbol(std::shared_ptr<AstSymbolTable> symbols, std::shared_ptr<AstTypeIntrinsic> type)
{
    symbols->AddSymbol(type->getIdentifier()->getName(), AstSymbolKind::Type, type);
}

void AstTypeIntrinsic::AddAll(std::shared_ptr<AstSymbolTable> symbols)
{
    AddIntrinsicSymbol(symbols, TypeBool);
    AddIntrinsicSymbol(symbols, TypeF16);
    AddIntrinsicSymbol(symbols, TypeF32);
    AddIntrinsicSymbol(symbols, TypeI16);
    AddIntrinsicSymbol(symbols, TypeI24);
    AddIntrinsicSymbol(symbols, TypeI32);
    AddIntrinsicSymbol(symbols, TypeI8);
    AddIntrinsicSymbol(symbols, TypeStr);
    AddIntrinsicSymbol(symbols, TypeU16);
    AddIntrinsicSymbol(symbols, TypeU24);
    AddIntrinsicSymbol(symbols, TypeU32);
    AddIntrinsicSymbol(symbols, TypeU8);
}
