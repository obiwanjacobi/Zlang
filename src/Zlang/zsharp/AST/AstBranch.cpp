#include "AstBranch.h"

bool AstBranchExpression::AddExpression(std::shared_ptr<AstExpression> expr) {
    if (_expression != nullptr) {
        /*if (hasSubBranches()) {
            return Last()->AddExpression(expr);
        }*/
        return false; 
    }
    expr->setParent(this);
    _expression = expr;
    return true;
}

bool AstBranchConditional::AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (_codeBlock != nullptr) { 
        //if (hasSubBranches()) {
        //    return Last()->AddCodeBlock(codeBlock);
        //}
        //else if (_codeBlock == nullptr) {
        //    codeBlock->setIndent(getIndent() + 1);
        //    codeBlock->setParent(this);
        //    _falseCodeBlock = codeBlock;    // 'else' code block
        //    return true;
        //}
        return false; 
    }

    codeBlock->setIndent(getIndent() + 1);
    codeBlock->setParent(this);
    _codeBlock = codeBlock;
    return true;
}

bool AstBranchConditional::AddSubBranch(std::shared_ptr<AstBranchConditional> subBranch)
{
    if (_subBranch != nullptr)
    {
        return false;
    }

    _subBranch = subBranch;
    _subBranch->setParent(this);
    _subBranch->setIndent(getIndent());
    return true;
}