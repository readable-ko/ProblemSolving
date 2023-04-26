#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> scores) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq ;
    
    for(int score : scores)
    {
        if(pq.empty() || pq.size() < k) pq.push(score) ;
        else if(pq.top() < score)
        {
            pq.pop() ;
            pq.push(score);
        }
        answer.emplace_back(pq.top()) ;
    }
    return answer;
}