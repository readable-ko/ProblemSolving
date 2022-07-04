#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0 ; i < skill_trees.size() ; i++)
    {
        vector<int> cnt(skill.length(), 0x3f3f3f3f) ;
        
        for(int j = 0 ; j < skill_trees[i].length() ; j++)
        {
            
            for(int stree = 0 ; stree < skill.length() ; stree++)
            {
                if(skill_trees[i][j] == skill[stree]) cnt[stree] = j ;
            }
        }
        
        bool flag = 1 ;
            for(int chck = 1 ; chck < cnt.size(); chck++)
            {
                if(cnt[chck] < cnt[chck - 1]) flag = 0 ;
            }
            
            if(flag == 1) answer++ ;
    }
    return answer;
}