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
    auto vectorread = duration_cast<microseconds>(end - start);
    
    inputFile.clear(); //clear inputFile
    inputFile.seekg(0); //move back to start of file
    
    start = high_resolution_clock::now();
    while(inputFile >> code)
    {
        lst.push_back(code);
    }
    end = high_resolution_clock::now();
    auto listread = duration_cast<microseconds>(end - start);
    
    inputFile.clear(); //clear inputFile
    inputFile.seekg(0); //move back to start of file
    
    start = high_resolution_clock::now();
    while(inputFile >> code)
    {
        st.insert(code);
    }
    end = high_resolution_clock::now();
    auto setread = duration_cast<microseconds>(end - start);
    
    cout << "Operation" << setw(width1) << "Vector" << setw(width1) << "List" << setw(width1) << "Set" << endl;
    cout << "Read" << setw(width2) << vectorread.count() << setw(width1) << listread.count() << setw(width2) << setread.count() << endl;
    
    start = high_resolution_clock::now();
    sort(vect.rbegin(), vect.rend());
    end = high_resolution_clock::now();
    auto vectsort = duration_cast<microseconds>(end - start);
    
    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    auto listsort = duration_cast<microseconds>(end - start);
    
    int setsort = -1;
    
    cout << "Sort" << setw(width2) << vectsort.count() << setw(width1) << listsort.count() << setw(width2) << setsort << endl;
    
    start = high_resolution_clock::now();
    vect.insert(vect.begin() + vect.size()/2, "TESTCODE");
    end = high_resolution_clock::now();
    auto vectinsert = duration_cast<microseconds>(end - start);
    
    start = high_resolution_clock::now();
    
    end = high_resolution_clock::now();
    auto listinsert = duration_cast<microseconds>(end - start);
    
    start = high_resolution_clock::now();
    vect.insert(vect.begin() + vect.size()/2, "TESTCODE");
    end = high_resolution_clock::now();
    auto setinsert = duration_cast<microseconds>(end - start);
    
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
