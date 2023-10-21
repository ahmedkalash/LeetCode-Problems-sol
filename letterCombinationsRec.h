//
// Created by Kalash on ٢٥/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_LETTERCOMBINATIONSREC_H
#define UNTITLED_LETTERCOMBINATIONSREC_H
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
vector<string> CombinationsResult;
string str;
void letterCombinationsRec(const unordered_map<int,string>& digits_map, const string& digits, int num)
{
    if(str.size() == digits.size())
    {
        CombinationsResult.push_back(str);
        return;
    }

    for (auto i:digits_map.at(digits[num]-'0'))
    {
        str+=i;
        letterCombinationsRec(digits_map,digits,num+1);
        str.pop_back();
    }


}
vector<string> letterCombinations(string digits)
{
    if(digits.size()==0)
        return CombinationsResult;

    unordered_map<int,string> digits_map;
    digits_map.insert({
                              {2, "abc"},
                              {3, "def"},
                              {4, "ghi"},
                              {5, "jkl"},
                              {6, "mno"},
                              {7, "pqrs"},
                              {8, "tuv"},
                              {9, "wxyz"}});
    letterCombinationsRec(digits_map, digits,0);
    return CombinationsResult;
}






#endif //UNTITLED_LETTERCOMBINATIONSREC_H
