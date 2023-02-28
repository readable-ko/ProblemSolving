/**
 * @file 1043.cpp
 * @author fpqpsxh
 * @brief 뭔가 결국 진실을 알고 있는 노드들과 연결되어있지 않은 노드들만 있는 파티를 찾으면 되는 것 같아서
 * 진실을 아는 사람들을 que에 넣고 그 que와 연결된 노드를 찾기 위해 bfs를 하고 그 이후 파티에서 걸러주었다.
 * @date 2023-02-28
 */
#include <bits/stdc++.h>
using namespace std;
queue<int> que ;
vector<int> party[51] ;
int graph[51][51] ;
bool check[51] ;
int N, M, cnt ;

void BFS()
{
    while(!que.empty())
    {
        int fnt = que.front() ;
        que.pop() ;

        for(int i = 1 ; i <= N ; i++)
            if(!check[i] && graph[fnt][i])
            {
                check[i] = 1 ;
                que.push(i) ;
            }
    }
}

void get_answer()
{
    BFS() ;

    int answer = 0 ;
    for(int i = 0 ; i < M ; i++)
    {
        bool flag = 1 ;
        for(int j = 0 ; j < party[i].size() ; j++)
            if(check[party[i][j]])
            {
                flag = 0 ;
                break ;
            }
         
        if(flag) answer++ ;
    }

    cout << answer << '\n' ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M >> cnt ;
    for(int i = 0 ; i < cnt ; i++)
    {
        int tmp ;
        cin >> tmp ;
        check[tmp] = 1 ;
        que.push(tmp) ;
    }

    for(int i = 0 ; i < M ; i++)
    {
        cin >> cnt ;
        for(int j = 0 ; j < cnt ; j++)
        {
            int tmp ;
            cin >> tmp ;
            party[i].push_back(tmp) ;
        }

        for(int j = 0 ; j < party[i].size() ; j++)
            for(int k = 0 ; k < party[i].size() ; k++)
                if(j != k) graph[party[i][j]][party[i][k]] = graph[party[i][k]][party[i][j]] = 1 ;
    }
    get_answer() ;
}