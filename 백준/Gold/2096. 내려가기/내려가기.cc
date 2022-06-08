#include <bits/stdc++.h>
using namespace std ;
int N ;
int arr[2][5] ;
int maximum[2][5] ;
int minimum[2][5] ;

int main()
{
    cin >> N ;

    for(int i = 1 ; i < 4 ; i++)
    {
        cin >> arr[0][i] ;
        maximum[0][i] = arr[0][i] ;
        minimum[0][i] = arr[0][i] ;
    }

    for(int i = 0 ; i <= 4 ; i+=4)
    {
        minimum[0][i] = 0x3f3f3f3f ;
        minimum[1][i] = 0x3f3f3f3f ;
    }
    
    for(int i = 1 ; i < N ; i++)
    {
        int button = i % 2 ;
        for(int j = 1 ; j <= 3 ; j++)
        {
            cin >> arr[button][j] ;
            maximum[button][j] = max(maximum[!button][j-1], max(maximum[!button][j], maximum[!button][j+1])) + arr[button][j] ; 
            minimum[button][j] = min(minimum[!button][j-1], min(minimum[!button][j], minimum[!button][j+1])) + arr[button][j] ; 
        }
    }

    cout << max(maximum[(N-1) % 2][1], max(maximum[(N-1) % 2][2], maximum[(N-1) % 2][3])) << " " ;
    cout << min(minimum[(N-1) % 2][1], min(minimum[(N-1) % 2][2], minimum[(N-1) % 2][3])) << "\n" ;
}