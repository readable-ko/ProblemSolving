#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N ;
bool arr[65][65] ;

void DivAndCon(int row, int col, int size)
{
    bool check = arr[row][col];
    bool flag = 1 ;

    if(size == 1)
    {
        cout << check ; return ;
    }

    for(int i = row ; i < size + row ; i++)
    {
        for(int j = col ; j < size + col ; j++)
        {
            if(check != arr[i][j])
            {
                flag = 0 ; break ;
            }
        }
        if(!flag) break ;
    }

    if(flag) {cout << check; return; }
    else
    {
        cout << "(" ;
        DivAndCon(row, col, size / 2) ;
        DivAndCon(row, col + size / 2, size / 2) ;
        DivAndCon(row + size / 2, col, size / 2) ;
        DivAndCon(row + size / 2, col + size / 2, size / 2) ;
        cout << ")" ;
    }
}

int main()
{
    SETTING ;
    cin >> N ;
    string temp ;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> temp ;
        for(int j = 1 ; j <= N ; j++)
            arr[i][j] = temp[j-1] - '0';
    }
    
    DivAndCon(1, 1, N) ;
}