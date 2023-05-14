#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {
   int answer = -1;
   int dx[] = { 1, 0, -1, 0 };
   int dy[] = { 0, 1, 0, -1 };
   vector< vector<int> > check(100, vector<int>(100));
   bool flag = 0 ;
   queue<pair<int, int>> que;

   for (int i = 0; i < board.size(); i++) {
      if(flag == 1) break ;
      for (int j = 0; j < board[i].size(); j++)
         if (board[i][j] == 'R') {
            que.push(make_pair(i, j));
            check[i][j] = 1;
            flag = 1 ;
            break;
         }
   }

   while (!que.empty()) {
      auto front = que.front(); que.pop();

      if (board[front.first][front.second] == 'G') {
          answer = check[front.first][front.second] - 1;
          break;
      }

      for (int i = 0; i < 4; i++)
      {
         int ny = front.first;
         int nx = front.second;
         while (nx >= 0 && nx < board[0].size() && ny >= 0 && ny < board.size() && board[ny][nx] != 'D')
         {
            ny += dy[i];
            nx += dx[i];
         }
         ny -= dy[i];
         nx -= dx[i];
         if (!check[ny][nx])
         {
            que.push(make_pair(ny, nx));
            check[ny][nx] = check[front.first][front.second] + 1;
         }
      }
   }

   return answer;
}