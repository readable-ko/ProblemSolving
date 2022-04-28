#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
#define INTMAX 0x3f3f3f3f
using namespace std ;
int N ;
int dp[50001] ;

void DynamicProgramming()
{
    fill(&dp[0],&dp[50001], INTMAX) ;
    dp[0] = 0, dp[1] = 1, dp[2] = 2 ;

    for(int i = 3 ; i <= N ; i++)
    {
        for(int j = 1 ; j*j <= i ; j++)
        {
            dp[i] = min(dp[i], dp[i - (j*j)] + 1) ;
        }
    }
}

void InputSetting()
{
    cin >> N ;
    DynamicProgramming() ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    cout << dp[N] ;
}