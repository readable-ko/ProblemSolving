#include <bits/stdc++.h>
using namespace std;
int test_case, N;

class Vertax {
    public:
        int x;
        int y;
        int d;
        Vertax() : x(0), y(0), d(0) {}
        Vertax(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

struct comp {
    bool operator()(const Vertax &l, Vertax &r) {
        return l.d > r.d;
    }
};

void findMinPath(int idx, vector<vector<int>> &cave) {
    vector<vector<int>> dist(N, vector<int>(N, 0x3f3f3f3f));
    priority_queue<Vertax, vector<Vertax>, comp> pq;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

    dist[0][0] = cave[0][0];
    pq.push(Vertax(0,0, dist[0][0]));

    while(!pq.empty()) {
        Vertax v = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++) {
            Vertax nv = Vertax();
            nv.x = v.x + dx[i];
            nv.y = v.y + dy[i];

            if(nv.x < 0 || nv.x >= N || nv.y < 0 || nv.y >= N) {
                continue;
            }
            nv.d = dist[v.x][v.y] + cave[nv.x][nv.y];
            if(dist[nv.x][nv.y] > nv.d) {
                dist[nv.x][nv.y] = nv.d;
                pq.push(nv);
            }
        }
    }
    cout << "Problem " << idx << ": " << dist[N - 1][N - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int times = 1;
    while(true) {
        cin >> N;
        if(N == 0) break;
        vector<vector<int>> cave(N, vector<int>(N));
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }
        
        findMinPath(times++, cave);
    }
}