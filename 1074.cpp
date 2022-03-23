#include <bits/stdc++.h>
#include <math.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int N, R, C, answer ;

void DivideAndConquer(int N, int R, int C)
{
    if(N == 1) return ;

    if(R < N / 2)
    {
        if(C < N / 2)
            DivideAndConquer(N / 2, R, C) ;
        else
        {
            answer += pow(N/2, 2) ;
            DivideAndConquer(N / 2, R, C - (N / 2)) ;
        }
    }
    else
    {
        if(C < N / 2)
        {
            answer += (pow(N/2, 2) * 2) ;
            DivideAndConquer(N / 2, R - (N / 2), C) ;
        }
        else
        {
            answer += (pow(N/2, 2) * 3) ;
            DivideAndConquer(N / 2, R - (N / 2), C - (N / 2)) ;
        }
    }
}

int main()
{
    SETTING ;
    cin >> N >> R >> C ;
    DivideAndConquer((1 << N), R, C) ;
    cout << answer ;
}