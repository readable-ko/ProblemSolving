#include <bits/stdc++.h>
using namespace std ;
int rcnt, ccnt;

void Make(int &a, int &rr)
{
    while(a % 4 != 0)
    {
        a++ ;
        rr++ ;
    }
}

int main()
{
    int N, M ;
    cin >> N >> M ;
    Make(N, rcnt) ;
    Make(M, ccnt) ;

    int answer = abs(M - N) / 4 + abs(rcnt - ccnt) ;
    cout << answer ;
}