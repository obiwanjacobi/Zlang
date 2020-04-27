#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstVariable.h"
#include "../../Zlang/zsharp/AST/AstSymbolTable.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>


bool hasEmptyEntry(std::shared_ptr<AstSymbolTable> symbolTable)
{
    for (const auto entry : symbolTable->getSymbolEntries())
    {
        if (!entry) return true;
    }
    return false;
}

TEST(AstSymbolTableTests, TopVariableDefInit)
{
    const char* src =
        "c: U8 = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));
    
    auto entry = symbols->getEntry("c", AstSymbolKind::Variable);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);
    auto def = entry->getDefinition<AstVariableDefinition>();
    ASSERT_NE(def, nullptr);
    auto typeRef = def->getTypeReference();
    ASSERT_NE(typeRef, nullptr);
    ASSERT_STREQ(typeRef->getIdentifier()->getName().c_str(), "U8");
}

TEST(AstSymbolTableTests, TopVariableName)
{
    const char* src =
        "c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto entry = symbols->getEntry("c", AstSymbolKind::Variable);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);
}

TEST(AstSymbolTableTests, FunctionName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto entry = symbols->getEntry("MyFunction", AstSymbolKind::Function);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Function);
}

TEST(AstSymbolTableTests, FunctionParameterName)
{
    const char* src =
        "MyFunction(c: U8)\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    symbols = cb->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto entry = symbols->getEntry("c", AstSymbolKind::Parameter);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Parameter);
}

TEST(AstSymbolTableTests, FunctionParameterTypedSelf)
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

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto fn = file->getFunctions().at(0);
    auto param = fn->getParameters().at(0);
    auto type = param->getTypeReference();
    ASSERT_NE(type, nullptr);
    ASSERT_STREQ(type->getIdentifier()->getName().c_str(), "U8");
}

TEST(AstSymbolTableTests, ParameterAssignment)
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

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();

    symbols = cb->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));
    ASSERT_NE(symbols->getEntry("c", AstSymbolKind::Parameter), nullptr);
    ASSERT_NE(symbols->getEntry("c", AstSymbolKind::Variable), nullptr);
}

TEST(AstSymbolTableTests, LocalVariableName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    symbols = cb->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto entry = symbols->getEntry("c", AstSymbolKind::Variable);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);
}

TEST(AstSymbolTableTests, LocalVariableDefAndUse)
{
    const char* src =
        "MyFunction()\n"
        "    c: U8\n"
        "    c = 42\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    symbols = cb->getSymbols();
    ASSERT_FALSE(hasEmptyEntry(symbols));

    auto entry = symbols->getEntry("c", AstSymbolKind::Variable);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);

    auto def = entry->getDefinition<AstVariable>();
    ASSERT_NE(def, nullptr);
    ASSERT_EQ(def->getIdentifier()->getType(), AstIdentifierType::Variable);

    auto ref = std::static_pointer_cast<AstVariableReference>(entry->getReferences().at(0));
    ASSERT_NE(ref, nullptr);
    ASSERT_EQ(ref->getIdentifier()->getType(), AstIdentifierType::Variable);
}
