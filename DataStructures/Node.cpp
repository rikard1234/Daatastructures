//
// Created by Kuba on 13.01.2020.
//

#include "Node.h"

Node::Node(double data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
Node::~Node()
{
}