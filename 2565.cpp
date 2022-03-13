#include <bits/stdc++.h>
using namespace std ;
int arr[501] ;
int dp[501] ;

int main()
{
    int N, num1, num2 ;
    cin >> N ;

    for(int i = 1 ; i <= N ; i++)
    {
        cin >> num1 >> num2 ;
        arr[num1] = num2 ;
    }

    for(int i = 1 ; i <= 500 ; i++)
    {
        if(arr[i] == 0) continue ;
        for(int j = 1 ; j <= i - 1 ; j++)
        {
            if(arr[j] == 0) continue ;
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]) ;
        }
        dp[i]++ ;
    }

    cout << N - *max_element(&dp[0], &dp[501]) ;
}

/*
9
1 101
50 102 
101 103
105 30
106 40
107 50
110 60
200 200
500 500
===========
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
===========
5
1 3
2 1
3 5
4 2
5 4
 */