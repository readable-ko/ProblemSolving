#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int N, M, R, u, v, cnt ;
vector<int> arr[100001] ;
int check[100001] ;

void DFS(int r)
{
    check[r] = ++cnt ;

    for(int i : arr[r])
        if(!check[i]) DFS(i) ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M >> R ;

    for(int i = M ; i ; i--)
    {
        cin >> u >> v ;
        arr[u].push_back(v) ;
        arr[v].push_back(u) ;
    }

    for(int i = N ; i; i--)
        sort(arr[i].begin(), arr[i].end(), [&](int a, int b){return a > b ;}) ;
    
    DFS(R) ;
    for(int i = 1 ; i <= N ; i++)
        cout << check[i] << "\n";
}