//
// Created by burakssen on 22.12.2020.
//

#ifndef HEAP_GETDATAS_H
#define HEAP_GETDATAS_H

#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "Data.h"


void getDataFromFile(std::vector<Data> *myHeap) // this function parse all the data from the file
{
    std::ifstream file;
    file.open("locations.txt");
    std::string header_line;
    std::getline(file,header_line,'\n'); // skip first line

    float latitude;
    float longitude;
    float pisagor;

    int i = 0;
    while(!file.eof()) // loop until end of the file
    {
        std::string taxiname = "Taxi - "; // taxi name
        file>>latitude;
        file>>longitude;
        pisagor = std::sqrt(latitude*latitude + longitude*longitude); // calculate distance
        taxiname += std::to_string(i);  // set taxi numbers
        Data *temp;
        temp = new Data(taxiname,pisagor); // create new data
        (*myHeap).emplace_back(*temp); // add to priority queue
        delete temp; // delete data
        i++;
    }
    file.close();
}

#endif //HEAP_GETDATAS_H
