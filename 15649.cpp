#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define MAX_SIZE 9
using namespace std ;

int M, N ;
int arr[MAX_SIZE] ;
bool visited[MAX_SIZE] ;

void BackTracking(int index)
{
    if(index == M)
    {
        for(int i = 0 ; i < index ; i++)
            cout << arr[i] << " " ;
        cout << endl ;
    }
    else
    {
        for(int i = 1 ; i <= N ; i++)
        {
            if(!visited[i])
            {
                visited[i] = 1 ;
                arr[index] = i ;
                BackTracking(index+1) ;
                visited[i] = 0 ;
            }
        }
    }
}

int main()
{
    SETTING ;
    cin >> N >> M ;
    BackTracking(0) ;
}