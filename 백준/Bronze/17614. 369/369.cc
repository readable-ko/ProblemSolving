#include <iostream>
using namespace std ;

int main()
{
    int N, answer = 0 ;
    cin >> N ;

    for(int i = 1 ; i <= N ; i++)
    {
        int test =  i ;
        while(test)
        {
            if(test % 10 == 3 || test % 10 == 6 || test % 10 == 9)
                answer++ ;
            
            test = test / 10 ;
        }
    }
    cout << answer ;
}