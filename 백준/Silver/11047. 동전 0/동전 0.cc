#include <iostream>
#include <limits.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int arr[10] ;
int N, K, sub = INT_MAX, CNT ;

int main()
{
    SETTING ;
    cin >> N >> K ;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i] ;

    while(K)
    {
        if(K < sub)
        {
            for(int i = 0 ; i < N ; i++)
            {
                if(K >= arr[i]) sub = arr[i] ;
                else break ;
            }
        }
        K -= sub ;
        CNT++ ;
    }
    cout << CNT ;
}