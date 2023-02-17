/**
 * @file 15650.cpp
 * @author fpqpsxh
 * @brief N과M(3) 이번에 중복가능.. 그냥 dfs같다.
 * @date 2023-02-17
 */

#include <bits/stdc++.h>
using namespace std ;
int N, M ;
bool visited[9] ;
vector<int> arr ;

void DFS(int idx)
{
    if(idx == M)
    {
        for(int i = 0 ; i < arr.size() ; i++)
            cout << arr[i] << ' ' ;
        cout << '\n' ;
        return ;
    }
    
    for(int i = 1 ; i <= N ; i++)
    {
        arr[idx] = i ;
        DFS(idx + 1) ;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M ;
    arr = vector<int>(M) ;
    DFS(0) ;
}
