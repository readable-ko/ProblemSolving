/**
 * This Code is written by gloryko fpqpsxh.
 * dp라고 생각했는데 100만의 무게에 1000개면 경우의 수가 1억이 넘는다.
 * 그리디일 것인데... 
 * 답지보니까 a[k]가 S[k-1]보다 작거나 같다면 a[k]+S[k-1]까지 모든 수 표현 가능
 * 그렇다면 a[k]가 s[k-1] + 1보다 크면 S[k-1] + 1 증명 불가능!
**/

#include <bits/stdc++.h>
using namespace std ;
int N, S ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> vec(N) ;
    
    for(int &it : vec)
        cin >> it ;
    
    sort(vec.begin(), vec.end()) ;

    for(auto it : vec)
    {
        if(it > S + 1) break ;
        else S += it ;
    }
    
    cout << S + 1 ; 
}