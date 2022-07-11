#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b)
{
    if(a.second == b.second) return a.first < b.first ;
    return a.second > b.second ;
}

vector<int> solution(int N, vector<int> stages) {
    vector< pair<int, double> > pi(N+2) ;
    vector<int> answer ;
    
    for(int i = 0 ; i <= N+1 ; i++)
    {
        pi[i].first = i ;
        pi[i].second = 0 ;
    }
    
    for(auto it : stages)
        pi[it].second++ ;
    
    int total = 0 ;
    for(int i = N+1 ; i >= 1 ; i--)
    {
        total += pi[i].second ;
        
        if(total == 0) pi[i].second = 0 ;
        else pi[i].second = pi[i].second / total ;
    }
    
    sort(pi.begin()+1, pi.end()-1, comp) ;
    
    for(int i = 1 ; i <= N ; i++)
        answer.push_back(pi[i].first) ;
    
    return answer;
}