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
    int answer = 0, now = 0, idx= 0 ;
    sort(jobs.begin(), jobs.end()) ;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq ;
    
    while(!pq.empty() || idx < jobs.size())
    {
        if(idx < jobs.size() && now >= jobs[idx][0])
        {
            pq.push(jobs[idx++]);
            continue ;
        }
        
        if(!pq.empty())
        {
            now += pq.top()[1] ;
            answer += now - pq.top()[0] ;
            pq.pop() ;
        }
        else
        {
            now = jobs[idx][0] ;
        }
    }
    return answer / jobs.size() ;
}