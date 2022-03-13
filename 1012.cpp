#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int T, N, M, K ;
vector< pair <int, int> > arr ;
bool visited[51][51] ;


void input_clear()
{
    arr = vector< pair <int, int> >() ;
    for(int i = 0 ; i < 51 ; i++)
        memset(visited[i], 0, sizeof(bool) * 51) ;
}

void input_setting()
{
    int xPoint, yPoint ;
    cin >> M >> N >> K;
    input_clear() ;

    for(int i = 0 ; i < K ; i++)
    {
        cin >> xPoint >> yPoint ;
        arr.push_back(make_pair(xPoint, yPoint)) ;
        visited[xPoint][yPoint] = 1 ;
    }
}

void find_answer(int x, int y)
{
    if(x >= M || y >= N || x < 0 || y < 0) return ;
    if(visited[x][y] == 0) return ;
    visited[x][y] = 0 ;

    int arrX[] = {1, 0, -1, 0} ;
    int arrY[] = {0, 1, 0, -1} ;
    for(int i = 0 ; i < 4 ; i++)
    {
        int nextX = arrX[i] + x ;
        int nextY = arrY[i] + y ;
        find_answer(nextX, nextY) ;
    }
    return ;
}

int main()
{
    SETTING ;
    cin >> T ;
    for(int i = 0 ; i < T ; i++)
    {
        int answer = 0 ;
        input_setting() ;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(visited[arr[i].first][arr[i].second]) 
            {
                answer++ ;
                find_answer(arr[i].first, arr[i].second) ;
            }
        }
        cout << answer << "\n" ;
    }
}