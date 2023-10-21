//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_SEQUANCES_H
#define UNTITLED_SEQUANCES_H
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
// ---------------------------------------------------------------
void binarySequance(string s="",int lSum=0, int rSum=0)
{
    // in the sketch
    static int length=5;
    if(s.size() == length)
    {
        // without lsum and rsum
        //int lSum=0, rSum=0;
        /*for (int i = 0; i < (s.length()/2) ; ++i) {
            lSum += (s[i]-30);
        }
        for (int i = (s.length()/2); i <s.length() ; ++i) {
            rSum += (s[i]-30);
        }*/
        if(lSum==rSum)
            cout << s<<endl;
        return;
    }

    binarySequance(s + '0',lSum,rSum);
    if(s.size() < (length / 2))
        binarySequance(s + '1',lSum+1,rSum);
    else
        binarySequance(s + '1',lSum,rSum+1);
}
// ---------------------------------------------------------------
bool Dvisited[5];
void decimalSequence(const bool distincit= false,string s= "" )
{
    // in the sketch binarySequance
    static int length=4;
    if(s.size() == length)
    {
        cout << s<<endl;
        // ------------------
        int i=(int)s.back()-48;
        Dvisited[i]= false;
        // ------------------
        return;
    }

    for (int i = 0; i <= 9; ++i)
    {
        if(distincit)
        {
            if (!Dvisited[i])
            {

                Dvisited[i] = true;
                // ------------------
                decimalSequence(distincit, s + (char) (i + 48) );
            }
        }
        else
            decimalSequence(distincit, s + (char) (i + 48) );
    }

    int i=(int)s.back()-48;
    Dvisited[i]= false;
}
// ---------------------------------------------------------------
unordered_set<int> Avisited;
void anySequence(const string sequence , const int& length  , const bool distincit= false, string s= "")
{
    // in the sketch binarySequance
    //static int length = 2;
    if(distincit && (length > sequence.size())) {
        cout << "There no possible solution: length > sequence's size \n";
        return;
    }
    if(s.size() == length)
    {
        cout << s<<endl;
        // ------------------
        auto i = s.back();
        Avisited.erase(i);
        // ------------------
        return;
    }
    for (auto i:sequence)
    {
        if(distincit)
        {
            if (Avisited.find(i) == Avisited.end())
            {
                Avisited.insert(i);
                // ------------------
                anySequence(sequence, length, distincit, s + i);
            }
        }
        else
        {
            anySequence(sequence, length, distincit, s + i);
        }

    }

    // ------------------
    auto i = s.back();
    Avisited.erase(i);
    // ------------------
}


#endif //UNTITLED_SEQUANCES_H
