#include "AstBranch.h"

bool AstBranchExpression::AddExpression(std::shared_ptr<AstExpression> expr) {
    if (_expression || !expr) {
        return false; 
    }
    expr->setParent(this);
    _expression = expr;
    return true;
}

bool AstBranchConditional::SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (_codeBlock || !codeBlock) { 
        return false; 
    }

    codeBlock->setIndent(getIndent() + 1);
    codeBlock->setParent(this);
    _codeBlock = codeBlock;
    return true;
}

bool AstBranchConditional::AddSubBranch(std::shared_ptr<AstBranchConditional> subBranch)
{
    if (_subBranch || !subBranch) {
        return false;
    }

    _subBranch = subBranch;
    _subBranch->setParent(this);
    _subBranch->setIndent(getIndent());
    return true;
}