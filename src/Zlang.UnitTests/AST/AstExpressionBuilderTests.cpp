#include "pch.h"

#include "../../Zlang/zsharp/AST/AstExpressionBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>

TEST(AstExpressionBuilderTests, Arithmetic1)
{
    const char* src =
        "a = 2 + 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
}

TEST(AstExpressionBuilderTests, Arithmetic2)
{
    const char* src =
        "a = 2 + 4 * 6\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Multiply);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
}

TEST(AstExpressionBuilderTests, ArithmeticUnary1)
{
    const char* src =
        "a = -4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Negate);
    ASSERT_EQ(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getUnsignedInt(), 4);
}

TEST(AstExpressionBuilderTests, ArithmeticUnary2)
{
    const char* src =
        "a = 2 + -4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Negate);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
}

TEST(AstExpressionBuilderTests, ArithmeticParenth)
{
    const char* src =
        "a = (2 + 4) * 6\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Multiply);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 6);
    ASSERT_NE(expr->getLHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Plus);
}


TEST(AstExpressionBuilderTests, ArithmeticNestedParenth)
{
    const char* src =
        "a = ((2 + 4) / 3) % 3\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Modulo);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 3);
    ASSERT_NE(expr->getLHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Divide);
    ASSERT_NE(expr->getLHS()->getExpression()->getLHS(), nullptr);
    ASSERT_NE(expr->getLHS()->getExpression()->getLHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getLHS()->getExpression()->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Plus);
}

TEST(AstExpressionBuilderTests, ArithmeticUnaryParenth1)
{
    const char* src =
        "a = 2 + -(4 * 3)\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Negate);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
}


TEST(AstExpressionBuilderTests, Comparison1)
{
    const char* src =
        "c = 2 > 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Greater);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
}

TEST(AstExpressionBuilderTests, ComparisonEqualAssign)
{
    const char* src =
        "c = 2 = 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Equal);
    ASSERT_NE(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getLHS()->getNumeric(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
}

TEST(AstExpressionBuilderTests, Logical1)
{
    const char* src =
        "b = not true\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Not);
    ASSERT_EQ(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getLiteralBool(), nullptr);
}

TEST(AstExpressionBuilderTests, LogicalComparison1)
{
    const char* src =
        "b = not (42 > 100)\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Not);
    ASSERT_EQ(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getExpression(), nullptr);
    ASSERT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Greater);
}

TEST(AstExpressionBuilderTests, Assignment1)
{
    const char* src =
        "a = 2\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    ASSERT_NE(expr, nullptr);
    ASSERT_EQ(expr->getOperator(), AstExpressionOperator::Number);
    ASSERT_EQ(expr->getLHS(), nullptr);
    ASSERT_NE(expr->getRHS(), nullptr);
    ASSERT_NE(expr->getRHS()->getNumeric(), nullptr);
    ASSERT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 2);
}
