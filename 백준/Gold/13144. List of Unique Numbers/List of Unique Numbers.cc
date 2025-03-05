#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> p(N);
    vector<bool> visit(100001);

    for(int &it: p) {
        cin >> it;
    }

    long long int answer = 0;
    int e = 0;
    for(int s = 0; s < N; s++) {

        while(e < N) {
            if(visit[p[e]]) {
                break;
            }
            visit[p[e]] = 1;
            e++;
        }
        answer += e - s;
        visit[p[s]] = 0;
    }

    cout << answer;
}