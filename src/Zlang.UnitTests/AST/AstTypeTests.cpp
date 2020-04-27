#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstVariable.h"
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
    ASSERT_NE(type->getIdentifier(), nullptr);
    ASSERT_STREQ(type->getIdentifier()->getName().c_str(), "U8");
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
    ASSERT_NE(type->getIdentifier(), nullptr);
    ASSERT_STREQ(type->getIdentifier()->getName().c_str(), "U8");
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
    ASSERT_NE(type->getIdentifier(), nullptr);
    ASSERT_STREQ(type->getIdentifier()->getName().c_str(), "U8");
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

TEST(AstTypeTests, TopVariableType)
{
    const char* src =
        "x: U8\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto cb = file->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto var = cb->getItemAt<AstVariableDefinition>(0);
    ASSERT_NE(var, nullptr);
    auto varEntry = symbols->getEntry(var->getIdentifier()->getName(), AstSymbolKind::Variable);
    ASSERT_NE(varEntry, nullptr);
    ASSERT_NE(varEntry->getDefinition<AstVariableDefinition>(), nullptr);
    auto typeRef = var->getTypeReference();
    ASSERT_NE(typeRef, nullptr);
    auto typeEntry = symbols->getEntry(typeRef->getIdentifier()->getName(), AstSymbolKind::Type);
    ASSERT_NE(typeEntry, nullptr);
    ASSERT_NE(typeEntry->getDefinition<AstTypeDefinition>(), nullptr);
}
