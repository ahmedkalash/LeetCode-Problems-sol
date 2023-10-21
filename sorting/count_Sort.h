//
// Created by ahmed on 01/01/23.
//

#ifndef UNTITLED_COUNT_SORT_H
#define UNTITLED_COUNT_SORT_H

#include <bits/stdc++.h>
#include "strstream"
using namespace std;


// ---------------------------------------------------------------
void countSort(vector<int>& nums)
{
    int mx= *(std::max_element(nums.begin(), nums.end()));
    int mn= *std::min_element(nums.begin(), nums.end());
    int shift = abs(min(mn,0));
    vector<int> freqArr(mx+shift+1,0);
    for (auto i:nums) { freqArr[i+shift]++;}
    for (int i = 0, j=0; i < freqArr.size(); ++i) {
        while (freqArr[i]--){nums[j++]=i-shift;}
    }
}
// ---------------------------------------------------------------
void countSortDigits(vector<int>& nums, int place)
{
    vector<queue<int>> freq(10);
    for (const int & i:nums) { freq[(i/place)%10].push(i);}

    for (int freqIndex = 0, numsIndex=0; freqIndex < 10; ++freqIndex) {
        while (!freq[freqIndex].empty()){
            nums[numsIndex++]=freq[freqIndex].front();
            freq[freqIndex].pop();
        }
    }
}
void radixSort(vector<int>& nums)
{
    int mx= *(max_element(nums.begin(), nums.end()));
    int mxLength=0;
    while(mx){mxLength++;mx/=10;}

    for (int i=1, place=1; i<=mxLength; ++i, place*=10 ) {countSortDigits(nums, place);}
}






#endif //UNTITLED_COUNT_SORT_H
