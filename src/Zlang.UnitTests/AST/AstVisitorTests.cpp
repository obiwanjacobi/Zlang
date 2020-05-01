#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"
#include "../../Zlang/zsharp/AST/AstCodeBlock.h"
#include "../../Zlang/zsharp/AST/AstExpression.h"
#include "../../Zlang/zsharp/AST/AstExpressionOperand.h"
#include "../../Zlang/zsharp/AST/AstFile.h"
#include "../../Zlang/zsharp/AST/AstFunction.h"
#include "../../Zlang/zsharp/AST/AstIdentifier.h"
#include "../../Zlang/zsharp/AST/AstModule.h"
#include "../../Zlang/zsharp/AST/AstNumeric.h"
#include "../../Zlang/zsharp/AST/AstType.h"
#include "../../Zlang/zsharp/AST/AstVariable.h"
#include "../../Zlang/zsharp/AST/AstVisitor.h"
#include "../../Zlang/zsharp/Semantics/ResolveTypes.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>


const char* src =
"// comment\n"
"export MyFunction\n"
"x = 42\n"
"MyFunction(a: U8): Bool\n"
"    if a = 42\n"
"        return true\n"
"    return a <> 0\n"
;


class AstParentChecker : public AstVisitor
{
public:
    void VisitAssignment(AstAssignment* assign) override {
        ASSERT_NE(assign->getParent(), nullptr);
        VisitChildren(assign);
    }
    void VisitBranch(AstBranch* branch) override {
        ASSERT_NE(branch->getParent(), nullptr);
        VisitChildren(branch);
    }
    void VisitBranchExpression(AstBranchExpression* branch) override {
        ASSERT_NE(branch->getParent(), nullptr);
        VisitChildren(branch);
    }
    void VisitBranchConditional(AstBranchConditional* branch) override {
        ASSERT_NE(branch->getParent(), nullptr);
        VisitChildren(branch);
    }
    void VisitCodeBlock(AstCodeBlock* codeBlock) override {
        ASSERT_NE(codeBlock->getParent(), nullptr);
        VisitChildren(codeBlock);
    }
    void VisitCodeBlockItem(AstCodeBlockItem* codeBlockItem) override {
        ASSERT_NE(codeBlockItem->getParent(), nullptr);
        VisitChildren(codeBlockItem);
    }
    void VisitExpression(AstExpression* expression) override {
        ASSERT_NE(expression->getParent(), nullptr);
        VisitChildren(expression);
    }
    void VisitExpressionOperand(AstExpressionOperand* operand) override {
        ASSERT_NE(operand->getParent(), nullptr);
        VisitChildren(operand);
    }
    void VisitFile(AstFile* file) override {
        // file is root in our tests
        //ASSERT_NE(file->getParent(), nullptr);
        VisitChildren(file);
    }
    void VisitFunction(AstFunction* function) override {
        ASSERT_NE(function->getParent(), nullptr);
        VisitChildren(function);
    }
    void VisitFunctionParameter(AstFunctionParameter* parameter) override {
        ASSERT_NE(parameter->getParent(), nullptr);
        VisitChildren(parameter);
    }
    void VisitIdentifier(AstIdentifier* identifier) override {
        ASSERT_NE(identifier->getParent(), nullptr);
        VisitChildren(identifier);
    }
    void VisitModule(AstModule* module) override {
        ASSERT_NE(module->getParent(), nullptr);
        VisitChildren(module);
    }
    void VisitNumeric(AstNumeric* numeric) override {
        ASSERT_NE(numeric->getParent(), nullptr);
        VisitChildren(numeric);
    }
    void VisitTypeReference(AstTypeReference* type) override {
        ASSERT_NE(type->getParent(), nullptr);
        VisitChildren(type);
    }
    void VisitTypeDefinition(AstTypeDefinition* type) override {
        ASSERT_NE(type->getParent(), nullptr);
        VisitChildren(type);
    }
    void VisitVariableDefinition(AstVariableDefinition* variable) override {
        ASSERT_NE(variable->getParent(), nullptr);
        VisitChildren(variable);
    }
    void VisitVariableReference(AstVariableReference* variable) override {
        ASSERT_NE(variable->getParent(), nullptr);
        VisitChildren(variable);
    }
};

TEST(AstVisitorTests, NodesHaveParents)
{
    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    AstParentChecker checker;
    checker.Visit(file.get());
}


class AstTypeChecker : public AstVisitor
{
public:
    void VisitExpression(AstExpression* expression) override {
        ASSERT_NE(expression->getTypeReference(), nullptr);
        VisitChildren(expression);
    }
    void VisitExpressionOperand(AstExpressionOperand* operand) override {
        if (!operand->getVariableReference()) {     // variable not implemented
            ASSERT_NE(operand->getTypeReference(), nullptr);
        }
        VisitChildren(operand);
    }
    void VisitFunction(AstFunction* function) override {
        ASSERT_NE(function->getTypeReference(), nullptr);
        VisitChildren(function);
    }
    void VisitFunctionParameter(AstFunctionParameter* parameter) override {
        ASSERT_NE(parameter->getTypeReference(), nullptr);
        VisitChildren(parameter);
    }
    void VisitTypeReference(AstTypeReference* type) override {
        ASSERT_NE(type->getTypeDefinition(), nullptr);
        VisitChildren(type);
    }
    void VisitVariableDefinition(AstVariableDefinition* variable) override {
        ASSERT_NE(variable->getTypeReference(), nullptr);
        VisitChildren(variable);
    }
};


TEST(AstVisitorTests, NodesHaveTypes)
{
    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ResolveTypes resolver;
    resolver.Apply(file.get());

    AstTypeChecker checker;
    checker.Visit(file.get());
}



class AstVariableChecker : public AstVisitor
{
public:
    void VisitAssignment(AstAssignment* assign) override {
        ASSERT_NE(assign->getVariable(), nullptr);
        VisitChildren(assign);
    }
    void VisitExpressionOperand(AstExpressionOperand* operand) override {
        if (!operand->getExpression() && !operand->getNumeric()) {
            ASSERT_NE(operand->getVariableReference(), nullptr);
        }
        VisitChildren(operand);
    }
    void VisitVariableReference(AstVariableReference* variable) override {
        //ASSERT_NE(variable->getVariableDefinition(), nullptr);
        VisitChildren(variable);
    }
};

TEST(AstVisitorTests, NodesHaveVariables)
{
    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    AstVariableChecker checker;
    checker.Visit(file.get());
}
