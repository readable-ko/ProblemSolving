#include <iostream>
#include <iomanip>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N, K, DEST ;
vector< vector< pair<int, int> > > graph(100001) ;
long long int dp[100001] ;
int arr[100001] ;

int find_answer()
{
    //first : Starting Point.   second: End Point(destination)
    queue< pair <int,int> > que ;
    while(!graph[DEST].empty())
    {
        que.push(graph[DEST].back()) ;
        graph[DEST].pop_back() ;
    }
    pair<int,int> temp ;
    if(que.empty()) return DEST ;
    int answer_point = que.front().first ;

    while(!que.empty())
    {
        temp = que.front() ;
        que.pop() ;
        dp[temp.second] = max(dp[temp.second], dp[temp.first] + arr[temp.first]) ;
        while(!graph[temp.second].empty())
        {
            que.push(graph[temp.second].back()) ;
            graph[temp.second].pop_back() ;
        }
        answer_point = temp.second ;
    }
    return answer_point ;
}

void input_setting()
{
    int startPoint, endPoint ;
    //graph = vector< vector< pair<int, int> > > (100001) ;
    memset(arr, 0, sizeof(int) * 100001) ;
    memset(dp, 0, sizeof(int) * 100001) ;
    //fill(dp, dp+100001, INT_MAX) ;
    cin >> N >> K ;
    for(int i = 1 ; i <= N ; i++)
        cin >> arr[i] ;
    
    for(int i = 0 ; i < K ; i++)
    {
        cin >> endPoint >> startPoint ;
        graph[startPoint].push_back(make_pair(startPoint, endPoint)) ;
    }
    cin >> DEST ;
    dp[DEST] = 0 ;
}

int main()
{
    vector<int> printer ;
    SETTING ;
    int T ;
    cin >> T ;
    for(int i = 0 ; i < T ; i++)
    {
        input_setting() ;
        int answer = find_answer() ;
        printer.push_back(dp[answer] + arr[answer]) ;
        //cout << dp[answer] + arr[answer] << "\n" ;
    }

    for(auto it : printer)
        cout << it << "\n" ;

}