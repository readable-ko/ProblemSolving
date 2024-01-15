/**
 * @author 
 * fpqpsxh
 * @brief 
 * 일단 dfs로 풀어보자
 * 단계별로 갈 때마다 가로 세로 대각선을 못가도록 하고
 * 퀸을 원하는 갯수만큼 놓을 때 정답 갯수 1 추가
 * 그리고 안되면 dfs 자동으로 넘어가도록 하면 될 거 같은데?
 * 
 * 근데 가로 세로는 그렇다고 쳐도 대각선 고려가 넘 문제여서 고민하다가 힌트 참조.
 * 반대 대각선 대구빡 깨지겠다.
 */
#include <bits/stdc++.h>
using namespace std;
int N, answer;
bool rows[16], cols[16], back_cross[32], cross[32];

void set_queen(int depth) {
    if (depth == N) {
        answer++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!rows[depth] && !cols[col] && !cross[depth + col] && !back_cross[N - depth + col]) {
            rows[depth] = 1, cols[col] = 1, cross[depth + col] = 1, back_cross[N - depth + col] = 1;
            set_queen(depth+1);
            rows[depth] = 0, cols[col] = 0, cross[depth + col] = 0, back_cross[N - depth + col] = 0;
        }
    }

    return;
}

int main() {
    cin >> N;
    set_queen(0);
    cout << answer;
}