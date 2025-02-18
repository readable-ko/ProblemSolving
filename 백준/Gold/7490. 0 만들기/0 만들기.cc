#include <bits/stdc++.h>
#include <regex>
using namespace std;
int test_cases, N;
char opt[3] = {' ', '+', '-'};

void dfs(int depth, string vec) {
    if(depth == N) {
        string expr = vec;
        expr = regex_replace(expr,regex(" "), "");
        int curr = 0, answer = 0;
        char op = '+';

        for(int i = 0 ; i < expr.length(); i++) {
            if(isdigit(expr[i])) {
                curr = curr * 10 + (expr[i] - '0');
            } 
            if(!isdigit(expr[i]) || i == expr.length() - 1) {
                if(op == '+') {
                    answer += curr;
                } else {
                    answer -= curr;
                }
                curr = 0;
                op = expr[i];
            }
        }
        if(answer == 0) {
            cout << vec << "\n";
        }
        return;
    }

    for(int i = 0; i < 3; i++) {
        vec += opt[i] + to_string(depth + 1);
        dfs(depth+1, vec);
        vec.pop_back();
        vec.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> test_cases;

    for(int t = 0; t < test_cases; t++) {
        cin >> N;
        dfs(1, "1");
        if(t != test_cases - 1)
            cout << "\n";
    }
}