#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
priority_queue<int> pq ;

void InputSetting()
{
    int N, tmp, answer ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> tmp ;
        if(tmp == 0 && !pq.empty())
        {
            cout << pq.top() << endl ;
            pq.pop() ;
        }
        else if(tmp != 0) pq.push(tmp);
        else cout << 0 << endl ;
    }
}

int main()
{
    SETTING ;
    InputSetting() ;
}