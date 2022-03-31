#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

struct comp{
    bool operator()(int x, int y)
    {
        return x > y ;
    }
};
priority_queue<int, vector<int>, comp> pq ;
int main()
{
    SETTING ;
    int T, N ;
    cin >> T ;
    while(T--)
    {
        cin >> N ;
        if(N) pq.push(N) ;
        else
        {
            pq.empty() ? cout << "0\n" : cout << pq.top() << "\n" ;
            if(!pq.empty()) pq.pop() ;
        }
    }
}