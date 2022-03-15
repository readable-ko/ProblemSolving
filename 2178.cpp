#include <bits/stdc++.h>
#define MAX 100001
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std ;
int N, M, cnt = 1 ;
bool graph[101][101] ;
bool arr[101][101] ;

int plus_x[] = {1, 0, -1, 0} ;
int plus_y[] = {0, 1, 0, -1} ;

void BFS()
{
    
    queue< pair<int, int> > que ;
    que.push(make_pair(1,1)) ;

    while(!que.empty())
    {
        int size = que.size() ;
        for(int i = 0 ; i < size ; i++)
        {
            pair<int, int> curr = que.front() ;
            que.pop() ;
            if(curr.first == N && curr.second == M) return ;

            for(int j = 0 ; j < 4 ; j++)
            {
                int next_x = curr.first + plus_x[j] ;
                int next_y = curr.second + plus_y[j] ;

                if(next_x < 1 || next_y < 1 || next_x > N || next_y > M) continue ;
                if(arr[next_x][next_y]) continue ;
                if(graph[next_x][next_y]) 
                {
                    que.push(make_pair(next_x, next_y)) ;
                    arr[next_x][next_y] = 1 ;
                }
            }
            arr[curr.first][curr.second] = 1 ;
        }
        cnt++ ;
    }
}

void InputSetting()
{
    string tmp ;
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> tmp ;
        for(int j = 1 ; j <= M ; j++)
        {
            graph[i][j] = tmp[j - 1] - '0' ;
        }
    }
    arr[1][1] = 1 ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    BFS() ;
    cout << cnt ;
}