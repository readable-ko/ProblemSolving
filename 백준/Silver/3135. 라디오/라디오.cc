#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
bool visited[500000] ;
int start, want, N, tmp ;
queue<int> que ;

void BFS()
{
    que.push(start + 1) ;
    que.push(start - 1) ;
    visited[start + 1] = 1 ;
    visited[start - 1] = 1 ;
    int cnt = 1 ;

    while(!que.empty())
    {
        if(visited[want])
        {
            cout << cnt ;
            break ;
        }
        int size = que.size() ;
        for(int i = 0 ; i < size ; i++)
        {
            int now = que.front() ;

            que.pop() ;
            
            if(!visited[now + 1])
            {
                que.push(now + 1) ;
                visited[now + 1] = 1 ;
            }
            if(!visited[now - 1])
            {
                que.push(now - 1) ;
                visited[now - 1] = 1 ;
            }
        }

        cnt++ ;
    }
}

int main()
{
    SETTING ;
    cin >> start >> want >> N ;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> tmp ;
        visited[tmp] = 1 ;
        que.push(tmp) ;
    }

    BFS() ;
}