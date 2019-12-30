#pragma once

enum class AstNodeType {
    None,
    Module,         // root
    File,           // Module::*
    Dependencies,   // File::1
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
    AstNode(AstNodeType nodeType, AstNode* parent) 
        : _nodeType(nodeType), _parent(parent)
    {}

private:
    AstNodeType _nodeType;
    AstNode* _parent;
};

