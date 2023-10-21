//
// Created by ahmed on 28/02/23.
//

#ifndef UNTITLED_KMP_H
#define UNTITLED_KMP_H
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

/* * ref
 * 1) cp algo:  https://cp-algorithms.com/string/prefix-function.html#search-for-a-substring-in-a-string-the-knuth-morris-pratt-algorithm
 * 2) mostafa saad
 * */


// O(n)
vector < int > kmp(string str)
{
    vector < int > fail(str.size(),0);
    for ( int i = 1; i < str.size(); i++)
    {
        int j = fail[i-1];

        while (j > 0 and str[i] != str[j])
            j = fail[j-1];

        if(str[i] == str[j])
            j++;
        fail[i] = j;
    }
    return fail;
}

// ----------------------------------------------- Apps -----------------------------------------------

// 0) Search for a substring (s) in a string (t)
/* * ans:
 *      => O(n)
 *      0) Construct str = s +'@'+ t   note that the '@' is a separator that appears neither in s nor in t
 *      Let us calculate the prefix function for this string. Now think about the meaning of the values of the prefix function,
 *      except for the first (n+1) entries (which belong to the string s  and the separator). By definition the value f[i]
 *      shows the longest length of a substring ending in position i that coincides with the prefix. But in our case this is
 *      nothing more than the largest block that coincides with s and ends at position i. This length cannot be bigger than n
 *      due to the separator. But if equality f[i]=n  is achieved, then it means that the string s
 *      appears completely in at this position, i.e. it ends at position i.
 *      Just do not forget that the positions are indexed in the string  s +'@'+ t
 *
 *      ==> Thus if at some position i we have f[i]==n hen at the position { i-(n+1)-(n-1) } which = (i-2*n) in the string t the string s appears.
 * */
void solve( )
{
    string str, pat; cin >> str >> pat;
    vi f = kmp(pat+'@'+str);
    int n = pat.size();
    vi ans;
    for (int i = 0; i < f.size(); ++i) {
        if(f[i]==n){ans.push_back(i-(n+1)-(n-1));}
    }
    if(ans.empty()){cout << "Not Found" << el;}
    else {
        cout << ans.size() << el;
        print(ans);
    }
    cout << el;
}




// 1) Problem: Given a string, What is the longest suffix of this string that is palindrome?
/* * ans:
*   => O(n)
*   1) Make a copy of str and reverse it lets say it is str2
*       str : abcdeffe => effe	in suffix problem
*       str2: effedcba => effe	in prefix problem
*   2) Now the problem is : find the longest suffix of str that is a prefix of str2
*   3) Let’s assume char @ will not be part of input..let’s construct:   effedcba@abcdeffe
*   4) Now problem, find longest prefix of the new string that is a suffix of it
*   5) Failure function can answer that easily: F[size-1] is answer
*/






// 2) Repetition. Problem:  Given a string, find the length of the smallest prefix that if we repeat it multiple tims
//                          we get the original string.

/* * ans:
 *  => O(n)
 *  1) If string is 10 times concatenated, The first 9 blocks = last 9 blocks  => here "abcdabcd" = "abcdabcd"
 *  2) So we can get the block easily =>	 Len – F[Len-1] = 12 – 8 = 4
 *  3) Observation: if(Len % (Len – F[Len-1] ) = 0){we have ans that =  Len – F[Len-1]}
 *                  else {the ans is the whole string that is 1}
 * */







// 3) Counting the number of occurrences of each prefix:  {مش فاهمها}  => O(n)
// black box from cp algo:
vector<int> prefixFreq(const string& str)
{
    // => O(n)
    int n = (int)str.size();
    vector<int> pi=kmp(str);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n - 1; i > 0; i--)
        ans[pi[i - 1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}






// 4) Count number of unique prefixes
/* * ans:
 *      => O(n)
 *      Count the number of occurrences of each prefix using prefixFreq() function and if freq[i]==1 it is unique
 * */






// 5) Count number of distinct substring  => O(n^2)
/* * ans:
 *       => O(n^2)
 *       1) Think Incrementally: If we know the answer for the first N letters…Could we know for the N+1?
 *       2) When we add the N+1 character, we have N+1 suffix. We need only the unique suffixes of them.
 *       3) For each prefix P  { Count += CountUniquePrefixes( reverse(P) ) }			=> O(n^2)
 * */




/* * * Key words:
    substring, prefix, suffix, string equalities
    Typically processing for the Pattern, similar to Input S
    Try to find solution in: S, SS, rev(S), S@S, and so on
 */




#endif //UNTITLED_KMP_H
