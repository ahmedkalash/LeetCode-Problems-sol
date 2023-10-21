//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_BIGMOD_H
#define UNTITLED_BIGMOD_H

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
unsigned long long bigModRec(const ull& b , ull p , const ull& m)
{
    if(p==1)      /* or   if(p==0) { return 1;}*/
        return b%m;
    if(p%2==0)
    {
        unsigned long long half = bigModRec(b, p / 2, m);
        return ((half*half) % m);
    }
    else
    {
        return (b % m * bigModRec(b, (p - 1), m) ) % m;
    }

}
unsigned long long bigMod( ull b  , ull p , const ull& m)
{

    ull newB=b%m;

    while (p>1)
    {
        if (p % 2 == 0) {
            newB = (newB*newB)%m;
        }
        else
        {
            newB = ((b%m) * ((newB*newB)%m))%m;
        }
        p/=2;
    }
    return newB;
}

#endif //UNTITLED_BIGMOD_H
