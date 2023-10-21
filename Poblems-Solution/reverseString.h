//
// Created by Kalash on ٢٥/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_REVERSESTRING_H
#define UNTITLED_REVERSESTRING_H
#include <bits/stdc++.h>
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
#define nnn  <<endl<<
#define ss   <<" "
#define sss   <<" "<

#define ull unsigned long long
#define ll long long

int charToInt(char ch)
{
    return (ch - 48);
}
char intToChar(  int digit)
{
    return (digit + 48);
}
char toLower(char upper)
{
    return upper + 32;
}

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
template <typename f,typename s>
void printPair(pair<f,s> p)
{
    cout << p.first << " " << p.second << endl;
}
template<typename T>
void swap(T arr[],int firstIndex, int secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}
template<typename T>
void swap(vector<T>& arr,int firstIndex, int secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}

// ---------------------------------------------------------------
void reverseString(vector<char>& s, int l, int r)
{
    if(l>=r)
        return;
    swap(s,l,r);
    reverseString(s,l+1,r-1);
}

#endif //UNTITLED_REVERSESTRING_H
