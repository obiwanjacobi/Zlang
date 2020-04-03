#include "DgmlBuilder.h"
#include "XmlWriter.h"
#include "../AST/AstModule.h"

static const char* ContainsCategory = "Contains";

std::shared_ptr<dgml::Node> DgmlBuilder::WriteFile(std::shared_ptr<AstFile> file)
{
    std::string moduleName("AutoModule");
    auto module = (AstModule*)(file->getParent());
    if (module != nullptr)
    {
        moduleName = module->getName();
    }

    auto node = createNode(moduleName, moduleName, "AstFile");
    
    for (const auto function : file->getFunctions())
    {
        WriteFunction(function, node->Id);
    }

    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteFunction(std::shared_ptr<AstFunction> function, const std::string& parentId)
{
    auto name = function->getIdentifier()->getName();
    auto node = createNode(name, name, "AstFunction");

    auto link = createLink(parentId, node->Id, ContainsCategory);
    link->Category = ContainsCategory;

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
    std::string name = "CodeBlock";
    auto node = createNode(name, name, "AstCodeBlock");
    auto link = createLink(parentId, node->Id, ContainsCategory);

    for (const auto item : codeBlock->getItems())
    {
        WriteCodeBlockItem(item, node->Id);
    }

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
    auto name = "Assignment: " + assignment->getIdentifier()->getName();
    auto node = createNode(name, name, "AstAssignment");
    auto link = createLink(parentId, node->Id);
    return node;
}

std::shared_ptr<dgml::Node> DgmlBuilder::WriteBranch(std::shared_ptr<AstBranch> branch, const std::string& parentId)
{
    auto name = "Branch-" + std::to_string((int)branch->getBranchType());
    auto node = createNode(name, name, "AstBranch");
    auto link = createLink(parentId, node->Id);

    auto conditional = branch->toCondtional();
    if (conditional != nullptr)
    {
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