/**
 * @file 1525.cpp
 * @author fpqpsxh
 * @brief 어떻게 푸는지 좀 고민했는데 결국 bfs 돌리면 되는거 아닌가? 패턴은 못찾았는데
 * 배열 10억개만 쓰면..? 배열 10억개 좀 빡세다 string map으로 해보자.
 * 놓친부분1. 4번째칸과 3번째 칸 6번째칸과 7번째칸 교환이 불가능하다.
 * @version 0.1
 * @date 2023-04-02
 */
#include <bits/stdc++.h>
using namespace std ;
const string want = "123456780" ;
vector<int> puzzle(9) ;
map<string, int> mp ;
int way[] = {1, -1, -3, 3} ;

int BFS()
{
	queue<string> que ;
	string start ;
	for(int& it : puzzle)
		start +=  it + '0' ;
	
	que.push(start) ;
	while(!que.empty())
	{
		string front = que.front() ;
		que.pop() ;
		if(front == want) return mp[front] ;

		int idx = 0 ;

		for( ; idx < front.size() ; idx++)
			if(front[idx] == '0') break ;

		for(int i = 0 ; i < 4 ; i++)
		{
			string new_str = front ;
			if(idx + way[i] < 0 || idx + way[i] > 8) continue ;
			if(i == 0 && (idx + way[i]) / 3 > idx / 3) continue ;
			if(i == 1 && (idx + way[i]) / 3 < idx / 3) continue ;

			swap(new_str[idx], new_str[idx + way[i]]) ;
			
			if(mp[new_str] == 0)
			{
				mp[new_str] = mp[front] + 1 ;
				que.push(new_str) ;
			}
		}
	}

	return -1 ;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0) ;
	for(int& it : puzzle)
		cin >> it ;

	cout << BFS() ;
}