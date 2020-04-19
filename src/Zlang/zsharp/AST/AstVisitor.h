#pragma once

#include "AstNode.h"

class AstAssignment;
class AstBranch;
class AstBranchExpression;
class AstBranchConditional;
class AstCodeBlock;
class AstCodeBlockItem;
class AstExpression;
class AstExpressionOperand;
class AstFile;
class AstFunction;
class AstFunctionParameter;
class AstIdentifier;
class AstModule;
class AstNumeric;
class AstTypeReference;
class AstVariableDefinition;
class AstVariableReference;


class AstVisitor
{
public:
    virtual void Visit(AstNode* node) {
        node->Accept(this);
    }

    virtual void VisitAssignment(AstAssignment* assign);
    virtual void VisitBranch(AstBranch* branch);
    virtual void VisitBranchExpression(AstBranchExpression* branch);
    virtual void VisitBranchConditional(AstBranchConditional* branch);
    virtual void VisitCodeBlock(AstCodeBlock* codeBlock);
    virtual void VisitCodeBlockItem(AstCodeBlockItem* codeBlockItem);
    virtual void VisitExpression(AstExpression* expression);
    virtual void VisitExpressionOperand(AstExpressionOperand* operand);
    virtual void VisitFile(AstFile* file);
    virtual void VisitFunction(AstFunction* function);
    virtual void VisitFunctionParameter(AstFunctionParameter* parameter);
    virtual void VisitIdentifier(AstIdentifier* identifier);
    virtual void VisitModule(AstModule* module);
    virtual void VisitNumeric(AstNumeric* numeric);
    virtual void VisitTypeReference(AstTypeReference* type);
    virtual void VisitVariableDefinition(AstVariableDefinition* variable);
    virtual void VisitVariableReference(AstVariableReference* variable);

protected:
    void VisitChildren(AstNode* node) {
        node->VisitChildren(this);
    }
};
