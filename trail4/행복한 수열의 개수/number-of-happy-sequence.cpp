#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

void printer() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, answer = 0;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        pair<int, int> prevRow = {0, 0};
        pair<int, int> prevCol = {0, 0};
        for (int j = 0; j < N; j++) {
            if(matrix[i][j] == prevRow.first) {
                prevRow.second++;
            } else {
                prevRow = {matrix[i][j], 1};
            }

            if(prevRow.second >= M) {
                answer++;
                break;
            }
        }

        for (int j = 0; j < N; j++) {
            if(matrix[j][i] == prevCol.first) {
                prevCol.second++;
            } else {
                prevCol = {matrix[j][i], 1};
            }

            if(prevCol.second >= M) {
                answer++;
                break;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}