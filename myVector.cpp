#include "myVector.hpp"
void vectorMedian (const std::vector<int> * instructions){
    std::vector<int> myVec;
    std::vector<int> res;
    std::vector<int>::iterator vecIt;
    std::vector<int>::iterator lowerBound;
    bool inserted;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        inserted = false;
        if(*it != -1){
            if(myVec.empty()){
                myVec.push_back(*it);
            }else{
                lowerBound = std::lower_bound(myVec.begin(),myVec.end(), *it);
                if(lowerBound == myVec.end()){
                    myVec.push_back(*it);
                }else{
                    myVec.insert(lowerBound,*it);
                }
            }
        }else{
            vecIt = myVec.begin();
            std::advance(vecIt, ceil(myVec.size() / 2.0) - 1);
            res.push_back(*vecIt);
            myVec.erase(vecIt);
        }
    }
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }  
}   