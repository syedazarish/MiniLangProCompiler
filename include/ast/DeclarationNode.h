#ifndef DECLARATION_NODE_H
#define DECLARATION_NODE_H

#include "StatementNode.h"

class DeclarationNode : public StatementNode
{
public:

    virtual ~DeclarationNode() = default;
};

using DeclarationNodePtr = std::shared_ptr<DeclarationNode>;

#endif