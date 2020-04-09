#pragma once

enum class AstNodeType {
    None,
    Module,         // root
    File,           // Module::*
    Global,         // File::1
    Function,       // File::*
    Struct,         // File::*
    Enum,           // File::*
    Type,           // File::*, Variable:[1], Parameter:[1]

    CodeBlock,      // File::*
    Assignment,     // CodeBlock::*
    Branch,         // CodeBlock::*
    Expression,     // CodeBlock::*, Branch::[1]
    Numeric,        // Expression::1

    Identifier,     // Function::1, Struct::1, Enum::1, Assignment::1

    FunctionParameter,
};

class AstNode
{
public:
    AstNodeType getNodeType() const { return _nodeType; }

    AstNode* getParent() const { return _parent; }
    void setParent(AstNode* parent) { _parent = parent; }

    template<class T>
    T* getParent() const { return dynamic_cast<T*>(_parent); }
    template<class T>
    T* getParentRecursive() const
    {
        auto parent = getParent();

        if (parent) {
            T* typedParent = getParent<T>();

            if (typedParent) {
                return typedParent;
            }

            return parent->getParentRecursive<T>();
        }

        return nullptr;

    }

protected:
    AstNode(AstNodeType nodeType)
        : _nodeType(nodeType), _parent(nullptr)
    {}
    virtual ~AstNode() {}

private:
    AstNodeType _nodeType;
    AstNode* _parent;
};

