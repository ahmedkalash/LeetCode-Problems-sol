//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_BINARYWATCH_H
#define UNTITLED_BINARYWATCH_H
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

unordered_set<string> taken;
vector<string> binaryWatchRes;
int h[4]  = {8,4,2,1};
int m[6] = {32,16,8,4,2,1};
bool hVisited [10];
bool mVisited[35];

void readBinaryWatchRec(int H, int M, int H_i, int M_i,char type, int n)
{
    if(n==0&& H==0 && M==0)
    {
        binaryWatchRes.emplace_back("0:00");
        return;
    }
    if((H>11) || (M>59))
        return;

    if(n==0)
    {
        if(M==0 && H ==0) return;

        string hours = to_string(H);

        ostringstream sss;
        sss << setw(2) << setfill('0') << to_string(M);
        string mints = sss.str() ;

        if(taken.find(hours + ':' + mints) == taken.end())
        {
            binaryWatchRes.push_back((hours + ':' + mints));
            taken.insert((hours + ':' + mints));
        }
        else
            cout << "////////////";
        return;
    }


    if(type != 'm')
    {
        for (int i = H_i; i < 4; ++i)
            //for (auto i:h)
        {
            if (!hVisited[h[i]])
            {
                hVisited[h[i]] = true;   // do
                readBinaryWatchRec(H + h[i], M, i, M_i, 'h', n - 1);
                hVisited[h[i]] = false;  // un-do
            }
        }
    }
    for (int i = M_i; i < 6; ++i)
        //for (auto i:m)
    {
        if(!mVisited[m[i]])
        {
            mVisited[m[i]] = true;    // do
            readBinaryWatchRec(H, M+m[i], H_i, i, 'm',n-1);
            mVisited[m[i]] = false;   // un-do
        }

    }


}
vector<string> readBinaryWatch(int turnedOn)
{

    readBinaryWatchRec(0,0,0,0,'h',turnedOn);

    return binaryWatchRes;
}








#endif //UNTITLED_BINARYWATCH_H
