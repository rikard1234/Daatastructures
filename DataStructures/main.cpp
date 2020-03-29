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
int sizes[] = {40000};
const int n = 20;
const int array_size = 1;
ofstream file_out;

void measure_component(string file_name, double* durationContainer, int sizes) {
    double average;
    double sum = 0;
    for(int i = 0; i < n; i++) {
       sum += durationContainer[i];
    }
    average = sum / n;
    file_out.open(file_name, fstream::app);
    file_out << "FOR" << sizes << "ELEMENTS" << endl;
    file_out << "AVERAGE :" << average << endl;
    double stdDeviation = 0;
    for(int i = 0; i < n; i++) {
        stdDeviation = stdDeviation + ((durationContainer[i] - average) * (durationContainer[i] - average));
    }
    stdDeviation = stdDeviation / n;
    pow(stdDeviation, 0.5);
    file_out << "DEVIATION :" << stdDeviation << endl;
    file_out.close();
}

void addDA() {
    double durationContainer[n];
    int j = 0;

    for (j; j < array_size;) {
        for (int i = 0; i < n; i++) {
            DList da;
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
    double durationContainer[n];
    int j = 0;

    for (j; j < array_size;) {
        for (int i = 0; i < n; i++) {
            DList da;
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
    double durationContainer[n];
    int j = 0;

    for (j; j < array_size;) {
        for (int i = 0; i < n; i++) {
            DList da;
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