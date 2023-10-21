//
// Created by ahmed on 26/01/23.
//

#ifndef UNTITLED_FLOYD_H
#define UNTITLED_FLOYD_H
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


const int N = 2005;
const ll inf = 1e15;
ll dist[N][N];
vector<vi> transition(N,vi(N,-1));


/*
 * Graph negative:
 * 	Shortest <-> Longest
 * 	Postive Cycle <-> Negative Cycle
 * 	Minimax <-> Maximin
 */




void floyd(int n)
{
    /*
        If you had a -ve cycle in a graph, the shortest path wouldn't be
        well defined, because you could keep going round and round the cycle
        making the path less.
    */

    // k = transition
    // 0 - Infinity MUST be larger than any path. Say we have n = 1000, and cost of edge max 5000, then min OO to = (1000-1) * 5000 + 1
	// 1- Set whole array to infinity:
	// 2- read input edges
	// 3- set diagonal to zeros: sometimes, if negative input you would like to leave them: e.g. adj[3][3] = -7 -> a self cycle



    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++) {
                if(dist[i][k] < inf && dist[k][j] <inf) // you could remove this line IFF 2*OO fit in the data type.
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                // for Retrieving the path
                if(dist[i][j] > (dist[i][k] + dist[k][j])) { transition[i][j] = k; }

            }

}

void build_path(int src, int dest)
{
    // What if we need to get the path?

	// Define path arr, initialize it to -1, which means direct
	// If path (i, j) has intermediate node k, then path[i][j] = k; means path from i to j pass with k
	// Write a recursive function be like:
    if( transition[src][dest] == -1 )	//So this is the last way
    {
        // print src or dest and take care of the repeated nodes on the end or on the beginning
        return;
    }
    build_path( src, transition[src][dest]);
    build_path( transition[src][dest], dest);
}


void check_existence(int n)
{
	// assume matrix is 0 for disconnect, 1 is connected
	// we only care if a path exist or not, not a shortest path value

    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++)
                dist[i][j] |= (dist[i][k] & dist[k][j]);
}


void minimax(int n)
{
	// find path such that max value on road is minimum

    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]) ); // remember that dist[i][k] contains the min
                //  value on the road for [i] to [k] as it builds it incrementally, and not the full distance
}

void maximin(int n)
{
	// find path such that min value on road is maximum

    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++)
                dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]) ); // remember that dist[i][k] contains the max
                //  value on the road for [i] to [k] as it builds it incrementally, and not the full distance
}

void longestPathDAG(int n)
{
    /*
        If you had a cycle in a graph, the longest path wouldn't be
        well defined, because you could keep going round and round the cycle
        making the path longer.
    */


    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++) {
                //  Graph negative:  Shortest <-> Longest

                // or
                dist[i][j] = max(dist[i][j], max(dist[i][k], dist[k][j]));

            }
}



void countPaths(int n)
{
    // Floyd warshal for counting #of paths
    for ( int k = 1;  k <= n ; k++)
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++)
                dist[i][j] += dist[i][k] * dist[k][j]; // number of roads from 'a' to 'b'
                // = (num of roads from 'a' to 'c') *  (num of roads from 'c' to 'b')


    // 1- assume graph is DAG
    /*
     * k = 5, i = 1, j = 2 we will use adj[ 1 ][ 5 ] with old value
     * k = 5, i = 1, j = 5 we will update adj[ 1 ] [ 5 ]
     * k = 5, i = 1, j = 7 we will use adj[ 1 ][ 5 ] with new value
     * Won't this give and incorrect result?
     *
     * NO. E.g. when k = 5, i = 1, j = 5:
     * adj[1][5] += adj[1][5] * adj[5][5];
     * adj[5][5] = 0, so no update happens. In general, when k = i or j, no updates happens, so in-placement update is fine.
     */

    /*
     * What if graph is not DAG.
     * if(adj[i][i] > 0)	-> i has a cycle path on it
     *
     * Generally, for any node v that has a cycle,
     * 		if i reaches v, and v reaches j, then count of (i, j) is useless as count is OO. Remain adj[][] is valid
     */

}

bool isNegativeCycle(int n) {
//    This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at
//    the end of the algorithm, the distance from a vertex 'v' to itself is negative.
    for ( int i = 1 ; i <= n ; i++) {
        if (dist[i][i] < 0)
            return true;    // then node i got to i with overall cost < 0.
    }
    return false;
}

bool anyEffectiveCycle(int src, int dest, int n)
{
    for ( int i = 1 ; i <= n ; i++) {
        if (dist[i][i] < 0) { // if 'i' in a -ve cycles
            if (dist[src][i] < inf && dist[i][dest] < inf) // if the
            { return true; }
        }
    }
    return false;
}



int graphDiameter(int n)
{
    // Longest path among all shortest ones

    int mx = 0;
    for ( int i = 1 ; i <= n ; i++)
        for ( int j = 1 ; j <= n ; j++)
            if(dist[i][j] < inf)
        mx = max((ll)mx, dist[i][j]);

    return mx;
}



// strongly connected component
vector< vector<int> > SCC()
{
    vector<int> comp(n, -1);

    int cnt = 0;
    lp(i, n) if(comp[i]==-1) {
        comp[i] = cnt++;
        lp(j, n) if(adj[i][j] < OO && adj[j][i] < OO)	// transitive clusre is enough
            comp[j] = comp[i];
    }

    vector< vector<int> > compGraph(cnt, vector<int>(cnt));

    lp(i, n) lp(j, n)	if(adj[i][j] < OO)
        compGraph[ comp[i] ][ comp[j] ] = 1;	// DAG

    return compGraph;
}










#endif //UNTITLED_FLOYD_H
