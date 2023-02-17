#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int M,K ;
bool flag ;
string N ;
stack<char> st ;

int main()
{
    cin >> M ;
    cin >> N ;
    cin >> K ;
    for(int i = 0 ; i < N.length() ; i++)
        st.push(N[i]) ;
    
    for(int i = 0 ; i < K ; i++)
    {
        if(st.empty()) break ;
        
        char now = st.top() ;
        st.pop() ;

        if(now != '0')
        {
            cout << "NO\n" ;
            return 0 ;
        }
    }
    cout << "YES\n" ;
}