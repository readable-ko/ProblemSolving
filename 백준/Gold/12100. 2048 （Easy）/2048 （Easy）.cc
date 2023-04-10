/**
 * @file 12100.cpp
 * @author fpqpsxh
 * @brief 
 * @version 0.1
 * @date 2023-04-07
 */
#include <bits/stdc++.h>
using namespace std ;
int answer, N ;

vector< vector<int> > Swipe_UP(vector <vector<int> > b)
{
    bool changed[N][N] ;
    memset(changed, 0, sizeof(changed));

    vector< vector<int> > board(N, vector<int>(N)) ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0, k = 0 ; j < N ; j++)
            if(k != 0 && board[k-1][i] == b[j][i] && !changed[k-1][i]) {
                board[k-1][i] <<= 1 ;
                answer = max(answer, board[k-1][i]);
                changed[k-1][i] = 1 ;
            }
            else if(b[j][i] != 0) board[k++][i] = b[j][i] ;

    return board ;
}

vector< vector<int> > Swipe_DOWN(vector <vector<int> > b)
{
    bool changed[N][N] ;
    memset(changed, 0, sizeof(changed)) ;
    vector< vector<int> > board(N, vector<int>(N)) ;

    for(int i = 0 ; i < N ; i++)
        for(int j = N - 1, k = N - 1 ; j >= 0 ; j--)
            if(k != N - 1 && board[k + 1][i] == b[j][i] && !changed[k+1][i]) {
                board[k+1][i] <<= 1 ;
                answer = max(answer, board[k+1][i]);
                changed[k+1][i] = 1 ;
            }
            else if(b[j][i] != 0) board[k--][i] = b[j][i] ;

    return board ;
}

vector< vector<int> > Swipe_LEFT(vector <vector<int> > b)
{
    bool changed[N][N] ;
    memset(changed, 0, sizeof(changed));
    vector< vector<int> > board(N, vector<int>(N)) ;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0, k = 0 ; j < N ; j++)
            if(k != 0 && board[i][k-1] == b[i][j] && !changed[i][k-1]) {
                board[i][k-1] <<= 1 ;
                answer = max(answer, board[i][k-1]);
                changed[i][k-1] = 1 ;
            }
            else if(b[i][j] != 0) board[i][k++] = b[i][j] ;

    
    return board ;
}

vector< vector<int> > Swipe_RIGHT(vector <vector<int> > b)
{
    bool changed[N][N];
    memset(changed, 0, sizeof(changed));
    vector< vector<int> > board(N, vector<int>(N)) ;

    for(int i = 0 ; i < N ; i++)
        for(int j = N - 1, k = N - 1 ; j >= 0 ; j--)
            if(k != N - 1 && board[i][k+1] == b[i][j] && !changed[i][k+1]) {
                board[i][k+1] <<= 1 ;
                answer = max(answer, board[i][k+1]);
                changed[i][k+1] = 1 ;
            }
            else if(b[i][j] != 0) board[i][k--] = b[i][j] ;

    return board ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector< vector<int> > board(N, vector<int>(N)) ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
        {
            cin >> board[i][j] ;
            answer = max(board[i][j], answer);
        }
    
    queue< vector < vector <int> > > que ;
    que.push(board) ;
    
    for(int i = 0 ; i < 5 ; i++)
    {
        int size = que.size() ;

        while(size--)
        {
            auto now = que.front() ;
            que.pop() ;
            que.push(Swipe_UP(now));
            que.push(Swipe_DOWN(now));
            que.push(Swipe_LEFT(now));
            que.push(Swipe_RIGHT(now));
        }   
    }

    cout << answer << "\n" ;
}