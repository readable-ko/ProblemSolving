#include <bits/stdc++.h>
using namespace std;
int R, C;
int maximum = 0, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<string> board;

void dfs(int r, int c, int bitmask, int cnt) {
   maximum = max(maximum, cnt);

   for (int i = 0; i < 4; i++) {
      int nx = r + dx[i];
      int ny = c + dy[i];

      if (0 > nx || nx >= R || 0 > ny || ny >= C) {
         continue;
      }

      int n = board[nx][ny] - 'A';
      if (!(bitmask & (1 << n))) {
         dfs(nx, ny, bitmask | (1 << n), cnt + 1);
      }
   }
   return;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   cin >> R >> C;
   board.resize(R);

   for (int i = 0; i < R; i++) {
      cin >> board[i];
   }

   int exist = board[0][0] - 'A';
   dfs(0, 0, (1 << exist), 1);
   cout << maximum << "\n";
}