#include <bits/stdc++.h>
using namespace std ;
int N ;

int main()
{
    scanf("%d", &N) ;
    vector<bool> arr(N) ;
    vector< pair<int, int> > ans(N+1) ;
    ans[0].first = 1 ;
    ans[0].second = 0 ;
    getchar() ;

    for(int i = 0 ; i < N ; i++)
    {
        char tmp = getchar() ;
        if(tmp == 'A')
        {
            arr[i] = 1 ;
            if(i == 0)
            {
                ans[0].first = 0 ;
                ans[0].second = 1 ;
            }
        }
    }

    for(int i = 1 ; i < N ; i++)
    {
        if(arr[i] == 0)
        {
            ans[i].first = min(ans[i-1].first + 1, ans[i-1].second + 1) ;
            ans[i].second = min(ans[i-1].first + 1, ans[i-1].second) ;
        }
        else
        {
            ans[i].first = min(ans[i-1].first, ans[i-1].second + 1) ;
            ans[i].second = min(ans[i-1].first + 1, ans[i-1].second + 1) ;
        }
    }

    printf("%d", ans[N-1].first) ;
}