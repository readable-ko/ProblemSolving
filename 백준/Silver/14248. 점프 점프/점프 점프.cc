#include <iostream>
#include <vector>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, s, cnt ;

int main()
{
    SETTING ;
    cin >> N ;
    vector<int> arr(N) ;
    vector<bool> visited(N) ;
    queue<int> que ;

    for(int& it : arr)
        cin >> it ;
    cin >> s ;

    que.push(--s) ;
    visited[s] = 1 ;

    while(!que.empty())
    {
        int now = que.front() ;
        que.pop() ;
        cnt++ ;
        
        if(arr[now] + now < N && !visited[arr[now] + now])
        {
            visited[arr[now] + now] = 1 ;
            que.push(arr[now] + now) ;
        }
        
        if(now - arr[now] >= 0 && !visited[now - arr[now]])
        {
            visited[now - arr[now]] = 1 ;
            que.push(now - arr[now]) ;
        }
    }

    cout << cnt << "\n" ;
}