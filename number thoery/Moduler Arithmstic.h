//
// Created by ahmed on 18/02/23.
//

#ifndef UNTITLED_MODULER_ARITHMSTIC_H
#define UNTITLED_MODULER_ARITHMSTIC_H
#include <bits/stdc++.h>
#include "strstream"
using namespace std;

#define vc vector
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

#define pn cout << "no" << endl
#define Pn cout << "No" << endl
#define PN cout << "NO" << endl
#define py cout << "yes" << endl
#define Py cout << "Yes" << endl
#define PY cout << "YES" << endl
#define fi first
#define se second


// // // // facts

// |a%n| has n values: 0, 1, ...n-1

// If a%n == b%n then (a-b)%n = 0
// largest n such that a%n = b%n is n = b-a

// (n ^ x) % n = 0

// x % (a+b) != x % a + x %b
// sum
// ((-a%n)+(a%n))%n = 0

// (a+b) % n = (a%n + b%n) % n
// (a+b+c+d)%n   == ((((a%n+(b%n))%n+c%n)%n+d%n)%n   @write a code

//--------------
// sub
// -a%m == -(a%m)
// -a%m = (-a%m)+m   ||   m-(a%m)  || (-a+m)%m

//--------------
// power
// (a^b) % n = ((a%n)^b) % n
// (a^b) % n = (a*a*a*a*a(b times)) % n = (((a%n * a%n)%n * a%n)%n * a%n)%n * ......

// --------------

// some implementation

// ---------------------------------------------------------------
ll bigModRec(const ll& b , ll p , const ll& m)
{
    if(p==1){ return b % m; }
    if(p%2==0)
    {
        ll half = bigModRec(b, p / 2, m);
        return (((half%m)*(half%m)) % m) ;
    }
    else{return ( (b%m) * (bigModRec(b, (p - 1), m)%m) ) % m;}
}


// ---------------------------------------------------------------
ll modInverseFermat(ll a, ll m)
{
    if(gcd(a,m)!=1){return -1;}
    return bigModRec(a,m-2,m);
}

#endif //UNTITLED_MODULER_ARITHMSTIC_H
