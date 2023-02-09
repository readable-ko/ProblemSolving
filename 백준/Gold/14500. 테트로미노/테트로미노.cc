#include <iostream>
#include <vector>
#include <algorithm>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int arr[502][502] ;
bool visited[502][502] ;
int plus_arrX[] = {1, -1, 0, 0} ;
int plus_arrY[] = {0, 0, 1, -1} ;
int answer, N, M ;

void InputSetting()
{
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            cin >> arr[i][j] ;
}

void PlusSetting()
{
    for(int row = 1 ; row <= N ; row++)
        for(int col = 1 ; col <= M ; col++)
        {
            int now = 0, sum = arr[row][col] ;
            for(int i = -1 ; i <= 1 ; i+=2)
            {
                sum += arr[row + i][col] ;
                sum += arr[row][col + i] ;
            }

            for(int i = -1 ; i <= 1 ; i+=2)
            {
                now = max(now, sum - arr[row+i][col]);
                now = max(now, sum - arr[row][col+i]);
            }
            answer = max(answer, now) ;
        }
}

void DFS(int deep, int now_sum, int row, int col)
{
    if(deep == 5)
    {
        answer = max(answer, now_sum) ;
        return ;
    }

    for(int k = 0 ; k < 4 ; k++)
    {
        int next_x = row + plus_arrX[k] ;
        int next_y = col + plus_arrY[k] ;
        if(next_x < 1 || next_x > N || next_y < 1 || next_y > M)
            continue ;
        if(visited[next_x][next_y]) continue ;
        
        visited[next_x][next_y] = 1;
        DFS(deep+1, now_sum + arr[row][col], next_x, next_y) ;
        visited[next_x][next_y] = 0;
    }

}

int main()
{
    SETTING ;
    InputSetting() ;
    PlusSetting() ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
        {
            visited[i][j] = 1 ;
            DFS(1, 0, i, j) ;
            visited[i][j] = 0 ;
        }
            
    cout << answer ;
}