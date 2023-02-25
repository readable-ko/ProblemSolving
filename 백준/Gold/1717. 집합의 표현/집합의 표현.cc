/**
 * @file 1717.cpp
 * @author fpqpsxh
 * @brief 유니온파인드, 분리집합 처음 공부해봤는데 다음에 코드만 보고도 이해할 수 있을까
 * @date 2023-02-25
 */
#include <bits/stdc++.h>
using namespace std;
int parents[10000001] ;
int ranking[10000001] ;
int n,m ;
int Find(int x)
{
    if(parents[x] == x) return x ;
    return parents[x] = Find(parents[x]) ;
}

void Merge(int x, int y)
{
    x = Find(x) ;
    y = Find(y) ;
    if(x == y) return ;
    if(ranking[x] < ranking[y]) swap(x, y) ;
    parents[y] = x ;
    ranking[x]++ ;
}

void UnionFind(int x, int y)
{
    x = Find(x) ;
    y = Find(y) ;
    (x == y) ? cout << "YES\n" : cout << "NO\n" ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    int button, set_a, set_b ;
    cin >> n >> m ;

    for(int i = 0 ; i <= n ; i++)
        parents[i] = i ;

    for(int i = 0 ; i < m ; i++)
    {
        cin >> button >> set_a >> set_b ;
        if(button) UnionFind(set_a, set_b) ;
        else
        {
            Merge(set_a, set_b) ;
        }
    }
}