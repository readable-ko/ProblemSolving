#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
    /**
    [방법 1]
    1. 256개의 방문 지도 만들기
    2. K번째 cctv의 경우 4^(K-1)의 배수 마다 다른 방향으로 보여주기.
    3. 그 방향으로 visited[a][b] = 1처리
    4. 1이 가장 많은 값 찾기
    5. 전체 - 벽 - 최대값
    
    [방법 2]
    반대로 그 자리에 체크는? 그게 그거지 ㅡㅡ...

    [방법 3]
    그럼 백트레킹을 힌트를 보고 왔으니...
    1. [ ] 전체 cctv 큐를 만들어서 다 넣고 시작
    2. [ ] dfs 느낌으로 구현은?
        2-1. [ ] 들어가면 현재 K의 cctv 타입 분석 (타입별로 값을 만들어두자)
        2-2. [ ] 이후 모두 4방향으로 돌림 처리 (*-1, 1) (*)
        2-3. [ ] 벽이나 끝을 만날 때까지 가는 길 다 visited 처리하기
        2-4. [ ] 그 맵 넘겨주기
    
    3. 쭉 들어가 마지막에 전체 방문 개수 파악 후 최대값 교체
    4. 전체 - 벽 - 최대값

    방법 3 채택!
    */

/**
    (1, 0) (-1, 0) (0, 1), (0, -1)
    1. 0, 1, 2, 3
    2. (0, 1), (2, 3)
    3. (0, 2), (0, 3), (1, 2), (1, 3)
    4. (0, 1, 2), (1, 2, 3), (2, 3, 0), (3, 0, 1)
    5. (0, 1, 2, 3)
*/

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> dw[6] = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 1}, {2, 3}},
    {{0, 2}, {0, 3}, {1, 2}, {1, 3}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

vector<pair<int, int>> que;
int N, M, answer = 0, max_depth, wall = 0;

void checkObserve(int x, int y, vector<vector<int>> &mp_cp, int way) {
    int nx = x;
    int ny = y;
    while (true) {
        nx += dx[way];
        ny += dy[way];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M || mp_cp[nx][ny] == 6) {
            break;
        }

        if(mp_cp[nx][ny] == 0) {
            mp_cp[nx][ny] = -1;
        }
    }
}

int countVisible(vector<vector<int>> &mp_cp) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(mp_cp[i][j] == -1) {
                cnt++;
            }
        }
    }
    return cnt;
}

void findMaxVisible(int now, vector<vector<int>> mp) {
    if (que.size() == now) {
        answer = max(answer, countVisible(mp));
        return;
    }
    int x = que[now].first;
    int y = que[now].second;
    int ct = mp[x][y]; //cctv type

    for (int i = 0; i < dw[ct].size(); i++) {
        vector<int> way = dw[ct][i];
        vector<vector<int>> mp_cp = mp;
        for (int j = 0; j < way.size(); j++) {
            checkObserve(x, y, mp_cp, way[j]);
        }

        findMaxVisible(now + 1, mp_cp);
    }

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // 지도 0 빈칸, 6 벽, 1~5 cctv
    // 세로 N 가로 M  CCTV 최대 8 N,M <= 8
    // 최대 맵 64 x 4^8(4방향으로 8개) => 64 * 2^16(7만?) => 100만번?
    vector<vector<int>> mp;

    cin >> N >> M;
    mp = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mp[i][j];
            // 벽인 경우
            if(mp[i][j] == 6) {
                wall++;
            // cctv인 경우
            } else if(mp[i][j] > 0) {
                que.push_back(make_pair(i, j));
            }
        }
    }

    max_depth = que.size();

    findMaxVisible(0, mp);
    int invisible = int(N * M) - answer - wall - que.size();
    cout << invisible << "\n";
}