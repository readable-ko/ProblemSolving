#include <bits/stdc++.h>
using namespace std ;
priority_queue<int, vector<int>, less<int> > pq ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    int N, K, tmp ;
    cin >> N >> K ;

    while(N--)
    {
        cin >> tmp ;
        if(pq.size() < K) pq.push(tmp) ;
        else if(tmp < pq.top())
        {
            pq.pop() ; pq.push(tmp) ;
        }
    }

    cout << pq.top() ;
}