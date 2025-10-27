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
    int midpt = lst.size()/2;
    int counter = 0;
    for (auto it = lst.begin(); it !=lst.end(); ++it) {
        if (counter == midpt){
            lst.insert(it, "TESTCODE");
            break;
        }
        counter++;
    }
    end = high_resolution_clock::now();
    auto listinsert = duration_cast<microseconds>(end - start);
    
    start = high_resolution_clock::now();
    st.insert("TESTCODE");
    end = high_resolution_clock::now();
    auto setinsert = duration_cast<microseconds>(end - start);
    
    cout << "Insert" << setw(width2) << vectinsert.count() << setw(width1) << listinsert.count() << setw(width2) << setinsert.count() << endl;
    
    start = high_resolution_clock::now();
    vect.erase(vect.begin() + vect.size()/2);
    end = high_resolution_clock::now();
    auto vectdelete = duration_cast<microseconds>(end - start);
    
    start = high_resolution_clock::now();
    counter = 0;
    for (auto it = lst.begin(); it !=lst.end(); ++it) {
        if (counter == midpt){
            lst.erase(it);
            break;
        }
        counter++;
    }
    end = high_resolution_clock::now();
    auto listdelete = duration_cast<microseconds>(end - start);
    
    counter = 0;
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (counter == st.size()/2){
            st.erase(it);
            break;
        }
        counter++;
    }
    
    return 0;
}
