//
// Created by ahmed on 20/02/23.
//

#ifndef UNTITLED_RABINKARP_H
#define UNTITLED_RABINKARP_H


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 1e6+10, mod = 1e9+7,  base = 31;


/* * * Apps of hashing
Comparing two strings in O(1) time complexity
Rabin-Karp algorithm for pattern matching in a string can be done in O(N)
Calculating the number of different substrings of a string in O(N^2 * log N)
Calculating the number of palindromic substrings in a string
*/




// returns hash value of string str

int pw[N], inv[N];

int add( int a , int b)
{
    return (0LL + a + mod + b) %mod;
}

int mul ( int a , int b)
{
    return 1LL * a * b %mod;
}

int fastpow( int b , int p)
{
    if(!p)
        return 1;
    int temp = fastpow(b , p >> 1);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}
// pre() is called once before all test cases

void pre()
{
    pw[0] = 1, inv[0] = 1;
    for ( int i = 1 ; i < N ; i++)
    {
        pw[i] = mul(base,pw[i-1]);
        inv[i] = fastpow(pw[i],mod-2);
    }
}
// pre-calculating hash values for all substrings
int pref[N];
void generateHash(string &str)
{
    for ( int i = 0 ; i < str.size() ; i++)
    {
        int idx = str[i] - 'a' + 1;
        pref[i] = mul(idx , pw[i]);
        if(i)
            pref[i] = add(pref[i],pref[i-1]);
    }
}

int getHash(string &str)
{
    int hashValue = 0;
    for ( int i = 0 ; i < str.size() ; i++)
    {
        int idx = str[i] - 'a' + 1;
        hashValue = add(hashValue,mul(idx , pw[i]));
    }
    return hashValue;
}


int getHash( int l , int r)
{
    int ret = pref[r];
    if(l)
        ret = add(ret , - pref[l-1]);
    ret = mul(ret, inv[l]);
    return ret;
}

void testCase() {
    string st1 , pat;
    cin >> st1 >> pat;
    generateHash(st1);
    int hash = getHash(pat);
    vector < int > ans;
    for ( int i = 0 ; i < st1.size();i++)
    {
        if( i + pat.size() - 1 >= st1.size())
            continue;
        if(getHash(i,i+pat.size()-1) == hash)
            ans.push_back(i);
    }
    if(ans.empty())
        cout << "Not Found\n";
    else
    {
        cout << ans.size() << '\n';
        for(auto i : ans)
            cout << i+1 << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    pre();
    Tsetso
    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();
}

#endif //UNTITLED_RABINKARP_H
