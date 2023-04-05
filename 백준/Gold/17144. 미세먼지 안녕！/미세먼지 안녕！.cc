#include <bits/stdc++.h>
using namespace std ;

class Dust
{
public:
    int x_ ;
    int y_ ;
    int n_ ;
    Dust(int x, int y, int z){x_ = x, y_=y, n_=z;}
    Dust(int x, int y){x_=x, y_=y, n_=0;}
};

int munzi[52][52] ;
int x_way[] = {-1, 0, 1, 0} ;
int y_way[] = {0, 1, 0, -1} ;
const int CLOCKWISE = -1 ;
const int ANTICLOCK = 1 ;
int cw[] = {0, 1, 2, 3} ;
int ccw[] = {2, 1, 0, 3} ;
int r,c, times ;
vector<Dust> machine ;

void Diffusion()
{
    queue<Dust> q ;

    for(int i = 1 ; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++)
            if(munzi[i][j] > 0) q.push(Dust(i,j, munzi[i][j])) ;
    
    while(!q.empty())
    {
        int x = q.front().x_ ;
        int y = q.front().y_ ;
        int cnt = 0, share = q.front().n_ / 5 ;
        q.pop() ;

        for(int i = 0 ; i < 4 ; i++)
        {
            int new_x = x + x_way[i] ;
            int new_y = y + y_way[i] ;

            if(new_x < 1 || new_x > r || new_y < 1 || new_y > c) continue ;

            if(munzi[new_x][new_y] != -1)
            {
                cnt++ ;
                munzi[new_x][new_y] += share ;
            }
        }

        munzi[x][y] -= cnt * share ;
    }
}

void Ventilation(int row, int col, int wise, int rot[])
{
    int x = row + wise ;
    int y = col ;
    for(int way = 0 ; way < 4 ; way++)
    {
        while(1)
        {
            int new_x = x + x_way[rot[way]] ;
            int new_y = y + y_way[rot[way]] ;
            if(wise == CLOCKWISE)
            {
                if(new_x < 1 || new_x > row || new_y < 1 || new_y > c) break ;
            }
            else
            {
                if(new_x < row || new_x > r || new_y < 1 || new_y > c) break ;
            }
            if(new_x == row && new_y == col) break ;

            munzi[x][y] = munzi[new_x][new_y] ;
            x = new_x ; y = new_y ;
        }
    }
    munzi[row][col + 1] = 0 ;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0) ;
    int answer = 0 ;
    cin >> r >> c >> times ;

    for(int i = 1 ; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++)
        {
            cin >> munzi[i][j] ;
            if(munzi[i][j] == -1) machine.push_back(Dust(i,j)) ;
        }

    while(times--)
    {
        Diffusion();
        Ventilation(machine[0].x_, machine[0].y_, CLOCKWISE, cw) ;
        Ventilation(machine[1].x_, machine[1].y_, ANTICLOCK, ccw) ;
    }

    for(int i = 1 ; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++)
            answer += munzi[i][j] ;
    
    cout << answer + 2 << '\n' ;
}
