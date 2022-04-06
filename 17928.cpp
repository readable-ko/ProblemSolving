#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;
int L, S, cnt;
int arr[101];
bool visited[101];

void InputSetting()
{
   int s_point, d_point;
   cin >> L >> S;
   for (int i = 1; i <= L + S; i++)
   {
      cin >> s_point >> d_point;
      arr[s_point] = d_point;
   }
}

void BFS()
{
   queue<int> que;
   que.push(1);

   while (!que.empty())
   {
      cnt++;
      int curr_size = que.size();
      for (int i = 0; i < curr_size; i++)
      {
         int curr = que.front();
         que.pop();
         if (curr == 100) return;
         for (int j = 1; j <= 6; j++)
         {
            if (!visited[curr + j])
            {
               if (!arr[curr + j])
               {
                  que.push(curr + j);
                  visited[curr + j] = 1;
               }
               else if (curr + j <= 100 && !visited[arr[curr + j]])
               {
                  que.push(arr[curr + j]);
                  visited[curr + j] = 1;
                  visited[arr[curr + j]] = 1;
               }
            }
         }
      }
   }
}

int main()
{
   SETTING;
   InputSetting();
   BFS();
   cout << cnt - 1;
}