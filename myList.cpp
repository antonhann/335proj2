#include "myList.hpp"
void listMedian (const std::vector<int> * instructions){
    std::list<int> myList;
    std::vector<int> res; //the result vector that will contain all the medians popped in the data set
    std::list<int>::iterator listIt; //my list iterator
    bool inserted; //check if the value was inserted inside the iteration of the list
    const auto start = std::chrono::steady_clock::now(); //start of time
    for(auto it = instructions->begin(); it != instructions->end(); ++it){//iterate through the instructions

        inserted = false; //reset the inserted bool 
        if(*it != -1){ //if the value isnt -1, we insert the value to the list
            for(listIt = myList.begin(); listIt != myList.end(); ++listIt){ //iterate through the list
                if(*listIt >= *it){
                    //if the current iteration is greater than or equal to the inserted value insert it before this position
                    myList.insert(listIt, *it);
                    inserted = true;
                    break;
                }
            }
            if(!inserted){
                //if we didnt insert in the list we push back the value
                myList.push_back(*it);
            }
        }else{
            listIt = myList.begin(); //reset the iteration pointer
            std::advance(listIt, ceil(myList.size() / 2.0) - 1); //point to the median of the list
            res.push_back(*listIt); //push back to res the median of this iteration
            myList.erase(listIt); //pop median from the list
        }
    }
    const auto end = std::chrono::steady_clock::now(); //end of time
    int time = std::chrono::duration <double, std::micro> (end - start).count(); //calculate the time taken
    // std::cout << "List Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){ 
        //iterate through the result array and print the medians to the terminal
        std::cout << res[i] << " ";
    }   
}