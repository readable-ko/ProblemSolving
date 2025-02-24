#include <bits/stdc++.h>
using namespace std;

int N, L, R;
vector<int> land;
vector<int> parent;

int find(int child) {
    if (parent[child] == child) return child;
    return parent[child] = find(parent[child]);  // 경로 압축
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) parent[rootB] = rootA;  // 오른쪽(큰 번호)를 왼쪽(작은 번호)에 연결
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> L >> R;
    land.resize(N * N);
    parent.resize(N * N);

    for (int i = 0; i < N * N; i++) {
        cin >> land[i];
        parent[i] = i;  // 부모를 자기 자신으로 초기화
    }

    int answer = 0;
    while (true) {
        bool flag = false;
        
        // 부모 배열 초기화
        for (int i = 0; i < N * N; i++) parent[i] = i;

        // 가로 연결 (좌우)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                int idx1 = i * N + j;
                int idx2 = i * N + j + 1;
                int diff = abs(land[idx1] - land[idx2]);
                if (L <= diff && diff <= R) {
                    unite(idx1, idx2);
                    flag = true;
                }
            }
        }

        // 세로 연결 (상하)
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int idx1 = i * N + j;
                int idx2 = (i + 1) * N + j;
                int diff = abs(land[idx1] - land[idx2]);
                if (L <= diff && diff <= R) {
                    unite(idx1, idx2);
                    flag = true;
                }
            }
        }

        if (!flag) break;  // 더 이상 연합이 없으면 종료

        // 연합을 그룹화하여 평균값 계산
        vector<vector<int>> merge(N * N);
        for (int i = 0; i < N * N; i++) {
            int p = find(i);
            merge[p].push_back(i);
        }

        // 평균값을 적용
        for (int i = 0; i < N * N; i++) {
            if (!merge[i].empty()) {
                int sum = 0;
                for (int idx : merge[i]) sum += land[idx];
                int avg = sum / merge[i].size();
                for (int idx : merge[i]) land[idx] = avg;
            }
        }

        answer++;
    }

    cout << answer;
}
