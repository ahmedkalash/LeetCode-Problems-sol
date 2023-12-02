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
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * */




class Solution {
    /* * *
        * Approach:
        *   * Simple two pointers, move the left ptr to right if you want to increase the result
        *   * or to the right ptr to the left if you want to decrease the ans.
        *
        * ------------------------------------------------------------------------------------------------
        * Time analysis:
        *      * O(n) where n is the length of input array.
        *
        * Space analysis:
        *      * O(1).
        *
        * * */
public:



    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r =numbers.size()-1;
        vector<int> ans(2);
        while (l<r){
            if(numbers[l]+numbers[r] == target){
                ans[0]=  l+1;
                ans[1]=  r+1;
                break;
            }else if(numbers[l]+numbers[r] < target){
                l++;
            }else{
                r--;
            }

        }
        return ans;

    }

};