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
 * Link: https://leetcode.com/problems/3sum/description/
 * */




class Solution {
    /* * *
        * Approach:
        *   * Sort the input array
        *   * for each nums[i] we need tow number that sum up to -nums[i]
        *   * now it was turned to tow sum problem
        *   * to prevent duplicates :
        *       - if(i!=0 && nums[i]==nums[i-1]){ continue;}
        *       - while (nums[l]==nums[l-1] && l< r){l++;}
        *
        * ------------------------------------------------------------------------------------------------
        * Time analysis:
        *      * O(n^2) where n is the length of input array.
        *
        * Space analysis:
        *      * O(1).
        *
        * * */
public:



    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if(i!=0 && nums[i]==nums[i-1]){ continue;}
            int l=i+1, r = nums.size()-1;
            while (l<r){
                if( l==i){
                    l++;
                    continue;
                }
                if(r==i){
                    r--;
                    continue;
                }

                int sum = nums[l]+nums[r]+nums[i];
                if( sum == 0){
                    ans.push_back({nums[l], nums[r], nums[i]});
                    r--;
                    l++;
                    while (nums[l]==nums[l-1] && l< r){l++;} // you can comment any one of these lines and it will still work
                    while (nums[r]==nums[r+1] && l< r){r--;} // you can comment any one of these lines and it will still work

                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }

            }

        }

        return  ans;

    }





};