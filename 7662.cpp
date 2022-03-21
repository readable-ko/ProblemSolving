#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int K, que_size ;

bool checked[1000001] ;

struct compare
{
	bool operator() (pair<int, int> &a, pair<int, int> &b)
	{
		return a.first > b.first ;
	}
};

void InputSetting()
{
	cin >> K ;
	priority_queue< pair <int, int> > max_que ;
	priority_queue< pair<int, int>, vector< pair<int, int> >, compare> min_que ;

	que_size = 0 ;
	memset(checked, 0, sizeof(bool) * 1000001) ;
	char ID ;
	int value ;
	
	for(int i = 0 ; i < K ; i++)
	{
		cin >> ID >> value ;
		if(ID == 'I')
		{
			min_que.push({value, i}) ;
			max_que.push({value, i}) ;
			checked[i] = true ;
			que_size++ ;
		}
		else
		{
			if(que_size == 0) continue ;
			if(value == 1)
			{
				while(!checked[max_que.top().second])
					max_que.pop() ;
				
				if(que_size == 0) continue ;
				checked[max_que.top().second] = 0 ;
				max_que.pop() ;
				que_size-- ;
			}
			else
			{
				while(!checked[min_que.top().second])
					min_que.pop() ;
				
				if(que_size == 0) continue ;
				checked[min_que.top().second] = 0 ;
				min_que.pop() ;
				que_size-- ;				
			}
		}
	}

	while(que_size != 0 && !checked[min_que.top().second])
		min_que.pop() ;
	while(que_size != 0 && !checked[max_que.top().second])
		max_que.pop() ;

	que_size <= 0 ? cout << "EMPTY" << endl : cout << max_que.top().first << " " << min_que.top().first << endl ;
}

int main()
{
	SETTING ;
    int T ;
    cin >> T ;
    for(int i = 0 ; i < T ; i++)
    {
		InputSetting() ;
    } 
}