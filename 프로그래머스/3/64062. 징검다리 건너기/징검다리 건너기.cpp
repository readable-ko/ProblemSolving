#include <bits/stdc++.h>
using namespace std;

class stone {
public:
    int count;
    int index;
    stone(int i, int c){count=c, index=i;}
};

struct cmp
{
    bool operator()(stone a, stone b) {
        if(a.count == b.count) a.index > b.index;
        return a.count < b.count;
    }
};

int solution(vector<int> stones, int k) {
    int answer = 200000000;
    priority_queue<stone, vector<stone>, cmp> pq;
    
    for (int i = 0 ; i < stones.size() ; i++) {
        while (!pq.empty() && pq.top().index + k < i) {
            pq.pop();
        }
        if(pq.size() >= k) {
            answer = min(answer, pq.top().count);
        }
        pq.push(stone(i, stones[i]));
    }

    if(pq.size() >= k) {
        pq.pop();
        answer = min(answer, pq.top().count);
    }
    return answer;
}