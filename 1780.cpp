#include <iostream>
#include <math.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int SIZE, minbox, zerobox, onebox ;
int arr[2188][2188] ;

void InputSetting()
{
    cin >> SIZE ;
    for(int i = 1 ; i <= SIZE ; i++)
        for(int j = 1 ; j <= SIZE ; j++)
            cin >> arr[i][j] ;
}

void DivAndCon(int row, int col, int asize)
{
    int end_row = row + asize ;
    int end_col = col + asize ;
    int prev = arr[row][col] ;
    if(asize > 1)
        for(int start_row = row ; start_row < end_row ; start_row++)
        {
            for(int start_col = col ; start_col < end_col ; start_col++)
            {
                if(arr[start_row][start_col] != prev)
                {
                    for(int i = 0 ; i < 3 ; i++)
                        for(int j = 0 ; j < 3 ; j++)
                        {
                            int temp_size = asize / 3 ;
                            DivAndCon(row + i * temp_size, col + j * temp_size, temp_size) ;
                        }
                    return ;
                }
                prev = arr[start_row][start_col] ;
            }
        }

    switch(prev)
    {
        case -1 : {minbox++ ; break ;}
        case 0 : {zerobox++ ; break ;}
        case 1 : {onebox++ ; break ; }
    }
}

int main()
{
    SETTING ;
    InputSetting() ;
    DivAndCon(1,1, SIZE) ;
    cout << minbox << "\n" << zerobox << "\n" << onebox ;
}