//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_NQUEENS_H
#define UNTITLED_NQUEENS_H

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
vector<vector<string>> finalAnswer;
vector<string> sol;
bool safe  (int i, int j, int n)
{
/*    for (int k = i; k <n ; ++k)
        if(sol[k][j]== 'Q')
            return false;
    for (int k = i; k >= 0 ; --k)
        if(sol[k][j]== 'Q')
            return false;

    for (int k = j; k < n; ++k)
        if(sol[i][k]== 'Q')
            return false;*/
    for (int k = j; k >=0 ; --k)  //
        if(sol[i][k]== 'Q')
            return false;
    // -----------------------------
    /*   for (int k = i, m=j; (k >=0) && (m < n); --k,++m)
           if(sol[k][m]== 'Q')
               return false;*/
    for (int k = i, m=j; (k < n) && (m >=0); ++k,--m) //
        if(sol[k][m]== 'Q')
            return false;

    for (int k = i, m=j; (k >=0) && (m >=0); --k,--m) //
        if(sol[k][m]== 'Q')
            return false;
/*    for (int k = i, m=j; (k < n) && (m < n); ++k,++m)
        if(sol[k][m]== 'Q')
            return false;*/


    return true;

}
void nQueens(const int& n , int j, int remainingQueens)
{
    if(remainingQueens==0)
    {
        finalAnswer.push_back(sol);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if(safe(i,j,n)) // isSafe(i,j,attackAble,n) // !attackAble[i][j]  // safe(i,j,sol,n)
        {
            sol[i][j]='Q';
            nQueens(n,j+1, remainingQueens-1);
            sol[i][j]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    sol=vector<string>(n,string (n,'.'));
    nQueens(n,0,n);
    return finalAnswer;
}



#endif //UNTITLED_NQUEENS_H
