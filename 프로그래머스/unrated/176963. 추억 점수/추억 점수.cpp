#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> mp ;
    for(int i = 0 ; i < name.size() ; i++)
        mp[name[i]] = yearning[i] ;
    
    vector<int> answer ;
    for(auto p : photo)
    {
        int sum = 0 ;
        for(int i = 0 ; i < p.size() ; i++)
            if(mp.count(p[i]) != 0) sum += mp[p[i]] ;
        answer.emplace_back(sum) ;
    }
    return answer;
}