#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> parent ;
vector<int> ranking ;
int rank_max ;

int Find(int num) {
    if(parent[num] == num) return num ;
    
    return Find(parent[num]) ;
}

void Union(int lhs, int rhs) {
    int l = Find(lhs) ;
    int r = Find(rhs) ;
    if(l != r) {
        if(ranking[l] >= ranking[r]) {
            parent[r] = l ;
            ranking[l] += ranking[r] ;
            rank_max = ranking[l] ;
        }
        else {
            parent[l] = r ;
            ranking[r] += ranking[l] ;
            rank_max = ranking[r] ;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 10e3;
    
    for(int i = 0 ; i < wires.size() ; i++) {
        parent = vector<int>(n + 1) ;
        iota(parent.begin(), parent.end(), 0) ;
        
        ranking = vector<int>(n+1, 1) ;
        rank_max = 1 ;
        
        for(int j = 0 ; j < wires.size() ; j++) if(i != j) {
            Union(wires[j][0], wires[j][1]) ;
        }

        answer = min(answer, abs(2 * rank_max - n)) ;
    }
    return answer;
}