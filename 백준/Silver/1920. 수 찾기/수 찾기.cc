/**
 * @file 1920
 * @author fpqpsxh
 * @brief 그냥 10만개 솔트 Nlog(N) 2번이면 오바되고
 *        하나 솔트하고 이분탐색하는 방법 귀찮아서 map으로 되나 짜봤다.
 * @date 2023-01-10
 */
#include <bits/stdc++.h>
using namespace std ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    int N, M, tmp ;
    map<int, bool> mp ;
    cin >> N ;
    while(N--)
    {
        cin >> tmp ;
        mp[tmp] = true ;
    }

    cin >> M ;
    while(M--)
    {
        cin >> tmp ;
        cout << mp[tmp] << "\n" ;
    }
}