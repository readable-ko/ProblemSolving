#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, now, ans ;
bool arr[1000002] ;

int main()
{
    SETTING ;
    cin >> N ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> now ;
        if(arr[i] != now)
        {
            ans++ ;
            for(int j = 0 ; j < 3 ; j++)
                arr[i + j] = !arr[i + j] ;
        }
        
    }

    cout << ans ;
}