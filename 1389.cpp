#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define MAX 10000
using namespace std ;
vector< vector<int> > graph(101) ;
bool visited[101] ;
int answer[101] ;
int N, M ;

void InputSetting()
{
    int start, end ;
    cin >> N >> M ;
    for(int i = 1 ; i <= M ; i++)
    {
        cin >> start >> end ;
        graph[start].push_back(end) ;
        graph[end].push_back(start) ;
    }
}

int KevinBacon(int idx)
{
    memset(visited, 0, sizeof(bool) * 101) ;
    visited[idx] = 1 ;

    int bacon_num = 0;
    queue <int> que ;

    for(int it : graph[idx])
    {
        if(!visited[it]) que.push(it) ;
        visited[it] = 1 ;
    }

    int loop = 1 ;
    while(!que.empty())
    {
        int size = que.size() ;

        for(int j = 0 ; j < size ; j++)
        {
            int curr = que.front() ; 
            que.pop() ;

            bacon_num += loop ;
            
            for(int it : graph[curr])
                if(!visited[it])
                {
                    que.push(it) ;
                    visited[it] = 1 ;
                }
        }
        loop++ ;
    }

    return bacon_num ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    fill(&answer[0], &answer[101], MAX) ;
    for(int i = 1 ; i <= N ; i++)
        answer[i] = KevinBacon(i) ;
    cout << min_element(&answer[1], &answer[N+1])-&answer[0] << endl ;
}