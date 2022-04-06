#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int start = 19 ;
int arr[27] ;
string str ;

int main()
{
    cin >> str ;
    memset(arr, -1, sizeof(int)*27) ;

    // a % 27=19  h%26 = 0 g % 26 = 25
    for(int i = 0 ; i < str.length(); i++)
    {
        if(arr[str[i] % 26] == -1) arr[str[i] % 26] = i ;
    }

    while(1)
    {
        cout << arr[start] << " ";
        if(start == 18) break ;
        start < 25 ? start++ : start = 0 ;
    }
}