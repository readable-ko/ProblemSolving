#include <iostream>
#include <cmath>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std ;
long long int N, tmp ;

int main()
{
    SETTING ;
    cin >> N ;
    tmp = N ;

    if(N > 1)
        tmp = MIN(ceil((N + 1) / 2.0), tmp) ;
    if(N > 3)
        tmp = MIN(ceil((N + 3) / 3.0), tmp) ;
    if(N > 6)
        tmp = MIN(ceil((N + 6) / 4.0), tmp) ;
    if(N > 10)
        tmp = MIN(ceil((N + 10) / 5.0), tmp) ;
    if(N > 15)
        tmp = MIN(ceil((N + 15) / 6.0), tmp) ;
    if(N > 21)
        tmp = MIN(((N + 21) / 7 + ((N + 21) % 7 != 0)), tmp) ;
    
    cout << tmp << "\n" ;
}