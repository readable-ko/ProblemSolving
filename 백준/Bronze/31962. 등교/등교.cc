#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, X, time = -1;
    int sp, ep;
    cin >> N >> X;

    while(N--) {
        cin >> sp >> ep;
        if (sp + ep <= X && sp > time) {
            time = sp;
        }
    }

    cout << time;
}