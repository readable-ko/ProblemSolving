#include <bits/stdc++.h>
using namespace std ;
int V, E, K ;
vector< pair<int, int> > arr[20001] ;
int dist[20001] ;
bool visited[20001] ;

struct comp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first ;
    }
};


void Dijkstra()
{    
    // 출발지 0으로
    // 가장 가까운 곳부터 뽑기 시작한다.
    // 거기서 이어지는 모든 엣지르 타서 최소값이 되는지 확인하고 갱신해준다.
    // 갱신된 값을 넣어준다.
    priority_queue<pair<int,int>, vector< pair<int,int> >, comp> pq ;
    dist[K] = 0 ;

    // first : distance | second : vertax
    pq.push({0, K}) ;

    while(!pq.empty())
    {
        pair<int, int> now = pq.top() ;
        pq.pop() ;

        for(int i = 0 ; i < arr[now.second].size() ; i++)
        {
            int next_vertax = arr[now.second][i].first ;
            int nv_dist = arr[now.second][i].second ;

            if(dist[next_vertax] > dist[now.second] + nv_dist)
            {
                dist[next_vertax] = dist[now.second] + nv_dist ;
                pq.push({dist[next_vertax], next_vertax}) ;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> V >> E >> K ;

    for(int i = 0 ; i < E ; i++)
    {
        int x, y, z ;
        cin >> x >> y >> z ;
        arr[x].push_back({y, z}) ;
    }

    fill(dist, dist+V+1, 0x3f3f3f3f) ;
    //fill이랑 fill_n 헷갈리지 말자.

    Dijkstra();

    for(int i = 1 ; i <= V ; i++)
        dist[i] == 0x3f3f3f3f ? cout << "INF\n" : cout << dist[i] << "\n" ;

    return 0 ;
}