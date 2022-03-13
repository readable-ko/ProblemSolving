#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int dp[100001][2] ;
int arr[100001] ;
int N ;

int find_arr(int N)
{
    int maxium = 1 ;

    for(int k = 2 ; k <= N ; k++)
    {
        if(arr[k] >= arr[k-1]) dp[k][0] = dp[k-1][0] + 1 ; 
        if(arr[k] <= arr[k-1]) dp[k][1] = dp[k-1][1] + 1 ;

        maxium = max(maxium , max(dp[k][0], dp[k][1])) ;
    }

    return maxium ;
}

int main()
{
    SETTING ;
    cin >> N ;

    for(int i = 1 ; i <= N ; i++)
        cin >> arr[i] ;

    fill(&dp[0][0], &dp[100000][2], 1) ;

    int answer = find_arr(N) ;
    cout << answer << "\n" ;

}