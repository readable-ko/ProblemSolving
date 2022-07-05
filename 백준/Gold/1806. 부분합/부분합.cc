#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;

int N, S ;
int arr[100001] ;

int main()
{
    SETTING ;

    cin >> N >> S ;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i] ;

    int sp = 0, ep = 1, cnt = 1, total = arr[0], answer = 0x3f3f3f ;
    
    if(total >= S) answer = cnt ;
    
    for(int i = 1 ; i < N ; i++)
    {
        total += arr[i] ;
        cnt++ ;

        if(total >= S)
        {
            while(total - arr[sp] >= S)
            {
                total -= arr[sp] ;
                cnt-- ;
                sp++ ;
            }
            answer = min(answer, cnt) ;
        }
    }

    answer > N ? cout << "0\n" : cout << answer << "\n" ;
}