#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int main()
{
    SETTING ;
    register string arr ;
    register int num = 0, N = 0;
    cin >> arr >> N ;

    for(register int i = arr.length() - 1 ; i >= 0 ; i--)
    {
        num = num << 1 ;
        if(arr[i] == 'B') num ^= 1;
    }

    num += N ;


    for(register int i = 0 ; i < arr.length() ; i++)
    {
        num & 1 == 1 ? cout << "B" : cout << "A" ;
        num >>= 1 ;
    }
}