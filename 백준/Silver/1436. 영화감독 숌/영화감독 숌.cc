#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;

//Has More than Three Six...
bool HMTS(int num)
{
    int cnt_six = 0 ;
    while(num)
    {
        if(cnt_six == 3) break ;
        if(num % 10 == 6) cnt_six++ ;
        else cnt_six = 0 ;
        num /= 10 ;
    }
    return cnt_six >= 3 ? true : false ;
}

int main()
{
    SETTING ;
    int N, cnt = 0, i = 666;
    cin >> N ;
    for( ; i <= 0x3f3f3f3f ; i++)
    {
        if(cnt == N) break ;
        if(HMTS(i)) cnt++ ;
    }

    cout << i - 1;
}