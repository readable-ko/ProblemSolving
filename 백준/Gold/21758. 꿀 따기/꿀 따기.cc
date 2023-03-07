/**
 * @file 21758.cpp
 * @author fpqpsxh
 * @date 2023-02-15
 * 
 */
#include <bits/stdc++.h>
using namespace std ;
int N, answer ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;

    cin >> N ;
    vector<int> sum(N), barrel(N) ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> barrel[i] ;
        (i != 0) ? sum[i] = sum[i-1] + barrel[i] : sum[i] = barrel[i] ;
    }

    for(int i = 1 ; i < N - 1 ; i++)
    {
        //꿀통이 가운데 있는 경우
        answer = max(answer, sum[N - 2] - barrel[0] + barrel[i]) ;

        //꿀통이 왼쪽에 있는 경우
        answer = max(answer, sum[N - 2] + sum[i] - 2 * barrel[i]) ;
        
        //꿀통이 오른쪽에 있는 경우
        answer = max(answer, sum[N - 1] - barrel[0] - barrel[i] + (sum[N - 1] - sum[i])) ;
    }
    cout << answer ;
}