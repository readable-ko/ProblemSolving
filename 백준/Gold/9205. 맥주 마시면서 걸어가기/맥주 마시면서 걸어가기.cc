#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int test_cases, store_cnt;

    cin >> test_cases;

    while(test_cases--) {
        bool visited[100];
        memset(visited, 0, 100);
        pair<int, int> store, sp, ep;
        vector< pair<int, int> > store_point;

        cin >> store_cnt;
        cin >> sp.first >> sp.second;

        for(int i = 0;  i < store_cnt; i++) {
            cin >> store.first >> store.second;
            store_point.push_back(store);
        }

        cin >> ep.first >> ep.second;

        queue<pair<int,int>> q;
        q.push(sp);
        while(!q.empty()) {
            pair<int, int> pos = q.front(); q.pop();
            if(abs(ep.first - pos.first) + abs(ep.second - pos.second) <= 1000) {
                q.push(sp);
                break;
            }

            for(int i = 0; i < store_cnt; i++) {
                if(visited[i])
                    continue;
                
                if(abs(store_point[i].first - pos.first) + abs(store_point[i].second - pos.second) <= 1000) {
                    q.push(store_point[i]);
                    visited[i] = true;
                }
            }
        }

        q.empty() ? cout << "sad\n" : cout << "happy\n";
    }
}