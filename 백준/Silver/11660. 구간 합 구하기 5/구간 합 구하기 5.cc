#include <iostream>
#include <unistd.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, M ;
int arr[1025][1025], saved[1025][1025][2] ;
int x[2], y[2] ;

void DP()
{
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
        {
            saved[i][j][0] = saved[i][j-1][0] + arr[i][j] ;
            saved[i][j][1] = saved[i][j-1][0] + saved[i-1][j][1] + arr[i][j] ;
        }
}

void InputSetting()
{
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> arr[i][j] ;
    
    DP() ;
    while(M--)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1] ;
        int answer = saved[x[1]][y[1]][1] + saved[x[0]-1][y[0]-1][1] ;
        answer -= saved[x[1]][y[0]-1][1] + saved[x[0]-1][y[1]][1] ;
        cout << answer << "\n" ;
    }
}

int main()
{
    SETTING ;
    InputSetting() ;
}