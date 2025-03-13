#include <bits/stdc++.h>
using namespace std;
int N, Q;
vector<pair<int,int>> video[5001];

void find_recommend_video(int k, int v) {
    int cnt = 0;
    queue<int> q;
    vector<bool> visited(N+1);
    
    visited[v] = 1;
    q.push(v);

    while(!q.empty()) {
        auto val = q.front(); q.pop();
        for(auto [nv, nk] : video[val]) {
            if(!visited[nv] && nk >= k) {
                visited[nv] = 1;
                q.push(nv);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    
    int sp, ep, r;
    for(int i = 0; i < N - 1; i++) {
        cin >> sp >> ep >> r;
        video[sp].push_back({ep, r});
        video[ep].push_back({sp, r});
    }

    int k, v;
    for(int i = 0; i < Q; i++) {
        cin >> k >> v;
        find_recommend_video(k, v);
    }
}