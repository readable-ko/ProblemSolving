#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int width, height ;
vector< vector<int> > arr ;
int x_add[8] = {1, -1, 0, 0, 1, 1, -1, -1} ;
int y_add[8] = {0, 0, 1, -1, 1, -1, -1, 1} ;

void BFS(vector< pair<int,int> > &spot)
{
    int cnt = 0 ;
    bool visited[width][height] ;
    memset(visited, 0, sizeof(visited)) ;
    for(pair<int,int> now : spot)
    {
        if(!visited[now.first][now.second])
        {
            queue< pair<int,int> > que ;
            que.push(now) ;
            visited[now.first][now.second] = 1 ;
            cnt++ ;

            while(!que.empty())
            {
                int x = que.front().first ;
                int y = que.front().second ;
                que.pop() ;

                for(int i = 0 ; i < 8 ; i++)
                {
                    int x_new = x + x_add[i] ;
                    int y_new = y + y_add[i] ;
                    
                    if(x_new < 0 || y_new < 0 || x_new >= width || y_new >= height) continue ;
                    if(!visited[x_new][y_new] && arr[x_new][y_new] == 1)
                    {
                        visited[x_new][y_new] = 1 ;
                        que.push(make_pair(x_new, y_new)) ;
                    }
                }
            }
        }
    }

    cout << cnt << "\n" ;
}

int main()
{
    SETTING ;
    while(1)
    {
        cin >> height >> width ;
        if(width == 0 && height == 0) break ;
        arr = vector < vector <int> >(width, vector<int>(height)) ;
        vector< pair<int,int> > spot ;

        for(int i = 0 ; i < width ; i++)
            for(int j = 0 ; j < height ; j++)
            {
                cin >> arr[i][j] ;
                if(arr[i][j] == 1) spot.push_back(make_pair(i,j)) ;
            }
        BFS(spot) ;
    }
}