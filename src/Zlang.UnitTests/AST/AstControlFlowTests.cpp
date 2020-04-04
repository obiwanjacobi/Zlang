#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"
#include <gtest/gtest.h>

TEST(AstControlFlowTests, If)
{
    const char* src =
        "MyFunction()\n"
        "    if c = 0\n"
        "        return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    ASSERT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);

    ASSERT_EQ(br->getBranchType(), AstBranchType::Conditional);
    ASSERT_TRUE(br->isConditional());
    ASSERT_TRUE(br->hasExpression());
    ASSERT_TRUE(br->hasCode());

    auto esle = br->getCodeBlock();
    auto ret = esle->getItems().at(0);
    ASSERT_EQ(ret->getNodeType(), AstNodeType::Branch);
}

TEST(AstControlFlowTests, ElseIf)
{
    const char* src =
        "MyFunction()\n"
        "    if c = 0\n"
        "        return\n"
        "    else if c = 42\n"
        "        return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    ASSERT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    ASSERT_TRUE(br->hasSubBranch());

    auto subBr = br->getSubBranch();
    ASSERT_EQ(subBr->getBranchType(), AstBranchType::Conditional);
    ASSERT_NE(br->getCodeBlock(), nullptr);
    ASSERT_TRUE(subBr->isConditional());
    ASSERT_TRUE(subBr->hasExpression());
    ASSERT_TRUE(subBr->hasCode());
}

TEST(AstControlFlowTests, Else)
{
    const char* src =
        "MyFunction()\n"
        "    if c = 0\n"
        "        return\n"
        "    else\n"
        "        return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    ASSERT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    ASSERT_TRUE(br->hasSubBranch());
    ASSERT_TRUE(br->hasExpression());

    auto subBr = br->getSubBranch();
    ASSERT_EQ(subBr->getBranchType(), AstBranchType::Conditional);
    ASSERT_NE(br->getCodeBlock(), nullptr);
    ASSERT_TRUE(subBr->isConditional());
    ASSERT_FALSE(subBr->hasExpression());
    ASSERT_TRUE(subBr->hasCode());
}

TEST(AstControlFlowTests, ElseIfElse)
{
    const char* src =
        "MyFunction()\n"
        "    if c = 0\n"
        "        return\n"
        "    else if c = 42\n"
        "        return\n"
        "    else\n"
        "        return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    ASSERT_NE(br->getCodeBlock(), nullptr);
    ASSERT_TRUE(br->hasExpression());
    auto subBr = br->getSubBranch();
    ASSERT_TRUE(subBr->hasExpression());
    ASSERT_NE(subBr->getCodeBlock(), nullptr);

    subBr = subBr->getSubBranch();
    ASSERT_NE(subBr->getCodeBlock(), nullptr);
    ASSERT_FALSE(subBr->hasExpression());
}

TEST(AstControlFlowTests, IfNested)
{
    const char* src =
        "MyFunction()\n"
        "    if c = 0\n"
        "        if c = 0\n"
        "            return\n"
        "        return\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto br = std::static_pointer_cast<AstBranchConditional>(cb->getItems().at(0));

    auto br2 = std::static_pointer_cast<AstBranchConditional>(br->getCodeBlock()->getItems().at(0));
    ASSERT_TRUE(br->isConditional());
    ASSERT_TRUE(br->hasExpression());
    ASSERT_TRUE(br->hasCode());
}

TEST(AstControlFlowTests, Return)
{
    const char* src =
        "MyFunction()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    ASSERT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranch>(fi);
    ASSERT_EQ(br->getBranchType(), AstBranchType::ExitFunction);
}

TEST(AstControlFlowTests, ReturnValue)
{
    const char* src =
        "MyFunction(): U8\n"
        "    return 42\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    ASSERT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchExpression>(fi);
    ASSERT_EQ(br->getBranchType(), AstBranchType::ExitFunction);
    ASSERT_NE(br->getExpression(), nullptr);
    
}
