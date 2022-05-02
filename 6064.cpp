// Soon Try agian.
#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int N, M, x, y ;

int main(){
	int T ;
	cin >> T ;
	while(T--)
	{
		cin >> M >> N >> x >> y ;
		x--; y--;
		int i = x ;

		for(; i < M*N ; i += M)
		{
			if(i % N == y) break ;
		}

		i >= M*N ? cout << "-1\n" : cout << i+1 << "\n" ;
	}	
}