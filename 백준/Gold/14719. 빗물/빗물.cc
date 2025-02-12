#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<int> block(W);

    for(int i = 0; i < W; i++) {
        cin >> block[i];
    }

    int answer = 0;
    for(int i = 1; i < W - 1; i++) {
        int left_max = *max_element(block.begin(), block.begin() + i);
        int right_max = *max_element(block.begin() + i + 1, block.end());
        int stagnant = min(left_max, right_max);
        answer += max(stagnant - block[i], 0);
    }

    cout << answer;
}