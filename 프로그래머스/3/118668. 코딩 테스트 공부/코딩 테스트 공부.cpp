#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
// 3차원 dp 낯설다.
int max_row, max_col;
vector< vector<int> > dp(151, vector<int>(151, 0x3f3f3f3f));

class problem {
    public:
    int alp_req;
    int cop_req;
    int alp_rwd;
    int cop_rwd;
    int cost;
    
    problem(vector<int> vec) : alp_req(vec[0]),
    cop_req(vec[1]), alp_rwd(vec[2]), cop_rwd(vec[3]), cost(vec[4]) {
    }
    
};

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for (vector<int> v: problems) {
        max_row = max(max_row, v[0]);
        max_col = max(max_col, v[1]);
    }
    alp = min(alp, max_row);
    cop = min(cop, max_col);
    
    dp[alp][cop] = 0;
    
    for (int row = alp; row <= max_row; row++) {
        for (int col = cop; col <= max_col; col++) {
            if (row < max_row) dp[row+1][col] = min(dp[row][col]+1, dp[row+1][col]);
            if (col < max_col) dp[row][col+1] = min(dp[row][col]+1, dp[row][col+1]);
            
            for (vector<int> v: problems) {
                problem p = problem(v);
                
                if(row >= p.alp_req && col >= p.cop_req) {
                    int new_row = min(row + p.alp_rwd, max_row);
                    int new_col = min(col + p.cop_rwd, max_col);
                    
                    dp[new_row][new_col] = min(dp[row][col] + p.cost,
                                      dp[new_row][new_col]);
                }
            }
        }
    }
    
    return dp[max_row][max_col];
}