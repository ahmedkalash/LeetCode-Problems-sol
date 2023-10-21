//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_NCM_H
#define UNTITLED_NCM_H
#include <bits/stdc++.h>

using namespace std;
#define nn   <<endl
#define ss   <<" "<<
#define ull unsigned long long
#define ll long long


long long allValues[101][101];// filed with 0s
void fill_nCrArr()
{

    // base case
    allValues[1][0]=1;
    allValues[1][1]=1;

    for (int n = 2; n < 101 ; ++n)
    {
        // C(N,0) = 1 always
        allValues[n][0] = 1;
        for (int m = 1; m <= n; ++m)
        {
            // C(n,m) = C(n-1,m)+C(n-1,m-1)
            allValues[n][m] = allValues[n - 1][m] + allValues[n - 1][m - 1];
        }
    }
}
// ---------------------------------------------------------------


vector<vector<ll>>nCrArr(101,vector<ll>(101,0));
void fill_nCrArr(ll n, ll r)
{
    if(n<0 || r < 0){ return;}
    if(nCrArr[n][r]){ return;}
    if(n==r){ nCrArr[n][r]=1; return;}
    if(n<r) { return;}
    if(r==1){ nCrArr[n][1] = n; return;}
    if(r==0){ nCrArr[n][0] = 1; return;}

    fill_nCrArr(n-1,r);
    fill_nCrArr(n-1,r-1);
    nCrArr[n][r]=nCrArr[n-1][r] + nCrArr[n-1][r-1];
}


// ---------------------------------------------------------------
long long nCr(int n, int r) {
    // idea= The product of any (k) consecutive integers is divisible by (k!)
    // (a*b*c)/(d*e*f) = ( (((a/d)*b)/e)*c)/f )
    r = min(r, n-r);
    ll ans=1;

    for (int i = 1, j=r+1; i <=(n-r); ++i, j++) {ans = (ans*j)/i;}
    return ans;
}


#endif //UNTITLED_NCM_H
