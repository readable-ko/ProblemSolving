#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
최대 50 * 50개의 배열을 6번 돌려야해. 2500 * 6 => 15000 + 행렬계산 충분!

S는 무조건 1보다 큼
* 1 ≤ r-s < r < r+s ≤ N
* 1 ≤ c-s < c < c+s ≤ M
즉, r,c가 구석탱이일 확률이 없다! --> 만약 있으면 어케 풀까..?

1. 특정 배열에서 위치를 기준으로 S가 주어지면
2. 상하좌우 중 절대값으로 depth를 벗어나면 안됨!
        2-1. S가 1이면 (-1, -1) (-1, 0) (-1, 1) (0, 1) (1, 1) ...
        2-2. S가 2이면 (-2, -2), (-2, -1) (-2, 0) ...
        r,c 중에 1개는 절대값으로 S와 같고 나머지 1개는 작거나 같아야 함
        DFS로 풀 수 있나? for문 돌리는게 최고인가?

        ##DFS의 경우##
        1. (R-S, C-S)에서 시작해서 (1, 0)에서 값 훔쳐와서 시작
          1-1. r-s || c-s가 0보다 작거나 N보다 클 수 있음 -> 아님 불가능
        2. 만약 현재 노드 방문한 적 있다면 return (S-1)
        3. 아니라면 방문 체크 후 우하좌상 순서로 움직임
        4. 현재 값을 넘겨주고 가진 값 덮어쓰기
        5. return이나 finish 조건을 어떻게 할건데?
        6. s가 0이 되는 경우. 방문할 곳이 없는 경우 알아서 종료됨

*/

int N, M, s_size;
int r, c;
// 우하좌상
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
vector<vector<int>> mtx;
vector<vector<int>> S;
vector<vector<bool>> visited;

// row, col, point, depth
void rotateMatrix(vector<vector<int>> &arr, int x, int y, int p, int d) {
  for (int i = 0; i < 4; i++) {
    int nr = x + dr[i];
    int nc = y + dc[i];
    // 벗어나는 경우.
    if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
      continue;
    }
    // 해당 depth가 아닌 경우
    if (abs(r - nr - 1) > d || abs(c - nc - 1) > d) {
      continue;
    }

    if (visited[nr][nc]) {
      continue;
    }

    visited[nr][nc] = 1;
    int np = arr[nr][nc]; // next_point
    arr[nr][nc] = p;
    rotateMatrix(arr, nr, nc, np, d);
  }

  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> s_size;
  mtx = vector<vector<int>>(N, vector<int>(M));
  S = vector<vector<int>>(s_size);
  vector<int> order(s_size);
  // 최소행 찾기 시작 (각 행 최대값은 100이니 최대 50*100)
  int answer = 5000;

  // 배열을 만든다
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> mtx[i][j];
    }
  }

  for (int i = 0; i < s_size; i++) {
    order[i] = i;

    int s;
    cin >> r >> c >> s;
    S[i].push_back(r);
    S[i].push_back(c);
    S[i].push_back(s);
  }

  do {
    // 매트릭스 돌리기 시작
    vector<vector<int>> arr = mtx;
    for (int i = 0; i < s_size; i++) {
      int s;
      int odr = order[i];
      // cin >> r >> c >> s;
      r = S[odr][0];
      c = S[odr][1];
      s = S[odr][2];
      visited = vector<vector<bool>>(N, vector<bool>(M));
      visited[r - 1][c - 1] = 1;
      for (int j = 1; j <= s; j++) {
        int sr = r - j - 1;   // start_r
        int sc = c - j - 1;   // start_c
        int sp = arr[sr][sc]; // start_point
        // visited[sr][sc] = 1;

        rotateMatrix(arr, sr, sc, sp, j);
      }
    }

    int sub_sum = 5000;
    for (int i = 0; i < N; i++) {
      int row_sum = 0;
      for (int j = 0; j < M; j++) {
        row_sum += arr[i][j];
      }
      sub_sum = min(row_sum, sub_sum);
    }
    answer = min(sub_sum, answer);

  } while (next_permutation(order.begin(), order.end()));

  cout << answer;
}