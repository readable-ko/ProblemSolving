/**
 * @file 25370.cpp
 * @author fpqpsxh
 * @date 2023-01-17
 * @brief 뭔가 패턴이 있어보이지 않아서 브루트포스인 것 같은데 N이 정해져있지 않아서 난관이었다.
 * 그러다 문득 곱셈이니 한 숫자씩 붙잡고 1~9를 곱하고 다음 숫자를 바꿔가는 형식이면 되지 않을까?
 * 생각하게 되었고 그럼 set을 사용하자는 생각을 하게 되었다. --> set은 sort되는 문제가 있다.
 * 그럼 좀 더 느리지만 배열와 bool 배열을 사용해서 구현하고자 했다. 최대값 9^7확인해보니 400만이라 구현가능!
 **/
#include <bits/stdc++.h>
using namespace std ;
bool checker[5000000] ;
int N, answer ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> arr ;
    checker[1] = 1 ;
    arr.push_back(1) ;

    for(int i = 0 ; i < N ; i++)
    {
        int size = arr.size() ;
        for(int j = 0 ; j < size ; j++)
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp = arr[j] * k ;
                if(!checker[tmp])
                {
                    checker[tmp] = 1 ;
                    arr.push_back(tmp) ;
                }
            }
    }

    cout << arr.size() ;
}