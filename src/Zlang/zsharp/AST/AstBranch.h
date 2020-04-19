#pragma once

#include "AstNode.h"
#include "AstExpression.h"
#include "AstCodeBlock.h"
#include <memory>

enum class AstBranchType {
    NotSet,
    Conditional,        // if-else
    ExitIteration,      // continue
    ExitLoop,           // break
    ExitFunction,       // return
};

class AstBranchExpression;
class AstBranchConditional;

class AstBranch : public AstCodeBlockItem
{
public:
    AstBranch(zsharp_parserParser::Statement_returnContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitFunction),
        _breakCtx(nullptr), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_breakContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitLoop),
        _breakCtx(ctx), _continueCtx(nullptr)
    {}
    AstBranch(zsharp_parserParser::Statement_continueContext* ctx)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(AstBranchType::ExitIteration),
        _breakCtx(nullptr), _continueCtx(ctx)
    {}

    AstBranchType getBranchType() const { return _branchType; }
    
    bool isExpression() const { return _branchType == AstBranchType::ExitFunction || isConditional(); }
    AstBranchExpression* toExpression() const { return isExpression() ? (AstBranchExpression*)this : nullptr; }
    
    bool hasCode() const { return _branchType == AstBranchType::Conditional; }
    bool isConditional() const { return _branchType == AstBranchType::Conditional; }
    AstBranchConditional* toCondtional() const { return isConditional() ? (AstBranchConditional*)this : nullptr; }

    void Accept(AstVisitor* visitor) override;

protected:
    AstBranch(AstBranchType branchType)
        : AstCodeBlockItem(AstNodeType::Branch),
        _branchType(branchType),
        _breakCtx(nullptr), _continueCtx(nullptr)
    {}

private:
    AstBranchType _branchType;

    
    zsharp_parserParser::Statement_breakContext* _breakCtx;
    zsharp_parserParser::Statement_continueContext* _continueCtx;
};

//
// A Branch that contains an expression
//

class AstBranchExpression : public AstBranch, public AstExpressionSite
{
public:
    AstBranchExpression(zsharp_parserParser::Statement_returnContext* ctx)
        : AstBranch(AstBranchType::ExitFunction), _returnCtx(ctx)
    {}

    bool SetExpression(std::shared_ptr<AstExpression> expr);
    bool hasExpression() const { return getExpression() != nullptr; }

    void Accept(AstVisitor* visitor) override;

protected:
    AstBranchExpression(AstBranchType branchType)
        : AstBranch(branchType), _returnCtx(nullptr)
    {}

private:
    zsharp_parserParser::Statement_returnContext* _returnCtx;
};

//
// A branch that is conditional and optionally contains an expression
//

class AstBranchConditional : public AstBranchExpression, public AstCodeBlockSite
{
public:
    AstBranchConditional(zsharp_parserParser::Statement_ifContext* ctx)
        : AstBranchExpression(AstBranchType::Conditional),
        _ifCtx(ctx), _elseCtx(nullptr), _elseifCtx(nullptr),
        _subBranch(nullptr)
    {}
    AstBranchConditional(zsharp_parserParser::Statement_elseContext* ctx)
        : AstBranchExpression(AstBranchType::Conditional),
        _ifCtx(nullptr), _elseCtx(ctx), _elseifCtx(nullptr),
        _subBranch(nullptr)
    {}
    AstBranchConditional(zsharp_parserParser::Statement_elseifContext* ctx)
        : AstBranchExpression(AstBranchType::Conditional),
        _ifCtx(nullptr), _elseCtx(nullptr), _elseifCtx(ctx),
        _subBranch(nullptr)
    {}

    // if/else body
    bool SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) override;

    // chain of else/else-if's
    std::shared_ptr<AstBranchConditional> getSubBranch() const { return _subBranch; }
    bool AddSubBranch(std::shared_ptr<AstBranchConditional> subBranch);
    bool hasSubBranch() const { return _subBranch != nullptr; }

    AstBranchConditional* LastSubBranch() { return hasSubBranch() ? _subBranch->LastSubBranch() : this; }

    void Accept(AstVisitor* visitor) override;

private:
    std::shared_ptr<AstBranchConditional> _subBranch;

    zsharp_parserParser::Statement_ifContext* _ifCtx;
    zsharp_parserParser::Statement_elseContext* _elseCtx;
    zsharp_parserParser::Statement_elseifContext* _elseifCtx;
};
