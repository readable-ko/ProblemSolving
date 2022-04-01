#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int T, N, answer ;
map<string, int> arr ;

int main()
{
    SETTING ;
    cin >> T ;
    while(T--)
    {
        arr.clear() ;
        cin >> N ;
        while(N--)
        {
            string temp ;
            cin >> temp >> temp ;
            arr[temp]++ ;
        }
        answer = 1 ;
        for(auto it : arr)
            answer *= (it.second + 1);
        cout << answer - 1 << endl;
    }
}