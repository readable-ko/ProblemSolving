#include <bits/stdc++.h>
#define MAXIMUM 20
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T ;
    cin >> T;

    while (T--) {
        int idx, sum = 0;
        vector<int> student(20);
        cin >> idx;
        for (int &s : student) {
            cin >> s;
        }

        for (int i = 0 ; i < MAXIMUM; i++) {
            for (int j = 0; j < i; j++) {
                if (student[i] < student[j]) {
                    sum++;
                }
            }
        }
        cout << idx << " " << sum << "\n";
    }
}