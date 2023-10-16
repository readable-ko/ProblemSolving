#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
/*
* 근거. wire는 최대 100개 이하이며 각각을 기준으로 완전탐색은 최악 100회 이하
* 10000번이므로 1초 이내이니까 완전탐색 때려보자!
*/

//sp: staring_point cp: cutting_point
int BFS(vector< vector<int> > &tree, int sp, int cp) {
    int cnt = 1 ;
    queue<int> que ;
    vector<bool> visited(101) ;
    visited[sp] = 1 ;
    
    for(int branch : tree[sp])
        if(!visited[branch] && branch != cp) {
                visited[branch] = 1 ;
                que.push(branch) ;
                cnt++ ;
            }
    
    while(!que.empty()) {
        int front = que.front() ;
        que.pop() ;
        
        for(int branch : tree[front])
            if(!visited[branch]) {
                visited[branch] = 1 ;
                que.push(branch) ;
                cnt++ ;
            }
    }
    
    return cnt ;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    // 1. 트리 완성하기
    vector< vector<int> > tree(101) ;
    
    for(vector<int> wire : wires) {
        tree[wire[0]].push_back(wire[1]) ;
        tree[wire[1]].push_back(wire[0]) ;
    }
    
    
    // 2. 각 wire를 기준으로 끊어내서 양옆 사이즈 구하기
    // 3. 사이즈 차이 최소를 정답으로.
    for(vector<int> wire : wires) {
        int rhs = BFS(tree, wire[0], wire[1]) ;
        int lhs = BFS(tree, wire[1], wire[0]) ;
        
        if(abs(rhs - lhs) < answer)
            answer = abs(rhs - lhs) ;
    }
    
    return answer;
}