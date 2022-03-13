#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N ;
long long int dp[101][101] ;
int arr[101][101] ;

long long int find_answer(int x, int y)
{
    int next_x = x + arr[x][y] ;
    int next_y = y + arr[x][y] ;

    if(x > N || y > N) return 0 ;
    if(x == N && y == N) return 1 ;
    if(dp[x][y] != -1) return dp[x][y] ;

    dp[x][y] = 0 ;
    dp[x][y] = find_answer(next_x, y) + find_answer(x, next_y) ;
    return dp[x][y] ;
}

void input_setting()
{
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
        {
            cin >> arr[i][j] ;
            dp[i][j] = -1 ;
        }
}

int main()
{
    SETTING ;
    input_setting() ;
    cout << find_answer(1,1) ;
        
}