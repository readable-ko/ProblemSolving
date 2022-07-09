#include <iostream>
using namespace std ;

int main(int T)
{
    cin >> T ;
    printf((T % 10) ? "-1": "%d %d %d", T/300, T%300/60, T%60/10) ;
}