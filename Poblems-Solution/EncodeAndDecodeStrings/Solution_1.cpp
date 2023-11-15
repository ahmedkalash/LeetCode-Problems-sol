//
// Created by ahmedkalash on 12/11/23.
//
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

#define voyager ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);



/**
 * Medium
 * Link: https://www.lintcode.com/problem/659/
 * */




class Solution {
    /* * *
        * Approach:
        *   * All we need what is the start and the end of each string
        *   * Prefix each string with its length and a delimiter
        *
        * ------------------------------------------------------------------------------------------------
        * Time analysis:
        *      * O(n) where n is the total number of characters in all strings.
        *
        * Space analysis:
        *      * O(n) where n is the total number of characters in all strings.
        *
        * * */
public:

    ll stringToInt(const string& strNum)
    {
        ll num=0, n=0;
        for (ll i = (ll)strNum.size()-1; i >=0 ; i--,n++){
            num += (strNum[i]-'0') * (ll)pow(10,n);
        }
        return num;
    }
    string intToString(ll num)
    {
        strstream s; s << num;
        string str ; s >> str;
        return str;
    }


    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string hash;
        for (const auto& str: strs) {
            hash += intToString(str.size()) + '.' +str;
        }
        return hash;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> strs;
        for (int i = 0; i < str.size(); ) {
            string len_str;
            while ( str[i]!='.'){
                len_str+=str[i];
                i++;
            }
            int len_int = stringToInt(len_str);

            string item = str.substr(++i, len_int);
            strs.push_back(item);
            i+= len_int ;

        }

        return strs;
    }
};