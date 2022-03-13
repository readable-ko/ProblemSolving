#include <bits/stdc++.h>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int N, K,testCases, DEST ;
int building[100001] ;
int answer[100001] ;
vector< vector<int> > graph(100001) ;

void dp()
{
    queue<int> que ;
    int prev ;
    
    que.push(graph[DEST].back()) ;
    prev = DEST ;
    answer[DEST] = 0 ;
    graph[DEST].pop_back() ;

    while(!que.empty())
    {
        answer[que.front()] = min(answer[que.front()], answer[prev] + building[prev]) ;
        que.push()
    }
}

void input_setting()
{
    int starting, ending ;
    memset(&building, 0, 100001 * sizeof(int)) ;
    fill(&answer[0], &answer[100001], INT_MAX) ;
    graph = vector< vector<int> >(100001);
    cin >> N >> K ;
    for(int i = 1 ; i <= N ; i++)
        cin >> building[i] ;
    
    for(int i = 1 ; i <= K ; i++)
    {
        cin >> ending >> starting ;
        graph[starting].push_back(ending) ;
    }
    cin >> DEST ;
}

int main()
{
    SETTING ;
    cin >> testCases ;
    for(int i = 0 ; i < testCases ; i++)
    {
        input_setting() ;
        dp() ;
    }
    
}