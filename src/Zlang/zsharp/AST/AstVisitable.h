#pragma once

class AstVisitor;

class AstVisitable
{
public:
    virtual void Accept(AstVisitor* vistor) = 0;
    virtual void VisitChildren(AstVisitor* vistor) {}
};
