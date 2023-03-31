#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

bool DFS(vector<int> &str, int sp, int ep)
{
    int mid = (sp + ep) / 2 ;
    if(sp == ep) return true ;
    
    if(str[mid] == 0) 
    {
        bool flag = 0 ;
        for(int i = sp ; i <= ep ; i++)
            if(str[i] != 0) flag = 1 ;
        
        return flag ? false : true ;
    }
    
    return DFS(str, sp, mid) & DFS(str, mid + 1, ep) ;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long num: numbers)
    {
        int i = 0 ;
        while(pow(2,pow(2,i)-1) < num) i++ ;
        
        vector<int> str(pow(2,i) - 1) ;
        
        for(int i = str.size() - 1 ; i >= 0 ; i--)
        {
            str[i] = 1 & num ;
            num >>= 1 ;
        }
        
        if(num == 1) str.push_back(1) ;
        int tmp = DFS(str, 0, str.size() - 1) ;
        answer.push_back(tmp) ;
    }
    return answer;
}