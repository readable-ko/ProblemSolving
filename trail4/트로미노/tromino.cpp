#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

vector<vector<int>> board;
int N, M, answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int d, vector<vector<bool>> &check, int sum) {
    if(d == 3) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0 ; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        if(!check[nx][ny]) {
            check[nx][ny] = 1;
            dfs(nx, ny, d+1, check, sum + board[nx][ny]);
            check[nx][ny] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 결국 DFS로 depth 3인 모든 곳인데 depth3까지 가는 경로는 다 달라서 반복 체크 필요 없음
    // 12개의 올바른 경로. 직전에 갔던 곳 못가게 체크하고 세면 될 거 같은뎨?
    // 40000 * 많아도 64 => 400,0000 보다 적음! (1초미만)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<vector<bool>> check(N+1, vector<bool>(M+1));
            check[i][j] = 1;
            dfs(i, j, 1, check, board[i][j]);
        }
    }
    cout << answer << "\n";
    return 0;
}