/**
 * @file 17135.cpp
 * @author fpqpsxh
 * @brief 어렵다.. 최대 N(15) M(15) 인 225개 중에서 궁수를 3명 배치하는 225 C 3 = 대략 180만번
 * 거기에 궁수 3명이 각각 15번의 시뮬레이션을 거치면 180만 x 15 x 3으로 딱 8천번 1초 이내다.
 * 이 문제는 브루트포스로 풀어낼 수 있는 문제이다.
 * @date 2023-03-02
 */
#include <bits/stdc++.h>
using namespace std;

//super class for location
class Human
{
public:
    int x_ ;
    int y_ ;
    Human() {x_ = 0, y_ = 0 ;}
    Human(int x, int y) {x_ = x, y_ = y;}
};

int N, M, D, max_answer ;
int _map[15][15] ;
bool visited[15] ;
Human archer[3] ;

//BFS로 한 턴을 실행.
Human PlayOneTurn(int idx, int new_map[15][15])
{
    int dist = 1 ;
    bool check[15][15] ;
    memset(check, 0, sizeof(check)) ;
    int x_dist[] = {0, -1, 0, 1} ;
    int y_dist[] = {-1, 0, 1, 0} ;
    
    queue<Human> que ;
    que.push(archer[idx]) ;

    while(!que.empty())
    {
        int q_sz = que.size() ;
        for(int j = 0 ; j < q_sz ; j++)
        {
            Human front = que.front() ; que.pop() ;
            for(int i = 0 ; i < 4 ; i++)
            {
                int x_new = front.x_ + x_dist[i] ;
                int y_new = front.y_ + y_dist[i] ;

                if(x_new >= N || y_new >= M || x_new < 0 || y_new < 0) continue ;
                if(dist > D) return Human(-1, -1) ;
                if(new_map[x_new][y_new]) return Human(x_new, y_new) ;

                if(!check[x_new][y_new])
                {
                    check[x_new][y_new] = 1 ;
                    que.push(Human(x_new, y_new)) ;
                }
            }
        }
        dist++ ;  
    }

    return Human(-1, -1) ;
}

void Simulate()
{
    int round = 0, answer = 0 ;
    int new_map[15][15] ;
    Human dead[3] ;
    memcpy(new_map, _map, sizeof(_map)) ;
    while(round <= 15)
    {
        for(int i = 0 ; i < 3 ; i++)
            dead[i] = PlayOneTurn(i, new_map) ;

        for(int i = 0 ; i < 3 ; i++)
        {
            if(dead[i].x_ != -1 && dead[i].y_ != -1 && new_map[dead[i].x_][dead[i].y_] == 1)
            {
                answer++ ;
                new_map[dead[i].x_][dead[i].y_] = 0 ;
            }
        }

        for(int i = N - 2 ; i >= 0 ; i--)
            memcpy(new_map[i + 1], new_map[i], sizeof(new_map[i])) ;
        memset(new_map[0], 0, sizeof(new_map[0])) ;
        
        round++ ;
    }

    max_answer = max(answer, max_answer) ;
}

//궁수 사용하는 조합 찾기.
void SetArcher(int idx, int depth)
{
	for (int i = 0 ; i < M; i++)
		for (int j = i + 1 ; j < M; j++)
			for (int k = j + 1 ; k < M; k++)
			{
                archer[0] = Human(N, i) ;
                archer[1] = Human(N, j) ;
                archer[2] = Human(N, k) ;
                Simulate() ;
            }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> M >> D ;
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin >> _map[i][j] ;
    
    SetArcher(0, 0) ;

    cout << max_answer ;
}