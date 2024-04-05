#include "myHeap.hpp"
void heapMedian (const std::vector<int> * instructions){

    std::priority_queue<int> large;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it != -1){

        }else{

        }
    }
}

void insertHeapMedian(std::priority_queue<int>& large, std::priority_queue<int, std::vector<int>, std::greater<int>>& small, int val){
    
}
