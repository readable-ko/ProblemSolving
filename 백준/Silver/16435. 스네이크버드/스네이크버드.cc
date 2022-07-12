#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, L ;

int main()
{
    SETTING ;
    cin >> N >> L ;
    int arr[N] ;

    for(int i = 0 ; i < N ; i++)
        cin >> arr[i] ;

    sort(&arr[0], &arr[N]) ;
    
    for(int i = 0 ; i < N ; i++)
    {
        if(arr[i] <= L) L++ ;
        else break ;
    }

    cout << L ;
}