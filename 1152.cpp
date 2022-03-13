#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int answer = 0 ;
    string str ;
    getline(cin, str) ;
    int i = str[0] == ' ' ? 1 : 0 ;

    for( ; i < str.length() ; i++)
    {
        if(str[i] == ' ') answer++ ;
    }
    str.back() == ' ' ? cout << answer : cout << ++answer ;
}