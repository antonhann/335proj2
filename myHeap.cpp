#include "myHeap.hpp"
void insertHeapMedian(std::priority_queue<int, std::vector<int>, std::less<int>> & small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int val){
    if(small.empty()){
        //push the value if small is empty
        small.push(val);
    }
    else{
        //to find out which heap we insert the value into, by comparing the value to the max of the small heap
        if(val >= small.top()){
            //insert into the large heap
            large.push(val);
            if(large.size() == small.size() + 1){
                //rebalance the small and large heap to keep size constraint 
                //by moving the min of the top over to the small heap and popping the large heap
                small.push(large.top());
                large.pop();
            }
        }else{
            //insert into small heap
            small.push(val);
            if(small.size() == large.size() + 2){
                //rebalance the small and large heap to keep size constraint
                //by moving the max of the small heap to the large heap and popping the small heap
                large.push(small.top());
                small.pop();
            }
        }
    } 
}

void heapMedian (const std::vector<int> * instructions){
    std::priority_queue<int, std::vector<int>, std::less<int>> small; //max heap to hold the smaller numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; //min heap to hold the greater numbers
    //size constraint is the size of the small heap has to be equal to the size of the large heap or size of large + 1
    std::vector<int> res; //result vector that will hold the medians popped
    const auto start = std::chrono::steady_clock::now(); //start of time
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        //iterate through the instructions
        if(*it != -1){
            //if the value isn't negative one, we insert it into our structure
            insertHeapMedian(small,large,*it);
        }else{
            res.push_back(small.top()); //push the median on to the result vector
            //median of this structure is the max of the small heap which is located at the top since it is a max heap
            small.pop(); //pop the median
            if(large.size() == small.size() + 1){ 
                //rebalance the structure to keep size constraint by moving the the min of large to the small and popping the large
                small.push(large.top()); 
                large.pop();
            }
        }
    }
    const auto end = std::chrono::steady_clock::now(); //end time
    int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "Heap Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){
        //print the medians to the terminal
        std::cout << res[i] << " ";
    }   
}
