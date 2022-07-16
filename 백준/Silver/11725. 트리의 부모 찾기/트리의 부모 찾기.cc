#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
vector< vector<int> > tree ;
bool visited[100001] ;
int N, cnt ;

int main()
{
    SETTING ;
    cin >> N ;
    tree = vector< vector<int> >(N+1) ;
    int ans[N+1] ;
    for(int i = 1 ; i < N ; i++)
    {
        int s = 0, e = 0 ;
        cin >> s >> e ;
        tree[s].push_back(e) ;
        tree[e].push_back(s) ;
    }

    queue<int> que ;
    que.push(1) ;
    while(!que.empty())
    {
        int tmp = que.front() ;
        que.pop() ;
        for(int i = 0 ; i < tree[tmp].size() ; i++)
        {
            if(!visited[tree[tmp][i]])
            {
                ans[tree[tmp][i]] = tmp ;
                visited[tree[tmp][i]] = 1 ;
                que.push(tree[tmp][i]) ;
            }
        }
    }

    for(int i = 2 ; i <= N ; i++)
        cout << ans[i] << "\n" ;
}