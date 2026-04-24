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

    int numOperation = 1;
    do {
        cout << "\nTime: " << numOperation << " Operation: ";
        int probability = rand() % 100;
        if (probability < 55) {
            cout << "Car paid: ";
            line.front().print();
            line.pop_front();
        } else if (probability > 55) {
            cout << "Joined lane: ";
            Car joinedCar;
            line.push_back(joinedCar);
            line.back().print();
        }
        ++numOperation;
    } while (!line.empty() && numOperation <= 6);

    return 0;
}

void printQueue(deque<Car> queue) {
    for (auto& )
}