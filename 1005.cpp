#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int N, K, DEST;
int totalTime[1001] ;
int buildTime[1001] ;
int Topology_Sort[1001] ;
vector< vector <int> > graph(1001) ;

void find_answer()
{
    queue<int> que ;

    for(int i = 1 ; i <= N ; i++)
        if(!Topology_Sort[i]) que.push(i) ;
    
    while(!que.empty())
    {
        int curr = que.front() ;
        que.pop() ;

        if(curr == DEST) break ;
        for(int i = 0 ; i < graph[curr].size() ; i++)
        {
            totalTime[graph[curr][i]] = 
                max(totalTime[graph[curr][i]], totalTime[curr] + buildTime[curr]) ;
            
            Topology_Sort[graph[curr][i]]-- ;
            if(!Topology_Sort[graph[curr][i]]) que.push(graph[curr][i]) ;
        }
    }
}

void input_setting()
{
    int startPoint, endPoint ;
    graph = vector< vector <int> > (1001) ;

    memset(buildTime, 0, sizeof(int) * 1001) ;
    memset(totalTime, 0, sizeof(int) * 1001) ;
    memset(Topology_Sort, 0, sizeof(int) * 1001) ;
    
    cin >> N >> K ;
    for(int i = 1 ; i <= N ; i++)
        cin >> buildTime[i] ;
    
    for(int i = 0 ; i < K ; i++)
    {
        cin >> startPoint >> endPoint ;
        graph[startPoint].push_back(endPoint) ;
        Topology_Sort[endPoint]++ ;
    }

    cin >> DEST ;
}

int main()
{
    SETTING ;
    int T ;
    cin >> T ;
    for(int i = 0 ; i < T ; i++)
    {
        input_setting() ;
        find_answer() ;
        cout << totalTime[DEST] + buildTime[DEST] << "\n" ;
    }
}