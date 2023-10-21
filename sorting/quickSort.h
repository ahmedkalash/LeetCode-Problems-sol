//
// Created by ahmed on 11/11/22.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef UNTITLED_QUICKSORT_H
#define UNTITLED_QUICKSORT_H



void swapMe(int& a, int& b){ int temp = a; a=b; b=temp; }
int partitioning (vector<int>& arr,int left,  int right)
{
    int pivot = left;

    for (int i = left+1; i <= right ; ++i) {
        if(arr[i] < arr[pivot]){
            swapMe(arr[pivot+1], arr[i]);
            swapMe(arr[pivot], arr[pivot+1]);
            pivot++;
        }
    }
    return pivot;
}
void quickSort(vector<int>& arr,int left,  int right)
{
    if(left >= right){ return;}

    int pivot = partitioning(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}










#endif //UNTITLED_QUICKSORT_H
