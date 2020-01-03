#include "pch.h"

#include "../../Zlang/zsharp/AST/AstExpressionBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"

TEST(AstExpressionBuilderTests, Arithmetic1)
{
    const char* src =
        "a = 2 + 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getLHS()->getNumeric(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 4);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 2);
}

TEST(AstExpressionBuilderTests, Arithmetic2)
{
    const char* src =
        "a = 2 + 4 * 6\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getLHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Multiply);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 2);
}
