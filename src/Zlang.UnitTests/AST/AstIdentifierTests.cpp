#include "pch.h"

#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>
#include <memory>

TEST(AstIndentifierTests, FunctionName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto identifier = fn->getIdentifier();
    ASSERT_NE(identifier, nullptr);
    ASSERT_STREQ(identifier->getName().c_str(), "MyFunction");
}

TEST(AstIndentifierTests, FunctionParameterName)
{
    const char* src =
        "MyFunction(a: U8)\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto pid = param->getIdentifier();
    ASSERT_NE(pid, nullptr);
    ASSERT_STREQ(pid->getName().c_str(), "a");
}

TEST(AstIndentifierTests, FunctionParameterSelf)
{
    const char* src =
        "MyFunction(self)\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto pid = param->getIdentifier();
    ASSERT_NE(pid, nullptr);
    ASSERT_STREQ(pid->getName().c_str(), "self");
    auto type = param->getTypeReference();
    ASSERT_EQ(type, nullptr);
}

TEST(AstIndentifierTests, FunctionParameterTypedSelf)
{
    const char* src =
        "MyFunction(self: U8)\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto pid = param->getIdentifier();
    ASSERT_NE(pid, nullptr);
    ASSERT_STREQ(pid->getName().c_str(), "self");
    auto type = param->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_STREQ(type->getIdentifier()->getName().c_str(), "U8");
}


TEST(AstIndentifierTests, VarAssignment)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    auto codeItems = cb->getItems();
    auto ci = std::static_pointer_cast<AstAssignment>(codeItems.at(0));
    auto identifier = ci->getVariable()->getIdentifier();
    ASSERT_NE(identifier, nullptr);
    ASSERT_STREQ(identifier->getName().c_str(), "c");
}

TEST(AstIndentifierTests, ParameterAssignment)
{
    const char* src =
        "MyFunction(c: U8)\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    auto codeItems = cb->getItems();
    auto ci = std::static_pointer_cast<AstAssignment>(codeItems.at(0));
    auto identifier = ci->getVariable()->getIdentifier();
    ASSERT_NE(identifier, nullptr);
    ASSERT_STREQ(identifier->getName().c_str(), "c");

    auto st = cb->getSymbols();
    ASSERT_NE(st->getEntry(".MyFunction.c", AstSymbolKind::Parameter), nullptr);
    ASSERT_NE(st->getEntry(".MyFunction.c", AstSymbolKind::Variable), nullptr);
}

