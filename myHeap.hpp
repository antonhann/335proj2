#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <chrono>
void heapMedian (const std::vector<int> * instructions);
void insertHeapMedian(std::priority_queue<int, std::vector<int>, std::less<int>> & small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int val);