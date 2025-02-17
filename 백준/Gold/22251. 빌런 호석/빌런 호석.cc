#include <bits/stdc++.h>
using namespace std;
int N, K, P; // 최대층, 자리수, 반전수
string X; // 현재 층
bool digit[10][7] = {
    {1,1,1,0,1,1,1}, // 0
    {0,0,1,0,0,1,0}, // 1
    {1,0,1,1,1,0,1}, // 2
    {1,0,1,1,0,1,1}, // 3
    {0,1,1,1,0,1,0}, // 4
    {1,1,0,1,0,1,1}, // 5
    {1,1,0,1,1,1,1}, // 6
    {1,0,1,0,0,1,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}, // 9
    };

int _compareDigit(int lhs, int rhs) {
    int cnt = 0;
    for(int i = 0; i < 7; i++) {
        if(digit[lhs][i] ^ digit[rhs][i]) {
            cnt++;
        }
    }
    return cnt;
}

bool compareDigit(string num) {
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        cnt += _compareDigit(num[i] - '0', X[i] - '0');
        if(cnt > P) {
            return false;
        }
    }
    if(cnt == 0) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> P >> X;
    X = string(K - X.length(), '0') + X;
    
    int answer = 0;
    for(int i = 1 ; i <= N; i++) {
        string tmp = to_string(i);
        string num = string(K - tmp.length(), '0') + tmp;
        if(compareDigit(num)) {
            answer++;
        }
    }

    cout << answer;
}