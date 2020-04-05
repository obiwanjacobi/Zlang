#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstError.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"
#include <gtest/gtest.h>

TEST(AstIndentationTests, FunctionBody)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
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
    auto cb = fn->getCodeBlock();
    auto assign = cb->getItems().at(0);
    ASSERT_NE(assign, nullptr);
    auto branch = cb->getItems().at(1);
    ASSERT_NE(branch, nullptr);
}

TEST(AstIndentationTests, E_FunctionBody_CodeBlockEmpty)
{
    const char* src =
        "MyFunction()\n"
        "c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_TRUE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_TRUE(uut.hasErrors());

    auto errors = uut.getErrors();
    ASSERT_TRUE(errors.size() > 0);

    auto error = errors.at(0);
    ASSERT_STREQ(error->getText().c_str(), AstError::EmptyCodeBlock);
}

TEST(AstIndentationTests, FunctionBody_Branch)
{
    const char* src =
        "MyFunction()\n"
        "    if true\n"
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
    auto cb = fn->getCodeBlock();
    
    auto ifbranch = std::static_pointer_cast<AstBranchConditional>(cb->getItems().at(0));
    ASSERT_NE(ifbranch, nullptr);
    ASSERT_EQ(ifbranch->getBranchType(), AstBranchType::Conditional);
    
    auto subBranch = std::static_pointer_cast<AstBranch>(ifbranch->getCodeBlock()->getItems().at(0));
    ASSERT_NE(subBranch, nullptr);
    ASSERT_EQ(subBranch->getBranchType(), AstBranchType::ExitFunction);

    auto branch = std::static_pointer_cast<AstBranch>(cb->getItems().at(1));
    ASSERT_NE(branch, nullptr);
    ASSERT_EQ(branch->getBranchType(), AstBranchType::ExitFunction);
}
