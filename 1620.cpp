#include <bits/stdc++.h>
#include <string>
#include <map>
#define endl "\n"
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std ;
string dogam[100001] ;
map <string, int> answer ;


int main()
{
    SETTING ;
    int N, M ;
    string key = "" ;
    cin >> N >> M ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> dogam[i] ;
        answer.insert({dogam[i], i});
    }
    for(int i = 0 ; i < M ; i++)
    {
        cin >> key ;
        if(isdigit(key[0])) cout << dogam[stoi(key)-1] << endl ;
        else cout << answer[key] + 1 << endl ;
    }
}