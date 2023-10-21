//
// Created by Kalash on ١٢/٠٧/٢٠٢٢.
//

#ifndef UNTITLED_GENERATEPARENTHESIS_H
#define UNTITLED_GENERATEPARENTHESIS_H

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



// on leet code
// ---------------------------------------------------------------
vector<string> answer;
string s;
bool  wellFormedParentheses (const string& s)
{
    stack<char> back;
    int ctr=0;
    while (ctr<s.size())
    {
        if(s[ctr]=='(')
            back.push(s[ctr]);
        else
        {
            if(back.empty())
                return false;
            else
                back.pop();
        }
        ctr++;
    }
    if (!back.empty())
        return false;


    return true;

}
void generateParenthesisRec(const int n, int opened, int closed)
{


    if((opened>n) || (closed>n)) { return; }
    if(opened==n && closed==n)
        // if(s.length()==2*n)
    {
        //if(wellFormedParentheses(s))
        answer.push_back(s);
        return;
    }

    if(opened!=n) {
        s.push_back('(');  // do
        generateParenthesisRec(n, opened + 1, closed);
        s.pop_back();  // unDo
    }

    if(opened > closed)
    {
        s.push_back(')');   // do
        generateParenthesisRec(n, opened, closed + 1);
        s.pop_back();   // unDo
    }
}
vector<string> generateParenthesis(int n)
{

    generateParenthesisRec(n,0,0);
    return answer;
}


#endif //UNTITLED_GENERATEPARENTHESIS_H
