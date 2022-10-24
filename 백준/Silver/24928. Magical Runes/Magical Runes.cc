#include <bits/stdc++.h>
using namespace std ;

int main()
{
    string str ;
    int N, answer ;
    cin >> str >> N ;
    
    for(int i = str.length() - 1 ; i + 1 ; i--)
    {
        answer <<= 1 ;
        if(str[i] == 'B') answer |= 1 ;
    }
    
    answer += N ;
    
    for(int i = 0 ; i < str.length() ; i++)
    {
        answer & 1 ? cout << 'B' : cout << 'A' ;
        answer >>= 1;
    }
}