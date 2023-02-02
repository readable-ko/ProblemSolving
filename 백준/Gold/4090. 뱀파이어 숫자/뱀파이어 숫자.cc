/**
 * @file 4090.cpp
 * @author fpqpsxh
 * @brief 며칠 전부터 brute force로 뱀파이어 숫자를 판별하면 될 거 같은데 만약 받은 숫자가 뱀파이어 숫자가 아니면
 * 끝없이 올라가면서 확인해야할텐데 느려서 터지지 않을까? 하며 시도도 못하고 고민하고 있었다. 그런데 10초면 꽤나 긴 시간이므로
 * 하나씩 올라가면서 확인하는 방법을 쓰고 뱀파이어 숫자 판별은 결국 공약수 2개로 하면 되겠다는 생각이 들어 시간 단축이 되었으니
 * 진행해보았다.
 * @date 2023-02-02
 */
#include <bits/stdc++.h>
using namespace std ;
int x ;
bool flag ;

bool is_vampire(int x)
{
    flag = 0 ;
    string origin = to_string(x), divided = "" ;
    for(int i = 2 ; i * i <= x ; i++)
    {
        if(x % i == 0)
        {
            divided = to_string(i) + to_string(x / i) ;
            sort(origin.begin(), origin.end()) ;
            sort(divided.begin(), divided.end()) ;
            if(divided.compare(origin) == 0)
            {
                flag = 1 ;
                break ;
            }
        }
    }

    return flag ? true : false ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    while(1)
    {
        cin >> x ;
        if(x == 0) break ;

        while(!is_vampire(x)) ++x ;
        
        cout << x << '\n' ;
    }
}