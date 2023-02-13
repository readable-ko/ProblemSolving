/**
 * @file 23879.cpp
 * @author fpqpsxh
 * @brief 뭔가 dp나 그리디 같은데 메모리가 1GB로 후하다.. dp인가..? 시간보니 그리딘가...
 * N 10만이라 긴가민가하다. 하루 고민해보니 결국 조약돌 문제처럼 한 번에 최대한 많은 방의 온도를 맞춰야한다.
 * 바깥쪽부터 +들끼리 묶어주면서 처리하고 -끼리 묶어주면서 처리하고 하면 되지 않을까? -> WA 받았다
 * dp같지 않은 조약돌같은 dp로 풀어보자
 * @date 2023-02-09 ~ 2023-02-10
 */
#include <bits/stdc++.h>
using namespace std ;
int N ;
bool flag ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    string pw ;
    cin >> pw ;

    cin >> N ;
    string word[N] ;
    for(int i = 0 ; i < N ; i++)
        cin >> word[i] ;
    
    for(int i = 0 ; i < 27 ; i++)
    {
        for(int j = 0 ; j < pw.size() ; j++)
            if(pw[j] + 1 <= 'z') pw[j]++ ;
            else pw[j] = 'a' ;
        
        for(int j = 0 ; j < N ; j++)
            if(pw.find(word[j]) != string::npos) flag = 1 ;
        
        if(flag) break ;
    }
    cout << pw << '\n' ;
}