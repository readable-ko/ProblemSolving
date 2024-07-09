#include <bits/stdc++.h>
using namespace std;
int N;

int find_minimum_square(int target, int& now) {
    int sp = 0;
    while(target > now) {
        sp++;
        now *= 2;
    }

    return sp;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int prev = 0, answer = 0;

    cin >> N;
    vector<int> sequence(N);

    for (int i = 0 ; i < N ; i++) {
        cin >> sequence[i];
        if (i != 0 && sequence[i - 1] > sequence[i]) {
            answer += find_minimum_square(sequence[i - 1], sequence[i]);
        }
    }

    cout << answer;
}