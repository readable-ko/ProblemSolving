#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
// 모든 숫자는 1개뿐이며 순서도 1개 뿐. one to one이며 onto 함수다.
// 고로 모든 숫자들을 찍어보며 가장 점수가 큰 2 경우를 고르면 된다.
using namespace std;

int DFS(int idx, int card, vector<bool> &visited, vector<int> &cards) {
    if(visited[card]) return idx ;

    visited[card] = 1 ;
    return DFS(idx + 1, cards[card - 1], visited, cards) ;
}

int solution(vector<int> cards) {
    int answer = 0;
    priority_queue<int> pq ;
    vector<bool> visited(cards.size() + 1) ;
    
    for(int card : cards) {
        if(visited[card]) continue ;
        pq.push(DFS(0, card, visited, cards)) ;
    }

    if(pq.size() >= 2) {
        answer = pq.top() ; pq.pop() ;
        answer *= pq.top() ;
    }
    return answer;
}