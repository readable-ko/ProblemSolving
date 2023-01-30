/**
 * @file 2358.cpp
 * @author fpqpsxh
 * @date 2023-01-30
 * @brief key들만 따로 저장할 방법이 떠오르지 않아서 set과 map을 이용하였다.
 **/
#include <bits/stdc++.h>
using namespace std ;
set<int> points ;
map<int, int> x_axis, y_axis ;
int N, x, y, answer ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> x >> y ;
        x_axis[x]++ ;
        y_axis[y]++ ;
        points.insert(x) ;
        points.insert(y) ;
    }

    for(set<int>::iterator i = points.begin() ; i != points.end() ; i++)
    {
        if(x_axis[*i] > 1) answer++ ;
        if(y_axis[*i] > 1) answer++ ;
    }


    cout << answer << '\n' ;
}