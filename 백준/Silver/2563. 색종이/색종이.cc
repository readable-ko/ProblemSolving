#include <bits/stdc++.h>
using namespace std ;
bool paper[101][101] ;
int cases, answer ;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0) ;
	cin >> cases ;

	int row, col ;
	while(cases--)
	{
		cin >> row >> col ;
		for(int i = row ; i < row + 10 ; i++)
			for(int j = col ; j < col + 10 ; j++)
				paper[i][j] = 1 ;
	}

	for(int i = 0 ; i <= 100 ; i++)
		for(int j = 0 ; j <= 100 ; j++)
			if(paper[i][j]) answer++ ;

	cout << answer ;
}