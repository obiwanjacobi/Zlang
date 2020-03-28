#include "LlvmIrBuilder.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>

static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);

llvm::Module* LlvmIrBuilder::Build(std::shared_ptr<AstModule> astModule)
{
    if (astModule == nullptr) { return nullptr; }

    auto module = new llvm::Module(astModule->getName(), TheContext);

    for (auto file : astModule->getFiles()) {
        BuildFile(module, file);
    }

    return module;
}

void LlvmIrBuilder::BuildFile(llvm::Module* module, std::shared_ptr<AstFile> astFile)
{
    for (auto fn : astFile->getFunctions()) {
        auto funct = BuildFunction(module, fn);
    }
}

llvm::Function* LlvmIrBuilder::BuildFunction(llvm::Module* module, std::shared_ptr<AstFunction> astFunction)
{
    auto fnType = llvm::FunctionType::get(Builder.getVoidTy(), /*isVarArg*/ false);
    auto linkage = llvm::Function::LinkageTypes::CommonLinkage;

    auto fn = llvm::Function::Create(fnType, linkage, astFunction->getIdentifier()->getName(), module);
    return fn;
}