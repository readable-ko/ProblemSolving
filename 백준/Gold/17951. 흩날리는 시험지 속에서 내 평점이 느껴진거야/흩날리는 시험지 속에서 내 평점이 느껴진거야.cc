#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &papers, int mid, int K) {
    int sum = 0, cnt = 0;
    for (int paper: papers) {
        sum += paper;
        if (sum >= mid) {
            sum = 0;
            cnt++;
        }
    }
    return cnt >= K;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, high, low = 0;
    cin >> N >> K;

    vector<int> papers(N);
    for(int &it: papers) {
        cin >> it;
    }

    high = accumulate(papers.begin(), papers.end(), 0) / K;

    while(low < high) {
        int mid = (low + high + 1) / 2;

        if (is_possible(papers, mid, K)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << low;
}