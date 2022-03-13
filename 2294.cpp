#include <iostream>
#include <algorithm>
#include <vector>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define I_MAX 30000
using namespace std ;
int dp[10001] ;

int main()
{
    SETTING ;
    fill(&dp[0], &dp[10001], I_MAX) ;
    int N, K ;
    cin >> N >> K ;
    vector<int> arr(N) ;

    for(int &it : arr)
        cin >> it ;
    
    for(int i = 1 ; i <= K ; i++)
    {
        for(int &coin : arr)
        {
            if(i - coin == 0) dp[i] = 1 ;
            else if(i - coin > 0) dp[i] = min(dp[i], (dp[i - coin] + 1)) ;
        }
    }
    dp[K] >= I_MAX ? cout << "-1\n" : cout << dp[K] << "\n" ;
}