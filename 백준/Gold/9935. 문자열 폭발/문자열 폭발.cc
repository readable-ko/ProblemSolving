//코드 설명 https://readble-ko.tistory.com/197
#include <bits/stdc++.h>
using namespace std ;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> indexs;
    string str, boom, words = "";

    cin >> str;
    cin >> boom;
    int idx = 0;
    
    for (int curr_idx = 0; curr_idx < str.length() ; curr_idx++) {
        if (boom[idx] == str[curr_idx]) {
            if (idx == 0) {
                indexs.push(0);
            }
            idx++;
        } else {
            indexs.push(idx);
            idx = (boom[0] == str[curr_idx]) ? 1 : 0;
        }

        if (idx == boom.length()) {
            while(--idx) {
                words.pop_back();
            }
            
            idx = indexs.top();
            indexs.pop();
            continue;
        }
        words.push_back(str[curr_idx]);
    }

    words.empty() ? cout << "FRULA" : cout << words;

}