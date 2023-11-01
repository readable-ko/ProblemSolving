#include <bits/stdc++.h>
using namespace std;
bool visited[501][501][4];
int x_way[] = {1, 0, -1, 0};
int y_way[] = {0, 1, 0, -1};
vector<string> mp;

int change_direction(char c, int way) {
    switch(c) {
        case 'S':
            break;
        case 'R':
            way = (way + 1) % 4;
            break;
        case 'L':
            way--;
            if(way < 0) way = 3;
            break;
    }
    return way ;
}

int simulation(int row, int col, int way, int depth) {
    if (visited[row][col][way]) {
        return depth;
    }
    visited[row][col][way] = 1;
    
    way = change_direction(mp[row][col], way);
    row = row + x_way[way];
    col = col + y_way[way];
    
    if (row < 0) row = mp.size() - 1;
    if (row >= mp.size()) row = 0;
    if (col < 0) col = mp[row].size() - 1;
    if (col >= mp[row].size()) col = 0;
    
    return simulation(row, col, way, depth + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    mp = grid;
    
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            for (int way = 0; way < 4 ; way++) {
                int cycle_size = simulation(row, col, way, 0);
                if (cycle_size != 0) {
                    answer.push_back(cycle_size);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}