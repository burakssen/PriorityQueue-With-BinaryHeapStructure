//
// Created by burakssen on 24.12.2020.
//

#include "Data.h"


Data::Data(std::string name,float data) { // data constructor
    this->name = name;  //set name
    this->data = data;  //set data
    this->first_distance = data; // set first distance data
}

std::string Data::getName() {
    return this->name;
}

float Data::getData() {
    return this->data;
}

float Data::getFirstDistance() { // get first distance data
    return this->first_distance;
}

void Data::operator-=(float data) { // operator -= for easy substruction
    this->data -= data;
}

void Data::operator=(Data data) { // set data from another data
    this->data = data.getData();
    this->name = data.getName();
}

void Data::setFirstDistance() { // set first distance
    this->first_distance = this->data;
}

void Data::setUpdated(bool updated) { // set updated flag
    this->updated = updated;
}

bool Data::getUpdated() {   // get if our data is updated
    return this->updated;
}

Data::~Data() {

}



