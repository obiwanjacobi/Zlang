#include "../AST/AstBranch.h"
#include "LlvmIrBuilder.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/ADT/ArrayRef.h>

static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);

llvm::Type* LlvmIrBuilder::createType(const AstType* type)
{
    if (!type) return nullptr;
    auto identifier = type->getIdentifier();
    auto name = identifier->getName();

    if (name == "U8") {
        return Builder.getInt8Ty();
    }
    if (name == "U16") {
        return Builder.getInt16Ty();
    }
    return nullptr;
}

std::string LlvmIrBuilder::getNextName()
{
    std::string name;

    auto fn = getFunction();
    if (fn) {
        name += fn->getName();
    }
    else {
        name += "global";
        name_index = -1;
    }

    if (name_index > 0) {
        name += name_index;
        name_index++;
    } 
    else if (fn) {
        name += ".entry";
    }

    return name;
}

llvm::Module* LlvmIrBuilder::Build(AstModule* astModule)
{
    guard(astModule);
    guard(!getModule());

    VisitModule(astModule);

    auto module = getModule();
    setModule(nullptr);
    return module;
}


void LlvmIrBuilder::VisitAssignment(AstAssignment* assign) {}

void LlvmIrBuilder::VisitBranch(AstBranch* branch) {}

void LlvmIrBuilder::VisitBranchExpression(AstBranchExpression* branch) {}

void LlvmIrBuilder::VisitBranchConditional(AstBranchConditional* branch) {
}

void LlvmIrBuilder::VisitCodeBlock(AstCodeBlock* codeBlock) {
    auto name = getNextName();
    auto basicBlock = llvm::BasicBlock::Create(TheContext, name, getFunction());

    setBasicBlock(basicBlock);
}

void LlvmIrBuilder::VisitCodeBlockItem(AstCodeBlockItem* codeBlockItem) {
}

void LlvmIrBuilder::VisitExpression(AstExpression* expression) {
}

void LlvmIrBuilder::VisitExpressionOperand(AstExpressionOperand* operand) {
    VisitChildren(operand);
}

void LlvmIrBuilder::VisitFile(AstFile* file) {
    VisitChildren(file);
}

void LlvmIrBuilder::VisitFunction(AstFunction* function) {
    std::vector<llvm::Type*> params;
    for (auto p : function->getParameters())
    {
        params.push_back(createType(p->getTypeReference().get()));
    }

    auto retRefType = function->getTypeReference().get();
    auto retType = retRefType ? createType(retRefType) : Builder.getVoidTy();

    auto fnSymbol = function->getParent<AstCodeBlock>()->getSymbols()->getEntry(
        function->getIdentifier()->getName(), AstSymbolKind::Function);
    auto isExported = fnSymbol->getSymbolLocality() == AstSymbolLocality::Exported;

    auto fnType = llvm::FunctionType::get(retType, params, /*isVarArg*/ false);
    auto linkage = isExported
        ? llvm::Function::LinkageTypes::CommonLinkage
        : llvm::Function::LinkageTypes::InternalLinkage;
    auto addressSpace = 0U;

    auto fn = llvm::Function::Create(
        fnType, linkage, addressSpace, function->getIdentifier()->getName(), getModule());
    
    fn->setCallingConv(llvm::CallingConv::C);
    fn->setVisibility(llvm::GlobalValue::VisibilityTypes::DefaultVisibility);

    if (!fn->arg_empty()) {
        auto arg = fn->arg_begin();
        for (auto p : function->getParameters())
        {
            arg->setName(p->getIdentifier()->getName());
            arg++;
        }
    }

    setFunction(fn);
    VisitChildren(function);
    setFunction(nullptr);
}

void LlvmIrBuilder::VisitFunctionParameter(AstFunctionParameter* parameter) {
}

void LlvmIrBuilder::VisitIdentifier(AstIdentifier* identifier) {
    switch (identifier->getType()) {
    case AstIdentifierType::Function:
        getFunction()->setName(identifier->getName());
        break;
    case AstIdentifierType::Parameter:
        break;  // no-op
    default:
        // not implemented
        assert(false);
    }
}

void LlvmIrBuilder::VisitModule(AstModule* module) {
    assert(!getModule());
    setModule(new llvm::Module(module->getName(), TheContext));
    VisitChildren(module);
}

void LlvmIrBuilder::VisitNumeric(AstNumeric* numeric) {}

void LlvmIrBuilder::VisitTypeReference(AstTypeReference* type) {}

void LlvmIrBuilder::VisitVariableDefinition(AstVariableDefinition* variable) {}

void LlvmIrBuilder::VisitVariableReference(AstVariableReference* variable) {}
