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
int duration_container[20000] = {0};
int n = 100;
int sum = 0;
unsigned int stdDeviation = 0;
double average = 0;
void measure_component(string file_name, int i) {
    if (i == 29) {
        file_out.open(file_name, fstream::app);
        for (int i = 0; i <= 29; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 0; i <= 29; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / 30 << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        n = 500;
        file_out.close();
    }
    else if (i == 59) {
        file_out.open(file_name, fstream::app);
        for (int i = 30; i <= 59; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 30; i <= 59; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / n << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        n = 1000;
    }
    else if (i == 89) {
        file_out.open(file_name, fstream::app);
        for (int i = 60; i <= 89; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 60; i <= 89; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / n << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        n = 2000;
        file_out.close();
    }
    else if (i == 119) {
        file_out.open(file_name, fstream::app);
        for (int i = 90; i <= 119; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 90; i <= 119; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / n << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        n = 5000;
        file_out.close();
    }
    else if (i == 149) {
        file_out.open(file_name, fstream::app);
        for (int i = 120; i <= 149; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 120; i <= 149; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / n << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        n = 10000;
        file_out.close();
    }
    else if (i == 179) {
        file_out.open(file_name, fstream::app);
        for (int i = 150; i <= 179; i++) {
            sum += duration_container[i];
        }

        average = sum / 30;

        for (int i = 150; i <= 179; i++) {
            stdDeviation = stdDeviation + ((duration_container[i] - average) * (duration_container[i] - average));
        }
        pow(stdDeviation, 0.5);
        file_out << "AVERAGE: " << average << "-----------------------------" << endl;
        file_out << "DEVIATION: " << stdDeviation / n << "-----------------------------" << endl;
        stdDeviation = 0;
        sum = 0;
        file_out.close();
    }
}

void addDA() {
    n = 100;
    for (int i = 0; i < 180; i++) {
        file_out.open("addDA.txt", fstream::app);
        int *data_ref = new int[n];

        for (int i = 0; i < n; i++) {
            data_ref[i] = rand() % 200 - 100;
        }
        for (int i = 0; i < n; i++) {
            dynamicArray.add((double) data_ref[i]);
        }

        double item = rand() % 200 - 100;
        auto t1 = std::chrono::high_resolution_clock::now();
        dynamicArray.add(item);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        duration_container[i] = duration;

        if (file_out.is_open()) {

            file_out << duration << "  for i:" << i << endl;
        }
        file_out.close();
        measure_component("AddDA.txt", i);
    }
    file_out.close();
}

void findDA() {
    n = 100;
    for (int i = 0; i < 180; i++) {
        file_out.open("findDA.txt", fstream::app);
        int *data_ref = new int[n];

        for (int i = 0; i < n; i++) {
            data_ref[i] = rand() % 200 - 100;
        }
        for (int i = 0; i < n; i++) {
            dynamicArray.add((double) data_ref[i]);
        }

        double item = rand() % 200 - 100;
        auto t1 = std::chrono::high_resolution_clock::now();
        dynamicArray.find(item);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        duration_container[i] = duration;

        if (file_out.is_open()) {
            file_out << duration << "  for i:" << i << endl;
        }
        file_out.close();
        measure_component("findDA.txt", i);
    }
        file_out.close();
}

void removeDA() {
    n = 100;
    for (int i = 0; i < 180; i++) {

        file_out.open("removeDA.txt", fstream::app);
        int *data_ref = new int[n];

        for (int i = 0; i < n; i++) {
            data_ref[i] = rand() % 200 - 100;
        }
        for (int i = 0; i < n; i++) {
            dynamicArray.add((double) data_ref[i]);
        }

        double item = rand() % 200 - 100;
        auto t1 = std::chrono::high_resolution_clock::now();
        dynamicArray.remove(item);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        duration_container[i] = duration;

        if (file_out.is_open()) {

            file_out << duration << "  for i:" << i << endl;
        }
        file_out.close();
        measure_component("removeDA.txt", i);
    }
        file_out.close();
}

int main() {
    srand(time(NULL));
   //removeDA();
  // addDA();
  // findDA();
}