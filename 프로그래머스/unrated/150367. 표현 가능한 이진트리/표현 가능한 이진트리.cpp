#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
bool check ;

bool DFS(vector<int> &str, int idx, int depth)
{
    if(depth == 0) return true ;
    if(str[idx] == 0)
        if(str[idx - depth] == 1 || str[idx + depth] == 1) return false ;

    bool lhs = DFS(str, idx - depth, depth / 2) ;
    bool rhs = DFS(str, idx + depth, depth / 2) ;
    
    return lhs & rhs ;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long num: numbers)
    {
        vector<int> str ;
        while(num)
        {
            str.emplace_back(num & 1) ;
            num >>= 1 ;
        }
        
        int k = 0;
        long long s = 0;

        while(str.size()> s)
            s += pow(2,k++);

        while(str.size() < s)
            str.emplace_back(0);

        answer.push_back(DFS(str, str.size() / 2, (1 + str.size()) / 4)) ;
    }
    return answer;
}