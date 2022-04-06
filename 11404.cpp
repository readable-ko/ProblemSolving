#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define MAX_INT 100000000
using namespace std ;
int Floyd[101][101] ;
int N, M ;
void InputSetting()
{
    //Initialize the value in to MAX
    fill(&Floyd[0][0], &Floyd[100][101], MAX_INT);

    int s_point, d_point, weight ;
    cin >> N >> M ;

    //Set itself zero
    for(int i = 1 ; i <= N ; i++)
        Floyd[i][i] = 0 ;

    //Connect the line
    for(int i = 0 ; i < M ; i++)
    {
        cin >> s_point >> d_point >> weight ;
        Floyd[s_point][d_point] = min(weight, Floyd[s_point][d_point]) ;
    }
}

void FloydWarshall()
{
    for(int k = 1 ; k <= N ; k++)
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                Floyd[i][j] = min(Floyd[i][j], Floyd[i][k] + Floyd[k][j]) ;
}

void PrintAnswer()
{
    for(int i = 1 ; i <= N ; i++)
    {   
        for(int j = 1 ; j <= N ; j++)
        {
            Floyd[i][j] == MAX_INT ? cout << "0 " : cout << Floyd[i][j] << " " ;
        }
        cout << endl ;
    }
}

int main()
{
    SETTING ;
    InputSetting() ;
    FloydWarshall() ;
    PrintAnswer() ;
}