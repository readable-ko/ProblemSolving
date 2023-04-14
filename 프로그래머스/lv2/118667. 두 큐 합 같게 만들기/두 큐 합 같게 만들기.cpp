#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long long lhs_sum = 0, rhs_sum = 0 ;
    queue<int> que1, que2 ;
    for(int num : queue1)
    {
        lhs_sum += num ;
        que1.push(num) ;
    }
    for(int num : queue2)
    {
        rhs_sum += num ;
        que2.push(num) ;
    }
    
    if((lhs_sum +rhs_sum) & 1 == 1) return -1 ;
    
    int cnt = 0 ;
    while(!que1.empty() && !que2.empty())
    {
        if(cnt > (que1.size() + que2.size())*2) return -1 ;
        if(lhs_sum == rhs_sum) return cnt ;
        if(lhs_sum > rhs_sum)
        {
            int front = que1.front() ;
            lhs_sum -= front ;
            rhs_sum += front ;
            que2.push(front) ;
            que1.pop() ;
            cnt++ ;
        }
        else
        {
            int front = que2.front() ;
            rhs_sum -= front ;
            lhs_sum += front ;
            que1.push(front) ;
            que2.pop() ;
            cnt++ ;
        }
    }
    return -1;
}