#ifndef STATEMENT_NODE_H
#define STATEMENT_NODE_H

#include "ASTNode.h"

class StatementNode : public ASTNode
{
public:

    virtual ~StatementNode() = default;
};

using StatementNodePtr = std::shared_ptr<StatementNode>;

#endif