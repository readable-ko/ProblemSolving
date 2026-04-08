#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    vector<bool> numbers(1000001);
    numbers[0] = 1;
    numbers[1] = 1;

    cin >> N >> M;

    for (int i = 2; i * i <= 1000000; i++) {
        if (!numbers[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                numbers[j] = 1;
            }
        }
    }

    for (int i = N; i <= M; i++) {
        if (!numbers[i]) {
            cout << i << "\n";
        }
    }
}