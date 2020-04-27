#pragma once

#include "../AST/AstVisitor.h"
#include <memory>

class AstModule;
class AstSymbolTable;

class ResolveTypes : public AstVisitor
{
public:
    void Apply(AstModule* module) {
        VisitModule(module);
    }
    void Apply(AstFile* file) {
        VisitFile(file);
    }

    void VisitTypeReference(AstTypeReference* type) override;
    void VisitCodeBlock(AstCodeBlock* codeBlock) override;
    void VisitFile(AstFile* file) override;

private:
    std::shared_ptr<AstSymbolTable> _symbolTable;
};

