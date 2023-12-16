#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int dh[] = {1,0,-1,0};
int dw[] = {0,1,0,-1};
bool visited[11][11];

int count_same_color(vector<vector<string>> &board, int h, int w) {
    int count = 0;
    queue<pii> que;
    que.push({h,w});
    
    while (!que.empty()) {
        pii front = que.front();
        que.pop();
        
        for (int i = 0 ; i < 4 ; i++) {
            int new_h = front.first + dh[i];
            int new_w = front.second + dw[i];
            if (new_h < 0 || new_h >= board.size() || new_w < 0 || new_w >= board.size() || visited[new_h][new_w])
                continue;
            
            visited[new_h][new_w] = 1;
            if (board[new_h][new_w] == board[h][w]) {
                count++;
            }
        }
    }
    return count;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = count_same_color(board, h, w);
    return answer;
}