#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int N, small, large, sum ;
int arr[51] ;

int main()
{
    SETTING ;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> arr[i] ;
        if(i == 1)
        {
            small = large = arr[i] ;
        }
        else
        {
            if(arr[i] > large) large = arr[i] ;
            if(arr[i] < small) small = arr[i] ;
        }
        sum += arr[i] ;
    }

    cout << sum - (large + small) ;
}