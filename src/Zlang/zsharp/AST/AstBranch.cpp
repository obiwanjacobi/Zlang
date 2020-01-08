#include "AstBranch.h"

bool AstBranch::AddExpression(std::shared_ptr<AstExpression> expr) {
    if (_expression != nullptr) {
        if (hasSubBranches()) {
            return Last()->AddExpression(expr);
        }
        return false; 
    }
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
            return true;
        }
        return false; 
    }
    _trueCodeBlock = codeBlock;
    return true;
}
