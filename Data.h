//
// Created by burakssen on 24.12.2020.
//

#ifndef TEMP_DATA_H
#define TEMP_DATA_H

#include <iostream>
#include <string>

class Data{
    std::string name;
    float data;
    float first_distance;
    bool updated = false;
public:
    Data(std::string, float);
    std::string getName();
    float getData();
    float getFirstDistance();
    void operator-=(float);
    void setFirstDistance();
    void operator=(Data);
    void setUpdated(bool);
    bool getUpdated();
    ~Data();
};


#endif //TEMP_DATA_H
