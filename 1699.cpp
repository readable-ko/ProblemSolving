#include <iostream>
#include <math.h>
#include <climits>
#include <algorithm>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int dp[100001] ;

int main()
{
    SETTING ;
    int N, now = 1;
    cin >> N ;
    fill(&dp[0], &dp[100001], INT_MAX) ; 
    dp[0] = 0, dp[1] = 1 ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = floor(sqrt(i)) ; j > 0 ; j--)
        {
            int prev =  i - pow(j, 2) ;
            dp[i] = min(dp[prev] + 1, dp[i]) ;
        }
    }

    cout << dp[N] ;
}


// 쑛코드
//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

bool chk[100050];
bool t_chk[100050];
vector <int> V;
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i * i <= N; i++) {
		chk[i*i] = true;
		V.push_back(i*i);
	}

	if (chk[N]) {
		printf("1");
		return 0;
	}

	for (i = 2;; i++) {
		for (j = 1; j <= N; j++) {
			if (!chk[j]) continue;
			for (k = 0; k < V.size(); k++) {
				if (j + V[k] > N) break;
				t_chk[j + V[k]] = true;
			}
		}
		for (j = 1; j <= N; j++) if (t_chk[j]) chk[j] = true;
		if (chk[N]) break;
	}
	
	printf("%d", i);
	return 0;
}
//*/