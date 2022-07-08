#include <iostream>
#include <map>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int x_arr[] = {1, -1, 0, 0} ;
int y_arr[] = {0, 0, 1, -1} ;
char arr[6][6] ;
string tmp ;
map<string, int> answer ;

void DFS(int i, int j, string tmp)
{
    if(tmp.length() == 6)
    {
        answer[tmp] = 1 ;
        return ;
    }

    for(int k = 0 ; k < 4 ; k++)
    {
        int x_new = x_arr[k] + i ;
        int y_new = y_arr[k] + j ;
        if(x_new < 1 || y_new < 1 || x_new > 5 || y_new > 5) continue ;
        
        if(tmp.length() != 6) DFS(x_new, y_new, tmp + arr[x_new][y_new]) ;
    }
}

int main()
{
    for(int i = 1 ; i < 6 ; i++)
        for(int j = 1 ; j < 6 ; j++)
            cin >> arr[i][j] ;

    for(int i = 1 ; i < 6 ; i++)
        for(int j = 1 ; j < 6 ; j++)
        {
            DFS(i, j, tmp) ;
            tmp = "" ;
        }

    cout << answer.size() ;
}