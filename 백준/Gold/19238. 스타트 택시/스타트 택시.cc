#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int map_taxi[21][21], N, M, flue;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
pair<int, int> mp; //mp: my position
map< pair<int, int>, pair<int, int> > pessanger;

pair<int, int> FindPessanger(pair<int, int> sp) //starting position sp
{
   queue< pair<int, int> > que;
   que.push(sp);

   bool visited[21][21];
   memset(visited, 0, sizeof(visited));
   visited[sp.first][sp.second] = 1;
   if (map_taxi[sp.first][sp.second] == 2) return sp;
   pair<int, int> gotcha = make_pair(0x3f3f3f3f, 0x3f3f3f3f);

   while (!que.empty())
   {
      int q_sz = que.size();
      for (int i = 0; i < q_sz; i++)
      {
         pair<int, int> now = que.front();
         que.pop();
         for (int i = 0; i < 4; i++)
         {
            pair<int, int> np; //new position np
            np.first = now.first + dx[i];
            np.second = now.second + dy[i];
            if (np.first < 1 || np.first > N || np.second < 1 || np.second > N) continue;
            if (!visited[np.first][np.second] && map_taxi[np.first][np.second] != 1)
            {
               visited[np.first][np.second] = 1;
               que.push(np);
               if (map_taxi[np.first][np.second] == 2)
               {
                  if (np.first < gotcha.first)
                  {
                     gotcha = np;
                  }
                  else if (np.first == gotcha.first && np.second < gotcha.second)
                  {
                     gotcha = np;
                  }
               }
            }
         }
      }
      if (gotcha.first != 0x3f3f3f3f) return gotcha;
   }

   flue = -1;
   return sp;
}

int FindDist(pair<int, int> sp, pair<int, int> dp) //starting position sp dest position dp
{
   queue< pair<int, int> > que;
   que.push(sp);

   int visited[21][21];
   memset(visited, 0, sizeof(visited));
   visited[sp.first][sp.second] = 1;
   if (map_taxi[sp.first][sp.second] == 2) return 1;

   while (!que.empty())
   {
      pair<int, int> now = que.front();
      que.pop();
      for (int i = 0; i < 4; i++)
      {
         pair<int, int> np; //new position np
         np.first = now.first + dx[i];
         np.second = now.second + dy[i];
         if (np.first < 1 || np.first > N || np.second < 1 || np.second > N) continue;
         if (!visited[np.first][np.second] && map_taxi[np.first][np.second] != 1)
         {
            visited[np.first][np.second] = visited[now.first][now.second] + 1;
            que.push(np);
            if (visited[dp.first][dp.second] != 0) return visited[dp.first][dp.second];
         }
      }
   }
   flue = -1;
   return visited[sp.first][sp.second];
}

void GuessFlue()
{
   for (int cnt = 0; cnt < M; cnt++)
   {
      pair<int, int> fp = FindPessanger(mp); //finded pessenger
      int pd = FindDist(mp, fp) - 1;

      flue -= pd;
      map_taxi[fp.first][fp.second] = 0;
      if (flue < 0) break;

      pair<int, int> fd = pessanger[fp]; //find destination
      mp = fp;

      pd = FindDist(mp, fd) - 1;
      mp = fd;
      if (pd > flue)
      {
         flue = -1; break;
      }
      else
      {
         flue -= pd;
         flue += pd * 2;
      }
   }

   cout << flue << "\n";
}

int main()
{
   ios::sync_with_stdio(0), cin.tie(0);
   cin >> N >> M >> flue;

   for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
      {
         cin >> map_taxi[i][j];
      }
   cin >> mp.first >> mp.second;

   for (int i = 0; i < M; i++)
   {
      pair<int, int> tmp_source, tmp_dest;
      cin >> tmp_source.first >> tmp_source.second >> tmp_dest.first >> tmp_dest.second;
      pessanger[tmp_source] = tmp_dest;
      map_taxi[tmp_source.first][tmp_source.second] = 2;
   }

   GuessFlue();
}