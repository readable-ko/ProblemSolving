#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, maxi, now ;

void DigitSum()
{
    int tmp = now ;
    while(tmp != 0)
    {
        now += tmp % 10 ;
        tmp /= 10 ;
    }
}

int main()
{
    SETTING ;
    cin >> N ;
    for(int i = N ; i >= 0 ; i--)
    {
        now = i ;
        DigitSum() ;
        if(N == now) maxi = i ;
    }

    cout << maxi ;
}