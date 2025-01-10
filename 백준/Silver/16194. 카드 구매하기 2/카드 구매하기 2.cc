#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> card(N+1, 0x3f3f3f3f);
    vector<int> price(N);

    for(int &it : price)
        cin >> it;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            if(j == 0) {
                card[j] = 0;
            }
            else if(j - (i + 1) >= 0) {
                card[j] = min(price[i] + card[j - i - 1], card[j]);
            }
        }
    }

    cout << card[N];
}