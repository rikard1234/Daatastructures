//
// Created by Kuba on 13.01.2020.
//

#ifndef DATASTRUCTURES_DLIST_H
#define DATASTRUCTURES_DLIST_H

#include "NODEDLL.h"

class DList
{
private:
    int size;
    NodeDLL* head;
public:
    DList();
    void add(double data);
    void show();
    NodeDLL* find(double data);
    void remove(double data);
    int getSize();
};
#endif //DATASTRUCTURES_DLIST_H
