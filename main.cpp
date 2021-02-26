#include <iostream>
#include <vector>
#include <chrono>

#include "PriorityQueue.h"
#include "GetDatas.h"

int main(int argc, char**argv) {
    auto tempstart = std::chrono::steady_clock::now(); //start the timer

    int m = std::atoi(argv[1]);     //take operation num
    float p = std::atof(argv[2]);   //take probability

    PriorityQueue* myHeap;
    myHeap = new PriorityQueue();//create priority queue

    getDataFromFile(&myHeap->getAllTaxis()); //get all the data from locations.txt
    auto start = std::chrono::steady_clock::now();  //start make operations timer
    myHeap->Make_Operations(m, p); // make operations
    myHeap->printDistanceUpdates(); //printe distance updates
    auto end = std::chrono::steady_clock::now();//stop make operations timer
    auto diff = end - start; // calculate make operations execution time
    std::cout <<"Execution Took: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl; // start timer for execution time for all the program
    delete myHeap;//delete priority queue
    auto tempend = std::chrono::steady_clock::now(); // stop program execution timer
    auto tempdiff = tempend - tempstart; // calculate execution time
    std::cout <<"All Took: " <<std::chrono::duration <double, std::milli> (tempdiff).count() << " ms" << std::endl; // start timer for execution time for all the program

    return 0;
}
