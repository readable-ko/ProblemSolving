#include <bits/stdc++.h>
using namespace std;

bool check(string str[3], char c) {
    for(int i = 0; i < 3; i++) {
        if (str[0][i] == str[1][1] &&
            str[0][i] == str[2][2 - i] &&
            str[0][i] == c) {
                return true;
            }
    }
    if(str[1][0] == str[1][1] && str[1][1] == str[1][2] && str[1][2] == c) {
        return true;
    }
    if(str[0][0] == str[0][1] && str[0][1] == str[0][2] && str[0][2] == c) {
        return true;
    }
    if(str[2][0] == str[2][1] && str[2][1] == str[2][2] && str[2][2] == c) {
        return true;
    }
    if(str[0][2] == str[1][2] && str[1][2] == str[2][2] && str[2][2] == c) {
        return true;
    }
    if(str[0][0] == str[1][0] && str[1][0] == str[2][0] && str[2][0] == c) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while(true) {
        cin >> str;
        if(str == "end") break;
        
        string tiktakto[3] = {"","",""};
        int x = 0, o = 0, nothing = 0;
        for(int idx = 0 ; idx < 9; idx++) {
            int i = idx / 3;
            char w = str[idx];

            if(w == 'X') {
                x++;
            } else if(w == 'O') {
                o++;
            } else {
                nothing++;
            }
            tiktakto[i].push_back(w);
        }

        bool flag = false;
        bool isOWin = check(tiktakto, 'O');
        bool isXWin = check(tiktakto, 'X');
        if(nothing) {

            if(x == o + 1) {
                if(!isOWin && isXWin) {
                    flag = true;
                }
            } else if(x == o) {
                if(!isXWin && isOWin) {
                    flag = true;
                }
            }
        } else {
            if(x == o + 1) {
                if(!isOWin) {
                    flag = true;
                }
            }
        }

        flag ? cout << "valid\n" : cout << "invalid\n";
    }
}