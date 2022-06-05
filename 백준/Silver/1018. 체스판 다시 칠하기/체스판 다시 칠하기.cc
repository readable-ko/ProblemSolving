#include <iostream>
#include <algorithm>
using namespace std ;
int N, M ;
bool arr[51][51] ;
int answer = 0x3f3f3f3f ;

void InputSetting()
{
    string temp ;
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> temp ;
        for(int j = 1 ; j <= M ; j++)
            if(temp[j-1] == 'B') arr[i][j] = 1 ;
    }
}

int main()
{
    InputSetting() ;
    for(int i = 1 ; i <= N - 7 ; i++)
    {
        for(int j = 1 ; j <= M - 7 ; j++)
        {
            bool w_start = 0 ;
            bool b_start = 1 ;
            int max_paint[2] = {0,0} ;
            for(int k = i ; k <= i + 7 ; k++)
            {
                for(int l = j ; l <= j + 7 ; l++)
                {
                    if(arr[k][l] != w_start) max_paint[0]++ ;
                    if(arr[k][l] != b_start) max_paint[1]++ ;
                    w_start = !w_start;
                    b_start = !b_start;
                }
                w_start = !w_start;
                b_start = !b_start;
            }
            answer = min(answer, min(max_paint[0], max_paint[1])) ;
        }
    }
    
    cout << answer ;
}