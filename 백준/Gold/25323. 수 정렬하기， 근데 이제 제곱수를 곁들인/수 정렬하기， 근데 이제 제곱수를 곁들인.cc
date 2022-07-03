#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

unsigned long long int lgcd(unsigned long long int x, unsigned long long int y)
{
    if(x < y) swap(x, y) ;
    unsigned long long int c ;
    while(y != 0)
    {
        c = x % y ;
        x = y ;
        y = c ;
    }
    return x ;
}

bool CheckingSqrt(unsigned long long int x, unsigned long long int y, unsigned long long int mn)
{
    double temp_sqrt = sqrt(y/mn) ;
    if((int)temp_sqrt != temp_sqrt) return false ;
    temp_sqrt = sqrt(x/mn) ;
    if((int)temp_sqrt != temp_sqrt) return false ;
    
    return true ;
}

int main()
{
    SETTING ;
    int N ;
    cin >> N ;
    vector<unsigned long long int> arr(N), answer(N) ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> arr[i] ;
        answer[i] = arr[i] ;
    }
    sort(answer.begin(), answer.end()) ;

    bool flag = 1 ;
    for(int i = 0 ; i < N ; i++)
    {
        if(arr[i] != answer[i])
        {
            unsigned long long int mn = lgcd(arr[i], answer[i]) ;
            if(!CheckingSqrt(arr[i], answer[i], mn))
            {
                flag = 0 ;
                break ;
            }
        }
    }

    flag ? cout << "YES\n" : cout << "NO\n" ;
}