//
// Created by ahmed on 01/01/23.
//

#ifndef UNTITLED_FACTORIZATION_H
#define UNTITLED_FACTORIZATION_H
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



template<typename T>
void getFactors(T n, vector<T>& ans, bool sorted=false)
{
    // O(sqrt(n))
    if(!sorted) {
        for (T i = 1; i * i <= n; ++i) {
            if ((n%i)==0) {
                ans.push_back(i);
                if (i * i != n) { ans.push_back(n / i); }
            }
        }
    }
    else{
        vector<T> secondHalf;
        for (T i = 1; i * i <= n; ++i) {
            if (!(n % i)) {
                ans.push_back(i);
                if (i * i != n) { secondHalf.push_back(n / i); }
            }
        }
        for(auto it=secondHalf.rbegin(); it<secondHalf.rend(); it++){ ans.push_back(*it); }
    }
}
void getPrimeFactors (ll n, vector<pair<ll,int>>& ans)
{
    // O(sqrt(n))
    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;}
        if(power){ans.emplace_back(i,power);}
    } // if n is not prime, it will become one, else it will remain n
    if(n>1){ ans.emplace_back(n,1); } // if n is prime
}
void getPrimeFactors (ll n, map<ll,int>& ans)
{
    // O(sqrt(n))
    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;}
        if(power){ans.insert({i, power});}
    }
    if(n!=1){ans.insert({n, 1});}
}
void getPrimeFactors (ll n, unordered_map<ll,int>& ans)
{
    // O(sqrt(n))
    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;} // <=O(64)
        if(power){ans.insert({i, power});}
    }
    if(n!=1){ans.insert({n, 1});}
}
void getPrimeFactors (ll n, vector<ll>& ans)
{
    // O(sqrt(n))
    for (ll i = 2; i*i<=n ; ++i) {
        while (n%i==0){ ans.emplace_back(i); n/=i;} // <=O(64)
    }
    if(n!=1){ans.emplace_back(n);}
}
void getPrimeFactors2(ll n, vector<pair<ll,int>>& ans)
{
    // O(sqrt(n))
    ll prevFactor=1;
    while (n>1)
    {
        // get fist factor. the fist factor of any number is always a prime number.
        ll firstFactor = -1;
        for (ll i = prevFactor + 1; i * i <= n; ++i) { if ((n % i) == 0) { firstFactor = i; break; }}
        if (firstFactor == -1) { firstFactor = n; } // if the n is prime
        // get the power of the first factor
        int power = 0;
        while ((n % firstFactor)==0) {power++;  n/=firstFactor;}
        ans.emplace_back(firstFactor, power);
        prevFactor = firstFactor;
    }
}

void getPrimeFactorsNumberSieve(ll n, vector<ll>& composite)
{
    // O(n*log(log(n)))
    composite.clear();
    composite.resize(n + 10, 0); // the value represent the number of destincit factors. if it = 0, then the number is prime
    composite[0]=0;composite[1]=0;
    for (ll i = 2; i<=n ; ++i) {
        if(!composite[i]){
            for(ll nonPrime= i * 2; nonPrime <= n; nonPrime+=i){ composite[nonPrime]++;}
        }
    }

}




#endif //UNTITLED_FACTORIZATION_H
