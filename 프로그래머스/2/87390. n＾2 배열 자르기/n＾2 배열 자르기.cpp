#include <string>
#include <vector>
#include <iostream>
#include <math.h>
/* val = max(row, col)
1 2 3 4 5
2 2 3 4 5
3 3 3 4 5
4 4 4 4 5
5 5 5 5 5

1 2 3 2 2 3
*/
using namespace std;
long long lmax(long long a, long long b) {
    return a < b ? b : a ;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long now = left ; now <= right ; now++) {
        long long row = (now % n) + 1 ;
        long long col = now / n + 1; 
        answer.push_back(lmax(row, col));
    }
    return answer;
}