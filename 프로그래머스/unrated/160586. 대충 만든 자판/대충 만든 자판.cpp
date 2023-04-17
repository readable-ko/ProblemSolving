#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> mp ;
    for(string key : keymap)
    {
        for(int i = 0 ; i < key.length() ; i++)
        {
            int now = i + 1 ;
            if(mp.count(key[i]) == 0)
                mp[key[i]] = i + 1 ;
            else
                mp[key[i]] = min(now, mp[key[i]]) ;
        }
    }
    
    for(string target : targets)
    {
        int cnt = 0 ;
        for(char c : target)
        {
            if(mp.count(c) == 0)
            {
                cnt = -1 ;
                break ;
            }
            else
                cnt += mp[c] ;
        }
        answer.emplace_back(cnt) ;
    }
    return answer;
}