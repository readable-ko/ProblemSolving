#include <bits/stdc++.h>
using namespace std ;
int N, x, y, now = 0x3f3f3f3f ;

int main()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> x >> y ;
        if(y - x >= 0 && y < now)
            now = y ;
    }
    now != 0x3f3f3f3f ? cout << now : cout << "-1" ;
}