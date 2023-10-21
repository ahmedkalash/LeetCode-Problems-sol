//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_CLIMBSTAIRS_H
#define UNTITLED_CLIMBSTAIRS_H

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
int ctrArr[46];
int climbStairsRec(const int& n, int currStep  )
{
    if(currStep == n)
        return ctrArr[n] = 1;

    if(currStep > n)
        return 0;

    if(!ctrArr[currStep])
        ctrArr[currStep] = (climbStairsRec(n,currStep+1 ) + climbStairsRec(n,currStep+2));
    return  ctrArr[currStep];

}
int climbStairs(int n)
{
    return climbStairsRec(n,0);
}



#endif //UNTITLED_CLIMBSTAIRS_H
