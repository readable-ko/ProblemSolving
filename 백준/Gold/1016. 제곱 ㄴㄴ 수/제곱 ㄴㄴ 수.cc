#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int min_val=0, max_val=0, sp=0, answer;
    cin >> min_val >> max_val;

    answer= max_val - min_val + 1;
    vector<bool> sieve = vector<bool>(max_val - min_val + 1, false);


    for(long long int i = 2; i * i <= max_val; i++) {
        
        long long int ret = ceil((long double)min_val / (i * i));
        
        while((i * i * ret) <= max_val) {
            if(!sieve[(i*i)*ret - min_val]) {
                sieve[(i*i)*ret - min_val] = true;
                answer--;
            }
            ret++;
        }
    }

    cout << answer;
}