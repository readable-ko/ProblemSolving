#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, h, max_height = 0;
    vector<pair<int,int>> tower;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> h;
        
        while(!tower.empty() && tower.back().second <= h) {
            tower.pop_back();
        }

        if(tower.empty()) {
            tower.push_back(make_pair(i+1, h));
            cout << 0 << " ";
        }
        else {
            cout << tower.back().first << " ";
            tower.push_back(make_pair(i+1, h));
        }
    }
}