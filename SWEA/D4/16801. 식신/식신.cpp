#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0), cin.tie(0);
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N ;
        ll int K ;
        cin >> N >> K ;

        vector<int> member(N), food(N) ;
        vector<ll int> mf(N) ;
        for(int &it : member) cin >> it ;
        for(int &it : food) cin >> it ;
        sort(member.begin(), member.end(), less<int>()) ;
        sort(food.begin(), food.end(), greater<int>()) ;

        for(int i = 0 ; i < N ; i++)
            mf[i] = (ll)member[i] * food[i] ;
        
        ll int lo = 0, hi = 10e11 + 1 ;
        while(lo != hi)
        {
            ll int cnt = 0, mid = (lo + hi) >> 1 ;
            for(int i = 0 ; i < N ; i++)
                if(mid < mf[i])
                {
                    if(cnt > K) break ;
                    cnt += member[i] - (mid / food[i]) ;
                }
            
            cnt <= K ? hi = mid : lo = mid + 1 ;
        }

        cout << "#" << test_case << " " << lo  << "\n" ;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}