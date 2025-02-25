#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, max_weight = 0;
    cin >> N;
    vector<int> rope(N);
    for(int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), greater<int>());
    for(int i = 0; i < N; i++) {
        max_weight = max(max_weight, rope[i] * (i + 1));
    }

    cout << max_weight;
}