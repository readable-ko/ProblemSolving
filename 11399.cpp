#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int T ;
int arr[1001] ;

int main()
{
    cin >> T ;

    for(int i = 1 ; i <= T ; i++)
        cin >> arr[i] ;

    sort(&arr[1], &arr[T+1]) ;
    int answer = arr[1] ;

    for(int i = 2 ; i <= T ; i++)
    {
        arr[i] = arr[i-1] + arr[i] ;
        answer += arr[i] ;
    }
    
    cout << answer ;

    return 0 ;
}