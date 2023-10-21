//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_FASTPOWER_H
#define UNTITLED_FASTPOWER_H
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
ll fastPower(ll x, ll n)
{
    // in the sketch
    ll powerOne=1;
    while (n>1) // if we used (n>=1) then we should return 'powerOne' only cause at the last step (x * powerOne) will be done and there is no need to re-multiplying it again
    {
        // remove all the redundant statements together or leave them together
        if(n%2==1)
        {
            powerOne *= x;
            x = x * x;  // redundant
            n = (n-1) / 2;  // redundant , here (n-1)/2) is the same as (n/2) e.g. --> 7/2 is the same as 6/2 <floor div>
        }
        else {  // redundant
            x = x * x;
            n = n / 2;
        }
    }
    return  x * powerOne;
}
ll fastPowerRec(ll x, ll n)
{
    if(!n){return 1;}
    ll sqrt=fastPower(x, n>>1);
    return sqrt * sqrt * ((n&1) ? x : 1);

}


#endif //UNTITLED_FASTPOWER_H
