#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N, K, temp ;

int main()
{
    SETTING ;
    cin >> N >> K ;

    while(N--)
    {
        cin >> temp ;
        while((temp & 1) == 0)
        {
            temp= (temp >> 1) ;
            K-- ;
        }
    }
    
    K <= 0 ? cout << "1\n" : cout << "0\n" ;
    return 0 ;
}