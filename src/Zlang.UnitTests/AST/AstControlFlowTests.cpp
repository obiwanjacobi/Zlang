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
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    EXPECT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);

    EXPECT_EQ(br->getBranchType(), AstBranchType::Conditional);
    EXPECT_TRUE(br->isConditional());
    EXPECT_TRUE(br->hasExpression());
    EXPECT_TRUE(br->hasCode());

    auto esle = br->getCodeBlock();
    auto ret = esle->getItems().at(0);
    EXPECT_EQ(ret->getNodeType(), AstNodeType::Branch);
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
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    EXPECT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    EXPECT_TRUE(br->hasSubBranch());

    auto subBr = br->getSubBranch();
    EXPECT_EQ(subBr->getBranchType(), AstBranchType::Conditional);
    EXPECT_NE(br->getCodeBlock(), nullptr);
    EXPECT_TRUE(subBr->isConditional());
    EXPECT_TRUE(subBr->hasExpression());
    EXPECT_TRUE(subBr->hasCode());
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
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    EXPECT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    EXPECT_TRUE(br->hasSubBranch());
    EXPECT_TRUE(br->hasExpression());

    auto subBr = br->getSubBranch();
    EXPECT_EQ(subBr->getBranchType(), AstBranchType::Conditional);
    EXPECT_NE(br->getCodeBlock(), nullptr);
    EXPECT_TRUE(subBr->isConditional());
    EXPECT_FALSE(subBr->hasExpression());
    EXPECT_TRUE(subBr->hasCode());
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

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    auto br = std::static_pointer_cast<AstBranchConditional>(fi);
    EXPECT_NE(br->getCodeBlock(), nullptr);
    EXPECT_TRUE(br->hasExpression());
    auto subBr = br->getSubBranch();
    EXPECT_TRUE(subBr->hasExpression());
    EXPECT_NE(subBr->getCodeBlock(), nullptr);

    subBr = subBr->getSubBranch();
    EXPECT_NE(subBr->getCodeBlock(), nullptr);
    EXPECT_FALSE(subBr->hasExpression());
}

TEST(AstControlFlowTests, Return)
{
    const char* src =
        "MyFunction()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    EXPECT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranch>(fi);
    EXPECT_EQ(br->getBranchType(), AstBranchType::ExitFunction);
}

TEST(AstControlFlowTests, ReturnValue)
{
    const char* src =
        "MyFunction(): U8\n"
        "    return 42\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto fi = cb->getItems().at(0);
    EXPECT_EQ(fi->getNodeType(), AstNodeType::Branch);
    auto br = std::static_pointer_cast<AstBranchExpression>(fi);
    EXPECT_EQ(br->getBranchType(), AstBranchType::ExitFunction);
    EXPECT_NE(br->getExpression(), nullptr);
    
}
