//https://wootool.tistory.com/83
#include <bits/stdc++.h>
using namespace std ;
int dp[501][501] ;
int graph[501][501] ;
int M, N ;

int find(int horiz, int verti)
{
    if(horiz == M && verti == N) return 1 ;
    if(horiz > M || verti > N || horiz < 1 | verti < 1) return 0 ;

    int x_asis[5] = { 1, 0, -1, 0 } ;
    int y_asis[5] = { 0, 1, 0, -1 } ;
    for(int i = 0 ; i <= 4 ; i++)
    {
        if(graph[horiz][verti] > graph[horiz + x_asis[i]][verti + y_asis[i]]) dp[horiz][verti] += find(horiz + x_asis[i], verti + y_asis[i]) ;
    }
    return dp[horiz][verti] ;
}

int main()
{
    cin >> M >> N ;
    
    //fill(&dp[0][0], &dp[500][501], -1) ;
    dp[M][N] = 1 ;
    for(int i = 1 ; i <= M ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> graph[M][N] ;
    
    dp[0][0] = find(M, N) ;
    cout << dp[0][0] ;
}