#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int v, e;
    cin >> v >> e;
    vector<vector<pii>> barn(v + 1);
    vector<int> dist(v + 1, 0x3f3f3f3f);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < e; i++) {
        int sp, ep, cow;
        cin >> sp >> ep >> cow;
        barn[sp].push_back({ep,cow});
        barn[ep].push_back({sp,cow});
    }
    dist[1] = 0;
    pq.push(make_pair(dist[1], 1));

    while(!pq.empty()) {
        pii front = pq.top(); pq.pop();
        int d = front.first;
        int sp = front.second;

        if(dist[sp] < d) {
            continue;
        }

        for(auto [ep, cost] : barn[sp]) {
            if(d + cost < dist[ep]) {
                dist[ep] = d + cost;
                pq.push(make_pair(dist[ep], ep));
            }
        }
    }

    cout << dist[v] << "\n";
}