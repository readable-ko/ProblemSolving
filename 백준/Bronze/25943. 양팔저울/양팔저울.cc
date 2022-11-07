/**
 * This Code is written by gloryko fpqpsxh.
 * ICPC 문제 그냥 조건대로 넣고 1,2,5로 모든 숫자를 그리디하게 표현할 수 있으니
 * 그냥 그리디로 풀자.
**/

#include <bits/stdc++.h>
using namespace std;
int N, tmp, lhs, rhs, answer, sub ;
int chu[] = {1, 2, 5, 10, 20, 50, 100} ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;

    while(N--)
    {
        cin >> tmp ;

        if(lhs == 0) lhs += tmp ;
        else if(lhs == rhs) lhs += tmp ;
        else
            lhs > rhs ? rhs += tmp : lhs += tmp ;
    }

    sub = abs(lhs - rhs) ;
    while(sub)
    {
        for(int i = 6 ; i + 1 ; i--)
        {
            if(chu[i] <= sub)
            {
                sub -= chu[i] ;
                answer++ ;
                break ;
            }
        }
    }

    cout << answer ;
}