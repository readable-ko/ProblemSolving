#include <bits/stdc++.h>
using namespace std;
vector<bool> visited ;

void BFS(vector<vector<int>> computers, int idx) {
    queue<int> que ;
    for(int i = 0 ; i < computers[idx].size() ; i++)
    {
        int curr_idx = computers[idx][i];
        if(!visited[i] && curr_idx) que.push(i) ;
    }
    
    while(!que.empty())
    {
        int top = que.front() ;
        que.pop() ;
        
        for(int i = 0 ; i < computers[top].size() ; i++)
        {
            int curr = computers[top][i] ;
            if(!visited[i] && curr)
            {
                visited[i] = 1 ;
                que.push(i) ;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited = vector<bool>(computers.size()) ;
    
    for(int i = 0 ; i < computers.size() ; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1 ;
            BFS(computers, i) ;
            answer++ ;
        }
    }
    return answer;
}