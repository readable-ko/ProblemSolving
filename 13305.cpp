#include <bits/stdc++.h>
using namespace std ;
long long int N, answer ;
int money[100000] ;
int way[100000] ;
int main()
{
    cin >> N ;
    for(int i = 0 ; i < N -1 ; i++)
        cin >> way[i] ;
    
    for(int i = 0 ; i < N ; i++)
        cin >> money[i] ;
    
    int minimum = money[0] ;
    for(int i = 0 ; i < N - 1 ; i++)
    {
        minimum = min(minimum, money[i]) ;
        answer += (long long)minimum * way[i] ;
    }
    
    cout << answer ;
}