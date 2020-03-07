//
// Created by Kuba on 13.01.2020.
//

#include <cstddef>
#include <iostream>
#include "DList.h"
using namespace std;

DList::DList()
{
    this->head = nullptr;
    this->size = 0;
}

int DList::getSize() {
    return this->size;
}
void DList::add(double data) {
    NodeDLL* newNode = new NodeDLL(data);
    this->size++;
    if(this->head == nullptr)
    {
        this->head = newNode;
        return;
    }
    this->head->left = newNode;
    newNode->right = this->head;
    this->head = newNode;
}
void DList::show() {
    NodeDLL* node = this->head;
    while(node != nullptr)
    {
        cout << node->data;
        cout << " ";
        node = node->right;
    }
    cout << endl;
}

NodeDLL* DList::find(double data)
{
    NodeDLL* node = this->head;
    if(node->data == data)
    {
        return node;
    }
    while(node->right != nullptr)
    {
        if(node->right->data == data)
        {
            return node->right;
        }
        else
        {
            node = node->right;
        }
    }
    return nullptr;
}
void DList::remove(double data)
{
    NodeDLL* node = this->find(data);
    if(node == nullptr) return;

    if(node->left == nullptr)
    {
        this->head = node->right;
        delete node;
    }
    else if(node->right != nullptr)
    {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }
    else
    {
        node->left->right = nullptr;
        delete node;
    }

    this->size--;

}