#ifndef BINARY_EXPRESSION_NODE_H
#define BINARY_EXPRESSION_NODE_H

#include "../common/TokenType.h"

#include "ExpressionNode.h"

class BinaryExpressionNode : public ExpressionNode
{
private:

    ExpressionNodePtr left;

    ExpressionNodePtr right;

    TokenType op;

public:

    BinaryExpressionNode(
        ExpressionNodePtr left,
        TokenType op,
        ExpressionNodePtr right)
    {
        this->left = left;
        this->op = op;
        this->right = right;
    }

    ExpressionNodePtr getLeft() const
    {
        return left;
    }

    ExpressionNodePtr getRight() const
    {
        return right;
    }

    TokenType getOperator() const
    {
        return op;
    }
};

using BinaryExpressionNodePtr =
    std::shared_ptr<BinaryExpressionNode>;

#endif