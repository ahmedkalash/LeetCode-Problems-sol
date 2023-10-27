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
     *      * All you need to do is to check that the items in each row and column and sub-box are unique.
     *      * You can use a set and a number_ctr and if(number_ctr != set.size()) then the numbers are not unique
     * --------------------------------------------------------------------------------------------------------------
     * Time analysis:
     *      *  O(3 * 9 * 9 * log(9))
     *
     *
     * * */


public:

    bool isValidRow(const vector<char>& row){
        // O(9*log(9))
        int nums_count = 0;
        set<char> nums_set;
        for (auto ch: row) {
            if(ch!='.'){
                nums_count++;
                nums_set.insert(ch);
            }
        }

        return nums_set.size() == nums_count;
    }


    bool isValidColumn(vector<vector<char>>& board, int col) {
        // O(9*log(9))
        int nums_count = 0;
        set<char> nums_set;

        for (auto row:board) {
            if(row[col]!='.'){
                nums_count++;
                nums_set.insert(row[col]);
            }
        }

        return nums_set.size() == nums_count;
    }


    bool isValidSubBox(vector<vector<char>>& board, int r, int c) {
        // O(9*log(9))
        // r and c are the the first cell of the sub-box - the upper left cell -
        int nums_count = 0;
        set<char> nums_set;
        for (int i = r; i <  r+3 ; ++i) {
            for (int j = c; j < c+3 ; ++j) {
                if(board[i][j] != '.'){
                    nums_count++;
                    nums_set.insert(board[i][j]);
                }
            }
        }
        return nums_set.size() == nums_count;
    }




    bool isValidSudoku(vector<vector<char>>& board) {

        bool rows_check = true, columns_check = true, sub_box_check = true;

        // check rows
        // O(9*9*log(9))
        for (const auto& row:board) {
            rows_check &= isValidRow(row);
        }

        // check columns
        // O(9*9*log(9))
        for (int i = 0; i < board.size(); ++i) {
            columns_check &= isValidColumn(board, i);
        }


        // check sub-boxes
        // O(9*9*log(9))
        for (int i = 0; i <=6 ; i+=3) {
            for (int j = 0; j <=6 ;  j+=3) {
                sub_box_check &= isValidSubBox(board, i, j);
            }
        }

        return rows_check && columns_check && sub_box_check;
    }


};