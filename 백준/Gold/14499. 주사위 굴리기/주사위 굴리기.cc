#include <bits/stdc++.h>
using namespace std;

/**
 * N: 지도 세로 크기
 * M: 지도 가로 크기
 * x, y: 주사위 세로 좌표
 * K: 명령의 개수
 */
int N, M, x, y, K;
int x_ep = 3, y_ep = 3;
int dice_x[4] = {0, 0, 0, 0};
int dice_y[4] = {0, 0, 0, 0};
map<int, pair<int,int>> order;
vector<vector<int>> mp(20, vector<int>(20));

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    order[1] = make_pair(0, 1);
    order[2] = make_pair(0, -1);
    order[3] = make_pair(-1, 0);
    order[4] = make_pair(1, 0);
}

void getSetting() {
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }
}

int getDirection() {
    int direction;
    cin >> direction;

    return direction;
}

int getMod4(int num) {
    if(num < 0) {
        return 3;
    } else if(num >= 4) {
        return num % 4;
    }
    return num;
}

void checkNumber(int mv_x, int mv_y) {
    if(mp[mv_x][mv_y] != 0) {
        dice_x[x_ep] = mp[mv_x][mv_y];
        dice_y[y_ep] = mp[mv_x][mv_y];
        mp[mv_x][mv_y] = 0;
    }
    else {
        mp[mv_x][mv_y] = dice_x[x_ep];
    }

    int top = getMod4(x_ep + 2);
    cout << dice_x[top] << "\n";
}

void rollDice(int mv_x, int mv_y) {
    int top;
    if(mv_x != 0) {
        x_ep = getMod4(x_ep + mv_x);
        dice_y[getMod4(y_ep + 2)] = dice_x[getMod4(x_ep + 2)];
        dice_y[y_ep] = dice_x[x_ep];
        
    } else {
        y_ep = getMod4(y_ep - mv_y);
        dice_x[getMod4(x_ep + 2)] = dice_y[getMod4(y_ep + 2)];
        dice_x[x_ep] = dice_y[y_ep];
        
    }
}

void moveDice(int direction) {
    pair<int, int> mv = order[direction];

    if(x + mv.first >= N || x + mv.first < 0) {
        return;
    }

    if(y + mv.second >= M || y + mv.second < 0) {
        return;
    }
    x += mv.first;
    y += mv.second;

    rollDice(mv.first, mv.second);
    checkNumber(x, y);
}

void playTurn(int times) {
    for(int i = 0 ; i < times; i++) {
        moveDice(getDirection());
    }
}

int main() {
    init();
    getSetting();
    playTurn(K);
    return 0;
}