#include <bits/stdc++.h>
using namespace std;
int checked[2001][2001];
vector<int> num;

bool checkPalindrom(int S, int E) {
    if(S >= E) {
        return true;
    }

    if(checked[S][E] == 0) {
        if(num[S] != num[E]) {
            checked[S][E] = -1;
            return false;
        }
        bool result = checkPalindrom(S + 1, E - 1);

        checked[S][E] = result ? 1 : -1;
        return result;
    } else if(checked[S][E] > 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    num = vector<int>(N+1);

    for(int i = 1 ; i <= N ; i++) {
        cin >> num[i];
        checked[i][i] = 1;
    }
    
    int S, E, M;
    cin >> M;
    for(int i = 0 ; i < M; i++) {
        cin >> S >> E;
        checkPalindrom(S, E);
        cout << (checked[S][E] > 0 ? 1 : 0) << "\n";
    }
}