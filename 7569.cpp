#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <functional>
#include <math.h>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int M, N ;
int arr[1001][1001] ;
bool visited[1001][1001] ;
queue< pair<int,int> > que ;

int FindDay()
{
    int count = -1 ;
    int x[] = {1, 0, -1, 0} ;
    int y[] = {0, 1, 0, -1} ;

    while(!que.empty())
    {
        int size = que.size() ;

        for(int i = 0 ; i < size ; i++)
        {
            pair<int,int> spot = que.front() ;
            que.pop() ;
            if(visited[spot.first][spot.second]) continue ;
            
            visited[spot.first][spot.second] = 1;

            if(arr[spot.first][spot.second] != -1)
            {
                arr[spot.first][spot.second] = 1 ;
                for(int j = 0 ; j < 4 ; j++)
                {
                    pair<int,int> temp = make_pair(spot.first + x[j], spot.second + y[j]) ;
                    if(temp.first < 1 || temp.first > N || temp.second < 1 || temp.second > M) continue ;
                    que.push(temp) ;
                }
            }
        }
        count++ ;
    }
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            if(!arr[i][j]) return -1 ;
    
    return count - 1 ;
}

void InputSetting()
{
    cin >> M >> N ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
        {
            cin >> arr[i][j] ;
            if(arr[i][j] == 1) que.push(make_pair(i, j)) ;
        }
}

int main()
{
    SETTING ;
    InputSetting() ;
    cout << FindDay() << "\n";
}