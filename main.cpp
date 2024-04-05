#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include "myVector.hpp"
#include "myList.hpp"
int main (){
    std::ifstream file("textinput.txt");
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
    // listMedian(data);
    vectorMedian(data);
    return 0;
}