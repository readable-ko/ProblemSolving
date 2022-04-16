#include <bits/stdc++.h>
using namespace std ;
int N, M, weight = 2, cnt = 0 ;
pair<int, int> now ;
int arr[21][21] ;
int x_arr[] = {0, -1, 0, 1} ;
int y_arr[] = {1, 0, -1, 0} ;

void InputSetting()
{
	cin >> N ;
	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= N ; j++)
		{	
			cin >> arr[i][j] ;
			if(arr[i][j] == 9)
			{
				now = {i, j} ;
				arr[i][j] = 0 ;
			}
		}
}

void BFS()
{
	queue< pair<int, int> > que ;
	que.push(now) ;
	
	while(!que.empty())
	{
		int que_size = que.size() ;
		for(int i = 0 ; i < que_size ; i++)
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				int x = que.front().first + x_arr[j] ;
				int y = que.front().second + y_arr[j] ;
				if(x > 0 && x < 21 && y > 0 && y < 21)
				{
					if(arr[x][y] <= weight) que.push({x,y}) ;
				}
			}			
		}
		//크면 못넘어가고 무섭다 몬간다.
		//같으면 지나갈 수만 있고 다음에 죽여주자.
		//작으면 잡아먹고 먹고 cnt올리고 자리빵으로. cnt가 wieght되면 cnt는 빵 weight은 증가
		//가장 위에나 왼쪽에 있는것부터 처먹는다. i j 순으로 따지면 되겠제?
		//BFS로 조져보자. 안에 for문 넣어서 cnt 갯수 세보고 처먹는 순간 cnt는 0이다.
		//처먹는 순간 que 비우고 그 자리에서 4개 채운다.
		//오버 되면 바로 빠구, 넣지도 못하게.

	}
}

int main()
{
	InputSetting() ;
	BFS() ;
}