#include <bits/stdc++.h>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int main()
{
    SETTING ;
    int N, temp ;
    priority_queue<int, vector<int>, greater<int>> pq ;
    cin >> N ;

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            cin >> temp ;
            pq.push(temp) ;
        }

        while(pq.size() != N)
            pq.pop() ;
    }

    cout << pq.top() ;
}