#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(vector<int> lhs, vector<int> rhs)
    {
        return lhs[1] > rhs[1] ;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, now = 0, idx= 0, N = jobs.size() ;
    sort(jobs.begin(), jobs.end(), greater<>()) ;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq ;
    pq.push(jobs.back());
    jobs.pop_back();
    
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        
        now = max(now + top[1], top[0] + top[1]) ;
        answer += now - top[0] ;
        
        while(!jobs.empty() && jobs.back()[0] <= now)
        {
            pq.push(jobs.back()); jobs.pop_back();
        }
        
        if(pq.empty() && !jobs.empty())
        {
            pq.push(jobs.back()); jobs.pop_back();
        }
    }
    return answer / N ;
}