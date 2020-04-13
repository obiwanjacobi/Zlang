#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstError.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"
#include <gtest/gtest.h>
#include "../../Zlang/zsharp/AST/AstAssignment.h"

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
    auto assign = cb->getItemAt<AstAssignment>(0);
    ASSERT_NE(assign, nullptr);
    auto branch = cb->getItemAt<AstBranch>(1);
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
    
    auto ifbranch = cb->getItemAt<AstBranchConditional>(0);
    ASSERT_NE(ifbranch, nullptr);
    
    auto subBranch = ifbranch->getCodeBlock()->getItemAt<AstBranch>(0);
    ASSERT_NE(subBranch, nullptr);
    ASSERT_EQ(subBranch->getBranchType(), AstBranchType::ExitFunction);

    auto branch = cb->getItemAt<AstBranch>(1);
    ASSERT_NE(branch, nullptr);
    ASSERT_EQ(branch->getBranchType(), AstBranchType::ExitFunction);
}
