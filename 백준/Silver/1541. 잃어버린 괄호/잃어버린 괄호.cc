#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int add, sub ;
string temp ;
bool button ;

int main()
{
    string input ;
    SETTING ;
    cin >> input ;
    for(int i = 0 ; i < input.length() ; i++)
    {
        if(isdigit(input[i])) temp+= input[i] ;
        else
        {
            button ? sub += stoi(temp) : add += stoi(temp) ;
            if(input[i] == '-') button = 1 ;
            temp = "";
        }
    }
    button ? sub += stoi(temp) : add += stoi(temp) ;
    cout << add - sub ;
}