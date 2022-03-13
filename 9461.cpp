#include <iostream>
#include <algorithm>
using namespace std ;
long long int dp[101] ;

int main()
{
    int N, biggest = 0;
    cin >> N ;
    int arr[N] ;
    dp[1] = 1, dp[2] = 1 ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> arr[i] ;
        biggest = max(biggest, arr[i]) ;
    }
    
    for(int i = 3 ; i <= biggest ; i++)
    {
        dp[i] = dp[i-2] + dp[i-3] ;
    }

    for(int i = 0 ; i < N ; i++)
        cout << dp[arr[i]] << "\n";
}