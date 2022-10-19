/**
 * This Code is written by gloryko fpqpsxh.
 * 그냥... sort하고 0아닌 양수끼리 음수끼리 묶어서 큰거부터 곱하고 더하면 되는거 아닌가./
 * -1 0 1이 반례가 되었다...
 * -5 -4 -1 0 5 10 = 70이 정답이 되어야지
 * 그럼 양수 음수 나눠서 양쪽으로 진행하자! 투 포인터는 설계하기 어려우니까 그냥 쪼개서 받자!
 * 정답은 2^31이지만 2^31이 넘었다가 줄어드는 걸 수 있으니 long long으로
**/

#include <bits/stdc++.h>
using namespace std ;
long long int answer ;
int N, has_zero ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> vec(N), positive, negative ;

    for(int &it : vec)
    {
        cin >> it ;
        if(it == 0)
        {
            has_zero = 1 ;
            continue ;
        }
        it > 0 ? positive.push_back(it) : negative.push_back(it) ;
    }

    sort(positive.begin(), positive.end()) ;
    sort(negative.begin(), negative.end()) ;
    if(has_zero) negative.push_back(0) ;

    for(int i = positive.size() - 1 ; i > 0 ; i-=2)
    {
        if(positive[i] == 1 || positive[i-1] == 1) answer += positive[i] + positive[i-1] ;
        else answer += positive[i] * positive[i-1] ;
    }
    
    for(int i = 0 ; i < (int)negative.size() - 1 ; i+=2)
        answer += negative[i] * negative[i+1] ;

    if(positive.size() & 1) answer += positive[0] ;
    if(negative.size() & 1) answer += negative[negative.size() - 1] ;
    cout << answer ;
}