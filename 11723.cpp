#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
unsigned int arr ;

int main()
{
    SETTING ;
    int N, x ;
    cin >> N ;
    string str ;
    while(N--)
    {
        cin >> str ;
        if(str == "all" || str == "empty")
        {
            str == "all" ? arr = (1<<21) - 1 : arr = 0 ;
        }
        else
        {
            cin >> x ;
            switch(str[0])
            {
                case 'a' : arr = arr | (1<<x) ; break ;
                case 'r' : arr &= (arr ^ (1<<x)) ; break ;
                case 't' : arr ^= (1<<x) ; break ;
                case 'c' : arr & (1<<x) ? cout << "1\n" : cout << "0\n" ;
            }
        }
    }
}