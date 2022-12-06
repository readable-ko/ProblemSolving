/**
 * number 25824
 * @author fpqpsxh
 * @date 2022-12-06
 * @brief 처음에 다익스트라나 플로이드와샬인가 싶었는데 다시 생각해보니 BFS..?
 * 그리고 다시 생각해보니 input은 12명으로 제한되어있는데 3초나 주어진다.
 * 모든 경우의 수는 leaf가 2^6으로 128 - 1개의 경우 뿐이니 브루트포스가 제일 적합해보여 일단 적용
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std ;
vector< vector<int> > input(12, vector<int>(12)) ;
vector< vector< pair< int, int> > > answer(6) ;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;

    for(int i = 0 ; i < 12 ; i++)
        for(int j = 0 ; j < 12 ; j++)
            cin >> input[i][j] ;
    
    answer[0].push_back(make_pair(input[0][1], 1)) ;
    answer[0].push_back(make_pair(input[1][0], 0)) ;

    for(int i = 1 ; i < 6 ; i++)
    {
        for(int j = 0 ; j < answer[i-1].size() ; j++)
        {
            int first = answer[i-1][j].first + input[answer[i-1][j].second][i*2] + input[i * 2][i * 2 + 1];
            int second = answer[i-1][j].first + input[answer[i-1][j].second][i*2 + 1] + input[i * 2 + 1][i * 2];
            answer[i].push_back(make_pair(first, i * 2 + 1)) ;
            answer[i].push_back(make_pair(second, i * 2)) ;
        }
    }
    int real_answer = 0x3f3f3f3f ;
    for(pair<int,int> tmp : answer[5])
        if(tmp.first < real_answer) real_answer = tmp.first ;
    
    cout << real_answer ;
}