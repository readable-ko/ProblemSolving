#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int dp[1001] ;
int arr[1001] ;

int main()
{
    SETTING ;
    int N ;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> arr[i] ;
    }

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j < i ; j++)
        {
            if(arr[i] < arr[j]) dp[i] = max(dp[i], dp[j]) ;
        }
        dp[i]++ ;
    }

    cout << *max_element(&dp[0], &dp[1001]) ;
}