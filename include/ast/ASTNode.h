#ifndef AST_NODE_H
#define AST_NODE_H

#include <memory>
#include <vector>

class ASTNode
{
public:

    virtual ~ASTNode() = default;
};

using ASTNodePtr = std::shared_ptr<ASTNode>;

#endif