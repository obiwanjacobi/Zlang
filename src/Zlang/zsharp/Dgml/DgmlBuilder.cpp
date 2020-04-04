#include "DgmlBuilder.h"
#include "XmlWriter.h"
#include "../AST/AstModule.h"
#include "AstExtensions.h"

static const char* ContainsCategory = "Contains";
static const dgml::Group DefaultGroup = dgml::Group::Collapsed;

std::string BranchTypeToName(AstBranchType branchType)
{
    switch (branchType)
    {
    case AstBranchType::Conditional:
        return "If|Else";
    case AstBranchType::ExitFunction:
        return "Ret";
    case AstBranchType::ExitIteration:
        return "Cont";
    case AstBranchType::ExitLoop:
        return "Brk";
    default:
        return "-";
    }
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteFile(std::shared_ptr<AstFile> file)
{
    std::string moduleName;
    auto module = (AstModule*)(file->getParent());
    if (module != nullptr)
    {
        moduleName = module->getName();
    }

    auto node = createNode(moduleName, moduleName, "File");
    
    for (const auto function : file->getFunctions())
    {
        WriteFunction(function, node->Id);
    }

    WriteSymbolTable(file->getSymbols(), node->Id);

    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteFunction(std::shared_ptr<AstFunction> function, const std::string& parentId)
{
    auto identifier = function->getIdentifier();
    auto name = identifier->getName();
    auto node = createNode(name, name, "Function");
    auto link = createLink(parentId, node->Id);

    std::string paramNames;
    for (const auto p : function->getParameters())
    {
        if (paramNames.length() > 0) { paramNames += ", ";  }
        paramNames += p->getIdentifier()->getName();
    }
    if (paramNames.length() > 0)
    {
        node->Group = DefaultGroup;
        auto paramNode = createNode(name, paramNames, "Parameter");
        auto paramLink = createLink(node->Id, paramNode->Id, ContainsCategory);
    }

    std::shared_ptr<AstCodeBlock> prevBlock = nullptr;
    for (const auto codeBlock : function->getCodeBlocks())
    {
        WriteCodeBlock(codeBlock, prevBlock, node->Id);
        prevBlock = codeBlock;
    }

    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock, std::shared_ptr<AstCodeBlock> prevBlock, const std::string& parentId)
{
    std::string name = "";
    auto node = createNode(name, name, "CodeBlock");
    auto link = createLink(parentId, node->Id);

    uint16_t i = 0;
    for (const auto item : codeBlock->getItems())
    {
        i++;
        auto itemNode = WriteCodeBlockItem(item, node->Id);
        if (itemNode)
        {
            link = findLink(node->Id, itemNode->Id);
            if (link)
            {
                link->Label = std::to_string(i);
            }
        }
    }

    WriteSymbolTable(codeBlock->getSymbols(), node->Id);

    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteCodeBlockItem(std::shared_ptr<AstCodeBlockItem> codeBlockItem, const std::string& codeBlockId)
{
    switch (codeBlockItem->getNodeType())
    {
    case AstNodeType::Assignment:
        return WriteAssignment(std::static_pointer_cast<AstAssignment>(codeBlockItem), codeBlockId);
    case AstNodeType::Branch:
        return WriteBranch(std::static_pointer_cast<AstBranch>(codeBlockItem), codeBlockId);
    default:
        auto name = "NotImplemented-" + std::to_string((int)codeBlockItem->getNodeType());
        auto node = createNode(name, name);
        auto link = createLink(codeBlockId, node->Id);
        return node;
    }
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteAssignment(std::shared_ptr<AstAssignment> assignment, const std::string& parentId)
{
    auto name = assignment->getIdentifier()->getName();
    auto node = createNode(name, name, "Assignment");
    auto link = createLink(parentId, node->Id);
    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteBranch(std::shared_ptr<AstBranch> branch, const std::string& parentId)
{
    auto name = BranchTypeToName(branch->getBranchType());
    auto node = createNode(name, name, "Branch");
    auto link = createLink(parentId, node->Id);

    auto conditional = branch->toCondtional();
    if (conditional != nullptr)
    {
        auto expression = conditional->getExpression();
        if (expression)
        {
            auto exprNode = createNode(name, ToString(expression));
            auto exprLink = createLink(node->Id, exprNode->Id, ContainsCategory);
            node->Group = DefaultGroup;
        }

        auto code = conditional->getCodeBlock();
        if (code != nullptr)
        {
            WriteCodeBlock(code, nullptr, node->Id);
        }

        auto subBranch = conditional->getSubBranch();
        if (subBranch != nullptr)
        {
            WriteBranch(subBranch, node->Id);
        }
    }

    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteSymbolTable(std::shared_ptr<AstSymbolTable> symbolTable, const std::string& parentId)
{
    auto node = createNode("", "", "Symbols");
    node->Group = DefaultGroup;
    auto link = createLink(parentId, node->Id, ContainsCategory);

    for (const auto entry : symbolTable->getSymbolEntries())
    {
        auto entryNode = createNode("Symbol", entry->getSymbolName().getQualifiedName(), "Symbol");
        auto entryLink = createLink(node->Id, entryNode->Id, ContainsCategory);
    }

    return node;
}

void DgmlBuilder::Serialize(std::ostream& output)
{
    XmlWriter::Xml(output);
    _graph->Serialize(output);
}

void DgmlBuilder::SaveAs(const std::string& filePath)
{
    std::ofstream file;
    file.open(filePath);
    Serialize(file);
    file.close();
}

void DgmlBuilder::createInitial()
{
    auto contains = createCategory(ContainsCategory, ContainsCategory);
    contains->IsContainment = true;
}

std::shared_ptr<dgml::Node> DgmlBuilder::createNode(const std::string& id, const std::string& label, const char* typeName)
{
    auto node = std::make_shared<dgml::Node>();
    node->Id = id + std::to_string(nextId());
    node->Label = label;
    if (typeName)
    {
        node->TypeName = typeName;
    }

    _graph->Nodes.push_back(node);
    return node;
}

std::shared_ptr<dgml::Link> DgmlBuilder::createLink(const std::string& sourceId, const std::string& targetId, const char* category)
{
    auto link = std::make_shared<dgml::Link>();
    link->Source = sourceId;
    link->Target = targetId;
    if (category)
    {
        link->Category = category;
    }

    _graph->Links.push_back(link);
    return link;
}

std::shared_ptr<dgml::Category> DgmlBuilder::createCategory(const std::string& id, const std::string& label)
{
    auto category = std::make_shared<dgml::Category>();
    category->Id = id + std::to_string(nextId());
    category->Label = label;

    _graph->Categories.push_back(category);
    return category;
}

std::shared_ptr<dgml::Link> DgmlBuilder::findLink(const std::string& sourceId, const std::string& targetId) const
{
    for (const auto l : _graph->Links)
    {
        if (l->Source == sourceId && l->Target == targetId)
        {
            return l;
        }
    }

    return nullptr;
}