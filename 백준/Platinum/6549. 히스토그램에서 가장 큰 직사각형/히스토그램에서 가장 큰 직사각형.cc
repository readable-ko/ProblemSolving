/**
 * number 6549
 * @author fpqpsxh
 * @date 2022-11-20 ~ 2022-11-28
 * @brief 며칠 고민하던 분할 정복 완전 정복
 * 일단 왼쪽 오른쪽 나눠 진행하는 건 쉬운데 Merge가 문제다.
 * lhs rhs mid 중 max를 취하는데 mid는 가운데부터 쭈욱 늘려보면 되지 않을까?
 */

#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B,C) ((A >= B && A >= C) ? (A) : ((B >= A && B >= C) ? (B) : (C)))
using namespace std ;
vector<int> hist ;
int N ;

ll int find_mid_max(int sp, int mid, int ep)
{
    int height = hist[mid] ;
    int lhs = mid - 1 ;
    int rhs = mid + 1 ;
    int width = 1 ;
    ll int local_max = width * height ;

    while(lhs >= sp || rhs <= ep)
    {
        if(lhs < sp)
            height = min(height, hist[rhs++]) ;
        else if(rhs > ep)
            height = min(height, hist[lhs--]) ;
        else if(hist[lhs] > hist[rhs])
            height = min(height, hist[lhs--]) ;
        else
            height = min(height, hist[rhs++]) ;
        
        local_max = max(local_max, (ll int)(++width) * height) ;
    }

    return local_max ;
}

ll int find_div_and_con(int sp, int ep)
{
    if(sp == ep) return hist[sp] ;

    //만약 왼쪽 끝자락이 포함되지 않는다면 rhs에서 정답을 찾았을 것이고
    //포함된다면 최대한 greedy하게 포함하면서 모든 사각형을 훑어보면 될 것이다.
    int mid = (sp + ep) / 2 ;
    ll int local_max = max(find_mid_max(sp, mid, ep), max(find_div_and_con(sp, mid), find_div_and_con(mid + 1, ep)));

    return local_max ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    while(1)
    {
        cin >> N ;
        
        if(N == 0) break ;
        hist.clear() ;
        hist.resize(N) ;

        for(int &it : hist)
            cin >> it ;
        
        cout << find_div_and_con(0, N - 1) << "\n" ;
    }
}