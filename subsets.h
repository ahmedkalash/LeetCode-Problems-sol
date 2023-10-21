//
// Created by Kalash on ٣٠/٠٦/٢٠٢٢.
//
#ifndef UNTITLED_SUBSETS_H
#define UNTITLED_SUBSETS_H
#include <iostream>
#include <string>
#include "cmath"
#include "vector"
#include "unordered_set"
#include "utility"
#include "algorithm"
#include "climits"
#include "iomanip"
#include "unordered_set"
#include "set"
#include "unordered_map"
#include "list"
#include "stack"
#include "queue"

#include <sstream>
// #include "helper_funs.h"
using namespace std;
#define nn   <<endl
#define ss   <<" "<<
#define ull unsigned long long
#define ll long long
template<typename T>
void printArray(T array[], int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " "  ;
    }
    cout << endl;
}
template<typename T>
void printVector(vector<T> vect)
{
    for (const auto& i: vect) { cout << i << ","; }
    cout << endl;
}

// ---------------------------------------------------------------
vector<vector<int>> subsetsRes;
vector<int>path;
void subsetsRec(const vector<int>& nums, int curr_i)
{
    subsetsRes.push_back(path);
    unordered_set<int> visited;
    for (int i = curr_i+1; i < nums.size(); ++i)
    {
        if(visited.find(nums.at(i)) == visited.end())
        {

            visited.insert(nums.at(i));  // don't take the same path twice.}
            path.push_back(nums.at(i));  // do

            subsetsRec(nums, i);  // recursion

            path.pop_back();  // un-do

        }

    }

}
vector<vector<int>> subsets(vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    subsetsRec(nums,-1);
    return subsetsRes;
}

#endif //UNTITLED_SUBSETS_H
