#include <iostream>
#include <vector>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int M, N ;
int dp[501][501] ;
int arr[501][501] ;

int find_path(int x , int y)
{
    int x_way[] = {1, 0, -1, 0} ;
    int y_way[] = {0, 1, 0, -1} ;

    if(x == M && y == N) return 1 ;
    if(dp[x][y] != -1) return dp[x][y] ;
    dp[x][y] = 0 ;
    
    for(int i = 0 ; i < 4 ; i++)
    {
        int next_x = x + x_way[i] ;
        int next_y = y + y_way[i] ;

        if(next_x > 0 && next_x <= M && next_y > 0 && next_y <= N)
            if(arr[next_x][next_y] < arr[x][y])
                dp[x][y] += find_path(next_x, next_y) ;
    }
    return dp[x][y] ;
}

void input_setting()
{
    cin >> M >> N ;
    for(int i = 1 ; i <= M ; i++)
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
    cout << find_path(1, 1) << "\n" ;
    return 0 ;
}