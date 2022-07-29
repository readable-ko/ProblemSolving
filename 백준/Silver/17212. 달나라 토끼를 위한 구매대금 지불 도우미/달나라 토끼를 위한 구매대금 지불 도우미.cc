#include <iostream>
#include <vector>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std ;
int pay[] = {1,2,5,7} ;
int N, dp[100001] ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        dp[i] = 0x3f3f3f3f ;
        if(i == 1 || i == 2 || i == 5 || i ==7)
            dp[i] = 1 ;
    }

    for(int i = 3 ; i <= N ; i++)
        for(int j = 0 ; j < 4 ; j++)
            if(i - pay[j] >= 0)
                dp[i] = MIN(dp[i - pay[j]] + 1, dp[i]) ;
    
    cout << dp[N] ;
}