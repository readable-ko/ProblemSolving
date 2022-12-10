/**
* number 5737
* @author fpqpsxh
* @date 2022-12-10
* @brief 시간 없어서 브론즈
*/

#include <bits/stdc++.h>
using namespace std;
int max_length ;
string str, temp ;

string CheckPunct()
{
    string tmp = "" ;
    for(char c : temp)
        if(isalpha(c) || c == '-')
            tmp += tolower(c) ;

    return tmp ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    while(1)
    {
        cin >> temp ;
        temp = CheckPunct() ;
        if(temp.length() > max_length)
        {
            str = temp ;
            max_length = temp.length() ;
        }
        if(temp == "e-n-d") break ;
    }

    cout << str ;
}