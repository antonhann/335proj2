#include "myVector.hpp"
void vectorMedian (const std::vector<int> * instructions){
    std::vector<int> myVec;
    std::vector<int> res; //result vector that will store the pop medians
    std::vector<int>::iterator vecIt; //vector iterator
    std::vector<int>::iterator lowerBound; //lowerbound iterator
    const auto start = std::chrono::steady_clock::now(); //start time
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        //iterate through the instructions
        if(*it != -1){
            //if the value doesn't equal negative one, we insert it into the sorted vector
            if(myVec.empty()){
                //if the vector is empty just push_back the value
                myVec.push_back(*it);
            }else{
                lowerBound = std::lower_bound(myVec.begin(),myVec.end(), *it);
                //lower bound is the operation to find where the value needs to be placed in the vector using binary search
                //lower bound points to the left most positon that it needs to be placed in
                if(lowerBound == myVec.end()){
                    //if the lowerbound was not found push the value to the end of the vector
                    myVec.push_back(*it);
                }else{
                    //insert the vector to the position of the lowerbound of the value in reference to the vector
                    myVec.insert(lowerBound,*it);
                }
            }
        }else{
            vecIt = myVec.begin(); //reset the iterator pointer
            std::advance(vecIt, ceil(myVec.size() / 2.0) - 1); 
            //advance ceil(size / 2) - 1, to find the median of the vector
            res.push_back(*vecIt); //push the median to result vector
            myVec.erase(vecIt); //pop the median
        }
    }
    const auto end = std::chrono::steady_clock::now(); //end time
    int time = std::chrono::duration <double, std::micro> (end - start).count(); //amount of time taken to complete instructions
    // std::cout << "Vector Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){
        //print the popped medians to the terminal
        std::cout << res[i] << " ";
    }  
}   