#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    for (int idx = 0; idx < A.size(); idx++) {
        answer += A[idx] * B[idx];
    }
    return answer;
}