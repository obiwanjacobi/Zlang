#pragma once

#include "../AST/AstFile.h"
#include "../AST/AstFunction.h"
#include "../AST/AstCodeBlock.h"
#include "../AST/AstAssignment.h"
#include "../AST/AstBranch.h"
#include "Dgml.h"
#include <ostream>
#include <memory>

class DgmlBuilder
{
public:
    DgmlBuilder()
        : _id(0)
    {
        _graph = std::make_unique<dgml::Graph>();
        createInitial();
    }

    std::shared_ptr<dgml::Node> WriteFile(std::shared_ptr<AstFile> file);
    std::shared_ptr<dgml::Node> WriteFunction(std::shared_ptr<AstFunction> function, const std::string& parentId);
    std::shared_ptr<dgml::Node> WriteCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock, std::shared_ptr<AstCodeBlock> prevBlock, const std::string& parentId);
    std::shared_ptr<dgml::Node> WriteCodeBlockItem(std::shared_ptr<AstCodeBlockItem> codeBlockItem, const std::string& codeBlockId);
    std::shared_ptr<dgml::Node> WriteAssignment(std::shared_ptr<AstAssignment> assignment, const std::string& parentId);
    std::shared_ptr<dgml::Node> WriteBranch(std::shared_ptr<AstBranch> branch, const std::string& parentId);

    void Serialize(std::ostream& output);
    void SaveAs(const std::string& filePath);

private:
    uint32_t _id;
    std::unique_ptr<dgml::Graph> _graph;

    uint32_t nextId() { return ++_id; }

    void createInitial();
    std::shared_ptr<dgml::Node> createNode(const std::string& id, const std::string& label, const char* typeName = nullptr);
    std::shared_ptr<dgml::Link> createLink(const std::string& sourceId, const std::string& targetId, const char* category = nullptr);
    std::shared_ptr<dgml::Category> createCategory(const std::string& id, const std::string& label);

    std::shared_ptr<dgml::Link> findLink(const std::string& sourceId, const std::string& targetId) const;
};

