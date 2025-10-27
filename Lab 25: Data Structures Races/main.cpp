//
//  main.cpp
//  Lab 25: Data Structures Races
//
//  Created by Guo An Wang on 10/26/25.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
const string txt = "codes.txt";

int main() {
    vector<string> vect;
    list<string> lst;
    set<string> st;
    ifstream inputFile(txt);
    string code;
    
    auto start = high_resolution_clock::now();
    while(inputFile >> code)
    {
        vect.push_back(code);
    }
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    
    inputFile.clear(); //clear inputFile
    inputFile.seekg(0); //move back to start of file
    
    start = high_resolution_clock::now();
    
    
    
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
