#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int mp[10000001];

int solution(int k, vector<int> tangerine) {
    int answer = 0 ;
    for(int num : tangerine)
        mp[num]++;
    
    sort(&mp[0], &mp[10000001], greater<int>());
    while(k > 0) {
        k -= mp[answer++];
    }
    return answer;
}