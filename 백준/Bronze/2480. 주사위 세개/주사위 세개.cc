#include <iostream>
using namespace std ;

int main()
{
    int a, b, c ;
    cin >> a >> b >> c ;
    int xor_abc = a ^ b ^ c ;
    if(a == b && b == c) cout << 10000 + a * 1000 << "\n" ;
    else if(xor_abc == a) cout << 1000 + b * 100 << "\n" ;
    else if(xor_abc == b) cout << 1000 + c * 100 << "\n" ;
    else if(xor_abc == c) cout << 1000 + a * 100 << "\n" ;
    else cout << max(max(a, b), c) * 100 << "\n" ;
}