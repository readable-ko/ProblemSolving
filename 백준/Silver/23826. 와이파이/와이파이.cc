/**
 * @file 25826.cpp
 * @author fpqpsxh
 * @date 2023-01-18
 * @brief 모든 방에서 모든 공유기가 닿았을 때 경우를 고려해야하는데 DFS를 이용한 브루트포스나
 * 그냥 for로 브루트포스 하면 될 거 같은 단순한 문제!
 **/
#include <iostream>
using namespace std ;
int signal_strength[1001][1001], maxim ;

class ROOM
{
    public:
        int x ;
        int y ;
        int p ;
};

int Effecting(int lhs_x, int lhs_y, int rhs_x, int rhs_y, int power)
{
    int signal = power - (abs(lhs_x - rhs_x) + abs(lhs_y - rhs_y)) ;
    return (signal <= 0) ? 0 : signal ;
}

int main()
{
    int N ;
    ios::sync_with_stdio(0), cin.tie(0) ;

    cin >> N ;
    ROOM room[N+1] ;

    for(int i = 0 ; i <= N ; i++)
        cin >>room[i].x >> room[i].y >> room[i].p ;
    
    for(int i = 1 ; i <= N ; i++)
        signal_strength[room[i].x][room[i].y] = Effecting(room[0].x, room[0].y, room[i].x, room[i].y, room[0].p) ;

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
        {
            if(signal_strength[room[i].x][room[i].y] <= 0) break ;
            signal_strength[room[i].x][room[i].y] -= Effecting(room[j].x, room[j].y, room[i].x, room[i].y, room[j].p) ;
        }
    
    for(int i = 1 ; i <= N ; i++)
        if(maxim < signal_strength[room[i].x][room[i].y]) maxim = signal_strength[room[i].x][room[i].y] ;
    
    maxim == 0 ? cout << "IMPOSSIBLE\n" : cout << maxim << '\n' ;
}