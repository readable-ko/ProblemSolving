#include <iostream>
#define MOD 10007
using namespace std ;
int dp[1001] ;

int main()
{
    int N ;
    cin >> N ;
    dp[1] = 1, dp[2] = 3 ;
    
    for(int i = 3 ; i <= N ; i++)
    {
        dp[i] = (2 * dp[i-2] + dp[i-1]) % MOD ;
    }
    
    cout << dp[N] ;
}