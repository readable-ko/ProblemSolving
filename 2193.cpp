#include <iostream>
using namespace std ;
long long int dp[2][2] ;
int main()
{
    long long int N ;
    int C = 1 ;
    cin >> N ;
    dp[0][1] = 1, dp[1][0] = 1 ;
    for(int i = 3 ; i <= N ; i++)
    {
        C = !C ;
        dp[C][0] = dp[!C][0] + dp[!C][1] ;
        dp[C][1] = dp[!C][0] ;
    }
    cout << dp[C][0] + dp[C][1] ;
}