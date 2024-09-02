#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N, L, W, H;
    cin >> N >> L >> W >> H;
    long double low = 0.0, mid, high = 1000000000.0;

    mid = (low + high) / 2.0;
    int cnt = 60;
    while(cnt--) {
        if ((long long int)(L / mid) * (long long int)(W / mid) * (long long int)(H / mid) >= N) {
            low = mid;
        } else {
            high = mid;
        }
        mid = (low + high) / 2.0;
    }
    cout << fixed;
    cout.precision(9);
    cout << low;
}