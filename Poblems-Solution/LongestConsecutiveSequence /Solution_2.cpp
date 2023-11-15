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




class Solution_1 {
    /* * *
        * Approach:
        *   * Determine the starting points
        *   * Start from each starting_point and while {starting_point++} exits in the array then increment the ctr
        *       and if it does not exit maximize the ctr and reset it
        * ------------------------------------------------------------------------------------------------
        * Time analysis:
        *      * O(n) where n is the size of the array.
        *
        * Space analysis:
        *      * O(n) where n is the size of the input array.
        *
        * * */
public:
    int longestConsecutive(vector<int> &nums) {
        set<int> freq, starting_points;

        // to answer: Do we have {num}? in o(1)
        for (auto num: nums) {
            freq.insert(num);
        }

        // setting the starting points
        for (auto num: nums) {
            if(freq.find(num-1) == freq.end()){
                starting_points.insert(num);
            }
        }

        int mx = 0;
        int ctr = 0;


        // start from each starting_point
        for (auto start_point: starting_points) {
            // start from each starting_point and if starting_point++ exits in the array
            while (freq.find(start_point++) != freq.end()){
                // then increment the ctr
                ctr++;
            }

            // and if it does not exit maximize the ctr and reset it
            mx = max(mx, ctr);
            ctr=0;
        }

        return mx;


    }
};