#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int N, answer = 0 ;
    cin >> N ;
    
    vector<int> temp(N+2) ;
    for(int i = 1 ; i <= N ; i++)
        cin >> temp[i] ;
    
    for(int i = 1 ; i <= N ; i++)
    {
        int want ;
        cin >> want ;
        temp[i] -= want ;
    }

    for(int i = 0 ; i <= N ; i++)
        answer += abs(temp[i] - temp[i+1]) ;
    
    cout << answer / 2 << "\n" ;
}