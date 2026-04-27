// COMSC-210 | Lab 32 | Barsbek
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

//
const int NUM_CAR = 2;              // initial num of cars
const int PROB_PRCNT = 100;         // probability range
const int LEAVE_CHANCE = 55;        // chance car leaves

void printQueue(const deque<Car>& queue);

int main() {
    srand(time(nullptr));
    deque<Car> line;                // queue of cars

    // initialize queue
    for (int i = 0; i < NUM_CAR; ++i) {
        Car car;
        line.push_back(car);
    }

    cout << "Initial queue:\n";     // initial val cars
    for (auto& cars : line)
        cars.print();

    int numOperation = 1;
    do {
        cout << "\nTime: " << numOperation << " Operation: ";
        int probability = rand() % PROB_PRCNT; // for prob
        if (probability < LEAVE_CHANCE) {      // car leaves
            if (!line.empty()) {
                cout << "Car paid: ";
                line.front().print();
                line.pop_front();
            }
            printQueue(line);
        } else {                               // car joins
            cout << "Joined lane: ";
            Car joinedCar;
            line.push_back(joinedCar);
            line.back().print();
            printQueue(line);
        }
        ++numOperation;
        if (line.empty())
            cout << "Empty\n";
    } while (!line.empty());
    return 0;
}

// print all cars in queue
void printQueue(const deque<Car>& queue) {
    cout << "Queue:\n";
    for (auto& fullQueue : queue)
        fullQueue.print();
}