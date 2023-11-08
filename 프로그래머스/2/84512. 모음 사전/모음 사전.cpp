#include <bits/stdc++.h>
using namespace std;
string alphbet = "AEIOU";
vector<string> dict;

void DFS(string str) {
    if (str.length() > 5) return;
    dict.push_back(str);
    
    for (char c: alphbet) {
        DFS(str + c) ;
    }
    return ;
}

int solution(string word) {
    int answer = 0;
    for (int i = 0 ; i < alphbet.length(); i++) {
        string str = "";
        DFS(str + alphbet[i]);
    }
    
    for (int i = 0 ; i < dict.size() ; i++) {
        if (dict[i] == word) {
            answer = i;
            break;
        }
    }
    return answer + 1;
}