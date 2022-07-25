#include <bits/stdc++.h>
using namespace std ;
int V ;
vector< pair<int, int> > arr[100001] ;
int dist[100001] ;
int global_max, max_leaf ;

struct comp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first ;
    }
};


void Dijkstra(int s)
{
    priority_queue<pair<int,int>, vector< pair<int,int> >, comp> pq ;
    fill(dist, dist+V+1, 0x3f3f3f3f) ;
    dist[s] = 0 ;
    
    // first : distance | second : vertax
    pq.push({0, s}) ;

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
                if(dist[next_vertax] > global_max)
                {
                    global_max = dist[next_vertax] ;
                    max_leaf = next_vertax ;
                }
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> V ;

    for(int i = 0 ; i < V ; i++)
    {
        int x, y, z ;
        cin >> x >> y ;
        while(y != -1)
        {
            cin >> z ;
            arr[x].push_back({y, z}) ;
            cin >> y ;
        }
    }

    Dijkstra(1);
    Dijkstra(max_leaf) ;
    cout << global_max << "\n" ;

    return 0 ;
}