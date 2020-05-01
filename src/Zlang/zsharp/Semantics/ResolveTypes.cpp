#include "ResolveTypes.h"
#include "../AST/AstAssignment.h"
#include "../AST/AstCodeBlock.h"
#include "../AST/AstExpression.h"
#include "../AST/AstExpressionOperand.h"
#include "../AST/AstFile.h"
#include "../AST/AstSymbolTable.h"
#include "../AST/AstType.h"


std::shared_ptr<AstTypeDefinition> findType(std::shared_ptr<AstSymbolTable> symbols, const std::string& typeName)
{
    auto entry = symbols->getEntry(typeName, AstSymbolKind::Type);
    if (entry) {
        return entry->getDefinition<AstTypeDefinition>();
    }
    return nullptr;
}

std::shared_ptr<AstTypeDefinition> ResolveTypes::findTypeByBitCount(uint32_t bitCount, AstNumericSign sign) const
{
    guard(_globalSymbols && "ResolveTypes has no Global SymbolTable.");
    
    auto index = bitCount / 8;
    if (bitCount % 8) index++;

    guard(index <= 32 && "Numeric Type too large.");

    std::shared_ptr<AstTypeDefinition> typeDef;
    std::string typeName = sign == AstNumericSign::Signed ? "I" : "U";

    switch (index) {
    case 2:
        typeDef = findType(_globalSymbols, typeName + "16");
        break;
    case 3:
        typeDef = findType(_globalSymbols, typeName + "24");
        break;
    case 4:
        typeDef = findType(_globalSymbols, typeName + "32");
        break;
    default:
        typeDef = findType(_globalSymbols, typeName + "8");
        break;
    }
    return typeDef;
}

void ResolveTypes::VisitTypeReference(AstTypeReference* type)
{
    if (type->getTypeDefinition()) { return; }
    guard(_symbolTable && "ResolveTypes has no SymbolTable.");

    auto entry = _symbolTable->getEntry(type->getIdentifier()->getName(), AstSymbolKind::Type);
    if (entry) {
        type->setTypeDefinition(entry->getDefinition<AstTypeDefinition>());
    }

    VisitChildren(type);
}

void ResolveTypes::VisitCodeBlock(AstCodeBlock* codeBlock)
{
    auto symbols = setSymbolTable(codeBlock->getSymbols());
    VisitChildren(codeBlock);
    setSymbolTable(symbols);
}

void ResolveTypes::VisitFile(AstFile* file)
{
    auto symbols = setSymbolTable(file->getSymbols());
    VisitChildren(file);
    setSymbolTable(symbols);
}

void ResolveTypes::VisitExpression(AstExpression* expression)
{
    VisitChildren(expression);

    if (!expression->getTypeReference()) {
        std::shared_ptr<AstTypeReference> leftTypeRef;
        auto lhs = expression->getLHS();
        if (lhs) leftTypeRef = lhs->getTypeReference();
        
        std::shared_ptr<AstTypeReference> rightTypeRef;
        auto rhs = expression->getRHS();
        if (rhs) rightTypeRef = rhs->getTypeReference();

        if (leftTypeRef && rightTypeRef)
        {
            guard(leftTypeRef->IsEqual(rightTypeRef) && "Expression has non-equal Types.");
        }

        std::shared_ptr<AstTypeReference> typeRef;
        if (leftTypeRef) {
            typeRef = AstTypeReference::Create(leftTypeRef);
        }
        else if (rightTypeRef) {
            typeRef = AstTypeReference::Create(rightTypeRef);
        }
        guard(typeRef && "Expression yielded no Type.");

        expression->SetTypeReference(typeRef);
    }
    
}

void ResolveTypes::VisitExpressionOperand(AstExpressionOperand* operand)
{
    VisitChildren(operand);

    if (operand->getTypeReference()) { return; }

    auto expr = operand->getExpression();
    if (expr) {
        auto typeRef = AstTypeReference::Create(expr->getTypeReference());
        operand->SetTypeReference(typeRef);
        return;
    }

    auto numeric = operand->getNumeric();
    if (numeric) {
        auto typeDef = findTypeByBitCount(numeric->getBitCount(), numeric->getSign());
        auto typeRef = AstTypeReference::Create(numeric, typeDef);
        operand->SetTypeReference(typeRef);
        return;
    }

    auto var = operand->getVariableReference();
    if (var) {
        // TODO
    }
}

void ResolveTypes::VisitAssignment(AstAssignment* assign)
{
    guard(_symbolTable && "ResolveTypes has no SymbolTable.");
    VisitChildren(assign);

    auto varDef = assign->getVariable<AstVariableDefinition>();
    if (varDef && !varDef->getTypeReference()) {
        // typeless assign of var (x = 42)
        auto expr = assign->getExpression();
        auto typeRef = expr->getTypeReference();

        auto entry = _symbolTable->getEntry(typeRef->getIdentifier()->getName(), AstSymbolKind::Type);
        if (entry) {
            typeRef = AstTypeReference::Create(expr, entry->getDefinition<AstTypeDefinition>());
            varDef->SetTypeReference(typeRef);
        }
    }
}
