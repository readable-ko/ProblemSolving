#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N ;
int x_arr[] = {1, -1, 0, 0} ;
int y_arr[] = {0, 0, 1, -1} ;
char arr[101][101] ;
bool rgbvisited[101][101] ;

void InputSetting()
{
    cin >> N ;
    string tmp ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> tmp ;
        for(int j = 0 ; j < tmp.length(); j++)
            arr[i][j+1] = tmp[j] ;
    }
}

void RGBFS(int row, int col)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        int xnew = row + x_arr[i] ;
        int ynew = col + y_arr[i] ;
        if(rgbvisited[xnew][ynew]) continue ;
        if(arr[xnew][ynew] != arr[row][col]) continue ;
        rgbvisited[xnew][ynew] = 1 ;
        RGBFS(xnew, ynew) ;
    }

    return ;
}

int BFS()
{
    int sector = 0 ;
        for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
        {
            if(!rgbvisited[i][j])
            {
                rgbvisited[i][j] = 1 ;
                sector++ ;
                RGBFS(i, j) ;
            }
        }
    return sector ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    int realsec = 0, dissec = 0 ;

    realsec = BFS() ;
    
    memset(rgbvisited, 0, sizeof(rgbvisited)) ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            if(arr[i][j] == 'G') arr[i][j] = 'R' ;

    dissec = BFS() ;
        
    cout << realsec << " " << dissec ;
}