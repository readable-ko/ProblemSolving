#include <bits/stdc++.h>
using namespace std;

map<int, string> to_str_dict;

void init(vector<string> &answer) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++) {
        to_str_dict[i] = to_string(i);
        answer.push_back(to_str_dict[i]);
    }
}

int main() {

    int N, sp = 0;
    cin >> N;
    vector<string> answer;
    init(answer);

    while(answer.size() <= (N + 1) && answer.back().size() <= 9) {
        int ep = answer.size();
        for(int i = 0; i <= 9; i++) {
            if(answer.size() > (N+1) || answer.back().size() > 9) {
                break;
            }
            for(int j = sp; j < ep; j++) {
                if(to_str_dict[i][0] <= answer[j][0]) {
                    break;   
                }
                
                answer.push_back(to_str_dict[i] + answer[j]);
            }
        }
        sp = ep;
    }
    answer.size() < (N+1) ? cout << "-1" : cout << answer[N];
}