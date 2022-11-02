/**
 * This Code is written by gloryko fpqpsxh.
 * 그냥 제일 먼곳 갈 때 그 다음으로 먼 근처 가면 안되나..?
 * 돌아와야하니까 맨 마지막에 제일 절대값이 먼 곳으로 다녀오고.
 * 최대값도 int 범위네!
**/

#include <bits/stdc++.h>
using namespace std;
int book, power, tmp, answer ;

int main()
{
    cin >> book >> power ;
    vector<int> plus_box, minus_box ;

    for(int i = book ; i ; i--)
    {
        cin >> tmp ;
        tmp > 0 ? plus_box.push_back(tmp) : minus_box.push_back(tmp) ;
    }

    sort(plus_box.begin(), plus_box.end()) ;
    sort(minus_box.begin(), minus_box.end(), greater<int>()) ;

    tmp = 0 ;
    if(!plus_box.empty()) tmp = plus_box.back() ;
    if(!minus_box.empty()) tmp = max(tmp, -minus_box.back()) ;
    answer -= tmp ;

    while(!plus_box.empty())
    {
        answer += plus_box.back() * 2 ;
        for(int i = 0 ; i < power ; i++)
            if(!plus_box.empty()) plus_box.pop_back() ;
    }

    while(!minus_box.empty())
    {
        answer -= minus_box.back() * 2 ;
        for(int i = 0 ; i < power ; i++)
            if(!minus_box.empty()) minus_box.pop_back() ;
    }

    cout << answer ;
}