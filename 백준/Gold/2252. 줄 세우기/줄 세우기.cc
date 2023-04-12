/**
 * @file 2252.cpp
 * @author fpqpsxh
 * @brief 그냥 위상 정렬 연습하려고 봤는데 기억이 안나네...
 * 일단 그냥 배열 만들면 터질 사이즈니까 벡터에 넣고 만약 앞에 호출된 적있으면 체크해두고 (que에서 탐색할 때 거꾸로 돌려야할 거 같아서)
 * 체크 안된 맨 처음 애들만 que에 넣고 시작하자. 그리고 que 순서대로 출력해주면 되는거 아닌가?
 * 응 아니야~ 44/ 12 23 43 41 했을 때 1423으로 나오는데 bfs로는 할 수 가 없다. 그렇다면 순서를 정해줘야한다.
 * 순서는 어떻게? 나에게 오는 모든 node가 없어지는 순간!
 * @version 0.1
 * @date 2023-04-12
 */
#include <bits/stdc++.h>
using namespace std ;
int N, M ;
int check[32001] ;
bool visited[32001] ;

vector<int> order[32001] ;
vector<int> answer ;

void BFS()
{
    queue<int> que ;

    for(int i = 1 ; i <= N ; i++)
        if(check[i] == 0)
        {
            answer.emplace_back(i) ;
            que.push(i) ;
        }
    
    while(!que.empty())
    {
        int front = que.front() ;
        que.pop() ;

        for(int num : order[front])
        {
            check[num]-- ;
            if(check[num] == 0)
            {
                answer.emplace_back(num) ;
                que.push(num) ;
            }
        }
    }
}

int main()
{
    cin >> N >> M ;
    for(int i = 1 ; i <= M ; i++)
    {
        int sp, ep ;
        cin >> sp >> ep ;
        check[ep]++ ;
        order[sp].emplace_back(ep) ;
    }

    BFS() ;

    for(int num : answer)
        cout << num << " " ;
}