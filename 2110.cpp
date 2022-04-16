#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int N, C ;

bool BinSearch(int mid, vector<int> &arr)
{
    int prev = -mid-1, cnt = C ;

    for(int &it : arr)
        if(it - prev >= mid) prev = it, cnt--;

    return cnt <= 0 ;
}

int main()
{
    SETTING ;
    cin >> N >> C ;
    vector<int> arr(N) ;  
    for(int &it : arr)
    {
        cin >> it ;
    }

    sort(arr.begin(), arr.end()) ;

    register int low = 0, high = arr.back() - arr.front() ;
    while(low != high)
    {
        int mid = (low + high + 1) >> 1 ;
        BinSearch(mid, arr) ? low = mid : high = mid - 1 ;
    }

    cout << low ;
}