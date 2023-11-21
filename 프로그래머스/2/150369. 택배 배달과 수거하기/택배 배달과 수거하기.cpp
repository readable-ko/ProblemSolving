#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int delivery_cnt = 0, pick_cnt = 0;
    
    for (int idx = n - 1 ; idx >= 0 ; idx--) {
        while (delivery_cnt < deliveries[idx] || pick_cnt < pickups[idx]) {
            answer += 2LL * (idx + 1);
            delivery_cnt += cap;
            pick_cnt += cap;
        }
        
        delivery_cnt -= deliveries[idx];
        pick_cnt -= pickups[idx];
    }
    return answer;
}