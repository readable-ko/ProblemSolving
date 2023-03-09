#include<bits/stdc++.h>
using namespace std;

long long int Solution(long long int val)
{
    long long int answer = INT64_MAX, now ;
    for(long long int i = 1 ; i * i <= val ; i++)
    {
        if(ldiv(val, i).rem == 0)
        {
            now = ldiv(val, i).quot + i - 2 ;
            answer = min(answer, now) ;
        }
    }
    return answer ;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long int tmp ;
        cin >> tmp ;
        cout << "#" << test_case << " " << Solution(tmp) << "\n" ;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}