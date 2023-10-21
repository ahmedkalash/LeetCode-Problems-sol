//
// Created by ahmed on 26/12/22.
//

#ifndef UNTITLED_BELLMANFORD_H
#define UNTITLED_BELLMANFORD_H
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

#define voyager ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
// INT MAX = 2.147483647 x 10^(9)
// LONG LONG MAX  = 9.223372036854799561 x 10^(18)


const ll N = 1e6+10, inf = 1e15;
struct edge{ll from, to, w;};
int n, m;

/**
 * bellman-Ford:
 * n^2
 * does not work for nodes that there is -ve cycle between them and the source
 * works for nodes that there is no -ve cycle between them and the source
 * In ith iteration, Shortest Paths of at most i edges are found
 * Improvement: If an iteration has no update, next won’t have update..just break
 * if we any node was relaxed after n-1 iterations for the outer loop, the we have a cycle
 * We can know all nodes affected by -ve cycle
    ◼ After bellman finishes, saves its distance array
    ◼ Run bellman on updated array (n iterations for the outer loop)
    ◼ Compare with new dist arr, Different values = Node Cycle
 * Find a cycle
    ◼ Start from any affected node, say node A
    ◼ it is either in the cycle...or cycle reach it
    ◼ Go back (prev array), n steps
    ◼ Now, you must be at a cycle..say node B
    ◼ Go back again, till you see B again..this a cycle
 * Find positive cycle? Multiple graph with -1
 * */
vll bellmanFord(ll src, vector<edge>& edgVector)
{
    // if there is a negative cycle -that is reachable from the src- (see bellman ford by mostafa saad's pdf page 5)this function will return an empty vector<ll>
    // otherwise it will return a vector<ll> containing the shortest path from the src to all the nodes
    vll dist(N, inf);
    // if you have multiple source put their dist = 0;
    dist[src]=0;
    bool cycle_found=0;
    for (int i = 1; i <= n ; ++i)
    {
        for (auto edg:edgVector)
        {
            if(dist[edg.from] < inf) // if there is no such verification,  incorrect distance, of the type inf-1 , inf-1e5 etc. would appear.
            {
                // the previous was made to avoid the following:
                /* we will check if (dist[edg.from] + edg.w < dist[edg.to])
                 * and if dist[edg.to] = 1e6  and  inf = 1e6+1e5  and  dist[edg.from]=inf  and  edg.w=-1e6
                 * this will result:  (inf-1e6< 1e6) which equal to (1e6+1e5-1e6 < 1e6) which equal to (1e5<1e6)  and finally this should be equal to  (inf< 1e6)
                 * but this was not happened
                 * */
                if (dist[edg.from] + edg.w < dist[edg.to]) {
                    if (i > n - 1) { cycle_found = 1; }
                    dist[edg.to] = dist[edg.from] + edg.w;
                }
            }

            // in case of undirected graph
            if(dist[edg.to] < inf)
            {
                if (dist[edg.from] > dist[edg.to] + edg.w) {
                    if (i > n - 1) { cycle_found = 1; }
                    dist[edg.from] = dist[edg.to] + edg.w;
                }
            }
        }
    }

    if(cycle_found){return vll();}
    else{return dist;}

}

// to get the longest Path
vll bellmanFord_longestPath(int src, vector<edge>& edgVector)
{
    // way 1:
    // multiply each wight by -1, calculate the shortest path, multiply the dist array by -1, and then you have what you need.
    //---------------------------------------------------------
    // way 2 :
    // initialize the dist array by -inf instead of inf
    // instead of relaxing(minimizing) you need to (maximize)
    vll dist(N,inf);
    dist[src]=0;
    for (int i = 1; i <n ; ++i) {

        for (auto edge: edgVector) {

            if(dist[edge.from]>-inf) // -inf instead of inf
            {
                if (dist[edge.from] + edge.w > dist[edge.to])  // instead of relaxing(minimizing) you need to (maximize)
                {
                    dist[edge.to] = dist[edge.from] + edge.w;
                }
            }
        }
    }


    return dist;
}

// how to check if a node is affected by a -ve cycle
vll bellmanFord_cycle_affectedNodes(ll src, vector<edge>& edgVector)
{

   /* We can also know all nodes affected by -ve cycle:
        ◼ After bellman finishes, saves its distance array
        ◼ Run bellman on updated array (n iterations for the outer loop)
        ◼ Compare with new dist arr, Different values = Node Cycle
    */

    // the outer loop will run for 2*n times to make sure that every node reachable form the -ve cycle is updated.
    vll dist(N,inf);
    dist[src]=0;
    for (int i = 1; i <=2*n ; ++i) {

        for (auto edge: edgVector) {
            if (dist[edge.from] + edge.w < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.w;
                if(i>=n) // if any node after n-1 iterations for the outer loop was updated then it is affected by a -ve cycle
                {
                    if(edge.to == n){return vll();}
                }
            }
        }
    }

    return dist;

}

// how to retrieve the Path from src to any node if such path exist
void bellmanFord_path(ll src, vector<edge>& edgVector)
{
    /* * * * The shortest path will not exist from src to target if there is
     * src not connected to target
     * a -ve cycle exist between src and target
     * * * */
    vll dist(N, inf);
    vll parent(N, -1);
    dist[src]=0;
    bool cycle_found=0;
    for (int i = 1; i <= 2*n ; ++i)
    {
        /* * * * After this loop runs:
         * dist will contain the shortest paths from src to all other nodes
         * dist[target] will equal to 'inf' if src not connected to target
         * dist[target] will equal to '-inf' if there is a -ve cycle that reaches the target
         * parent[target] will equal to -1 if there is a -ve cycle or no path from src to target
         * * * */
        for (auto edg:edgVector)
        {
            if(dist[edg.from] < inf)
            {
                if (dist[edg.from] + edg.w < dist[edg.to]) {
                    if (i > n - 1) {
                        cycle_found = 1;
                        dist[edg.to] = -inf; // there is a -ve cycle that reaches the target
                        parent[edg.to] = -1;
                    }
                    dist[edg.to] = dist[edg.from] + edg.w;
                    parent[edg.to] = edg.from;

                }
            }

            // in case of undirected graph
            if(dist[edg.to] < inf)
            {
                if (dist[edg.from] > dist[edg.to] + edg.w) {
                    if (i > n - 1) {
                        cycle_found = 1;
                        dist[edg.from] = -inf; // there is a -ve cycle that reaches the target
                        parent[edg.from] = -1;
                    }
                    dist[edg.from] = dist[edg.to] + edg.w;
                    parent[edg.from] = edg.to;
                }
            }
        }
    }


    // to construct a path
    int target ; // left uninitialized for you
    if(parent[target] == -1 && target!=src){ cout << "No path from " << src << " to " << target << ".";}
    else
    {
        vector<int> path;
        for (int cur = target; cur != -1; cur = parent[cur]) { path.push_back(cur); }
        reverse (path.begin(), path.end());

        cout << "Path from " << src << " to " << target << ": ";
        for (size_t i=0; i<path.size(); ++i) { cout << path[i] << ' '; }
    }



}

void bellmanFord_retrieve_cycle() {
    /** Find a cycle
    ◼ Start from any affected node, say node A
    ◼ it is either in the cycle...or cycle reach it
    ◼ Go back (prev array), n steps
    ◼ Now, you must be at a cycle..say node B
    ◼ Go back again, till you see B again..this a cycle
     */

    // let y be an affected node and parent[] be the parent array
    int A , parent[1000]; // left uninitialized for you
    for (int i=1; i<=n; ++i) { A = parent[A]; } // Go back (prev array), n steps

    vector<int> path;
    // Now, you must be at a cycle..say node B
    for (int B=A; ; B=parent[B]) // Go back again, till you see B again..this a cycle
    {
        path.push_back (B);
        if (B == A && path.size() > 1) { break; } // till you see B again..this a cycle
    }
    reverse (path.begin(), path.end());

    cout << "Negative cycle: ";
    for (size_t i=0; i<path.size(); ++i) { cout << path[i] << ' '; }
}









#endif //UNTITLED_BELLMANFORD_H
