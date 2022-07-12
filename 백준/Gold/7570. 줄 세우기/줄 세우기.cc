#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, now, ans = 0;

int main()
{
    SETTING ;
    cin >> N ;
    vector<int> chk(N+1) ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> now ;
        (chk[now - 1] != 0) ? chk[now] = chk[now - 1] + 1 : chk[now]++ ;
        ans = max(ans, chk[now]) ;
    }

    cout << N - ans ;
}