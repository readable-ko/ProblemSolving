#include <iostream>
using namespace std ;

int main()
{
    int s, e, cnt = 1, ans = 0;
    cin >> s >> e ;
    for(int i = 1 ; i <= e ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            if(cnt >= s && cnt <= e)
            {
                ans += i ;
            }
            cnt++ ;
        }
    }
    
    cout << ans ;
}