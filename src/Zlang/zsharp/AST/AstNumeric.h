#pragma once

#include "AstNode.h"
#include "../../zsharp/grammar/parser/zsharp_parserParser.h"

enum class AstNumericSign {
    NotSet,
    Unsigned,
    Signed,
};

class AstNumeric : public AstNode
{
public:
    AstNumeric(zsharp_parserParser::NumberContext* numberCtx)
        : AstNode(AstNodeType::Numeric), 
        _numberCtx(numberCtx), _sign(AstNumericSign::NotSet), _intValue(0)
    {}

    zsharp_parserParser::NumberContext* getContext() const { return _numberCtx; }
    
    void setValue(uint64_t value) { _intValue = value; }
    // call one of these based on getSign()
    uint64_t getUnsignedInt() const { return _intValue; }
    int64_t getSignedInt() const { return (int64_t)_intValue; }
    
    AstNumericSign getSign() const { return _sign; }
    uint32_t getBitCount() const;

    void Accept(AstVisitor* visitor) override;

private:
    uint64_t _intValue;
    AstNumericSign _sign;
    zsharp_parserParser::NumberContext* _numberCtx;
};

