#include "ResolveTypes.h"
#include "../AST/AstCodeBlock.h"
#include "../AST/AstFile.h"
#include "../AST/AstSymbolTable.h"
#include "../AST/AstType.h"

void ResolveTypes::VisitTypeReference(AstTypeReference* type)
{
    if (type->getTypeDefinition()) { return; }
    guard(_symbolTable && "ResolveTypes has no SymbolTable.");

    auto entry = _symbolTable->getEntry(type->getIdentifier()->getName(), AstSymbolKind::Type);
    if (entry) {
        type->setTypeDefinition(entry->getDefinition<AstTypeDefinition>());
    }
}

void ResolveTypes::VisitCodeBlock(AstCodeBlock* codeBlock)
{
    _symbolTable = codeBlock->getSymbols();
}

void ResolveTypes::VisitFile(AstFile* file)
{
    _symbolTable = file->getSymbols();
}
