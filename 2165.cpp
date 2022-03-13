#include <bits/stdc++.h>
using namespace std ;
int arr1[10001] ;
int arr2[10001] ;

int main()
{
    int N ;
    cin >> N ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> arr1[i] ;
    }

    int answer = arr1[1] ;
    arr2[1] = arr1[1] ;
    for(int i = 2 ; i<= N ; i++)
    {
        arr2[i] = max(arr2[i-2], arr1[i-2]) + arr1[i] ;
        arr1[i] = max(arr2[i-2], arr2[i-1]) + arr1[i] ;
        answer = arr1[i] > arr2[i] ? max(arr1[i], answer) : max(arr2[i], answer) ;
    }

    cout << answer ;
    
}