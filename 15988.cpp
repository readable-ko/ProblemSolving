#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009
using namespace std ;
long long int dp[1000001];

void find_dp(int N)
{
    if(dp[N] != 0)
    {
        cout << dp[N] << "\n" ;
        return ;
    }
    
    for(int i = 4 ; i <= N ; i++)
    {
        dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD + dp[i-3] % MOD) % MOD ;
    }
    cout << dp[N] << "\n" ;
}

int main()
{
    SETTING ;
    int M, N ;
    cin >>  M ;

    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    for(int i = 0 ; i < M ; i++)
    {
        cin >> N ;
        find_dp(N) ;
    }
}