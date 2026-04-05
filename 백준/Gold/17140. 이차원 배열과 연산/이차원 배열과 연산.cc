#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
/**
    행 개수 >= 열 개수 일 때 R 연산
    행 개수 < 열 개수 일 때 C연산

    1. 정렬된 값을 배열에 넣을 때 (수, 등장 횟수)로 넣음
    [3, 1, 1] -> 3 이 1, 1 이 2
    [3, 1, 1, 2] -> 3이 1, 1 이 2, 2 이 1
    [2, 1, 3, 1, 1, 2]
    가장 큰 행, 열의 크기 기준으로 0이 채워지고 0은 수를 정렬할 때 무시한다.
    [3, 2, 0, 0] 은 [3, 2]와 같다!
    100을 넘어가면 첫 100개 이후로는 버림
    A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간 (1 <= r, c, k <= 100)

    100 * 100log(100) * 100 (0.6초..?)

    r = 1, c = 2, k = 2

    1 2 1
    2 1 3
    3 3 3

    2 1 1 2 0 0
    1 1 2 1 3 1
    3 3 0 0 0 0

    1 1 1 1 3 1
    1 2 1 1 1 1
    2 3 2 2 0 0
    1 1 1 1 0 0
    3 0 0 0 0 0
    1 0 0 0 0 0

    counting sort!

    ######### LOGIC ###########
    1. 처음 r, c를 받으면서 MAX_R, MAX_C를 작성하기
    2-1. case: MAX_R >= MAX_C
        ROW 연산
    2-2. case: MAX_R < MAX_C
        COL 연산
    연산에 따라 어떻게 for문을 돌리지? 고민해보자! (쉽게는 그냥 if else로 2개
   만들어..)
    3. 숫자 1부터 100까지 배열 만들기!
    4. 현재 배열 원소로 COUNTING SORT 진행! -> 이후 어떻게 할래? sort하면 될 듯
    5.
    max(MAX_R, now_R) 로 MAX_R && max(MAX_C, now_C)로 MAX_C 갱신해주기

*/
int MAX_R = 3, MAX_C = 3;
const int MAX_NUM = 101;
bool mySort(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, k, loop = 0;
    cin >> r >> c >> k;

    vector<vector<int>> board(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    for (; loop <= 101; loop++) {

        if (r - 1 < board.size() && c - 1 < board[r - 1].size() &&
            board[r - 1][c - 1] == k) {
            break;
        }

        if (loop > 100) {
            loop = -1;
            break;
        }

        // R이 C보다 크거나 같은 경우
        if (MAX_R >= MAX_C) {
            int mr = MAX_R;
            int SUB_C = 0;
            for (int i = 0; i < mr; i++) {
                // counting sort;

                map<int, int> cs;

                for (int j = 0; j < MAX_C; j++) {
                    int d = board[i][j]; // d = digit
                    if (d == 0) {
                        continue;
                    }

                    cs[d]++;
                }

                SUB_C = max(SUB_C, (int)cs.size() * 2);

                vector<pair<int, int>> temp =
                    vector<pair<int, int>>(cs.begin(), cs.end());
                sort(temp.begin(), temp.end(), mySort);

                int row_len = min(100, (int)cs.size() * 2);
                board[i].resize(row_len, 0);
                for (int j = 0; j < temp.size(); j++) {
                    if (j * 2 >= 100) {
                        break;
                    }
                    board[i][j * 2] = temp[j].first;
                    board[i][j * 2 + 1] = temp[j].second;
                }
            }

            MAX_C = min(100, SUB_C);

            for (int i = 0; i < mr; i++) {
                board[i].resize(MAX_C, 0);
            }
            // C가 R보다 큰 경우
        } else {
            int mc = MAX_C;
            int SUB_R = 0;
            for (int i = 0; i < mc; i++) {
                map<int, int> cs;

                for (int j = 0; j < MAX_R; j++) {
                    int d = board[j][i];
                    if (d == 0) {
                        continue;
                    }

                    cs[d]++;
                }
                SUB_R = max(SUB_R, (int)cs.size() * 2);

                vector<pair<int, int>> temp =
                    vector<pair<int, int>>(cs.begin(), cs.end());
                sort(temp.begin(), temp.end(), mySort);

                int col_len = min(100, (int)temp.size() * 2);
                while (board.size() < col_len) {
                    board.push_back(vector<int>(MAX_C, 0));
                }
                for (int j = 0; j < temp.size(); j++) {
                    if (j * 2 >= 100)
                        break;
                    board[j * 2][i] = temp[j].first;
                    board[j * 2 + 1][i] = temp[j].second;
                }

                for (int j = col_len; j < MAX_R; j++) {
                    if (j < board.size() && i < board[j].size())
                        board[j][i] = 0;
                }
            }

            MAX_R = min(100, SUB_R);

            board.resize(MAX_R, vector<int>(MAX_C, 0));
        }
    }

    cout << loop << endl;
}