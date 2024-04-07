#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <chrono>
void heapMedian (const std::vector<int> * instructions);
void balanceHeaps(std::priority_queue<int>& large,std::priority_queue<int, std::vector<int>, std::greater<int>>& small, int val);