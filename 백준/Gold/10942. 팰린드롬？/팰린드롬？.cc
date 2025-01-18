#include <bits/stdc++.h>
using namespace std;

int checked[2001][2001];
vector<int> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N;
    cin >> N;
    arr = vector<int>(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        checked[i][i] = 1;
        if (i < N && arr[i] == arr[i + 1]) {
            checked[i][i + 1] = 1;
        }
    }

    for (int len = 3; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            int j = i + len - 1;
            if (arr[i] == arr[j] && checked[i + 1][j - 1] == 1) {
                checked[i][j] = 1;
            }
        }
    }

    int M, S, E;
    cin >> M;
    while (M--) {
        cin >> S >> E;
        cout << checked[S][E] << "\n";
    }
}
