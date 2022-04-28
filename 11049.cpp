//Matrix Chain Multiplication (MCM problem) by DP
#include <iostream>
#define MIN(A, B) (A > B ? B : A)
#define INTMAX 0x3f3f3f3f
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;

int N ;
int matrix[501][501] ;
pair<int, int> arr[501] ;
void InputSetting() ;
void MCM() ;

int main()
{
    SETTING ;
    InputSetting() ;
    MCM() ;
    cout << matrix[1][N] ;
}

void InputSetting()
{
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
        cin >> arr[i].first >> arr[i].second ;
    arr[0].second = arr[1].first ;
}

void MCM()
{
    // cross means diagonal
    for(int cross = 1 ; cross <= N ; cross++)
    {
        // i : col   // j : row // k : partition
        for(int i = 1 ; i <= N - cross ; i++)
        {
            int j = i + cross ;
            matrix[i][j] = INTMAX ;
            for(int k = i ; k < j ; k++)
            {
                matrix[i][j] = MIN((matrix[i][k] + matrix[k+1][j] + arr[i].first * arr[k].second * arr[j].second),matrix[i][j]) ;
            }
        }
    }
}