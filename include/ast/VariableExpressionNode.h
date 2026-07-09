#ifndef VARIABLE_EXPRESSION_NODE_H
#define VARIABLE_EXPRESSION_NODE_H

#include <string>

#include "ExpressionNode.h"

class VariableExpressionNode : public ExpressionNode
{
private:

    std::string name;

public:

    explicit VariableExpressionNode(const std::string& name)
    {
        this->name = name;
    }

    const std::string& getName() const
    {
        return name;
    }
};

using VariableExpressionNodePtr =
    std::shared_ptr<VariableExpressionNode>;

#endif