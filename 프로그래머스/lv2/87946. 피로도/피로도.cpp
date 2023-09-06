#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[9];
int answer = 0 ;

int DFS(int idx, int tired, vector<vector<int>> &dungeons) {
    int maxi = idx;
    for(int i = 0 ; i < dungeons.size() ; i++) {
        if(visited[i]) continue ;
        if(tired < dungeons[i][0]) continue ;
        visited[i] = 1 ;
        maxi = max(maxi, DFS(idx + 1, tired-dungeons[i][1], dungeons)) ;
        visited[i] = 0 ;
    }
    
    return maxi ;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = DFS(0, k, dungeons);
    return answer;
}