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
using namespace std;
int sizes[] = {100, 2000, 50000, 80000, 90000};
const int n = 5;
ofstream file_out;

void measure_component(string file_name, long double* durationContainer, int sizes) {
    long  double average;
    long  double sum = 0;
    for(int i = 0; i < 100; i++) {
       sum += durationContainer[i];
    }
    average = sum / 100;
    file_out.open(file_name, fstream::app);
    file_out << "FOR" << sizes << "ELEMENTS" << endl;
    file_out << "AVERAGE :" << average << endl;
    long double stdDeviation = 0;
    for(int i = 0; i < 100; i++) {
        stdDeviation = stdDeviation + ((durationContainer[i] - average) * (durationContainer[i] - average));
    }
    stdDeviation = stdDeviation / n;
    pow(stdDeviation, 0.5);
    file_out << "DEVIATION :" << stdDeviation << endl;
    file_out.close();
}

void addDA() {
    long double durationContainer[100];
    int j = 0;

    for (j; j < n;) {
        for (int i = 0; i < 100; i++) {
            BinaryTree da;
            for (int i = 0; i < sizes[j]; i++) {
                int temp = rand() % (2 * sizes[j]) - sizes[j];
                da.add((double)temp);
            }
            double item = rand() % (2 * sizes[j]) - sizes[j];
            auto t1 = std::chrono::high_resolution_clock::now();
            da.add(item);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            durationContainer[i] = duration;
        }
        measure_component("addDA.txt", durationContainer, sizes[j]);
        j++;
    }
}

void findDA() {
    long double durationContainer[100];
    int j = 0;

    for (j; j < n;) {
        for (int i = 0; i < 100; i++) {
            BinaryTree da;
            double* values = new double [sizes[j]];
            for (int i = 0; i < sizes[j]; i++) {
                values[i] = rand() % (2 * sizes[j]) - sizes[j];
                da.add(values[i]);
            }
            int index = rand () % sizes[j];
            auto t1 = std::chrono::high_resolution_clock::now();
            da.find(values[index]);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            durationContainer[i] = duration;
            delete values;
        }
        measure_component("findDA.txt", durationContainer, sizes[j]);
        j++;
    }
}

void removeDA() {
    long double durationContainer[100];
    int j = 0;
    for (j; j < n;) {
        for (int i = 0; i < 100; i++) {
            BinaryTree da;
            double* values = new double [sizes[j]];
            for (int i = 0; i < sizes[j]; i++) {
                values[i] = rand() % (2 * sizes[j]) - sizes[j];
                da.add(values[i]);
            }
            int index = rand () % sizes[j];
            auto t1 = std::chrono::high_resolution_clock::now();
            da.remove(values[index]);
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
    addDA();
 // findDA();



}