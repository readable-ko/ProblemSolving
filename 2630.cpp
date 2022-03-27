#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;
int N, zero_num, one_num ;
int arr[129][129] ;

void DivAndCon(int N, int row, int col)
{
    bool toggle = arr[row][col] ;
    bool flag = 0 ;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            if(toggle != arr[row + i][col + j])
            {
                flag = 1 ; break ;
            }
    
    if(flag)
    {
        DivAndCon(N / 2, row , col) ;
        DivAndCon(N / 2, row, col + (N / 2)) ;
        DivAndCon(N / 2, row + (N / 2), col) ;
        DivAndCon(N / 2, row + (N / 2), col + (N / 2)) ;

    }
    else
    {
        toggle ? one_num++ : zero_num++ ;
    }
}

int main()
{
    SETTING ;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> arr[i][j] ;
    DivAndCon(N, 1, 1) ;
    cout << zero_num << endl << one_num << endl ;
}