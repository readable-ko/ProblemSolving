#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0, sz = info.size();
    vector<vector<int>> dp(info.size() + 1, vector<int>(m, 0x3f3f3f3f));
    dp[0][0] = 0;
    
    for(int i = 1; i <= sz; i++) {
        int a = info[i - 1][0];
        int b = info[i - 1][1];
        for(int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
            if(b + j < m) {
                dp[i][b + j] = min(dp[i][b + j], dp[i - 1][j]);
            }
        }
    }
    
    answer = *min_element(&dp[sz][0], &dp[sz][m]);
    return answer < n ? answer : -1;
}