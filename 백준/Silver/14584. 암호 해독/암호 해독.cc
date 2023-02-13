#include <bits/stdc++.h>
using namespace std ;
int N ;
bool flag ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    string pw ;
    cin >> pw ;

    cin >> N ;
    string word[N] ;
    for(int i = 0 ; i < N ; i++)
        cin >> word[i] ;
    
    for(int i = 0 ; i < 27 ; i++)
    {
        for(int j = 0 ; j < pw.size() ; j++)
            if(pw[j] + 1 <= 'z') pw[j]++ ;
            else pw[j] = 'a' ;
        
        for(int j = 0 ; j < N ; j++)
            if(pw.find(word[j]) != string::npos) flag = 1 ;
        
        if(flag) break ;
    }
    cout << pw << '\n' ;
}