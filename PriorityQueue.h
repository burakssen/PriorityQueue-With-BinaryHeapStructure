//
// Created by burakssen on 24.12.2020.
//

#ifndef TEMP_PRIORITYQUEUE_H
#define TEMP_PRIORITYQUEUE_H

#include <string>
#include <iostream>
#include <vector>

#include "Data.h"

class PriorityQueue {
    std::vector<Data> *data;
    std::vector<Data> *alltaxis;
    int numberOfTaxiAdditions = 0;
    public:
        PriorityQueue();
        void Make_Operations(int, float);
        std::vector<Data> &getAllTaxis();
        void printDistanceUpdates();
        ~PriorityQueue();

};


#endif //TEMP_PRIORITYQUEUE_H
