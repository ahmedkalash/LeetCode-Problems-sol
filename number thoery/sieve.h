//
// Created by ahmed on 01/01/23.
//

#ifndef UNTITLED_SIEVE_H
#define UNTITLED_SIEVE_H

#include <bits/stdc++.h>
#include "strstream"
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pci pair<char, int>
#define pcl pair<char, long long>
#define psi pair<string, int>
#define psl pair<string, long long>
#define el  endl
#define ull unsigned long long
#define ll long long



// ---------------------------------------------------------------
void sieve(ll n, vector<ll>& ans)
{
    // O(n*log(log(n)))
    vector<bool> prims(n + 10, 1);
    prims[0] = prims[1] = 0;
    for (ll i = 2;  i <=n ; ++i) {
        if(prims[i]){
            ans.push_back(i);
            for(ll nonPrime = i*i; nonPrime <= n; nonPrime += i){ prims[nonPrime]=0;}
        }
    }
}
void sieve(ll n, unordered_set<ll>& ans)
{
    // O(n*log(log(n)))
    vector<bool> prims(n + 10, 1);
    prims[0]=0;prims[1]=0;
    for (ll i = 2; i <=n ; ++i) {
        if(prims[i]){
            ans.insert(i);
            for(ll nonPrime = i*i; nonPrime <= n; nonPrime += i){ prims[nonPrime]=0;}
        }
    }
}
// ---------------------------------------------------------------




#endif //UNTITLED_SIEVE_H
