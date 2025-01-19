#include <bits/stdc++.h>
using namespace std;
int mid = 0x3f3f3f3f;
priority_queue<int, vector<int>, greater<int>> max_pq; //큰 집합 중 최소
priority_queue<int, vector<int>, less<int>> min_pq; //작은 집합 중 최대

void reBranching() {
    if(max_pq.size() > min_pq.size()) {
        min_pq.push(max_pq.top());
        max_pq.pop();
    } else if(max_pq.size() + 1 < min_pq.size()) {
        max_pq.push(min_pq.top());
        min_pq.pop();
    }
    mid = min_pq.top();
}

void pushNumber(int num) {
    if(num <= mid) {
        min_pq.push(num);
    } else {
        max_pq.push(num);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, num;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        pushNumber(num);
        reBranching();
        cout << mid << "\n";
    }
}