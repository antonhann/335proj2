#include "myHeap.hpp"
void insertHeapMedian(std::priority_queue<int, std::vector<int>, std::less<int>> & small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int val){
    if(small.empty()){
        small.push(val);
    }
    else if(large.empty()){
        if(val >= small.top()){
            large.push(val);
        }else{
            large.push(small.top());
            small.pop();
            small.push(val);
        }
    }else{
        if(val >= large.top()){
            large.push(val);
            if(large.size() == small.size() + 1){
                small.push(large.top());
                large.pop();
            }
        }else{
            small.push(val);
            if(small.size() == large.size() + 2){
                large.push(small.top());
                small.pop();
            }
        }
    } 
}

void heapMedian (const std::vector<int> * instructions){

    std::priority_queue<int, std::vector<int>, std::less<int>> small; //max heap to hold the smaller numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; //min heap to hold the greater numbers
    std::vector<int> res;
    const auto start = std::chrono::steady_clock::now();
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it != -1){
            insertHeapMedian(small,large,*it);
        }else{
            res.push_back(small.top());
            small.pop();
            if(large.size() == small.size() + 1){
                small.push(large.top());
                large.pop();
            }
        }
    }
    const auto end = std::chrono::steady_clock::now();
    int time = std::chrono::duration <double, std::micro> (end - start).count();
    std::cout << "Heap Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }   
}
