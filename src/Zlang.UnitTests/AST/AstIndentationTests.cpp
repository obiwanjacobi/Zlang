#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstError.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"

TEST(AstIndentationTests, FunctionBody)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto assign = cb->getItems().at(0);
    EXPECT_NE(assign, nullptr);
}

TEST(AstIndentationTests, E_FunctionBody_CodeBlockEmpty)
{
    const char* src =
        "MyFunction()\n"
        "c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_TRUE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_TRUE(uut.hasErrors());

    auto errors = uut.getErrors();
    EXPECT_TRUE(errors.size() > 0);

    auto error = errors.at(0);
    EXPECT_STREQ(error->getText().c_str(), AstError::EmptyCodeBlock);
}


TEST(AstIndentationTests, E_FunctionBody_IndentationMismatch)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        "        d = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_TRUE(uut.hasErrors());

    auto errors = uut.getErrors();
    EXPECT_TRUE(errors.size() > 0);

    auto error = errors.at(0);
    EXPECT_STREQ(error->getText().c_str(), AstError::IndentationMismatch);
}
