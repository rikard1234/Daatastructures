//
// Created by Kuba on 13.01.2020.
//

#ifndef DATASTRUCTURES_BINARYTREE_H
#define DATASTRUCTURES_BINARYTREE_H
#include "Node.h"
class BinaryTree
{
private:
    Node* root;
    Node* add(double data, Node* root);
    Node* find(double data, Node* root);
    Node* findMin(Node* root);
public:
    BinaryTree();
    void add(double data);
    Node* find(double data);
    void remove(double data);
};

#endif //DATASTRUCTURES_BINARYTREE_H
