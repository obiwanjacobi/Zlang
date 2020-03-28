#include "LlvmIrBuilder.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>

std::shared_ptr<llvm::Module> LlvmIrBuilder::Build(std::shared_ptr<AstModule> astModule)
{
    if (astModule == nullptr) { return nullptr; }

    auto module = std::make_shared<llvm::Module>(astModule->getName(), _context);

    for (auto file : astModule->getFiles()) {
        BuildFile(module, file);
    }

    return module;
}

void LlvmIrBuilder::BuildFile(std::shared_ptr<llvm::Module> module, std::shared_ptr<AstFile> astFile)
{
    for (auto fn : astFile->getFunctions()) {
        BuildFunction(module, fn);
    }
}

llvm::Function* LlvmIrBuilder::BuildFunction(std::shared_ptr<llvm::Module> module, std::shared_ptr<AstFunction> astFunction)
{
    auto fnType = llvm::FunctionType::get(llvm::Type::getVoidTy(_context), /*isVarArg*/ false);
    auto linkage = llvm::Function::CommonLinkage;

    auto fn = llvm::Function::Create(fnType, linkage, astFunction->getIdentifier()->getName(), module.get());
    return fn;
}