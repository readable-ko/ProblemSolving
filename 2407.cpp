#include <bits/stdc++.h>
using namespace std ;
string dp[101][101] ;

string adder(string x, string y)
{
    string answer = "";
    int carry = 0 ;
    for(int i = 0 ; i < max(x.length(), y.length()) ; i++)
    {
        int sum = 0 ;
        if(i < x.length()) sum += x[i] - '0' ;
        if(i < y.length()) sum += y[i] - '0' ;
        answer += to_string((sum + carry) % 10) ;
        carry = (sum + carry) / 10 ;
    }
    if(carry) answer += "1" ;
    return answer ;
}

void combination(int N, int M) {
    for(int i = 2 ; i <= N; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            if(j == 0 || j == i) dp[i][j] = "1" ;
            else dp[i][j] = adder(dp[i-1][j], dp[i-1][j-1]) ;
        }
    }
}

int main()
{
    int N, M ;
    cin >> N >> M ;
    dp[1][0] = "1" , dp[1][1] = "1" ;
    combination(N, M) ;
    for(int i = dp[N][M].length() - 1 ; i >= 0 ; i--)
    {
        cout << dp[N][M][i] ;
    } 
    cout << "\n";
}