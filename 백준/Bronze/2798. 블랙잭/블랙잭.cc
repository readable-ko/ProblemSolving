#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;

int main()
{
    SETTING ;
    
    int N, M, sum = 0;
    cin >> N >> M;
    vector<int> arr(N) ;
    
    for(auto &it : arr)
        cin >> it ;
    
    for(int i = 0 ; i < arr.size() ; i++)
        for(int j = i + 1 ; j < arr.size() ; j++)
            for(int k = j + 1 ; k < arr.size() ; k++)
            {
                int now_sum = arr[i] + arr[j] + arr[k] ;
                if(now_sum <= M) sum = max(now_sum, sum) ;
            }
    
    cout << sum ;
}