//
// Created by ahmed on 20/02/23.
//

#ifndef UNTITLED_RABINKARPDOUBLEHASH_H
#define UNTITLED_RABINKARPDOUBLEHASH_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 1e6+10, mod = 1e9+7, inf = 2e9, sqr = 640, base = 31, base2 = 37;

// returns hash value of string str
int pw[N], inv[N];
int pw2[N] , inv2[N];
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
    pw2[0] = 1, inv2[0] = 1;
    for ( int i = 1 ; i < N ; i++)
    {
        pw[i] = mul(base,pw[i-1]);
        inv[i] = fastpow(pw[i],mod-2);
        pw2[i] = mul(base2,pw2[i-1]);
        inv2[i] = fastpow(pw2[i],mod-2);
    }
}
// pre-calculating hash values for all substrings
int pref[N], pref2[N];
void generateHash( string &str)
{
    for ( int i = 0 ; i < str.size() ; i++)
    {
        int idx = str[i] - 'a' + 1;
        pref[i] = mul(idx , pw[i]);
        if(i)
            pref[i] = add(pref[i],pref[i-1]);
        pref2[i] = mul(idx , pw2[i]);
        if(i)
            pref2[i] = add(pref2[i],pref2[i-1]);
    }
}
pair < int , int > getHash( string &str)
{
    int hashValue = 0, hashValue2=0;
    for ( int i = 0 ; i < str.size() ; i++)
    {
        int idx = str[i] - 'a' + 1;
        hashValue = add(hashValue,mul(idx , pw[i]));
        hashValue2 = add(hashValue2,mul(idx , pw2[i]));
    }
    return {hashValue,hashValue2};
}
pair < int , int >  getHash( int l , int r)
{
    int ret = pref[r];
    if(l)
        ret = add(ret , - pref[l-1]);
    ret = mul(ret, inv[l]);

    int ret2 = pref2[r];
    if(l)
        ret2 = add(ret2 , - pref2[l-1]);
    ret2 = mul(ret2, inv2[l]);
    return {ret,ret2};
}


void testCase() {
    int n , k;
    cin >> n >> k;
    string str;
    cin >> str;
    generateHash(str);
    set < pair < int, int > > st;
    for ( int i = 0 ; i < n ; i++)
    {
        if(i + k - 1 >= n)
            break;
        st.insert(getHash(i,i+k-1));
    }
    cout << st.size() << '\n';
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




#endif //UNTITLED_RABINKARPDOUBLEHASH_H
