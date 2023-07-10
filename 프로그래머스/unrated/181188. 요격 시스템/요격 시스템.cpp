#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int s = -1, e = -1 ;
    sort(targets.begin(), targets.end());
    
    for(vector<int> target : targets) {
        if(s == -1 && e == -1) {
            s = target[0], e = target[1] ;
            answer++ ;
        }
        else if(target[1] < e) e = target[1] ;
        else if(target[0] < e) continue ;
        else {
            s = target[0], e = target[1] ;
            answer++ ;
        }
    }
    
    return answer;
}