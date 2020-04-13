#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>
#include "../../Zlang/zsharp/AST/AstAssignment.h"

TEST(AstBuilderTests, BuildFile_empty)
{
    const char* src = 
        "// comment\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ASSERT_NE(file, nullptr);
    ASSERT_EQ(file->getNodeType(), AstNodeType::File);
}

TEST(AstBuilderTests, BuildFile_ImportsOne)
{
    const char* src =
        "import importmodule\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto imports = file->getImports();
    ASSERT_EQ(imports.size(), 1);

    auto import = imports.at(0);
    auto modName = import->module_name();
    auto text = modName->getText();
    ASSERT_STREQ(text.c_str(), "importmodule");
}

TEST(AstBuilderTests, BuildFile_Imports)
{
    const char* src =
        "import importmodule1\n"
        "import importmodule2\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto imports = file->getImports();
    ASSERT_EQ(imports.size(), 2);
    ASSERT_FALSE(uut.hasErrors());

    auto import = imports.at(0);
    auto modName = import->module_name();
    auto text = modName->getText();
    ASSERT_STREQ(text.c_str(), "importmodule1");

    import = imports.at(1);
    modName = import->module_name();
    text = modName->getText();
    ASSERT_STREQ(text.c_str(), "importmodule2");
}

TEST(AstBuilderTests, BuildFile_ExportsOne)
{
    const char* src =
        "export myFunction\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto exports = file->getExports();
    ASSERT_EQ(exports.size(), 1);

    auto exprt = exports.at(0);
    auto funName = exprt->identifier_func();
    auto text = funName->getText();
    ASSERT_STREQ(text.c_str(), "myFunction");
}

TEST(AstBuilderTests, BuildFile_Exports) 
{
    const char* src =
        "export myFunction1\n"
        "export myFunction2\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto exports = file->getExports();
    ASSERT_EQ(exports.size(), 2);

    auto exprt = exports.at(0);
    auto funName = exprt->identifier_func();
    auto text = funName->getText();
    ASSERT_STREQ(text.c_str(), "myFunction1");

    exprt = exports.at(1);
    funName = exprt->identifier_func();
    text = funName->getText();
    ASSERT_STREQ(text.c_str(), "myFunction2");
}

TEST(AstBuilderTests, BuildFile_Function)
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

    auto functions = file->getFunctions();
    ASSERT_EQ(functions.size(), 1);

    auto fn = functions.at(0).get();
    auto cb = fn->getCodeBlock();
    ASSERT_NE(cb, nullptr);
}

TEST(AstBuilderTests, BuildFile_Assignment)
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

    auto functions = file->getFunctions();
    auto fn = functions.at(0).get();
    auto cb = fn->getCodeBlock();
    auto assign = cb->getItemAt<AstAssignment>(0);
    ASSERT_NE(assign, nullptr);
}

TEST(AstBuilderTests, Build_ModuleName)
{
    const char* src =
        "module testmodule\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    uut.Build(fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto modules = uut.getModules();
    ASSERT_EQ(modules.size(), 1);

    auto mod = modules.at(0).get();
    auto name = mod->getName();
    ASSERT_STREQ(name.c_str(), "testmodule");
}
