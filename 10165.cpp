#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;

int N, M, s, e ;
struct node {
    int start, end, station ;
    node(int x, int y, int z) : start(x), end(y), station(z) {}
};

bool compare(node a, node b) {
    if(a.start == b.start) return a.end > b.end ;
    return a.start < b.start ;
}

bool comp_station(node a, node b) {
    return a.station < b.station ;
}

vector<node> arr ;

int main()
{
    SETTING ;
    cin >> N >> M ;
    for(int i = 0 ; i < M ; i++)
    {
        cin>> s >> e ;
        if(s > e) {
            arr.push_back(node(s, e + N, i + 1)) ;
            arr.push_back(node(s - N, e, i + 1)) ;
        }
        else arr.push_back(node(s, e, i + 1)) ;
    }

    sort(arr.begin(), arr.end(), compare) ;

    vector<node> sort_start ;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(sort_start.empty() || sort_start.back().end < arr[i].end) sort_start.push_back(arr[i]) ;
    }
    
    sort(sort_start.begin(), sort_start.end(), comp_station) ;
    
    
    int prev = INT_MAX ;
    for(auto i : sort_start)
        if(i.station != prev)
        {
            cout << i.station << " " ; prev = i.station ;
        }
}