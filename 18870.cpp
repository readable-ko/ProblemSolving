#include <bits/stdc++.h>
#include <map>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
multimap<int, int> arr ;
int answer[1000001] ;

int main()
{
    SETTING ;
    int N, temp, count = 0, prev = INT_MAX ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> temp ;
        arr.insert({temp, i}) ;
    }

    for(auto it = arr.begin() ; it != arr.end() ; it++)
    {
        it->first == prev ? answer[it->second] = count : answer[it->second] = ++count ;
        prev = it->first ;
    }
    for(int i = 0 ; i < N ; i++)
        cout << answer[i] - 1 << " " ;
}