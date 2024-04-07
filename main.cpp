#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"
int main (){
    std::vector<std::string> fileNames = {"input1.txt","input2.txt","input3.txt"};
    // std::vector<std::string> fileNames = {"textinput.txt"};
    for(int i = 0; i < fileNames.size(); i++){
        std::ifstream file(fileNames[i]);
        std::cout << "Testing File: "  << fileNames[i] << std::endl;
        if (file.fail()) {
            std::cerr << "File cannot be opened for reading." << std::endl;
            exit(1); // exit if failed to open the file
        }
        std::string input;
        std::string operation;
        std::vector<int> *data = new std::vector<int>({});
        while(file >> operation >> input){
            if(operation == "insert"){
                data->push_back(stoi(input));
            }else{
                data->push_back(-1);
            }
        }
        listMedian(data);
        vectorMedian(data);
        heapMedian(data);
        treeMedian(data);
        std::cout << std::endl;
    }
    return 0;
}