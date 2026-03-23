#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Pos {
    public:
        int v; //value
        int h; //high
        int l; //low
    
    Pos(int V, int H, int L) {
        v = V;
        h = H;
        l = L;
    };

    Pos() {
        v = 0;
        h = 0;
        l = 0;
    };
};

vector< vector<Pos> > mp_r, mp_c;
int N, L, answer = 0;

void check(vector<vector<Pos>> &mp) {
    // LOGIC
    /** 
    스택 운영
    1. 만약 현재값이 0이면 (high + 1)
    2. 현재 값이 이전값과 동일하다면 high + 1
    3. 만약 현재값이 이전값보다 크다면 스택이 L보다 큰지 확인한다.
        스택이 크다면 현재 값을 1로 만들고 진행
        스택이 작다면 불가능으로 표시 후 종료
    4. 만약 현재값이 이전값보다 작다면 high = -L + 1

    5. 왼오로 진행하며 row col을 뒤집어서 값을 한 번 받는다.
    */
    vector<bool> visisted(N);

    for (int i = 0 ; i < N; i++) {
        int j = 0;
        for (; j < N; j++) {
            if (j == 0) {
                mp[i][j].h = 1;
            // 현재 값이 이전값과 동일
            } else if (mp[i][j].v == mp[i][j - 1].v) {
                mp[i][j].h = mp[i][j - 1].h + 1;
            // 현재값이 이전값보다 크다면
            } else if ((mp[i][j].v == mp[i][j - 1].v + 1)
                        && (mp[i][j - 1].h >= L)) {
                mp[i][j].h = 1;
            // 현재값이 이전값보다 작다면
            } else if ((mp[i][j].v == mp[i][j - 1].v - 1) && mp[i][j - 1].h >= 0) {
                mp[i][j].h = 1 - L;
            } else {
                j = N + 1;
                break;
            }
        }
        if (j == N && mp[i][j - 1].h >= 0) {
            // cout << i << " " << j << "\n";
            answer++;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> L ;
    mp_r = vector<vector<Pos>>(N, vector<Pos>(N));
    mp_c = vector<vector<Pos>>(N, vector<Pos>(N));

    // get input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mp_r[i][j].v;
            mp_c[j][i].v = mp_r[i][j].v;
        }
    }

    check(mp_r);
    check(mp_c);
    cout << answer << "\n";
}