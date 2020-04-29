#pragma once

#include "../AST/AstVisitor.h"
#include "../AST//AstNumeric.h"
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
    void VisitExpression(AstExpression* expression) override;
    void VisitExpressionOperand(AstExpressionOperand* operand) override;
    void VisitAssignment(AstAssignment* assign) override;

private:
    std::shared_ptr<AstSymbolTable> _symbolTable;
    std::shared_ptr<AstSymbolTable> _globalSymbols;

    std::shared_ptr<AstSymbolTable> setSymbolTable(std::shared_ptr<AstSymbolTable> symbolTable) {
        if (!_globalSymbols) {
            _globalSymbols = symbolTable;
        }
        auto symbols = _symbolTable;
        _symbolTable = symbolTable;
        return symbols;
    }

    std::shared_ptr<AstTypeDefinition> findTypeByBitCount(uint32_t bitCount, AstNumericSign sign) const;
};

