// #include "myHeap.hpp"
// void insertHeapMedian(std::priority_queue<int>& large, std::priority_queue<int, std::vector<int>, std::greater<int>>& small, int val){
//     if(small.empty()){
//         small.push(val);
//     }
//     else if(large.empty()){
//         if(val >= small.top()){
//             large.push(val);
//         }else{
//             large.push(small.top());
//             small.pop();
//             small.push(val);
//         }
//     }else{
//         std::priority_queue<int> temp(large);
//         int minTop;
//         while(!temp.empty()){
//             minTop = temp.top();
//             temp.pop();
//         }
//         if(val >= minTop){
//             large.push(val);
//             if(large.size() == small.size() + 1){
//                 std::priority_queue<int> temp(large);
//                 std::priority_queue<int, std::vector<int>, std::greater<int>> min;
//                 while(!temp.empty()){
//                     min.push(temp.top());
//                     temp.pop();
//                 }
//                 small.push(min.top());
//                 min.pop();
//                 while(!large.empty()){
//                     large.pop();
//                 }
//                 while(!min.empty()){
//                     large.push(min.top());
//                     min.pop();
//                 }
//             }
//         }else{
            
//             small.push(val);
//             if(small.size() == large.size() + 2){
//                 std::priority_queue<int, std::vector<int>, std::greater<int>> temp(small);
//                 std::priority_queue<int> max;
//                 while(!temp.empty()){
//                     max.push(temp.top());
//                     temp.pop();
//                 }
//                 large.push(max.top());
//                 max.pop();
//                 while(!small.empty()){
//                     small.pop();
//                 }
//                 while(!max.empty()){
//                     small.push(max.top());
//                     max.pop();
//                 }
//             }
//         }
//     } 
// }

// void heapMedian (const std::vector<int> * instructions){

//     std::priority_queue<int> large;
//     std::priority_queue<int, std::vector<int>, std::greater<int>> small;
//     std::vector<int> res;
//     for(auto it = instructions->begin(); it != instructions->end(); ++it){
//         if(*it != -1){
//             insertHeapMedian(large,small,*it);
//         }else{
//             int median;
//             std::priority_queue<int, std::vector<int>, std::greater<int>> temp(small);
//                 std::priority_queue<int> max;
//             while(!temp.empty()){
//                 max.push(temp.top());
//                 temp.pop();
//             }
//             median = max.top();
//             max.pop();
//             while(!small.empty()){
//                 small.pop();
//             }
//             while(!max.empty()){
//                 small.push(max.top());
//                 max.pop();
//             }
//             if(large.size() == small.size() + 1){
//                 std::priority_queue<int> temp(large);
//                 std::priority_queue<int, std::vector<int>, std::greater<int>> min;
//                 while(!temp.empty()){
//                     min.push(temp.top());
//                     temp.pop();
//                 }
//                 small.push(min.top());
//                 min.pop();
//                 while(!large.empty()){
//                     large.pop();
//                 }
//                 while(!min.empty()){
//                     large.push(min.top());
//                     min.pop();
//                 }
//             }
//             res.push_back(median);
//         }
//     }
//     // std::cout << "small" << std::endl;
//     // while (!small.empty()) {
//     //     std::cout << small.top() << std::endl;
//     //     small.pop();
//     // }
//     // std::cout << "large" << std::endl;
//     // while (!large.empty()) {
//     //     std::cout << large.top() << std::endl;
//     //     large.pop();
//     // }
//     for(int i = 0; i < res.size(); i++){
//         std::cout << res[i] << " ";
//     }   
// }
