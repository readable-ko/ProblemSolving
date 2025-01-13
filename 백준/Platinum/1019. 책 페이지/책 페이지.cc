#include <bits/stdc++.h>
using namespace std;
int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, remain = 0;
    cin >> N;

    for(int i = 1; N > 0; i*=10) {
        int ret = N % 10;
        N /= 10;

        cnt[0] -= i;
        for(int j = 0; j < 10; j++) {
            if(j < ret) {
                cnt[j] += (N + 1) * i;
            }
            else if(j == ret) {
                cnt[j] += N * i + 1 + remain;
            }
            else {
                cnt[j] += N * i;
            }
        }

        remain += ret * i;
    }

    for(int digit: cnt)
        cout << digit << " ";
}