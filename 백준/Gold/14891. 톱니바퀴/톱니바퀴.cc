/**
 * @file 14891.cpp
 * @author fpqpsxh
 * @brief 그냥 보자마자 시뮬레이션 + 빡구현
 * @date 2023-03-16
 * @version 1.0 recursion
 */
#include<bits/stdc++.h>
using namespace std ;
int gear[6][8], N, number, dir ;
bool visited[8] ;

void Spin(int num, int direction)
{
    if(num < 1 || num > 4) return ;
    
    visited[num] = 1 ;
    int diff = (direction == 1 ? -1 : 1) ;

    if(gear[num][2] != gear[num+1][6] && !visited[num+1]) 
        Spin(num+1, diff) ;
    
    if(gear[num][6] != gear[num-1][2] && !visited[num-1])
        Spin(num-1, diff) ;

    if(direction == 1)
    {
        int remain = gear[num][7] ;
        memmove(gear[num] + 1, gear[num], sizeof(gear[num]) - 4) ;
        gear[num][0] = remain ;
    }
    else
    {
        int remain = gear[num][0] ;
        memmove(gear[num], gear[num] + 1, sizeof(gear[num]) - 4) ;
        gear[num][7] = remain ;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    for(int i = 1 ; i < 5 ; i++)
    {
        string str;
        cin >> str ;
        for(int j = 0 ; j < 8 ; j++)
            gear[i][j] = str[j] - '0' ;
    }

    cin >> N ;
    while(N--)
    {
        cin >> number >> dir ;
        memset(visited, 0, sizeof(visited)) ;
        Spin(number, dir) ;
    }
    
    int answer = 0 ;
    for(int i = 1 ; i < 5 ; i++)
        answer += (gear[i][0] << (i - 1)) ;
    cout << answer ;
}