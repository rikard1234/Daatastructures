//
// Created by Kuba on 13.01.2020.
//
using namespace std;
#include "iostream"
#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    this->size = 0;
    this->tab = new double[1];
}

DynamicArray::~DynamicArray()
{
    delete[] this->tab;
    this->size = 0;
}

void DynamicArray::add(double item)
{

    if (this->size == 0)
    {
        this->tab[size] = item;
        this->size++;
    }
    else
    {
        this->size++;
        tab = (double*)realloc(this->tab, sizeof(double) * (this->size));
        this->tab[this->size - 1] = item;
    }
}

void DynamicArray::display()
{
    for(int i = 0; i < this->size; ++i)
    {
        cout << this->tab[i] << " " << endl;
    }
}

int DynamicArray::find(double val)
{
    for (int i = 0; i < this->size - 1; ++i) {
        if (val == this->tab[i]) {
            return i;
        }
    }
    return -1;
}

void DynamicArray::remove(double val)
{
    if(this->size == 1)
    {
        this->size = 0;
        return;
    }
    for(int i = 0; i < this->size - 1; ++i)
    {
        if(this->tab[i] == val)
        {
            for(int j = i; j < this->size - 1; ++j)
            {
                this->tab[j] = this->tab[j+1];
            }
            this->size = this->size  - 1;
        }
    }
}
