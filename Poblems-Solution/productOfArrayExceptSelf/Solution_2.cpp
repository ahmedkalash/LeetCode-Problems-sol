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
     *     * Build a prefix array that hold the accumulated product of the input array from the start to the end in ans[]
     *     * such that ans[i] holds the accumulated product of all items that is before index i.
     *     * start from end to the begging with suffix=1 and in the iteration i :
     *         - {suffix} represents the accumulated product of numbers starting from the index i+1 till the end,
     *         - multiply suffix with ans[i] - where ans[i] holds the accumulated product of all items that is before index i -
     *         - update {suffix} to be equal to nums[i]
     *
     *

     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * O(n) where n is the size of the array.
     *
     * Space analysis:
     *      * O(1) where the output array does not count as extra space for space complexity analysis as the problem siad.
     *
     * * */


public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans(nums.size(), 1);
        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }


        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix*= nums[i];

        }

        return ans;

    }
};