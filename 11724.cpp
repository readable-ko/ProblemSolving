#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
vector< vector<int> > arr(1001) ;
bool visited[1001] ;
int V, E ;
void InputSetting()
{
    cin >> V >> E ;
    int start, dest ;
    for(int i = 0 ; i < E ; i++)
    {
        cin >> start >> dest ;
        arr[start].push_back(dest) ;
        arr[dest].push_back(start) ;
    }
}

int BFS()
{
    int cnt = 0 ;
    queue<int> que ;
    for(int i = 1 ; i <= V ; i++)
    {
        if(!visited[i])
        {
            cnt++ ;
            for(int j = 0; j < arr[i].size(); j++)
            {
                if(!visited[arr[i][j]]) que.push(arr[i][j]) ;
                visited[arr[i][j]] = 1 ;
            }
            while(!que.empty())
            {
                int que_size = que.size() ;
                
                for(int k = 0 ; k < arr[que.front()].size() ; k++)
                {
                    int temp = arr[que.front()][k] ;
                    if(!visited[temp])
                    {
                        visited[temp] = 1 ;
                        que.push(temp) ;
                    }
                }
                que.pop() ;
            }
        }
    }
    return cnt ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    cout << BFS() ;
}