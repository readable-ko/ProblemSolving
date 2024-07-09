#include <bits/stdc++.h>
using namespace std;
int N;

int find_minimum_square(int x, int target, int now) {
    return max(0, x + (int)ceil(log2((double)target/(double)now)));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int prev = 0;
    long long int answer = 0;

    cin >> N;
    vector<long long int> sequence(N);
    vector<int> power_cnt(N);

    for (int i = 0 ; i < N ; i++) {
        cin >> sequence[i];
        if (i != 0) {
            power_cnt[i] += find_minimum_square(power_cnt[i - 1], sequence[i - 1], sequence[i]);
            answer += power_cnt[i];
        }
    }

    cout << answer;
}