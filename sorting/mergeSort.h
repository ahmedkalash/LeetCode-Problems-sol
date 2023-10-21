//
// Created by ahmed on 16/09/22.
//
#include <bits/stdc++.h>
#include "strstream"
using namespace std;

#define ull unsigned long long
#define ll long long
#ifndef UNTITLED_MERGESORT_H
#define UNTITLED_MERGESORT_H



// for int
void mergee (vector<int>& arr, int left, int mid, int right, vector<int>& tempArr)
{
    // mid is included in the left subArray, and the right subArray starts from mid+1;
    int l_idx = left, r_idx = mid+1, tempArr_idx=left;

    // merging to sorted parts in one sorted part that is tempList.
    while(l_idx<=mid && r_idx <= right){
        if( arr[l_idx] <= arr[r_idx]) { tempArr[tempArr_idx++]=arr[l_idx++]; }
        else {  tempArr[tempArr_idx++]=arr[r_idx++];
        }
    }

    // pushing the remaining items in each of the two parts if any.
    while (l_idx <= mid ) { tempArr[tempArr_idx++]=arr[l_idx++]; }
    while (r_idx <= right){ tempArr[tempArr_idx++]=arr[r_idx++]; }

    // putting them pack in their original place
    for (int i = left, j=left; i <= right ; ++i, ++j) { arr[i]=tempArr[j]; }

}
void mergeSort(vector<int>& arr, int left, int right, vector<int>& tempArr)
{

    if(left >= right){ return;}

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid,tempArr );
    mergeSort(arr, mid+1, right, tempArr);

    mergee(arr, left, mid, right, tempArr);

}
void mergeSort(vector<int>& arr, int left, int right )
{
    vector<int> tempArr (arr.size());
    mergeSort(arr, left, right, tempArr);
}


//===============================================================================================

// overloaded version === with comp ===
template<typename itemType, typename comparator>
void mergee (vector<itemType>& arr, int left, int mid, int right, vector<itemType>& tempArr, comparator comp)
{
    // mid is included in the left subArray, and the right subArray starts from mid+1;
    int l_idx = left, r_idx = mid+1, tempArr_idx=left;

    // merging to sorted parts in one sorted part that is tempList.
    while(l_idx<=mid && r_idx <= right){
        if(comp(arr[l_idx], arr[r_idx])) { tempArr[tempArr_idx++] = arr[l_idx++]; }
        else { tempArr[tempArr_idx++] = arr[r_idx++];}
    }

    // pushing the remaining items in each of the two parts if any.
    while (l_idx <= mid ) { tempArr[tempArr_idx++]=arr[l_idx++]; }
    while (r_idx <= right){ tempArr[tempArr_idx++]=arr[r_idx++]; }

    // putting them pack in their original place
    for (int i = left, j=left; i <= right ; ++i, ++j) { arr[i]=tempArr[j]; }

}
template<typename itemType, typename comparator>
void mergeSortAux(vector<itemType>& arr, int left, int right, vector<itemType>& tempArr, comparator comp)
{

    if(left >= right){ return;}

    int mid = left + (right-left)/2;
    mergeSortAux(arr, left, mid, tempArr, comp);
    mergeSortAux(arr, mid+1, right, tempArr, comp);
    mergee(arr, left, mid, right, tempArr, comp);

}
template<typename itemType, typename comparator>
void mergeSort(vector<itemType>& arr, int left, int right,  comparator comp)
{
    vector<itemType> tempArr (arr.size());
    mergeSortAux(arr, left, right, tempArr, comp);
}






#endif //UNTITLED_MERGESORT_H
