#include <iostream>
using namespace std ;
int stack, answer ;

int main()
{
    string str ;
    cin >> str ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] == '(') stack++ ;
        else if(str[i] == ')' && str[i-1] == '(')
        {
            stack-- ;
            answer += stack ;
        }
        else
        {
            stack--;
            answer++ ;
        }
    }

    cout << answer ;
}