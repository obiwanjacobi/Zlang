#include "AstVisitor.h"
#include "AstAssignment.h"
#include "AstBranch.h"
#include "AstCodeBlock.h"
#include "AstExpression.h"
#include "AstExpressionOperand.h"
#include "AstFile.h"
#include "AstFunction.h"
#include "AstIdentifier.h"
#include "AstModule.h"
#include "AstNumeric.h"
#include "AstType.h"
#include "AstVariable.h"

void AstVisitor::VisitAssignment(AstAssignment* assign) {
    VisitChildren(assign);
}
void AstVisitor::VisitBranch(AstBranch* branch) {
    VisitChildren(branch);
}
void AstVisitor::VisitBranchExpression(AstBranchExpression* branch) {
    VisitChildren(branch);
}
void AstVisitor::VisitBranchConditional(AstBranchConditional* branch) {
    VisitChildren(branch);
}
void AstVisitor::VisitCodeBlock(AstCodeBlock* codeBlock) {
    VisitChildren(codeBlock);
}
void AstVisitor::VisitCodeBlockItem(AstCodeBlockItem* codeBlockItem) {
    VisitChildren(codeBlockItem);
}
void AstVisitor::VisitExpression(AstExpression* expression) {
    VisitChildren(expression);
}
void AstVisitor::VisitExpressionOperand(AstExpressionOperand* operand) {
    VisitChildren(operand);
}
void AstVisitor::VisitFile(AstFile* file) {
    VisitChildren(file);
}
void AstVisitor::VisitFunction(AstFunction* function) {
    VisitChildren(function);
}
void AstVisitor::VisitFunctionParameter(AstFunctionParameter* parameter) {
    VisitChildren(parameter);
}
void AstVisitor::VisitIdentifier(AstIdentifier* identifier) {
    VisitChildren(identifier);
}
void AstVisitor::VisitModule(AstModule* module) {
    VisitChildren(module);
}
void AstVisitor::VisitNumeric(AstNumeric* numeric) {
    VisitChildren(numeric);
}
void AstVisitor::VisitTypeReference(AstTypeReference* type) {
    VisitChildren(type);
}
void AstVisitor::VisitTypeDefinition(AstTypeDefinition* type) {
    VisitChildren(type);
}
void AstVisitor::VisitVariableDefinition(AstVariableDefinition* variable) {
    VisitChildren(variable);
}
void AstVisitor::VisitVariableReference(AstVariableReference* variable) {
    VisitChildren(variable);
}
