#include <bits/stdc++.h>
using namespace std ;
long long int N, curr, previous, sum, aver ;
int arr[200000] ;
int main()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> arr[i] ;
        aver += arr[i] ;
    }

    aver = aver / N ;
    for(int i = 0 ; i < N ; i++)
    {
        sum += abs(previous) ;
        curr = arr[i];
        previous -= (curr - aver) ;
    }
    cout << sum ;
//1  2  3  4  5  6  7
 //-2  2 -1 -2  1  0 -2   
}