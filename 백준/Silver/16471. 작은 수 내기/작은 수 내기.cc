/**
 * @file 16471.cpp
 * @author fpqpsxh
 * @date 2023-01-31
 * @brief dp이면 까다롭겠다 하고 문제를 읽어보니 그냥 그리디
 * 단지 index 2개를 사용해야한다는게 조금 귀찮은 문제이다.
 **/
#include <bits/stdc++.h>
using namespace std;
int N, i, j ;

int main()
{
    ios::sync_with_stdio(0) ;
    cin >> N ;
    vector<int> a(N), b(N) ;
    
    for(int &it : a) cin >> it ;
    for(int &it : b) cin >> it ;

    sort(a.begin(), a.end()) ;
    sort(b.begin(), b.end()) ;

    for( ; i < N ; i++)
    {
        if(j * 2 >= N + 1) break ;
        if(a[j] < b[i]) j++ ;
    }

    (j * 2 >= N + 1) ? cout << "YES\n" : cout << "NO\n" ;
}