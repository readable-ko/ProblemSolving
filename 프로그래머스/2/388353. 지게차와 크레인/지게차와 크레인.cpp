#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> block;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int R, C;

bool remove_block(pair<int, int> p, int depth) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(50, vector<bool>(50));
    q.push(p);
    
    while(!q.empty()) {
        pair<int, int> f = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                return true;
            }
            
            if(!visited[nx][ny] && block[nx][ny] < depth + 1 && block[nx][ny] != 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    // 1. 일단 각 알파벳 별로 map 만들어보자.
    // 2. map 원소들이 탈출 가능한지를 체크해보자. (BFS) queue에 넣었다가 마지막에 일괄 제거하자
    // 3. 남은 block을 세자
    map<char, queue<pair<int, int>>> mp;
    block = vector<vector<int>>(storage.size(), vector<int>(storage[0].size(), 0));
    R = storage.size();
    C = storage[0].size();
    
    // 1. set map data.
    for (int i = 0; i < storage.size(); i++) {
        for (int j = 0; j < storage[i].size(); j++) {
            mp[storage[i][j]].push({i, j});
        }
    }
    
    // 2. BFS
    for (int idx = 0; idx < requests.size(); idx++) {
        string request = requests[idx];
        char c = request[0];
        
        if(request.length() > 1) {
            // craine
            while(!mp[c].empty()) {
                pair<int,int> f = mp[c].front();
                mp[c].pop();
                block[f.first][f.second] = idx + 1;
            }
        }
        else {
            // car
            int sz = mp[c].size();
            for(int i = 0; i < sz; i++) {
                pair<int, int> f = mp[c].front();
                mp[c].pop();
                if(!remove_block(f, idx)) {
                    mp[c].push(f);
                } else {
                    block[f.first][f.second] = idx + 1;
                }
            }
        }
    }
    
    // 1. set map data.
    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < block[i].size(); j++) {
            if(block[i][j] == 0) {
                answer++;
            }
        }
    }
    
    return answer;
}