#pragma once

enum class AstNodeType {
    None,
    Module,         // root
    File,           // Module::*
    Global,         // File::1
    Function,       // File::*
    Struct,         // File::*
    Enum,           // File::*

    CodeBlock,      // File::*
    Branch,         // CodeBlock::*
    Expression,     // CodeBlock::*, Branch::[1]
    Numeric,        // Expression::1
};

class AstNode
{
public:
    AstNodeType getNodeType() const { return _nodeType; }

    const AstNode* getParent() const { return _parent; }
    void setParent(AstNode* parent) { _parent = parent; }

protected:
    AstNode(AstNodeType nodeType)
        : _nodeType(nodeType), _parent(nullptr)
    {}
    virtual ~AstNode() {}

private:
    AstNodeType _nodeType;
    AstNode* _parent;
};

