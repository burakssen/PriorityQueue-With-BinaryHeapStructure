//
// Created by burakssen on 24.12.2020.
//

#include "PriorityQueue.h"
#include <ctime>
#include "Heapify.h"


PriorityQueue::PriorityQueue() { // priority queue cosntructor
    this->data = new std::vector<Data>();   // this will be filled up when the operations start
    this->alltaxis = new std::vector<Data>();   // for holding all the data
}

void PriorityQueue::Make_Operations(int m, float p) { // make operations function for operations
    srand(time(NULL));

    int j = 0; // a variable that counts 0 to 100 to determine taxi calls
    for(int i = 0; i < m; i++) {
        int random = rand() % 101; // random number between 0 and 99 with
        if(random < p * 100){ // if p * 100 is greater than our random number it would be %(p*100) chance
            if(!this->data->empty()){   // if our data is not empty
                int randomTaxi = rand() % this->data->size();   // take a random taxi
                (*this->data)[randomTaxi] -= 0.01;  // decrease the distance by 0.01
                (*this->data)[randomTaxi].setUpdated(true);
                int k = randomTaxi;  // updated data index
                // like in the decrease key function we swap if parent's data is greater then our updated data
                while(k > 1 && (*this->data)[k].getData() < (*this->data)[Parent(k)].getData())
                {
                    //swap parent and our data
                    swap((*this->data)[k],(*this->data)[Parent(k)]);
                    k = Parent(k); // set index to parent's index
                }

            }
        }
        else{
            this->numberOfTaxiAdditions++; // increase the number of taxi additions
            //this->data->emplace_back((*this->alltaxis)[this->data->size()]); // add the new taxi to array
            Insert(this->data,(*this->alltaxis)[this->data->size()], this->data->size());
        }
        if(j == 99){// if 100 operations happened
            //print the called taxi
            std::cout << "Called Taxi Distance: " << (*this->data)[1].getName() << " - " << (*this->data)[1].getData()
                      << std::endl;
            try {
                // remove the taxi from the array (which is the root node)
                Extract_Min(this->data, this->data->size());
            }
            catch (const char* msg){
                // send error
                std::cout<<msg<<std::endl;
            }

            j = 0; // reset the operation counter
        }
        j++;
    }
}

std::vector<Data> &PriorityQueue::getAllTaxis() {   // get alltaxis address
    return *this->alltaxis;
}

void PriorityQueue::printDistanceUpdates() {    // print distance update information and number of taxi addition
    std::cout<<std::endl;
    for(int i = 0; i < this->data->size(); i++){
        if((*this->data)[i].getUpdated()){ // if our data is updated
            std::cout<<(*this->data)[i].getName()<<
                     "'s Distance Updated: [ FROM: "<<(*this->data)[i].getFirstDistance()
                     <<" --> To: "<<(*this->data)[i].getData()<<" ]"<<std::endl;
        }
    }
    std::cout<<std::endl<<"The Number Of Taxi Additons: "<<this->numberOfTaxiAdditions<<std::endl;
}

PriorityQueue::~PriorityQueue() { // delete the arrays
    delete this->data;
    delete this->alltaxis;
}
