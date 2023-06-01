#include <bits/stdc++.h>
using namespace std;
class point{
public:
    int x_ = 0 ;
    int y_ = 0 ;
    
    point(int x, int y){x_ = x, y_ = y;}
    point(){x_ = 0, y_ = 0;}
};

int dx[] = {0, 1, 0, -1} ;
int dy[] = {1, 0, -1, 0} ;

int BFS(point s, point e, vector<string> maps) {
    queue<point> que ;
    int chk[maps.size()][maps[0].size()];
    memset(chk, 0, sizeof(chk));
    chk[s.x_][s.y_] = 1 ;
    
    que.push(s) ;
    int cnt = 0 ;
    while(!que.empty()) {
        int size = que.size() ;
        for(int i = 0 ; i < size ; i++) {
            point now = que.front() ; que.pop() ;
            for(int j = 0 ; j < 4 ; j++) {
                int nx = now.x_ + dx[j] ;
                int ny = now.y_ + dy[j] ;
                if(nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[nx].size()) continue ;
                if(chk[nx][ny] || maps[nx][ny] == 'X') continue ;
                
                chk[nx][ny] = chk[now.x_][now.y_] + 1 ;
                que.push(point(nx, ny)) ;
                
                if(nx == e.x_ && ny == e.y_) return chk[nx][ny] ;
            }
        }
    }
    return -1 ;
}

int solution(vector<string> maps) {
    int answer = 0;

    point S = point();
    point E = point();
    point L = point();
        for(int i = 0 ; i < maps.size() ; i++)
            for(int j = 0 ; j < maps[i].size() ; j++)
                switch (maps[i][j]) {
                    case 'S': S.x_ = i, S.y_ = j ; break ;
                    case 'E': E.x_ = i, E.y_ = j ; break ;
                    case 'L': L.x_ = i, L.y_ = j ; break ;
                }
    int StoL = BFS(S, L, maps) - 1 ;
    int LtoE = BFS(L, E, maps) - 1 ;
    return (StoL >= 0 && LtoE >= 0) ? StoL + LtoE : -1;
}