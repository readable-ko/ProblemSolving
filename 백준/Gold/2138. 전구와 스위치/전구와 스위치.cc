#include <bits/stdc++.h>
using namespace std;

void fill_vec(vector<bool> &vec) {
    string tmp;

    cin >> tmp;
    for(int i = 0; i < tmp.length(); i++) {
        if(tmp[i] == '1') {
            vec[i] = 1;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<bool> zero(N);
    vector<bool> one(N);
    vector<bool> want(N);
    fill_vec(zero);
    fill_vec(want);
    one = zero;
    one[0] = !one[0]; one[1] = !one[1];

    int on_start = 1, off_start = 0;
    for(int i = 1; i < N - 1; i++) {
        if(one[i - 1] != want[i - 1]) {
            one[i+1] = !one[i+1];
            one[i] = !one[i];
            on_start++;
        }
        if(zero[i - 1] != want[i - 1]) {
            zero[i] = !zero[i];
            zero[i+1] = !zero[i+1];
            off_start++;
        }
    }

    if(one[N - 2] != want[N - 2]) {
        one[N - 1] = !one[N - 1];
        on_start++;
    }
    if(zero[N - 2] != want[N - 2]) {
        zero[N - 1] = !zero[N - 1];
        off_start++;
    }
    
    if(one[N - 1] != want[N - 1]) {
        if(zero[N - 1] != want[N - 1]) {
            cout << "-1\n";
        } else {
            cout << off_start << "\n";
        }
    } else {
        if(zero[N - 1] == want[N - 1]) {
            cout << min(on_start, off_start) << "\n";
        } 
        else {
            cout << on_start << "\n";
        }
    }
}