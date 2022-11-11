/**
 * This Code is written by gloryko fpqpsxh.
 * 그냥 sort시간은 빠듯하니까 pq 2개 만들어서 max min 1개 차이면
 * return해주자.
 * 근데 생각해보니 1000 1 50 이러면 반례생김 오래걸릴거야 그냥 다 더해서 평균내자.
**/

#include <bits/stdc++.h>
using namespace std ;
int N, answer, aver, mod ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> container(N) ;

    for(int &it : container)
    {
        cin >> it ;
        aver += it ;
    }

    mod = aver % N ;
    aver = aver / N ;

    for(int it : container)
        if(it > aver) 
        {
            mod > 0 ? answer += it - aver - 1 : answer += it - aver ;
            mod-- ;
        }
    
    cout << answer ;
}