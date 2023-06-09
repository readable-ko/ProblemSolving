#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i = 0 ; i <= d ; i += k) {
        long long tmp = floor(sqrt(((long long) d * d) - i * i)) / k ;
        answer += tmp + 1;
    }
    return answer;
}