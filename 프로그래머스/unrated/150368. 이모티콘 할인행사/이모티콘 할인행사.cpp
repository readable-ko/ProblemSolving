#include <bits/stdc++.h>
using namespace std;
vector<int> dis_emo ;
int max_plus, max_sales ;

void DFS(int idx, vector<int> &emoticons, vector<vector<int>> &users)
{
    if(idx == emoticons.size())
    {
        int sum = 0 ;
        int cnt_plus = 0 ;
        for(vector<int> user: users)
        {
            int local_sum = 0 ;
            for(int i = 0 ; i < dis_emo.size() ; i++)
            {
                if(dis_emo[i] >= user[0])
                    local_sum += emoticons[i] * (100 - dis_emo[i]) / 100 ;
                if(local_sum >= user[1])
                {
                    cnt_plus++ ;
                    local_sum = 0 ;
                    break ;
                }
            }
            sum += local_sum ;   
        }
        if(cnt_plus > max_plus)
        {
            max_plus = cnt_plus ;
            max_sales = sum ;
        }
        else if(cnt_plus == max_plus)
        {
            max_sales = max(sum, max_sales) ;
        }
        return ;
    }
    
    for(int i = 0 ; i < 50 ; i +=10)
    {
        dis_emo[idx] = i ;
        DFS(idx + 1, emoticons, users) ;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dis_emo = vector<int>(emoticons.size()) ;
    
    DFS(0, emoticons, users) ;
    answer.push_back(max_plus) ;
    answer.push_back(max_sales) ;
    return answer;
}