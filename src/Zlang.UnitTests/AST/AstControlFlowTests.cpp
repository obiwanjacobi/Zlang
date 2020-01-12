#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"

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
    auto br = std::static_pointer_cast<AstBranch>(fi);

    EXPECT_EQ(br->getBranchType(), AstBranchType::Conditional);
    EXPECT_TRUE(br->hasCondition());
    EXPECT_TRUE(br->hasCode());
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
    auto br = std::static_pointer_cast<AstBranch>(fi);
    EXPECT_TRUE(br->hasSubBranches());

    auto subBr = br->getSubBranches().at(0);
    EXPECT_EQ(subBr->getBranchType(), AstBranchType::Conditional);
    EXPECT_NE(br->getConditionTrueCodeBlock(), nullptr);
    EXPECT_TRUE(subBr->hasCondition());
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
    auto br = std::static_pointer_cast<AstBranch>(fi);
    EXPECT_FALSE(br->hasSubBranches());

    auto esle = br->getConditionFalseCodeBlock();
    auto ret = esle->getItems().at(0);
    EXPECT_EQ(ret->getNodeType(), AstNodeType::Branch);
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
    auto br = std::static_pointer_cast<AstBranch>(fi);
    EXPECT_EQ(br->getConditionFalseCodeBlock(), nullptr);
    auto subBr = br->getSubBranches().at(0);
    EXPECT_NE(subBr->getConditionFalseCodeBlock(), nullptr);
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
