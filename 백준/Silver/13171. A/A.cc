#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007 ;
long long X, A ;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0) ;
	cin >> A ; cin >> X ;

	vector<long long> saved ;
	saved.push_back(A % MOD) ;

	while((1LL << (saved.size() - 1)) < X)
	{
		long long top = saved.back() % MOD ;
		saved.push_back((top * top) % MOD) ;
	}

	long long int answer = 1 ;
	for(int i = 0 ; i < saved.size() ; i++)
	{
		if(X & (1LL << i))
			answer = (answer * saved[i]) % MOD ;
	}
	cout << answer << "\n" ;
}