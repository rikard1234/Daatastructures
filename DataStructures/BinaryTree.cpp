//
// Created by Kuba on 13.01.2020.
//
#include "BinaryTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
    this->root = nullptr;
}

void BinaryTree::add(double data)
{
    this->add(data, this->root);
}

Node* BinaryTree::add(double data, Node* node)
{
    if(this->root == nullptr)
    {
        this->root = new Node(data);
    }
    if(node == nullptr)
    {
        node = new Node(data);
    }
    else if (data < node->data)
    {
        node->left = add(data, node->left);
        node->left->parent = node;
    }
    else if (data > node->data)
    {
        node->right = add(data, node->right);
        node->right->parent = node;
    }
    return node;
}

Node* BinaryTree::find(double data)
{
    return this->find(data, this->root);
}

Node* BinaryTree::find(double data, Node* node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    else if (data < node->data)
    {
        return find(data, node->left);
    }
    else if (data > node->data)
    {
        return find(data, node->right);
    }
    else if(data == node->data)
    {
        return node;
    }
}

void BinaryTree::remove(double data)
{
    Node* toDelete = find(data);

    if (toDelete == nullptr) return;

    if (toDelete->right == nullptr && toDelete->left == nullptr)
    {
        if(toDelete->parent != nullptr)
        {
            if (toDelete->parent->data < toDelete->data)
            {
                toDelete->parent->right = nullptr;
            }
            else if (toDelete->parent->data > toDelete->data)
            {
                toDelete->parent->left = nullptr;
            }
        }
        else
        {
            this->root = nullptr;
        }

        delete toDelete;
    }
    else if (toDelete->left != nullptr && toDelete->right != nullptr)
    {
        Node *temp = findMin(toDelete->right);
        if(temp->parent == toDelete)
        {
            toDelete->right = temp->right;
        }
        else
        {
            temp->parent->left = nullptr;
        }

        toDelete->data = temp->data;
        delete temp;
    }
    else if (toDelete->right != nullptr)
    {
        if (toDelete->parent == nullptr)
        {
            this->root = this->root->right;
        }
        else
        {
            toDelete->parent->right = toDelete->right;
        }

        delete toDelete;
    }
    else
    {
        if (toDelete->parent == nullptr)
        {
            this->root = this->root->left;
        }
        else
        {
            toDelete->parent->left = toDelete->left;
        }

        delete toDelete;
    }
}

Node* BinaryTree::findMin(Node* node)
{
    while(node->left != nullptr) node = node->left;
    return node;
}
