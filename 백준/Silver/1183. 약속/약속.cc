#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, est_time, real_time;

    cin >> N;
    vector<int> arr;

    for(int i = 0 ; i < N ; i++) {
        cin >> est_time >> real_time;
        arr.push_back(est_time - real_time);
    }
    sort(arr.begin(), arr.end());

    N & 1 ? cout << 1 : cout << arr[N/2] - arr[N/2 - 1] + 1;
}