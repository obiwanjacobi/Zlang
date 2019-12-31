#pragma once

#include "../AST/AstModule.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>

class LlvmIrBuilder
{
public:
    LlvmIrBuilder()
        : _irBuilder(_context)
    {}

    std::shared_ptr<llvm::Module> Build(AstModule* module);

    void BuildFile(std::shared_ptr<llvm::Module> module, std::shared_ptr<AstFile> astFile);
    llvm::Function* BuildFunction(std::shared_ptr<llvm::Module> module, std::shared_ptr<AstFunction> astFunction);
private:
    llvm::LLVMContext _context;
    llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter> _irBuilder;
};

