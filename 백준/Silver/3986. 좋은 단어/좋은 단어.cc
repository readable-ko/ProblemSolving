#include <bits/stdc++.h>
using namespace std ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    int N, answer = 0 ;
    cin >> N ;
    while(N--)
    {
        string str ;
        vector<char> st ;
        cin >> str ;

        for(char c : str)
            if(st.empty()) st.push_back(c) ;
            else if(st.back() == c) st.pop_back() ;
            else st.push_back(c) ;
        
        if(st.empty()) answer++ ;
    }
    cout << answer ;
}