#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"

TEST(AstBuilderTests, BuildFile_empty)
{
    const char* src = 
        "// comment\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    EXPECT_NE(file, nullptr);
    EXPECT_EQ(file->getNodeType(), AstNodeType::File);
}

TEST(AstBuilderTests, BuildFile_ImportsOne)
{
    const char* src =
        "import importmodule\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto imports = file->getImports();
    EXPECT_EQ(imports.size(), 1);

    auto import = imports.at(0);
    auto modName = import->module_name();
    auto text = modName->getText();
    EXPECT_STREQ(text.c_str(), "importmodule");
}

TEST(AstBuilderTests, BuildFile_Imports)
{
    const char* src =
        "import importmodule1\n"
        "import importmodule2\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto imports = file->getImports();
    EXPECT_EQ(imports.size(), 2);

    auto import = imports.at(0);
    auto modName = import->module_name();
    auto text = modName->getText();
    EXPECT_STREQ(text.c_str(), "importmodule1");

    import = imports.at(1);
    modName = import->module_name();
    text = modName->getText();
    EXPECT_STREQ(text.c_str(), "importmodule2");
}

TEST(AstBuilderTests, BuildFile_ExportsOne)
{
    const char* src =
        "export myFunction\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto exports = file->getExports();
    EXPECT_EQ(exports.size(), 1);

    auto exprt = exports.at(0);
    auto funName = exprt->identifier_func();
    auto text = funName->getText();
    EXPECT_STREQ(text.c_str(), "myFunction");
}

TEST(AstBuilderTests, BuildFile_Exports) 
{
    const char* src =
        "export myFunction1\n"
        "export myFunction2\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto exports = file->getExports();
    EXPECT_EQ(exports.size(), 2);

    auto exprt = exports.at(0);
    auto funName = exprt->identifier_func();
    auto text = funName->getText();
    EXPECT_STREQ(text.c_str(), "myFunction1");

    exprt = exports.at(1);
    funName = exprt->identifier_func();
    text = funName->getText();
    EXPECT_STREQ(text.c_str(), "myFunction2");
}

TEST(AstBuilderTests, BuildFile_Function)
{
    const char* src =
        "MyFunction()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    
    auto functions = file->getFunctions();
    EXPECT_EQ(functions.size(), 1);

    auto fn = functions.at(0).get();
    auto fnCtx = fn->getContext();
    EXPECT_NE(fnCtx->codeblock(), nullptr);
}

TEST(AstBuilderTests, BuildFile_FunctionExternal)
{
    const char* src =
        "export MyFunction\n"
        "MyFunction()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);

    auto functions = file->getFunctions();
    EXPECT_EQ(functions.size(), 1);

    auto fn = functions.at(0).get();
    EXPECT_TRUE(fn->isExternal());
}

TEST(AstBuilderTests, Build_ModuleName)
{
    const char* src =
        "module testmodule\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    uut.Build(fileCtx);

    auto modules = uut.getModules();
    EXPECT_EQ(modules.size(), 1);

    auto mod = modules.at(0).get();
    auto name = mod->getName();
    EXPECT_STREQ(name.c_str(), "testmodule");
}
