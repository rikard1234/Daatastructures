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


ofstream file_out;

void measure_component(string file_name, int* durationContainer, int sizes) {
    int average;
    int sum = 0;
    for(int i = 0; i < 30; i++) {
       sum += durationContainer[i];
    }
    average = sum / 30;
    file_out.open(file_name, fstream::app);
    file_out << "FOR" << sizes << "ELEMENTS" << endl;
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
    int j = 0;

    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {
            DynamicArray dynamicArray;
            for (int i = 0; i < sizes[j]; i++) {
                int temp = rand() % 2 * sizes[j] - sizes[j];
                dynamicArray.add((double)temp);
            }
            double item = rand() % 2 * sizes[j] - sizes[j];
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.add(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            durationContainer[i] = duration;
        }
        measure_component("addDA.txt", durationContainer, sizes[j]);
        j++;
    }
}

void findDA() {
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};
    int durationContainer[30];
    int j = 0;

    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {
            DynamicArray dynamicArray;
            for (int i = 0; i < sizes[j]; i++) {
                int temp = rand() % 2 * sizes[j] - sizes[j];
                dynamicArray.add((double) temp);
            }
            double item = rand() % 2 * sizes[j] - sizes[j];;
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.find(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            durationContainer[i] = duration;
        }
        measure_component("findDA.txt", durationContainer, sizes[j]);
        j++;
    }
}

void removeDA() {
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};
    int durationContainer[30];
    int j = 0;
    for (j; j < 6;) {
        for (int i = 0; i < 30; i++) {
            DynamicArray dynamicArray;
            double* values = new double [sizes[j]];
            for (int i = 0; i < sizes[j]; i++) {
                values[i] = rand() % 2 * sizes[j] - sizes[j];
                dynamicArray.add(values[i]);
            }
            int index = rand () % sizes[j];
            auto t1 = std::chrono::high_resolution_clock::now();
            dynamicArray.remove(values[index]);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            durationContainer[i] = duration;
            delete values;
        }
        measure_component("removeDA.txt", durationContainer, sizes[j]);
        j++;
    }
}

int main() {
    srand(time(NULL));
  // removeDA();
  // addDA();
 //  findDA();

}