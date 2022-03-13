#include <iostream>
#include <math.h>
#include <algorithm>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1001][1001] ;
int dp[1001][1001] ;

int max_triple(int &a, int &b, int &c)
{
    return max(a, max(b, c)) ;
}
int main()
{
    SETTING ;
    int N, M ;
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            cin >> arr[i][j] ;

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            dp[i][j] = max_triple(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + arr[i][j] ;

    cout << dp[N][M] << "\n" ;
}

#include <cstdio>
#include <unistd.h>
#define max(x, y) (x > y ? x : y)

int main() {
    char r[1 << 16], *p = r; read(0, r, 1 << 16);
    auto ReadInt = [&]() {
        int n = 0;
        while (1) {
            if (p - r == 1 << 16) read(0, p = r, 1 << 16);
            if (~*p & 16) break;
            n = 10 * n + (*p++ & 15);
        }
        return p++, n;
    };
    
	int n = ReadInt(), m = ReadInt(), DP[1001]{};
    while (n--) for (int i = 1; i <= m; i++) DP[i] = max(DP[i - 1], DP[i]) + ReadInt();
    printf("%d\n", DP[m]);
}