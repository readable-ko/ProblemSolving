#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N, dist, weight = 2, cnt = 0, answer = 0, loop = 0 ;
vector< pair< pair <int, int> , int > > eat ;
pair<int, int> now ;
int arr[21][21] ;
bool visited[21][21] ;
int x_arr[] = {0, -1, 0, 1} ;
int y_arr[] = {1, 0, -1, 0} ;

void InputSetting()
{
	SETTING ;
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
	dist = INT_MAX ;
	eat.clear() ;
	queue< pair<int, int> > que ;
	que.push(now) ;
	memset(visited, 0, sizeof(visited)) ;
	loop = 0 ;

	while(!que.empty())
	{
		loop++ ;
		int que_size = que.size() ;
		for(int i = 0 ; i < que_size ; i++)
		{
			int xn = que.front().first ;
			int yn = que.front().second ;
			que.pop() ;
			for(int j = 0 ; j < 4 ; j++)
			{
				int x = xn + x_arr[j] ;
				int y = yn + y_arr[j] ;

				if(x > 0 && x <= N && y > 0 && y <= N)
				{
					if(arr[x][y] <= weight && !visited[x][y])
					{
						que.push({x,y}) ; visited[x][y] = 1 ;
						if(arr[x][y] > 0 && weight > arr[x][y])
						{
							if(dist >= loop)
							{
								dist = loop ;
								eat.push_back({{x,y},dist}) ;
							}
						}
					}
				}
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

int main()
{
	InputSetting() ;
	while(1)
	{
		BFS() ;
		if(eat.empty()) break ;
		else
		{
			sort(eat.begin(), eat.end()) ;
			cnt++ ;
			answer += eat[0].second ;
			int temp_X = eat[0].first.first ;
			int temp_Y = eat[0].first.second ;
			arr[temp_X][temp_Y] = 0 ;
			now = {temp_X, temp_Y} ;
			if(weight == cnt)
			{
				cnt = 0 ; weight++ ;
			}
		}
	}

	cout << answer ;
	return 0 ;
}