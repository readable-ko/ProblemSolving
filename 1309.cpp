#include <iostream>
using namespace std ;
int dp[3] ;

int main()
{
    int N ;
    cin >> N ;
    N++ ;
    dp[0] = 1 , dp[1] = 1 ;
    for(int i = 2 ; i <= N ; i++)
    {
        dp[i % 3] = (dp[(i + 2) % 3] * 2 + dp[(i + 1) % 3]) % 9901 ;
    }
    cout << dp[N % 3] << "\n" ;
}