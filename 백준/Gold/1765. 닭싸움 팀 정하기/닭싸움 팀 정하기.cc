#include <bits/stdc++.h>
using namespace std;
vector<int> parent, depth;
vector<vector<int>> enermy;

int find(int c) {
    if(c == parent[c]) {
        return c;
    }

    return parent[c] = find(parent[c]);
}

void merge(int l, int r) {
    int pl = find(l);
    int pr = find(r);
    if(pl == pr) {
        return;
    }
    if(depth[pl] > depth[pr]) {
        parent[pr] = pl;
    } else if(depth[pl] < depth[pr]) {
        parent[pl] = pr;
    } else {
        parent[pr] = pl;
        depth[pl]++;
    }
}

void print() {
    set<int> s;
    for(int i = 1; i < parent.size();i++) {
        s.insert(find(i));
    }
    cout << s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, sp, ep;
    char c;
    cin >> N; cin >> M;
    parent = vector<int>(N+1);
    iota(parent.begin(), parent.end(), 0);
    depth = vector<int>(N+1, 1);
    enermy = vector<vector<int>>(N+1);

    for(int i = 0; i < M; i++) {
        cin >> c >> sp >> ep;
        if(c == 'F') {
            merge(sp, ep);
        } else {
            enermy[sp].push_back(ep);
            enermy[ep].push_back(sp);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int e : enermy[i]) {
            for(int ee : enermy[e]) {
                merge(i, ee);
            }
        }
    }
    print();
}