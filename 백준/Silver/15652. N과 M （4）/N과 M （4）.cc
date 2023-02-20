#include <bits/stdc++.h>
using namespace std;
int N, M ;
vector<int> arr ;
bool visited[9] ;

void DFS(int num, int idx)
{
    if(idx == M)
    {
        for(int i = 0 ; i < M ; i++)
            cout << arr[i] << " " ;
        cout << '\n' ;
        return ;
    }

    for(int i = num ; i <= N ; i++)
    {
        visited[i] = 1 ;
        arr[idx] = i ;
        DFS(i, idx+1) ;
        visited[i] = 0 ;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M ;
    arr = vector<int>(M) ;

    DFS(1, 0) ;
}