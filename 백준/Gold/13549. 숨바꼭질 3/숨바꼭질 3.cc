#include <bits/stdc++.h>
#define MAX_VAL 0x3F3F3F3F
using namespace std;

int N, K;
int point[100001];
bool visited[100001];
queue<pair<int, int>> q;

void BFS(int k, int depth) {
   point[k] = depth;

   q.push(make_pair(k, depth));
   visited[k] = true;

   while (!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        if (top.first == K) {
            cout << top.second;
            break;
        }
        
        int min_one = top.first - 1, plus_one = top.first + 1, mul_two = top.first * 2;

        if (0 <= mul_two && mul_two <= 100000 && !visited[mul_two]) {
            visited[mul_two] = true;
            q.push(make_pair(mul_two, top.second));
        }

        if (min_one >= 0 && !visited[min_one]) {
            visited[min_one] = true;
            q.push(make_pair(min_one, top.second + 1));
        }

        if (plus_one <= 100000 && !visited[plus_one]) {
            visited[plus_one] = true;
            q.push(make_pair(plus_one, top.second + 1));
        }
    }
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   cin >> N >> K;
   memset(point, MAX_VAL, sizeof(point));

   BFS(N, 0);
}