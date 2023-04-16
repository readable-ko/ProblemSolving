#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> name_rank ;
    map<int, string> rank_name ;
    
    for(int i = 0 ; i < players.size() ; i++)
    {
        name_rank[players[i]] = i + 1 ;
        rank_name[i + 1] = players[i] ;
    }
    
    for(string name : callings)
    {
        int prev_num = name_rank[name] - 1 ;
        string prev_name = rank_name[prev_num] ;
        name_rank[prev_name]++ ;
        rank_name[prev_num + 1] = prev_name ;
        name_rank[name]-- ;
        rank_name[prev_num] = name ;
    }
    
    for(auto ranking : rank_name)
        answer.emplace_back(ranking.second) ;
        
    return answer;
}