//
// Created by Kalash on ٠١/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_FREQUENCYSORT_H
#define UNTITLED_FREQUENCYSORT_H
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



// on leet code
unordered_map<char,int> freqMap;
class pairCompair
{
public:
    bool operator ()(const pair<char,int> first, const pair<char,int> second) const
    {
        if(first.second < second.second)
            return true;
        return false;
    }
};
priority_queue<pair<char,int>,vector<pair<char,int>>,pairCompair> pQ;
string frequencySort(string s)
{
    string result;
    for (auto i: s)
    {
        if(freqMap.find(i) == freqMap.end())
            freqMap.insert({i,1});
        else
            freqMap[i]++;
    }
    for (auto& i: freqMap) {
        pQ.push(i);
    }
    while (!pQ.empty())
    {
        char ch = pQ.top().first;
        int freq = pQ.top().second;
        pQ.pop();

        for (int i = 1; i <= freq; ++i)
        {
            result += ch;
        }
    }
    return result;

}

#endif //UNTITLED_FREQUENCYSORT_H
