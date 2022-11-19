/**
 * number 2447
 * @author fpqpsxh
 * @date 2022-11-20
 * @brief size 3-3으로 쪼개가다가 3이되는 순간 3개짜리 그려줄랬는데
 * 그런식이면 공백처리나 여러줄 처리가 쉽지 않다. i = 1 ; i <=3 이런식으로 할랬는데
 * 그냥 다 보면서 1-1 1-4 1-7 1-10  || 3-3 3-4 3-5 4-3 4-4 4-5 5-3 5-4 5-5 체크해줘야겠다.
 */
#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N ;

void Drawing(int row, int col, int size)
{
    
    if(row / size % 3 == 1 && col / size % 3 == 1) cout << " " ;
    else if(size % 3 == 0) Drawing(row, col, size / 3) ;
    else cout << "*" ;
}

int main()
{
    SETTING ;
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
            Drawing(i, j, N) ;
        cout << "\n" ;
    }
}