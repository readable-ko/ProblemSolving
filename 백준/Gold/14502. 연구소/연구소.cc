/**
 * This Code is written by gloryko fpqpsxh.
 * N M이 몇인지도 나와있지 않아서 와 이거 어케푸냐.. 하고 있었는데
 * 그냥 감 1도 못잡다가 힌트 봤더니 브루트포스 문제 다시 보니까 8보다 작다고 명시되어있네
 * 브루트포스로 벽 위치를 다 찍어보고 그 순간마다 bfs 돌려봐야할 거 같은데. 시간 너무 오래걸리려나
 * dfs로 벽 세우는 위치 찍고 bfs돌리는 방법이 있드라!
**/

#include <bits/stdc++.h>
using namespace std;
int N, M, tmp, global_max ;
vector< vector<int> > arr;
int x_plus[4] = {1, 0, -1, 0} ;
int y_plus[4] = {0, 1, 0, -1} ;

int BFS(vector< vector<int> > institution)
{
    queue< pair<int, int> > que ;
    int local_max = 0;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            if(institution[i][j] == 2) que.push(make_pair(i, j)) ;
    
    while(!que.empty())
    {
        pair<int,int> now = que.front(); 
        que.pop() ;
        for(int i = 0 ; i < 4 ; i++)
        {
            int x_new = now.first + x_plus[i] ;
            int y_new = now.second + y_plus[i] ;
            if(x_new >= 0 && y_new >= 0 && x_new < N && y_new < M)
                if(institution[x_new][y_new] == 0)
                {
                    institution[x_new][y_new] = 2 ;
                    que.push(make_pair(x_new, y_new)) ;
                }
        }
    }

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            if(institution[i][j] == 0) local_max++ ;

    return local_max;
}

void MakeWall(int cnt, vector< vector<int> > institution)
{
    if(cnt == 3)
    {
        global_max = max(global_max, BFS(institution));
    }
    else
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
            {
                if(institution[i][j] == 0)
                {
                    institution[i][j] = 1 ;
                    MakeWall(cnt + 1, institution) ;
                    institution[i][j] = 0 ;
                }
            }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M ;

    arr.assign(N, vector<int>(M, 0)) ;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin >> arr[i][j] ;

    MakeWall(0, arr) ;

    cout << global_max ;
}