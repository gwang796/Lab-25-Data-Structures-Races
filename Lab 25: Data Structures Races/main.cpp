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
const int width1 = 8;
const int width2 = 12;

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
    auto duration1 = duration_cast<microseconds>(end - start);
    
    inputFile.clear(); //clear inputFile
    inputFile.seekg(0); //move back to start of file
    
    start = high_resolution_clock::now();
    while(inputFile >> code)
    {
        lst.push_back(code);
    }
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);
    
    inputFile.clear(); //clear inputFile
    inputFile.seekg(0); //move back to start of file
    
    start = high_resolution_clock::now();
    while(inputFile >> code)
    {
        st.insert(code);
    }
    end = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end - start);
    
    cout << "Operation" << setw(width1) << "Vector" << setw(width1) << "List" << setw(width1) << "Set" << endl;
    cout << "Read" << setw(width2) << duration1.count() << setw(width1) << duration2.count() << setw(width2) << duration3.count() << endl;
    
    

    
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
