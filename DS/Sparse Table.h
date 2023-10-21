//
// Created by ahmed on 16/03/23.
//

#ifndef UNTITLED_SPARSE_TABLE_H
#define UNTITLED_SPARSE_TABLE_H

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10 ;

// range min , max , gcd in O(1)


int sp[N][25], lg[N],  a[N];
int merge(int a , int b)
{
    return min(a , b);
}

void build_sparse_table(int n)
{
    // O(nlog(n))
    lg[0] = lg[1] = 0;
    for ( int i = 2 ; i <= n ; i++)
        lg[i] = lg[i>>1] + 1 ;

    for ( int i = 0 ; i < n ; i++)
        sp[i][0] = a[i];

    for ( int j = 1 ; j < 21 ; j++)
        for ( int i = 0 ; i + (1<<j) <= n ; i++)
            sp[i][j] = merge(sp[i][j-1] , sp[i + (1<<(j-1))][j-1]);
}

int query( int l , int r)
{
    // O(1)
    int k = lg[r-l+1];
    return merge(sp[l][k], sp[r-(1<<k)+1][k]);
}



#endif //UNTITLED_SPARSE_TABLE_H
