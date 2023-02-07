/**
 * @file 9613.cpp
 * @author fpqpsxh
 * @brief 그냥 보자마자 gcd로 풀어야하는 문제더라
 * @date 2023-02-07
 */
#include <bits/stdc++.h>
using namespace std ;
int T, N, num ;
long long sum ;

int gcd(int lhs, int rhs)
{
    if(rhs == 0) return lhs ;
    return gcd(rhs, lhs % rhs) ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> T ;

    while(T--)
    {
        cin >> N ;
        sum = 0 ;
        vector<int> arr(N) ;

        for(int &it : arr)
            cin >> it ;
        
        for(int i = 0 ; i < N ; i++)
            for(int j = i + 1 ; j < N ; j++)
                sum += gcd(arr[i], arr[j]) ;

        cout << sum << '\n' ;
    }
}