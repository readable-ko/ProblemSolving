#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(), [&](vector<int> a, vector<int> b){
        if(a[col-1] == b[col-1]) return a[0] > b[0] ;
            return a[col - 1] < b[col - 1] ;
    });
    
    for(; row_begin <= row_end ; row_begin++) {
        int tmp = 0 ;
        for(int it : data[row_begin - 1])
            tmp += (it % row_begin) ;
        answer ^= tmp ;
    }
    return answer;
}

// 3 8 3
// 1 5 10
// 2 2 6
// 4 2 9