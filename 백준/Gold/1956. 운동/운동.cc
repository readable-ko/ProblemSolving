#include <bits/stdc++.h>
using namespace std;

const int INF = 40000001;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int sp, ep, dist, V, E;
    cin >> V >> E;

    vector< vector<int> > village(V+1, vector<int>(V+1, INF));
    

    for(int i = 0; i < E; i++) {
        cin >> sp >> ep >> dist;
        village[sp][ep] = dist;
    }

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            for(int k = 1; k <= V; k++) {
                if(village[i][k] == INF || village[k][j] == INF)
                    continue;
                if(village[i][j] > village[i][k] + village[k][j]) {
                    village[i][j] = village[i][k] + village[k][j];
                }
            }
        }
    }

    int answer = village[0][0];
    for(int i = 1; i < V; i++) {
        answer = min(village[i][i], answer);
    }

     cout << (answer < INF ? answer : -1);
}