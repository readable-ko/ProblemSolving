// This Code is written by gloryko fpqpsxh.
#include <iostream>
#include <vector>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std ;
int N, arr[1001], dp[1001], gusanr ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> arr[i] ;
        dp[i] = arr[i] ;
    }
    gusanr = dp[0] ;

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
            if(arr[i] < arr[j]) dp[i] = MAX(dp[j] + arr[i], dp[i]) ;

        gusanr = MAX(gusanr, dp[i]) ;
    }
    cout << gusanr ;
}