#pragma once

#include "../AST/AstModule.h"
#include "../AST/AstVisitor.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>

class LlvmIrBuilder : protected AstVisitor
{
public:
    LlvmIrBuilder()
        : _irBuilder(_context), name_index(0),
        _module(nullptr), _function(nullptr), _basicBlock(nullptr)
    {}

    llvm::Module* Build(AstModule* module);


protected:
    void VisitAssignment(AstAssignment* assign) override;
    void VisitBranch(AstBranch* branch) override;
    void VisitBranchExpression(AstBranchExpression* branch) override;
    void VisitBranchConditional(AstBranchConditional* branch) override;
    void VisitCodeBlock(AstCodeBlock* codeBlock) override;
    void VisitCodeBlockItem(AstCodeBlockItem* codeBlockItem) override;
    void VisitExpression(AstExpression* expression) override;
    void VisitExpressionOperand(AstExpressionOperand* operand) override;
    void VisitFile(AstFile* file) override;
    void VisitFunction(AstFunction* function) override;
    void VisitFunctionParameter(AstFunctionParameter* parameter) override;
    void VisitIdentifier(AstIdentifier* identifier) override;
    void VisitModule(AstModule* module) override;
    void VisitNumeric(AstNumeric* numeric) override;
    void VisitTypeReference(AstTypeReference* type) override;
    void VisitVariableDefinition(AstVariableDefinition* variable) override;
    void VisitVariableReference(AstVariableReference* variable) override;

    llvm::Type* createType(const AstType* type);

    void setModule(llvm::Module* module) { _module = module; }
    llvm::Module* getModule() { return _module; }
    
    void setFunction(llvm::Function* function) {
        _function = function;
        name_index = 0;
    }
    llvm::Function* getFunction() { return _function; }

    void setBasicBlock(llvm::BasicBlock* basicBlock) {
        _basicBlock = basicBlock;
        _irBuilder.SetInsertPoint(_basicBlock);
    }
    llvm::BasicBlock* getBasicBlock() const { return _basicBlock; }

private:
    llvm::LLVMContext _context;
    llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter> _irBuilder;
    
    llvm::Module* _module;
    llvm::Function* _function;
    llvm::BasicBlock* _basicBlock;

    uint32_t name_index;
    std::string getNextName();
};

