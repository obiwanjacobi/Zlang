#include "AstBranch.h"

bool AstBranchExpression::SetExpression(std::shared_ptr<AstExpression> expr) {
    if (AstExpressionSite::SetExpression(expr)) {
        expr->setParent(this);
        return true;
    }
    return false;
}

bool AstBranchConditional::SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (AstCodeBlockSite::SetCodeBlock(codeBlock)) {
        codeBlock->setIndent(getIndent() + 1);
        codeBlock->setParent(this);
        return true;
    }
    return false;
}

bool AstBranchConditional::AddSubBranch(std::shared_ptr<AstBranchConditional> subBranch)
{
    if (!_subBranch && subBranch) {
        _subBranch = subBranch;
        _subBranch->setParent(this);
        _subBranch->setIndent(getIndent());
        return true;
    }
    return false;
}