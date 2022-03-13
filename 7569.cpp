#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;

int arr[1001][1001] ;
bool visited[1001][1001] ;
queue< pair<int, int> > que ;
int N, M ;
int x[] = {1, 0, -1, 0} ;
int y[] = {0, 1, 0, -1} ;

int FindDay()
{
    int count = -1 ;
    while(!que.empty())
    {
        if(count > M + N) return -1 ;
        int size = que.size() ;
        for(int i = 0 ; i < size ; i++)
        {
            pair<int,int> spot = que.front() ;
            if(!visited[spot.first][spot.second])
            {
                visited[spot.first][spot.second] = 1 ;
                for(int j = 0 ; j < 4 ; j++)
                {
                    
                    pair<int,int> temp = make_pair( spot.first+x[j], spot.second+y[j] ) ;
                    if(!visited[temp.first][temp.second]) 
                        if(temp.first > -1 && temp.first < M && temp.second > -1 && temp.second > N) que.push(temp) ;
                }
            }
            que.pop() ;
        }
        count++ ;
    }

    for(int i = 0 ; i < M ; i++)
        for(int j = 0 ; j < N ; j++)
            if(!visited[i][j] && arr) return -1 ;
    
    return count ;      
}

void InputSetting()
{
    cin >> M >> N ;
    for(int i = 0 ; i < M ; i++)
        for(int j = 0 ; j < N ; j++)
        {
            cin >> arr[i][j] ;
            if(arr[i][j] == 1) que.push(make_pair(i, j)) ;
        }
}

// if Day is over than M + N - 2 can not.
int main()
{
    SETTING ;
    InputSetting() ;
    cout << FindDay() ;
}