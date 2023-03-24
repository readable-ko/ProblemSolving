/**
 * @file 19539.cpp
 * @author fpqpsxh
 * @brief 뭔가 결국 모든 숫자를 만들 수 있으니 전체 합이 3의 배수인지만 확인하면 되는거 아닌가? 했다가
 * 1 1 1 3 3 이면 반례가 생기는 것을 알게 되었고 3의 배수는 만들 수 있는 숫자니 일단 모든 숫자는 3으로 나눈 나머지로 바꾼 후
 * 1의 갯수와 2의 갯수를 비교하면 되지 않나? 는 생각을 하게 되었다. 10 1 1이 반례가 되었다.
 * 뭔가 2가 실마리가 되는 것 같은데 힌트를 참조했다.
 * @test 6 1 1 1 / 6 2 1 / 1 1 1 3 3 / 10 1 1
 * @version greedy
 * @date 2023-03-24
 */
#include <bits/stdc++.h>
using namespace std;
int N, now, cnt_1, cnt_2, sum ;

int main()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> now ;
        sum += now ;
        cnt_2+= now / 2 ;
    }
    if(sum % 3 != 0) cout << "NO\n" ;
    else cnt_2 >= sum / 3 ? cout << "YES\n" : cout << "NO\n" ;
}