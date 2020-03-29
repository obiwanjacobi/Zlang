#pragma once

#include "../AST/AstFile.h"
#include "../AST/AstFunction.h"
#include "../AST/AstCodeBlock.h"
#include "../AST/AstAssignment.h"
#include "../AST/AstBranch.h"
#include "Dgml.h"
#include <ostream>

class DgmlBuilder
{
public:
    DgmlBuilder()
    {
        _graph = std::make_unique<dgml::Graph>();
        createInitial();
    }

    void WriteFile(std::shared_ptr<AstFile> file);
    void WriteFunction(std::shared_ptr<AstFunction> function, const std::string& fileNodeId);
    void WriteCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock, std::shared_ptr<AstCodeBlock> prevBlock, const std::string& parentId);
    void WriteCodeBlockItem(std::shared_ptr<AstCodeBlockItem> codeBlockItem, const std::string& codeBlockId);
    void WriteAssignment(std::shared_ptr<AstAssignment> assignment, const std::string& parentId);
    void WriteBranch(std::shared_ptr<AstBranch> branch, const std::string& parentId);

    void Serialize(std::ostream& output);
    void SaveAs(const std::string& filePath);
private:
    std::unique_ptr<dgml::Graph> _graph;

    void createInitial();
    void createContains();
    std::shared_ptr<dgml::Node> createNode(const std::string& id, const std::string& label);
    std::shared_ptr<dgml::Link> createLink(const std::string& sourceId, const std::string& targetId);
    std::shared_ptr<dgml::Category> createCategory(const std::string& id, const std::string& label);
};

