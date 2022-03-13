//https://st-lab.tistory.com/162 페르마의 소 정리!
//https://velog.io/@gidskql6671/%EC%9D%B4%ED%95%AD-%EA%B3%84%EC%88%98-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
#include <iostream>
#define MOD 10007
using namespace std ;
int dp[2][1001] ;

int combination(int N)
{
    int i = 1 ;
    for(int front = 1 ; front <= N ; front++)
    {
        i = !i ;
        dp[i][0] = 1, dp[i][front] = 1 ;
        for(int j = 1 ; j < front ; j++)
        {
            dp[i][j] = (dp[!i][j-1] + dp[!i][j]) % MOD ;
        }
    }
    return i ;
}

int main()
{
    int N, K ;
    cin >> N >> K ;
    int i = combination(N) ;
    cout << dp[i][K] ;
}