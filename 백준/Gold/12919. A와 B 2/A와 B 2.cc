#include <bits/stdc++.h>
using namespace std;
int answer = 0;

void check(string s, string t) {
    if(s == t) {
        answer = 1;
    }
    if(s.size() > t.size()) {
        return;
    }

    if(t.front() == 'B') {
        string tmp = t;

        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        check(s, tmp);
    }
    if(t.back() == 'A') {
        string tmp = t;
        
        tmp.pop_back();
        check(s, tmp);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string prev, curr;
    cin >> prev;
    cin >> curr;

    check(prev, curr);
    cout << answer;
}