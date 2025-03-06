#include <bits/stdc++.h>
using namespace std;
int N, M, val;
vector<vector<bool>> city;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N; cin >> M;
    city = vector<vector<bool>>(N, vector<bool>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> val;
            city[i][j] = val;
        }
        city[i][i] = 1;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!city[i][j] & city[i][k] & city[k][j]) {
                    city[i][j] = 1;
                }
            }
        }
    }

    vector<int> visit(M);
    for(int i = 0; i < M; i++) {
        cin >> visit[i];
    }

    bool possible = true;
    for(int i = 1; i < M; i++) {
        int sp = visit[i - 1] - 1;
        int ep = visit[i] - 1;
        if(!city[sp][ep]) {
            possible = false;
            break;
        }
    }

    possible ? cout << "YES\n" : cout << "NO\n";
}