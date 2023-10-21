//
// Created by Kalash on ٠٥/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_PI_H
#define UNTITLED_PI_H
#include <iostream>
#include <string>
#include "cmath"
#include "vector"
#include "unordered_set"
#include "utility"
#include "algorithm"
#include "climits"
#include "iomanip"
#include "unordered_set"
#include "set"
#include "unordered_map"
#include "list"
#include "stack"
#include "queue"
#include <sstream>

// #include "helper_funs.h"
using namespace std;
#define nn   <<endl
#define ss   <<" "<<
#define ull unsigned long long
#define ll long long

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=353
int gcd(int a, int b)
{
    /*
     * This function returns the gcd of "a" and "b" by the Euclid's Algorithm.
     */
    if(b>a)
    {
        int temp = b;
        b =a;
        a =temp;
    }
    if(b==0)
        return a;
    int r=a%b;
    return gcd(b,r);
}

void findCoPrimsRec(const vector<int>& numSet, vector<int>& path, int& ctr, int curr_i=0 )
{
    if(path.size()==2)
    {
        if(  gcd(path[0], path[1]) == 1 )
            ctr++;
        return ;
    }
    for (int i = curr_i; i < numSet.size(); ++i)
    {
        path.push_back(numSet[i]);   // do
        findCoPrimsRec(numSet, path, ctr, i+1);
        path.pop_back();             // un-do
    }
}
int findCoPrims(const vector<int>& numSet)
{
    int ctr=0;
    vector<int> path;
    findCoPrimsRec(numSet, path, ctr);
    return ctr;
}

int mainn()
{
    int num, x;
    vector<int> dataSet;
    while((cin >> num) && (num!=0))
    {
        for (int i = 0; i < num; ++i)
        {
            cin >> x;
            dataSet.push_back(x);
        }
        int count = findCoPrims(dataSet);
        if(count)
        {
            int sum = ((double)(num-1)/2) * (1+num-1);
            double pi = sqrt((double)(6*sum) / (double)count);
            printf("%.6lf\n", pi);
        }
        else
            puts("No estimate for this data set.");

        dataSet.clear();
    }





}
#endif //UNTITLED_PI_H
