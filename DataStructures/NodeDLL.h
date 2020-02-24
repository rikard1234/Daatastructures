//
// Created by Kuba on 13.01.2020.
//

#ifndef DATASTRUCTURES_NODEDLL_H
#define DATASTRUCTURES_NODEDLL_H


class NodeDLL
{
    public:
        NodeDLL(double e);
        NodeDLL* left;
        NodeDLL* right;
        double data;
};



#endif //DATASTRUCTURES_NODEDLL_H
