#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int N, K ;
int dp[200002] ;

int main()
{
    SETTING ;
    cin >> N >> K ;
    
    for(int i = N ; i >= 0 ; i--)
    {
        dp[i] = N - i ;
    }

    for(int i = N + 1 ; i <= K ; i++)
    {
        i & 1 ? dp[i] = min(dp[i / 2] + 2, dp[(i + 1) / 2] + 2) : dp[i] = dp[i/2] + 1 ;
        dp[i] = min(dp[i-1] + 1, dp[i]) ;
    }

    cout << dp[K] ;
}