//
// Created by ahmedkalash on 21/10/23.
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
 * Link: https://leetcode.com/problems/product-of-array-except-self/description/
 * */


class Solution {
     /* * *
     * Approach:
     *     * Build a prefix array that hold the accumulated product of the input array from the start to the end
     *     * Build a suffix array that hold the accumulated product of the input array from the end to the start
     *     * when i = 0 : ans[i] =  suffix[i+1]
     *     * else when i = n-1 : ans[i] = prefix[i-1]
     *     * else ans[i] = prefix[i-1] * suffix[i+1]
     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * O(n) where n is the size of the array.
     *
     * Space analysis:
     *      * O(2*n) where n is the size of the input array.
     *
     * * */


public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = nums[0];
        for (int i = 1; i <nums.size() ; ++i) {
            prefix[i] = prefix[i-1]*nums[i];
        }

        suffix[nums.size()-1] =  nums[nums.size()-1];
        for (int i = nums.size()-2; i >=0 ; --i) {
            suffix[i] = nums[i]*suffix[i+1];
        }

        vector<int> ans(nums.size());

        for (int i = 0; i <nums.size() ; ++i) {
            if(i == 0){
                ans[i] =  suffix[i+1];
            }else if(i ==nums.size()-1){
                ans[i] = prefix[i-1] ;
            }else{
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }
        return ans;

    }
};