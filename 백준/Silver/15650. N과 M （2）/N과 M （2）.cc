/**
 * @file 15650.cpp
 * @author fpqpsxh
 * @brief N과M(2) 이번에 오름차순만 추가되었는데 백트래킹이 참 어렵다...
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
    }

    for(int i = 1 ; i <= N ; i++)
    {
        if(!visited[i] && (arr.empty() || i > arr.back()))
        {
            visited[i] = 1 ;
            arr.push_back(i) ;
            DFS(idx + 1) ;
            arr.pop_back() ;
            visited[i] = 0 ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M ;
    DFS(0) ;
}
