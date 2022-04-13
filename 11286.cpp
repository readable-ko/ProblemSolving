#include <bits/stdc++.h>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;

struct compare
{
    bool operator() (int &x, int &y)
    {
        if(abs(x) == abs(y)) return x > y ;
        return abs(x) > abs(y) ;
    }
};

int N, X ;
priority_queue<int, vector<int>, compare> pq ;

int main()
{
    SETTING ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> X ;
        if(!X)
        {
            pq.empty() ? cout << "0\n" : cout << pq.top() << endl ;
            if(!pq.empty()) pq.pop() ;
        }
        else pq.push(X) ;
    }
}