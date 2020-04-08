#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>
#include <memory>

TEST(AstTypeTests, FunctionType)
{
    const char* src =
        "MyFunction(): U8\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto type = fn->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_FALSE(type->getIsOptional());
    ASSERT_FALSE(type->getIsError());
    // TODO: known_types not implemented yet
    ASSERT_EQ(type->getIdentifier(), nullptr);
}

TEST(AstTypeTests, FunctionOptionalErrorType)
{
    const char* src =
        "MyFunction(): U8!?\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto type = fn->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_TRUE(type->getIsOptional());
    ASSERT_TRUE(type->getIsError());
    // TODO: known_types not implemented yet
    ASSERT_EQ(type->getIdentifier(), nullptr);
}

TEST(AstTypeTests, FunctionParameterType)
{
    const char* src =
        "MyFunction(p: U8)\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto type = param->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_FALSE(type->getIsOptional());
    ASSERT_FALSE(type->getIsError());
    // TODO: known_types not implemented yet
    ASSERT_EQ(type->getIdentifier(), nullptr);
}

TEST(AstTypeTests, FunctionParameterCustomType)
{
    const char* src =
        "MyFunction(p: SomeType)\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto type = param->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_FALSE(type->getIsOptional());
    ASSERT_FALSE(type->getIsError());
    
    auto identifier = type->getIdentifier();
    ASSERT_NE(identifier, nullptr);
    ASSERT_STREQ(identifier->getName().c_str(), "SomeType");
}

TEST(AstTypeTests, FunctionParameterOptionalCustomType)
{
    const char* src =
        "MyFunction(p: SomeType?)\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto type = param->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_TRUE(type->getIsOptional());
    ASSERT_FALSE(type->getIsError());

    auto identifier = type->getIdentifier();
    ASSERT_NE(identifier, nullptr);
    ASSERT_STREQ(identifier->getName().c_str(), "SomeType");
}
