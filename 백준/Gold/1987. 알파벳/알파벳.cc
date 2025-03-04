#include <bits/stdc++.h>
using namespace std;
int R, C;
int maximum = 0, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<string> board;

void dfs(int r, int c, vector<bool> &exist, int cnt) {
   int num = board[r][c] - 'A';
   maximum = max(maximum, cnt);

   for (int i = 0; i < 4; i++) {
      int nx = r + dx[i];
      int ny = c + dy[i];

      if (0 > nx || nx >= R || 0 > ny || ny >= C) {
         continue;
      }

      int n = board[nx][ny] - 'A';
      if (!exist[n]) {
         exist[n] = true;
         dfs(nx, ny, exist, cnt + 1);
         exist[n] = false;
      }
   }
   return;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   cin >> R >> C;
   vector<bool> exist(26);

   for (int i = 0; i < R; i++) {
      string str;
      cin >> str;
      board.push_back(str);
   }

   exist[board[0][0] - 'A'] = true;
   dfs(0, 0, exist, 1);
   cout << maximum << "\n";
}