#include "myVector.hpp"
void vectorMedian (const std::vector<int> * instructions){
    std::vector<int> myVec;
    std::vector<int> res;
    std::vector<int>::iterator vecIt;
    bool inserted;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it != -1){
            if(myVec.empty()){
                myVec.push_back(*it);
            }else{
                for(vecIt = myVec.begin(); vecIt != myVec.end(); ++vecIt){
                    if(*vecIt >= *it){
                        myVec.insert(vecIt, *it);
                        inserted = true;
                        break;
                    }
                }
                if(!inserted){
                    myVec.push_back(*it);
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