#ifndef LITERAL_EXPRESSION_NODE_H
#define LITERAL_EXPRESSION_NODE_H

#include <string>

#include "ExpressionNode.h"

class LiteralExpressionNode : public ExpressionNode
{
private:

    std::string value;

public:

    explicit LiteralExpressionNode(const std::string& value)
    {
        this->value = value;
    }

    const std::string& getValue() const
    {
        return value;
    }
};

using LiteralExpressionNodePtr =
    std::shared_ptr<LiteralExpressionNode>;

#endif