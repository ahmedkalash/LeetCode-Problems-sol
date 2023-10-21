//
// Created by ahmed on 19/12/22.
//

#ifndef UNTITLED_EULER_GRAPH_H
#define UNTITLED_EULER_GRAPH_H

#include <bits/stdc++.h>
#include "strstream"
using namespace std;

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



const int mod = 1e9+7;
const ll N = 1e6+10;
vector<set<ll>> graph(N);
vector<bool> vis(N,0);



// Euler Circut Undirected
// alternative :: https://ideone.com/0RNtEN

vll path;
void eulerCircut(ll src)
{

    while (!graph[src].empty()) {
        auto it = graph[src].begin();
        ll ch = *it;

        graph[src].erase(it);
        graph[ch].erase(src);

        eulerCircut(ch);
    }

    // ask the coach about it why it can not be at the begging of the the fun
    path.emplace_back(src);

    // 1 2 3 5 4 2 6 3 1

}
void solve_eulerCircut (int testcase)
{
    int n, m; cin >> n>>m;
    for (int i = 0; i < m; ++i) {
        ll u, v; cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    for (int i = 1; i <=n ; ++i) {
        if(graph[i].size()%2){return cout << "IMPOSSIBLE\n", void(); }
    }

    eulerCircut(1);


    if(path.size()!=m+1){return cout << "IMPOSSIBLE\n", void(); }

    std::reverse(path.begin(), path.end());

    print(path);

}
//===============================================



// Euler Path   directed
// alternative ::  https://ideone.com/7BEU5k

vll path;
void eulerPath(ll src)
{
    while (!graph[src].empty()) {
        auto it = graph[src].begin();
        ll ch = *it;

        graph[src].erase(it);

        eulerPath(ch);
    }

    // ask the coach about it why it can not be at the begging of the the fun
    path.emplace_back(src);

    // 1 2 3 5 4 2 6 3 1

}
int in[N], out[N] ;
void solve (int testcase)
{
    int n, m; cin >> n>>m;
    for (int i = 0; i < m; ++i) {
        ll u, v; cin >> u >> v;
        graph[u].insert(v);
        out[u]++;
        in[v]++;
    }

    if((out[1]-in[1]!=1) && (in[n]-out[n]!=1)){return cout << "IMPOSSIBLE\n", void(); }
    for (int i = 2; i <n ; ++i) {
        if(!(in[i]==out[i] && (out[1]-in[1]==1) && (in[n]-out[n]==1))){return cout << "IMPOSSIBLE\n", void(); }
    }

    eulerPath(1);


    if(path.size()!=m+1){return cout << "IMPOSSIBLE\n", void(); }

    std::reverse(path.begin(), path.end());

    print(path);

}






#endif //UNTITLED_EULER_GRAPH_H
