#include "DgmlBuilder.h"
#include "XmlWriter.h"
#include "../AST/AstModule.h"

static const char* ContainsCategory = "Contains";

void DgmlBuilder::WriteFile(std::shared_ptr<AstFile> file)
{
    std::string moduleName("AutoModule");
    auto module = (AstModule*)(file->getParent());
    if (module != nullptr)
    {
        moduleName = module->getName();
    }

    auto node = createNode(moduleName, "[AstFile] " + moduleName);
    
    for (const auto function : file->getFunctions())
    {
        WriteFunction(function, moduleName);
    }
}

void DgmlBuilder::WriteFunction(std::shared_ptr<AstFunction> function, const std::string& fileNodeId)
{
    auto fnName = function->getIdentifier()->getName();
    auto node = createNode(fnName, "[AstFunction] " + fnName);

    auto link = createLink(fileNodeId, fnName);
    link->Category = ContainsCategory;

    std::shared_ptr<AstCodeBlock> prevBlock = nullptr;
    for (const auto codeBlock : function->getCodeBlocks())
    {
        WriteCodeBlock(codeBlock, prevBlock, fnName);
        prevBlock = codeBlock;
    }
}

void DgmlBuilder::WriteCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock, std::shared_ptr<AstCodeBlock> prevBlock, const std::string& parentId)
{
    auto codeBlockName = parentId + "-Entry";
    auto node = createNode(codeBlockName, "[AstCodeBlock] " + codeBlockName);

    if (prevBlock != nullptr)
    {
        codeBlockName = parentId + "-CodeBlock";
    }

    auto link = createLink(parentId, codeBlockName);

    for (const auto item : codeBlock->getItems())
    {
        WriteCodeBlockItem(item, codeBlockName);
    }
}

void DgmlBuilder::WriteCodeBlockItem(std::shared_ptr<AstCodeBlockItem> codeBlockItem, const std::string& codeBlockId)
{
    switch (codeBlockItem->getNodeType())
    {
    case AstNodeType::Assignment:
        WriteAssignment(std::static_pointer_cast<AstAssignment>(codeBlockItem), codeBlockId);
        break;
    case AstNodeType::Branch:
        WriteBranch(std::static_pointer_cast<AstBranch>(codeBlockItem), codeBlockId);
        break;
    default:
        auto name = codeBlockId + "-NotImplemented-" + std::to_string((int)codeBlockItem->getNodeType());
        auto node = createNode(name, name);
        auto link = createLink(codeBlockId, name);
        break;
    }
}

void DgmlBuilder::WriteAssignment(std::shared_ptr<AstAssignment> assignment, const std::string& parentId)
{
    auto name = parentId + "-Assignment: " + assignment->getIdentifier()->getName();
    auto node = createNode(name, "[AstAssignment] " + name);
    auto link = createLink(parentId, name);
}

void DgmlBuilder::WriteBranch(std::shared_ptr<AstBranch> branch, const std::string& parentId)
{
    auto name = parentId + "-Branch-" + std::to_string((int)branch->getBranchType());
    auto node = createNode(name, "[AstBranch] " + name);
    auto link = createLink(parentId, name);

    auto code = branch->getConditionTrueCodeBlock();
    if (code != nullptr)
    {
        WriteCodeBlock(code, nullptr, name);
    }

    for (const auto subBranch : branch->getSubBranches())
    {
        WriteBranch(subBranch, name);
    }

    code = branch->getConditionFalseCodeBlock();
    if (code != nullptr)
    {
        WriteCodeBlock(code, nullptr, name);
    }
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
    createContains();
}

void DgmlBuilder::createContains()
{
    auto contains = createCategory(ContainsCategory, ContainsCategory);
    contains->IsContainment = true;
}

std::shared_ptr<dgml::Node> DgmlBuilder::createNode(const std::string& id, const std::string& label)
{
    auto node = std::make_shared<dgml::Node>();
    node->Id = id;
    node->Label = label;
    
    _graph->Nodes.push_back(node);
    return node;
}

std::shared_ptr<dgml::Link> DgmlBuilder::createLink(const std::string& sourceId, const std::string& targetId)
{
    auto link = std::make_shared<dgml::Link>();
    link->Source = sourceId;
    link->Target = targetId;
    
    _graph->Links.push_back(link);
    return link;
}

std::shared_ptr<dgml::Category> DgmlBuilder::createCategory(const std::string& id, const std::string& label)
{
    auto category = std::make_shared<dgml::Category>();
    category->Id = id;
    category->Label = label;

    _graph->Categories.push_back(category);
    return category;
}