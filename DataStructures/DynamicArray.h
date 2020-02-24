//
// Created by Kuba on 13.01.2020.
//

#ifndef DATASTRUCTURES_DYNAMICARRAY_H
#define DATASTRUCTURES_DYNAMICARRAY_H

class DynamicArray {
private:
    int size;
    double* tab;
public:
    DynamicArray();
    ~DynamicArray();
    void add(double item);
    void display();
    int find(double val);
    void remove(double val);
};


#endif //DATASTRUCTURES_DYNAMICARRAY_H
