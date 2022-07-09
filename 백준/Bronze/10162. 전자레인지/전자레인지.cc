#include <bits/stdc++.h>
using namespace std ;
int T, arr[2][3] = {{300, 60, 10}, {0, 0, 0}};

int main()
{
    cin >> T ;
    
    for(int i = 0 ; i < 3 ; i++)
    {
        if(T / arr[0][i] <= 0) continue ;
        arr[1][i] = T / arr[0][i] ;
        T = T % arr[0][i] ;
    }

    if(T != 0) cout << "-1" ;
    else
        for(int i = 0 ; i < 3 ; i++) cout << arr[1][i] << " " ;
}