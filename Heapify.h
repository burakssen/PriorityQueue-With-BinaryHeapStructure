//
// Created by burakssen on 23.12.2020.
//

#ifndef TEMP_HEAPIFY_H
#define TEMP_HEAPIFY_H

#include <vector>

#include "Data.h"

int Parent(int index){
    return index / 2;
}

void swap( Data &first, Data &second ) { // swap datas
    Data temp = first;
    first = second;
    second = temp;
}

void Min_Heapify(std::vector<Data>* data, int heapsize, int index){ // min heapify
    // in this function we make our array a minimum heap structured array
    int smallest = index; //smallest index
    int left = 2 * index ; // take left node
    int right = 2 * index + 1;  //take right node

    // if left node num is not greater than the array size
    // and if left node num's data is smaller than the smallest data so far
    if (left < heapsize && (*data)[left].getData() < (*data)[smallest].getData())
        smallest = left; // assign left's num to smallest's num

    // if right node num is not greater than the array size
    // and if right node num's data is smaller than the smallest data so far
    if (right < heapsize && (*data)[right].getData() < (*data)[smallest].getData())
        smallest = right; // assign right's num to smallest's num

    if (smallest != index) { // if our smallest num is not our root which is in the minimum heap structure the top node
        swap((*data)[index], (*data)[smallest]); // swap smallest and index data
        Min_Heapify(data, heapsize, smallest); // and arrange again
    }
}

/*
void Build_Min_Heap(std::vector<Data> *data, int heapsize) {
    // In this function we execute the array with the root nums of the each leafs (heapsize - 1)/2 is root for the each leaf
    for(int i = (heapsize - 1)/2 ; i > 0; i--) {
        Min_Heapify(data, heapsize, i); // for each leaf arange the array
    }
}
 */

Data Extract_Min(std::vector<Data> *data, int heapsize){
    // In this function we pop our minimum number from top
    // In other terms we pop our root from the top
    if (heapsize < 1)
        throw "Error";
    Data min = (*data)[1]; // get the top root our root is the second element in the array
    (*data)[1] = (*data)[heapsize - 1]; //  take the last element to the root's place
    heapsize--; // decrease the element size
    Min_Heapify(data,heapsize,1); // arrange the array
    return min;// return the smallest element (root)
}

void Decrease_Key(std::vector<Data> *data, int index, Data key){
    // Decrease Key function decreases inserted data if it is lower than the smallest data
    if(key.getData() > (*data)[index].getData())    // if key is greater than infinite(100000 is enough I think for this case)
        return;

    (*data)[index] = key; // set key as an new data
    //set the first distance
    (*data)[index].setFirstDistance();
    int i = index;// set index number
    // if index is not 1 (which means our data is not the smallest right now)
    // and if our datas parent is greater than it self, loop
    while(i > 1 && (*data)[Parent(i)].getData() > (*data)[i].getData()){
        swap((*data)[i],(*data)[Parent(i)]); // swap the parent of our data with our data
        i = Parent(i);  // change the index to parent (which is our inserted data's index)
    }
}

void Insert(std::vector<Data>* data, Data key, int heapsize){ //In this function we insert a data to array
    Data temp("NULL", 100000); // create new data for the list (with infinite distance)
    (*data).emplace_back(temp); // place it the end of the list
    Decrease_Key(data,heapsize,key);
    // call decrease key function if our key is lower then infinite
    // it will be inserted a logical place
}


#endif //TEMP_HEAPIFY_H
