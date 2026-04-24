// COMSC-210 | Lab 32 | Barsbek
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int NUM_CAR = 2;
const int PROB_PRCNT = 100;

int main() {
    srand(time(nullptr));
    deque<Car> line;
    for (int i = 0; i < NUM_CAR; ++i) { // Initial val
        Car car;
        line.push_back(car);
    }

    cout << "Initial queue:\n";
    for (auto& cars : line)
        cars.print();

    return 0;
}


// int numOperation = 1;
// do {
//     cout << "Time: " << numOperation << " Operation: ";
//     int probability = rand() % 100;
//     if (probability < 55) {
//
//     }
// } while (!line.empty());