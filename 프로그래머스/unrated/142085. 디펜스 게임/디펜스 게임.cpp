#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0 ;
    priority_queue<int> pq ;
    for(int i = 0 ; i < enemy.size() ; i++) {
        n -= enemy[i] ;
        pq.push(enemy[i]) ;
        
        if(n >= 0) {
            answer = i + 1 ;
        }
        else if(k > 0) {
            k-- ;
            n += pq.top() ;
            pq.pop() ;
            if(n >= 0) answer = i + 1;
        }
        else break;
    }
    return answer;
}