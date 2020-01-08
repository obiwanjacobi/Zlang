#pragma once

#include "AstNode.h"
#include "AstExpression.h"
#include "AstCodeBlock.h"
#include <memory>

enum class AstBranchType {
    NotSet,
    Conditional,    // if-else
    ExitIteration,  // continue
    ExitLoop,       // break
    ExitFunction,   // return
};

class AstBranch : public AstCodeBlockItem, public AstExpressionSite, public AstCodeBlockSite
{
public:
    AstBranch(zsharp_parserParser::Statement_ifContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch), 
        _branchType(AstBranchType::Conditional), _ifCtx(ctx), _elseifCtx(nullptr), 
        _returnCtx(nullptr), _breakCtx(nullptr), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_elseifContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::Conditional), _ifCtx(nullptr), _elseifCtx(ctx), 
        _returnCtx(nullptr), _breakCtx(nullptr), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_returnContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitFunction), _ifCtx(nullptr), _elseifCtx(nullptr), 
        _returnCtx(ctx), _breakCtx(nullptr), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_breakContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitLoop), _ifCtx(nullptr), _elseifCtx(nullptr),
        _returnCtx(nullptr), _breakCtx(ctx), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_continueContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitIteration), _ifCtx(nullptr), _elseifCtx(nullptr),
        _returnCtx(nullptr), _breakCtx(nullptr), _continueCtx(ctx)
    {}

    // sites
    bool AddExpression(std::shared_ptr<AstExpression> expr);
    bool AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock);

    AstBranchType getBranchType() const { return _branchType; }
    bool hasCondition() const { return _branchType == AstBranchType::Conditional; }
    bool hasCode() const { return _branchType == AstBranchType::Conditional; }

    std::shared_ptr<AstExpression> getCondition() const { return _condition; }
    // if body
    std::shared_ptr<AstCodeBlock> getConditionTrueCodeBlock() const { return _trueCodeBlock; }
    void setConditionTrueCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) { _trueCodeBlock = codeBlock; }
    // else body (for last branch in if-else-if chain)
    std::shared_ptr<AstCodeBlock> getConditionFalseCodeBlock() const { return _falseCodeBlock; }
    void setConditionFalseCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) { _falseCodeBlock = codeBlock; }
    // else-if's
    const std::vector<std::shared_ptr<AstBranch>>& getSubBranches() const { return _subBranches; }
    void AddSubBranch(std::shared_ptr<AstBranch> subBranch) { _subBranches.push_back(subBranch); }
    bool hasSubBranches() const { return _subBranches.size() > 0; }

    AstBranch* Last() { return hasSubBranches() ? _subBranches.at(_subBranches.size() - 1).get() : this; }
    
private:
    AstBranchType _branchType;
    std::shared_ptr<AstExpression> _condition;
    std::shared_ptr<AstCodeBlock> _trueCodeBlock;
    std::shared_ptr<AstCodeBlock> _falseCodeBlock;
    std::vector<std::shared_ptr<AstBranch>> _subBranches;

    zsharp_parserParser::Statement_ifContext* _ifCtx;
    zsharp_parserParser::Statement_elseifContext* _elseifCtx;
    zsharp_parserParser::Statement_returnContext* _returnCtx;
    zsharp_parserParser::Statement_breakContext* _breakCtx;
    zsharp_parserParser::Statement_continueContext* _continueCtx;
};

