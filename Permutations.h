//
// Created by Kalash on ٣٠/٠٦/٢٠٢٢.
//
/*
 * https://leetcode.com/problems/permutations/
 */
#ifndef UNTITLED_PERMUTATIONS_H
#define UNTITLED_PERMUTATIONS_H

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
void swap(vector<T>& arr,int firstIndex, int secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}



vector<vector<int>> permuteRes;
vector<int> path;

// with a container to track the visited items
unordered_set<int> visited;
void  permuteRec(const vector<int>& nums)
{
    // may be redundant base case, the loop recursive will be ended without it , but we need it to collect the possible solutions.
    if (path.size()==nums.size())
    {
        permuteRes.push_back(path);  // we need it to collect the possible solutions.
        return; // redundant
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if(visited.find(nums.at(i))==visited.end())
        {
            visited.insert(nums.at(i)); // do1
            path.push_back(nums.at(i));  // do2

            permuteRec( nums); // recursive case

            visited.erase(nums.at(i));  // un-do1
            path.pop_back();                 // un-do2


        }
    }
}

// ---------------------------------------------------------------
// 2-pointers - without a container to track the visited items
void  permuteRec( vector<int>& nums, int l=0)
{
    // may be redundant base case, the loop recursive will be ended without it , but we need it to collect the possible solutions.
    if (path.size()==nums.size()) // or l == nums.size()
    {
        permuteRes.push_back(path);  // we need it to collect the possible solutions.
        return; // redundant
    }

    for (int i = l; i < nums.size(); ++i)
    {

        path.push_back(nums.at(i));  // do2
        swap(nums,i,l); //  do3

        permuteRec(nums,l+1); // recursive case

        path.pop_back();                 // un-do2
        swap(nums,i,l); //  un-do3



    }
}



vector<vector<int>> permute(vector<int>& nums)
{
    permuteRec(nums);
    return permuteRes;

}















#endif //UNTITLED_PERMUTATIONS_H
