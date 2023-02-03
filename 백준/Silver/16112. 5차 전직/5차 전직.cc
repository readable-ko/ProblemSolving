/**
 * @file 16112.cpp
 * @author fpqpsxh
 * @brief 그냥 보자마자 그리디더라
 * @date 2023-02-02
 */
#include <bits/stdc++.h>
using namespace std ;
int N, K ;
long long int answer ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> K ;
    int stone[N] ;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> stone[i] ;
    }
    
    sort(stone, stone + N) ;

    for(int i = 0 ; i < N ; i++)
        answer += (long long int)stone[i] * min(i, K) ;

    cout << answer << "\n";
}