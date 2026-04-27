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
const int MAX_TIME_PERIOD = 20;

void printLanes(const array<deque<Car>, MAX_TOLL_BOOTH>& lanes);
// void shiftLanes(deque<Car> carShift, array<deque<Car>, MAX_TOLL_BOOTH> lanes);

int main() {
    srand(time(nullptr));

    array<deque<Car>, MAX_TOLL_BOOTH> lanes;
    for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
        for (int j = 0; j < NUM_CAR; j++) {
            lanes.at(i).push_back(Car());
        }
    }

    printLanes(lanes);

    int numOperation = 1;
    do {
        cout << "\nTime: " << numOperation << '\n';
        for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
            cout << "Lane " << i + 1 << " ";

            if (rand() % 2 == 0) {  // 50/50 leave
                if (!lanes.at(i).empty()) {
                    cout << "Paid: ";
                    lanes.at(i).front().print();
                    lanes.at(i).pop_front();
                } else {
                    cout << "Empty\n";
                }
            } else {                // join
                cout << "Joined: ";
                Car joinedCar;
                lanes.at(i).push_back(joinedCar);
                joinedCar.print();
            }
        }
        for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
            cout << "Lane " << i + 1 << " Queue:\n";
            for (auto& car : lanes.at(i)) {
                car.print();
            }
        }
        ++numOperation;
    } while (numOperation <= MAX_TIME_PERIOD);
    return 0;
}

void printLanes(const array<deque<Car>, MAX_TOLL_BOOTH>& lanes) {
    for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
        cout << "Lane " << i + 1 << " Queue:\n";
        for (const auto& car : lanes.at(i)) {
            car.print();
        }
    }
}
