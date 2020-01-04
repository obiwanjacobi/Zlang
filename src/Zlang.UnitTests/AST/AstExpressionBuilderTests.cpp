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
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
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
    EXPECT_NE(expr->getRHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Multiply);
    EXPECT_NE(expr->getLHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
}

TEST(AstExpressionBuilderTests, ArithmeticUnary1)
{
    const char* src =
        "a = -4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Negate);
    EXPECT_EQ(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getUnsignedInt(), 4);
}

TEST(AstExpressionBuilderTests, ArithmeticUnary2)
{
    const char* src =
        "a = 2 + -4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Plus);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getRHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getRHS()->getExpression()->getOperator(), AstExpressionOperator::Negate);
    EXPECT_NE(expr->getLHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
}

TEST(AstExpressionBuilderTests, ArithmeticParenth)
{
    const char* src =
        "a = (2 + 4) * 6\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Multiply);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 6);
    EXPECT_NE(expr->getLHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Plus);
}


TEST(AstExpressionBuilderTests, ArithmeticNestedParenth)
{
    const char* src =
        "a = ((2 + 4) / 3) % 3\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Modulo);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 3);
    EXPECT_NE(expr->getLHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Divide);
    EXPECT_NE(expr->getLHS()->getExpression()->getLHS(), nullptr);
    EXPECT_NE(expr->getLHS()->getExpression()->getLHS()->getExpression(), nullptr);
    EXPECT_EQ(expr->getLHS()->getExpression()->getLHS()->getExpression()->getOperator(), AstExpressionOperator::Plus);
}

TEST(AstExpressionBuilderTests, Comparison1)
{
    const char* src =
        "c = 2 > 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Greater);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getLHS()->getNumeric(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
}

TEST(AstExpressionBuilderTests, ComparisonEqualAssign)
{
    const char* src =
        "c = 2 = 4\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Equal);
    EXPECT_NE(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getLHS()->getNumeric(), nullptr);
    EXPECT_NE(expr->getRHS()->getNumeric(), nullptr);
    EXPECT_EQ(expr->getLHS()->getNumeric()->getSignedInt(), 2);
    EXPECT_EQ(expr->getRHS()->getNumeric()->getSignedInt(), 4);
}

TEST(AstExpressionBuilderTests, Logical1)
{
    const char* src =
        "b = not true\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);

    AstExpressionBuilder uut;
    auto expr = uut.Test(sourceCtx);

    EXPECT_NE(expr, nullptr);
    EXPECT_EQ(expr->getOperator(), AstExpressionOperator::Not);
    EXPECT_EQ(expr->getLHS(), nullptr);
    EXPECT_NE(expr->getRHS(), nullptr);
    EXPECT_NE(expr->getRHS()->getLiteralBool(), nullptr);
}
