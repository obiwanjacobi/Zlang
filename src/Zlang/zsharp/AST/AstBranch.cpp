#include "AstBranch.h"

bool AstBranch::AddExpression(std::shared_ptr<AstExpression> expr) {
    if (_expression != nullptr) {
        if (hasSubBranches()) {
            return Last()->AddExpression(expr);
        }
        return false; 
    }
    expr->setParent(this);
    _expression = expr;
    return true;
}

bool AstBranch::AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (_trueCodeBlock != nullptr) { 
        if (hasSubBranches()) {
            return Last()->AddCodeBlock(codeBlock);
        }
        else if (_falseCodeBlock == nullptr) {
            _falseCodeBlock = codeBlock;    // 'else' code block
            codeBlock->setParent(this);
            return true;
        }
        return false; 
    }
    codeBlock->setParent(this);
    _trueCodeBlock = codeBlock;
    return true;
}
