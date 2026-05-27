#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, answer = 0;
    cin >> N;

    vector<vector<int>> space(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j =0; j < N; j++) {
            cin >> space[i][j];
        }
    }

    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= N - 3; j++) {

            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if(space[x][y]) {
                        sum++;
                    }
                }
            }
            answer = max(answer, sum);
        }
    }
    cout << answer << "\n";
    return 0;
}