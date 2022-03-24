#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
unordered_set<string> arr ;
string answer[500000] ;
int N, M, idx ;

int main()
{
    SETTING ;
    cin >> N >> M ;
    
    string str ;
    for(int i = 0 ; i < M+N ; i++)
    {
        cin >> str ;
        if(i < N) arr.insert(str) ;
        else if(arr.find(str) != arr.end()) answer[idx++] = str ;
    }
    sort(&answer[0], &answer[idx]) ;

    cout << idx << endl ;
    for(int i = 0 ; i < idx ; i++)
        cout << answer[i] << endl;
}