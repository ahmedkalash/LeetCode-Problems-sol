//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_POWERSUM_H
#define UNTITLED_POWERSUM_H
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
// the powerSum solution
void solve(int X,int N,int i,int& ctr,int sum)
{
    if(i>=32)
    {
        if(sum==X)
            ctr++;
        return ;
    }
    /*if(sum>X)  // can be used instead of   if(sum+pow(i,N) <= X)
    {
        return;
    }*/
    if(sum+pow(i,N) <= X)
        solve(X,N,i+1,ctr,sum+pow(i,N));
    solve(X,N,i+1,ctr,sum);

}
// Another approach for the fun solve.
bool Svisited[50];
void solve_withDecimalSequence(const int x, const int n, int& ctr , int sum= 0, string s= "")
{
    // in the sketch binary Sequence
    if(sum==x)
    {
        //cout << s << endl; // print out the solutions
        ctr++;
        // ------------------  // Dis-mark it so we can use it in other branches that is not created from its children.
        int i=(int)s.back()-48;
        Svisited[i]= false;
        // ------------------------------------
        return;
    }
    /* // redundant check , I did a better on in the loop below, that is ( if((sum+pow(i,n))>x) {break;} ).
        if(sum > x) {
        // ------------------
        int i = (int) s.back() - 48;
        Svisited[i] = false;
        // ------------------
        return;
    }*/

    for (int i = 1; i <= 32; ++i) // (32) can be replaced with (sqrt(x)+1)
    {
        // ------------------------------------
        // In this problem: 1234 is the same as 4321 ,4213,....etc , so to prevent count the same result many times, we use this check.
        // This check says that: "if we are in a construction of a solution and last digit in 's' is 'i', all the digits that come after 'i' should be greater than it(skip values < 'i')".
        // ex: skip 43'21 ,because we already made 1234 --> skipping will happen once we reach the digit just before the (') .
        // ex: skip 142'3 ,because we already made 1234 --> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.
        // ex: skip 143'2 ,because we already made 1234 --> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.
        // ex: do not skip 1456.
        int last_i_is_s=(int)s.back()-48;  // the i that called the current function copy
        if(i<last_i_is_s)
            continue;
        // ------------------------------------
        // to reduce the calls that are impossible to get the solution
        if((sum+ pow(i,n)) > x)
            break;
        // ------------------------------------
        if (!Svisited[i])
        {
            // mark it as used, so we do not use it again in the same path, to avoid duplicated digits in the same 's' (possible solution)
            Svisited[i] = true;
            // ------------------------------------
            solve_withDecimalSequence(x, n, ctr, sum + pow(i, n), s + (char) (i + 48));
        }
    }
    // ------------------------------------
    // Dis-mark it so we can use it in other branches that is not created from its children.
    int i=(int)s.back()-48;
    Svisited[i]= false;
}
int powerSum(int X, int N)
{
    int ctr=0;
    int i=1;
    int sum=0;
    solve(X,N,i,ctr,sum);
    cout << ctr;
    cout << "\n =================================\n";
    ctr=0;
    solve_withDecimalSequence(X, N, ctr, sum);
    return ctr;

}



#endif //UNTITLED_POWERSUM_H
