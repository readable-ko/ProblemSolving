#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0, n = maps.size(), m = maps[0].size() ;    
    int dx[] = {1, -1, 0, 0} ;
    int dy[] = {0, 0, 1, -1} ;

    queue< pair<int,int> > que ;
    que.push({0,0}) ;

    int visited[n][m] ;
    memset(visited, 0, sizeof(visited)) ;
    
    while(!que.empty())
    {
        pair<int,int> now = que.front() ; que.pop() ;

        for(int j = 0 ; j < 4 ; j++)
        {
            int next_x = now.first + dx[j] ;
            int next_y = now.second + dy[j] ;
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
            if(maps[next_x][next_y] && visited[next_x][next_y] == 0)
            {
                visited[next_x][next_y] = visited[now.first][now.second] + 1 ;
                if(now.first == n - 1 && now.second == m - 1) break ;

                que.push(make_pair(next_x, next_y)) ;
            }
        }
        answer++ ;
    }
    return visited[n-1][m-1] ? visited[n-1][m-1] + 1 : -1 ;
}