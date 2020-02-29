#include <iostream>
#include "DynamicArray.h"
#include "BinaryTree.h"
#include "DList.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <utility>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
using namespace std;;

DynamicArray dynamicArray;
ofstream file_out;

void measure_component(string file_name, int* durationContainer, int sum, int* sizes) {
    int average;
    average = sum / 30;
    file_out.open(file_name, fstream::app);
    file_out << "FOR" << *sizes << "ELEMENTS" << endl;
    file_out << "AVERAGE :" << average << endl;
    int stdDeviation = 0;
    for(int i = 0; i < 30; i++) {
        stdDeviation = stdDeviation + ((durationContainer[i] - average) * (durationContainer[i] - average));
    }
    pow(stdDeviation, 0.5);
    file_out << "DEVIATION :" << stdDeviation << endl;
    file_out.close();
}

void addDA() {
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};
    int durationContainer[30];
    int sum = 0, j = 0;
    int *data_ref = new int[sizes[j]];

    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {

            for (int i = 0; i < sizes[j]; i++) {
                data_ref[i] = rand() % 200 - 100;
                dynamicArray.add((double) data_ref[i]);
            }

            double item = rand() % 200 - 100;
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.add(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            dynamicArray.remove(item);

            sum += duration;
            durationContainer[i] = duration;
        }

        measure_component("addDA.txt", durationContainer, sum, &sizes[j]);
        sum = 0;
        j++;
        delete [] data_ref;
        if(j < 6) data_ref =  new int [sizes[j]];
    }

}

void findDA() {
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};
    int durationContainer[30];
    int sum = 0, j = 0;
    int *data_ref = new int[sizes[j]];

    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {

            for (int i = 0; i < sizes[j]; i++) {
                data_ref[i] = rand() % 200 - 100;
                dynamicArray.add((double) data_ref[i]);
            }

            double item = rand() % 200 - 100;
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.find(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();


            sum += duration;
            durationContainer[i] = duration;
        }

        measure_component("findDA.txt", durationContainer, sum, &sizes[j]);
        sum = 0;
        j++;
        delete [] data_ref;
        if(j < 6) data_ref =  new int [sizes[j]];
    }

}

void removeDA() {
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};
    int durationContainer[30];
    int sum = 0, j = 0;
    int *data_ref = new int[sizes[j]];

    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {

            for (int i = 0; i < sizes[j]; i++) {
                data_ref[i] = rand() % 200 - 100;
                dynamicArray.add((double) data_ref[i]);
            }

            double item = rand() % 200 - 100;
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.remove(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

            sum += duration;
            durationContainer[i] = duration;
        }

        measure_component("removeDA.txt", durationContainer, sum, &sizes[j]);
        sum = 0;
        j++;
        delete [] data_ref;
        if(j < 6) data_ref =  new int [sizes[j]];
    }

}

int main() {
    srand(time(NULL));
     removeDA();
    //addDA();
    //findDA();
}