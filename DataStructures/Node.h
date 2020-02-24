//
// Created by Kuba on 13.01.2020.
//

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H


class Node
{
    public:
        double data;
        Node* parent;
        Node();
        ~Node();
        Node(double data);
        Node* left;
        Node* right;
    };




#endif //DATASTRUCTURES_NODE_H
