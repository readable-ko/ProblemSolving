/**
 * @file 17070.cpp
 * @author fpqpsxh
 * @brief dp 아니면 뭔가 dfs로 경우 잘주고 return 때리면 될 거 같은데 return 조건을 잘 모르겠네...
 * 뭔가 더 간단하게 짤 수 있을 거 같은데 어렵네
 * @date 2023-03-12
 */
#include<bits/stdc++.h>
#define VERTICAL 1
#define HORIZONTAL 2
#define DIAGONAL 3

using namespace std;
int N ;
bool room[17][17] ;

int DFS(int x, int y, int pos, int cnt)
{
    if(x < 1 || x > N || y < 1 || y > N) return 0 ;
    
    if(room[x][y] == 1) return 0 ;
    if(pos == DIAGONAL && ((room[x-1][y] == 1) || (room[x][y-1] == 1))) return 0 ;

    if(x == N && y == N) return 1 ;
    
    if(pos == VERTICAL)
    {
        return DFS(x + 1, y, VERTICAL, cnt) + DFS(x + 1, y + 1, DIAGONAL, cnt) ;
    }
    else if(pos == HORIZONTAL)
    {
        return DFS(x, y + 1, HORIZONTAL, cnt) + DFS(x + 1, y + 1, DIAGONAL, cnt) ;
    }
    else 
        return DFS(x + 1, y, VERTICAL, cnt) + DFS(x, y + 1, HORIZONTAL, cnt) + DFS(x + 1, y + 1, DIAGONAL, cnt) ;
}

int main()
{
    cin >> N ;

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> room[i][j] ;
    
    cout << DFS(1, 2, HORIZONTAL, 0) << "\n" ;
}