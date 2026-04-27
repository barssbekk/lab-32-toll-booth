// COMSC-210 | Lab 32 | Barsbek
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Car.h"

using namespace std;

const int NUM_CAR = 2;              // initial num of cars
const int PROB_PRCNT = 100;         // probability range
const int LEAVE_CHANCE = 46;        // chance car leaves
const int JOIN_CHANCE = 39;
const int SHIFT_LANE_CHANCE = 15;
const int MAX_TOLL_BOOTH = 4;       // max amount of toll both lan

void printQueue(const deque<Car>& queue);
void shiftLanes(deque<Car> carShift, array<deque<Car>, MAX_TOLL_BOOTH> lanes);

int main() {
    srand(time(nullptr));
    deque<Car> line;                // queue of cars

    // initialize queue
    for (int i = 0; i < NUM_CAR; ++i) {
        Car car;
        line.push_back(car);
    }

    array<deque<Car>, MAX_TOLL_BOOTH> lanes;
    for (int i = 0; i < MAX_TOLL_BOOTH; i++) {
        lanes.at(i).push_back(Car());
    }
    cout << " Milestone 2 \n";

    for (int i = 0; i < MAX_TOLL_BOOTH; i++) {
        cout << "Lane " << i + 1 << ":\n";
        for (auto& car : lanes.at(i)) {
            car.print();
        }
    }

    cout << "\nInitial queue:\n";     // initial val cars
    for (auto& cars : line)
        cars.print();

    int numOperation = 1;
    do {
        cout << "\nTime: " << numOperation << " Operation: ";
        int probability = rand() % PROB_PRCNT; // for prob
        if (probability < LEAVE_CHANCE) {      // car leaves //
            if (!line.empty()) {
                cout << "Car paid: ";
                line.front().print();
                line.pop_front();
            }
            printQueue(line);
        } else {    // FIXME: prob  // 39           // car joins
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

// void shiftLanes(deque<Car> line, array<deque<Car>, MAX_TOLL_BOOTH> lanes) {
//     for (int i = 0; i < lanes.size(); ++i) {
//         lanes.at(i).push_back(line.back());
//     }
// }
