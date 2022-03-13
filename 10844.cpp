#include <iostream>
#define MOD 1000000000
using namespace std ;
long long int dp[101][10] ;

int main()
{
    int N ;
    long long int answer = 0 ;
    cin >> N ;
    fill(&dp[1][1], &dp[1][10], 1) ;

    for(int i = 2 ; i <= N ; i++)
    {
        for(int j = 0 ; j <= 9 ; j++)
        {
            if(j == 0) dp[i][j] = dp[i-1][j+1] % MOD ;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % MOD ;
            else dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1]) % MOD ;
        } 
    }
    
    for(int i = 0 ; i < 10 ; i++)
    {
        answer += dp[N][i] ;
    }
    cout << answer % MOD;
}