#include<bits/stdc++.h>
using namespace std;
int N, M, R, C, L ;
int y_way[8][4] = {{0,0,0,0},{1, 0, -1, 0}, {0, 0, 0, 0}, {1, -1, 0, 0}, {0, 1,0,0}, {0, 1,0,0}, {-1, 0,0,0}, {-1, 0,0,0}};
int x_way[8][4] = {{0,0,0,0},{0, 1, 0, -1}, {1, -1, 0, 0},{0, 0, 0, 0},  {-1, 0,0,0},{1,0,0,0}, {0, 1,0,0}, {0, -1,0,0}};

void BFS(vector<vector <int> > &mp, vector<vector <int> > &visited, int L) {
    queue< pair<int, int> > que ;
    que.push(make_pair(R, C)) ;
    
    while(!que.empty()) {
        pair<int,int> f = que.front(); que.pop() ; //f: front
        
        if(visited[f.first][f.second] > L) break ;

        for(int i = 0 ; i < 4 ; i++) {
            int p = mp[f.first][f.second] ; //p : pipe
            int nx = f.first + x_way[p][i] ;  //nx : new x position
            int ny = f.second + y_way[p][i] ; //ny : new y position

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if(visited[nx][ny] == 0 && mp[nx][ny] != 0) {
                bool flag = 0;
                for(int j = 0 ; j < 4 ; j++) {
                    int rx = nx + x_way[mp[nx][ny]][j] ;
                    int ry = ny + y_way[mp[nx][ny]][j] ;

                    if(rx == f.first && ry == f.second) flag = 1 ;
                }
                if(flag) {
                    visited[nx][ny] = visited[f.first][f.second] + 1 ;
                    que.push(make_pair(nx, ny)) ;
                }
            }
        }
    }

    int answer = 0 ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            if(visited[i][j] <= L && visited[i][j] > 0 ) {
                //cout << i << j << "@@\n" ;
                answer++ ;
            }
    
    cout << answer << "\n" ;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0), cin.tie(0) ;
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		//각 테스트 케이스의 첫 줄에는 지하 터널 지도의 세로 크기 N, 가로 크기 M,
        //맨홀 뚜껑이 위치한장소의 세로 위치 R, 가로 위치 C, 그리고 탈출 후 소요된 시간 L 이 주어진다.
        
        cin >> N >> M >> R >> C >> L ;

        vector< vector<int> > mp(N, vector<int>(M)) ;
        vector< vector<int> > visited(N, vector<int>(M)) ;
        visited[R][C] = 1 ;

        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                cin >> mp[i][j] ;
        
        cout << "#" << test_case << " ";
        BFS(mp, visited, L) ;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}