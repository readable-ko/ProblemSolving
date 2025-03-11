#include <bits/stdc++.h>
using namespace std;
int max_length;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;

    vector<string> words(N);
    set<string> check;
    map<string, vector<int>> mp;

    for(int i = 0; i < N; i++) {
        cin >> words[i];

        if(check.find(words[i]) != check.end()) {
            continue;
        }
        
        string word = "";
        for(char c : words[i]) {
            word += c;
            mp[word].push_back(i);

            if(mp[word].size() >= 2 && max_length < word.length()) {
                max_length = word.length();
            }
        }
    }

    pair<int, string> answer = {0x3f3f3f3f, ""};
    for(auto& [key, value] : mp) {
        if(value.size() >= 2 && max_length == key.length()) {
            if(value.front() < answer.first) {
                answer.first = value.front();
                answer.second = key;
            }
        }
    }

    cout << words[mp[answer.second][0]] << "\n" << words[mp[answer.second][1]];
}