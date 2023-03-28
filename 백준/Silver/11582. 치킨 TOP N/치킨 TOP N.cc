#include<bits/stdc++.h>
using namespace std;
int N, now ;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0) ;
	cin >> N ;
	vector<int> chicken(N) ;

	for(int &it : chicken)
		cin >> it ;
	cin >> now ;

	for(int i = 0 ; i < N ; i+= N/now)
	{
		sort(&chicken[i], &chicken[i + N / now]) ;
	}

	for(int it : chicken)
		cout << it << " " ;
}