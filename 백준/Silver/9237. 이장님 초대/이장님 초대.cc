#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int answer, N ;

int main()
{
    SETTING ;
    cin >> N ;
    vector<int> arr(N) ;

    for(auto &it : arr)
        cin >> it ;

    sort(arr.begin(), arr.end(), greater<int>()) ;
    
    for(int i = 1 ; i <= arr.size() ; i++)
    {
        if(arr[i - 1] - arr.size() + i <= 0) continue ;
        answer = max(answer, arr[i - 1] - (int)arr.size() + i) ;
    }

    cout << answer + N + 1 ;
}