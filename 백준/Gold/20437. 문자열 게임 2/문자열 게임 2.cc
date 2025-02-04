#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int T, K;
    string word;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> word;
        cin >> K;

        map<char, vector<int>> mp;
        int min_ans = 10001, max_ans = -1;

        for(int j = 0; j < word.length(); j++) {
            char c = word[j];
            mp[c].push_back(j);
        }
        
        for(auto it : mp) {
            vector<int> val = it.second;
            for(int j = K - 1; j < val.size(); j++) {
                min_ans = min(min_ans, val[j] - val[j - K + 1] + 1);
                max_ans = max(max_ans, val[j] - val[j - K + 1] + 1);
            }
        }

        if(min_ans != 10001 && max_ans != -1) {
            cout << min_ans << " " << max_ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
}