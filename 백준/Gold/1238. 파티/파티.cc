#include <bits/stdc++.h>
using namespace std;
int answer, N, M, X;
vector< vector<int> > village;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);    
    cin >> N >> M >> X;

    vector< vector<int> > village(N+1, vector<int>(N+1, 0));
    vector< vector<int> > dist(N+1,vector<int>(N+1, 0x3f3f3f3f));

    for (int i = 0 ; i < M ; i++) {
        int sp, ep, time;
        cin >> sp >> ep >> time;
        village[sp][ep] = time;
    }

    for(int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else if(village[i][j]) dist[i][j] = village[i][j];
            else dist[i][j] = 0x3f3f3f3f;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N ; i++) {
        answer = max(dist[i][X] + dist[X][i], answer);
    }
    cout << answer;
}