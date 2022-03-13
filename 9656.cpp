#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
bool dp[1001] ;
int N ;

void find_answer()
{
    for(int i = 4 ; i <= N ; i++)
        dp[i] = !dp[i-1] || !dp[i-3] ;
}

int main()
{
    // SK win == 1 CY win == 0
    SETTING ;
    cin >> N ;
    dp[2] = 1, dp[4] = 1 ;
    find_answer() ;
    dp[N] ? cout << "SK\n" : cout << "CY\n" ;
}