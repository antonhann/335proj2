#include "myList.hpp"
void listMedian (const std::vector<int> * instructions){
    std::list<int> myList;
    std::vector<int> res;
    std::list<int>::iterator listIt;
    bool inserted;
    const auto start = std::chrono::steady_clock::now();
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        inserted = false;
        if(*it != -1){
            if(myList.empty()){
                myList.push_front(*it);
            }else{
                for(listIt = myList.begin(); listIt != myList.end(); ++listIt){
                    if(*listIt >= *it){
                        myList.insert(listIt, *it);
                        inserted = true;
                        break;
                    }
                }
                if(!inserted){
                    myList.push_back(*it);
                }
            }
        }else{
            listIt = myList.begin();
            std::advance(listIt, ceil(myList.size() / 2.0) - 1);
            res.push_back(*listIt);
            myList.erase(listIt);
        }
    }
    const auto end = std::chrono::steady_clock::now();
    int time = std::chrono::duration <double, std::micro> (end - start).count();
    // std::cout << "List Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }   
}