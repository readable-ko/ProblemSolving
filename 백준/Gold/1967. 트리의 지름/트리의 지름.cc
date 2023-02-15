/**
 * @file 1967.cpp
 * @author fpqpsxh
 * @brief 처음에 1만개의 배열이면 벨만포드로 풀 수 있겠다 생각했는데
 * 모든 간선에 대해 계산하면 N * O(NV)라 시간초과가 날 거 같더라. 그럼 어떻게 해야하나
 * DFS떄려야하나 고민하다가 예전에 풀었던 트리문제가 생각났다. 증명하자.
 * 근데 예전에 풀었던 문제인데 기억 못했던 거 보면 내 머리 빡대가리
 * @version DFS
 * @date 2023-02-15
 * 
 */
#include <bits/stdc++.h>
using namespace std ;
class tree
{
    public:
    int ep;
    int value;

    tree(int e, int val) {ep = e, value=val ;}
};

int N, sp, ep, val ;
tree max_node = tree(0, 0);
bool check[10001] ;
vector<tree> node[10001] ;

void DFS(int point, int val)
{
    if(val > max_node.value) max_node = tree(point, val) ;

    for(int i = 0 ; i < node[point].size() ; i++)
    {
        int new_point = node[point][i].ep ;

        if(!check[new_point])
        {
            check[new_point] = 1 ;
            DFS(new_point, val + node[point][i].value) ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    while(--N)
    {
        cin >> sp >> ep >> val ;
        node[sp].push_back(tree(ep, val)) ;
        node[ep].push_back(tree(sp, val)) ;
    }

    DFS(1, 0) ;
    
    memset(check, 0, sizeof(check)) ;
    check[max_node.ep] = 1 ;
    max_node.value = 0 ;

    DFS(max_node.ep, 0) ;

    cout << max_node.value ;
}