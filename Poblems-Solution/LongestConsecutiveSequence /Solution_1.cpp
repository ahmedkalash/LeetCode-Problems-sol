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
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
 * */




class Solution{
    /* * *
        * Approach:
        *     * Sort the array
        *     * Then the sorted array will contain a segments of the consecutive numbers, and they determine the end of each
        *       segment use this condition if(i == nums.size()-1  || nums[i]+1 != nums[i+1]).
        *     * Now loop through the sorted array and count number of elements in each segment and chose the maximum number
        *       and don't forget to count the repeated number only one.
        *
        * ------------------------------------------------------------------------------------------------
        * Time analysis:
        *      * O(n*log(n)) where n is the size of the array.
        *
        * Space analysis:
        *      * O(n) where n is the size of the input array.
        *
        * * */
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int mx = 0;
        int ctr = 0;

        for (int i =0; i < nums.size(); ++i) {
            // skip repeated numbers
            if(i != 0 && i != nums.size()-1  && nums[i]==nums[i+1]){
                continue;
            }

            ctr++;
            if(i == nums.size()-1  || nums[i]+1 != nums[i+1]){
                mx =max(mx, ctr);
                ctr=0;
            }
        }

        return mx;

    }
};