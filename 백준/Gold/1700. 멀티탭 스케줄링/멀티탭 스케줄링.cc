/**
 * This Code is written by gloryko fpqpsxh.
 * Memory Replacement Algorithm에서 optimal한 방법이 뒤에 올 것이 무엇인지
 * 알 수 없어서 적용하지 못하지만 여기서는 적용이 가능하다
 * 가지고 있는 것들 중에 더 일찍 재사용 될 친구를 찾으면 된다.
 * 각각 큐에 넣고 계산하면 되지 않겠어?
**/

#include <bits/stdc++.h>
using namespace std ;
int hole, item, temp, answer ;

int main()
{
    cin >> hole >> item ;
    int arr[item+1] ;
    queue<int> que[item+1] ;
    vector<int> lotate ;

    for(int i = 0 ; i < item ; i++)
    {
        cin >> temp ;
        arr[i] = temp ;
        que[temp].push(i) ;
    }

    for(int i = 0 ; i < item ; i++)
    {
        if(lotate.size() < hole)
        {
            bool flag = 1 ;
            for(int it : lotate)
            {
                if(it == arr[i])
                {
                    flag = 0 ; break ;
                }
            }
            if(flag) lotate.push_back(arr[i]) ;
        }
        else 
        {
            bool flag = 0 ;
            int out = 0 ;
            for(int j = 0 ; j < lotate.size() ; j++)
            {
                int now = lotate[j] ;
                if(now == arr[i])
                {
                    flag = 1 ; break ;
                }
                else
                {
                    if(que[lotate[out]].empty()) continue ;
                    if(que[now].empty() || que[now].front() > que[lotate[out]].front())
                        out = j ;
                }
            }

            if(!flag)
            {
                answer++ ;
                lotate[out] = arr[i] ;
            }
        }

        que[arr[i]].pop() ;
    }

    cout << answer ;
}