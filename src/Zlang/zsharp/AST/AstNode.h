#pragma once

enum class AstNodeType {
    None,
    Module,         // root
    File,           // Module::*
    Global,         // File::1
    Function,       // File::*
    Struct,         // File::*
    Enum,           // File::*
};

class AstNode
{
public:
    AstNodeType getNodeType() const { return _nodeType; }
    const AstNode* getParent() const { return _parent; }

protected:
    AstNode(AstNodeType nodeType)
        : _nodeType(nodeType), _parent(nullptr)
    {}

    void setParent(AstNode* parent) { _parent = parent; }

private:
    AstNodeType _nodeType;
    AstNode* _parent;
};

