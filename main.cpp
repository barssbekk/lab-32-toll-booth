// COMSC-210 | Lab 33 | Barsbek
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
const int JOIN_CHANCE = 39;         //
const int MAX_TOLL_BOOTH = 4;       // max amount of toll both lan
const int MAX_TIME_PERIOD = 20;     // 

void printLanes(const array<deque<Car>, MAX_TOLL_BOOTH>& lanes);

int main() {
    srand(time(nullptr));

    array<deque<Car>, MAX_TOLL_BOOTH> lanes;
    for (int i = 0; i < MAX_TOLL_BOOTH; ++i) { // fill each lane w 2 cars
        for (int j = 0; j < NUM_CAR; j++) {
            lanes.at(i).push_back(Car());
        }
    }

    // init val
    printLanes(lanes);
    cout << '\n';

    int numOperation = 1;
    do {
        cout << "\nTime: " << numOperation << '\n';

        for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
            cout << "Lane " << i + 1 << " ";
            int rnd = rand() % PROB_PRCNT;
            if (lanes.at(i).empty()) {
                if (rand() % 2 == 0) { // 50/50
                    cout << "Joined: ";
                    Car car;
                    lanes.at(i).push_back(car);
                    car.print();
                } else {
                    cout << "Empty\n";
                }
            }
            else if (rnd < LEAVE_CHANCE) { // car leaves
                cout << "Paid: ";
                lanes.at(i).front().print();
                lanes.at(i).pop_front();
            }
            else if (rnd < LEAVE_CHANCE + JOIN_CHANCE) { // car joins
                cout << "Joined: ";
                Car car;
                lanes.at(i).push_back(car);
                car.print();
            }
            else { // switch lane
                Car movingCar = lanes.at(i).back();
                lanes.at(i).pop_back();

                int newLane;
                do {
                    newLane = rand() % MAX_TOLL_BOOTH;
                } while (newLane == i);

                lanes.at(newLane).push_back(movingCar);

                cout << "Switched: ";
                movingCar.print();
            }
        }

        printLanes(lanes);

        ++numOperation;

    } while (numOperation <= MAX_TIME_PERIOD);
    return 0;
}

// print each lane
void printLanes(const array<deque<Car>, MAX_TOLL_BOOTH>& lanes) {
    for (int i = 0; i < MAX_TOLL_BOOTH; ++i) {
        cout << "Lane " << i + 1 << " Queue:\n";
        for (const auto& car : lanes.at(i)) {
            cout << '\t';
            car.print();
        }
    }
}
