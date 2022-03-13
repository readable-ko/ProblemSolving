#include <iostream>
#include <algorithm>
#include <iomanip>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define COIN_MAX 100001
using namespace std ;

int main()
{
    SETTING ;
    int N ;
    cin >> N ;
    int dp[N+1] ;
    fill(&dp[0], &dp[N+1], COIN_MAX) ;
    dp[2] = 1, dp[4] = 2, dp[5] = 1 ;

    for(int i = 6 ; i <= N ; i++)
    {
        dp[i] = min(dp[i-2], dp[i-5]) + 1 ;
    }

    dp[N] >= 100001 ? cout << "-1\n" : cout << dp[N] << "\n" ;
}