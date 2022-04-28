#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
string str1, str2 ;
string arr[2][1002] ;
int STRSIZE1, STRSIZE2 ;

void InputSetting()
{
    cin >> str2 >> str1 ;
    str1 = " " + str1, str2 = " " + str2 ;
    STRSIZE1 = str1.length() ;
    STRSIZE2 = str2.length() ;
}

void DP()
{
    for(int i = 1 ; i <= STRSIZE1 ; i++)
        for(int j = 1 ; j <= STRSIZE2 ; j++)
        {
            bool row = i % 2 ;
            if(str1[i] == str2[j]) arr[row][j] = arr[!row][j - 1] + str2[j] ;
            else arr[row][j - 1].length() >= arr[!row][j].length() ? arr[row][j] = arr[row][j - 1] : arr[row][j] = arr[!row][j] ;
        }
}

int main()
{
    SETTING ;
    InputSetting() ;
    DP() ;
    string it = arr[STRSIZE1 % 2][STRSIZE2] ;

    if(!it.empty())
        cout << it.length() - 1 << "\n" << it ;
    else
        cout << "0\n" ;
}