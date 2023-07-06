#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wants, day;
    
    for(int i = 0 ; i < want.size() ; i++)
        wants[want[i]] = number[i] ;
    
    for(int item = 0 ; item < discount.size() ; item++) {
        day[discount[item]]++ ;
        bool flag = true ;
        
        for(pair<string, int> key : wants) {
            if(day[key.first] != key.second) {
                flag = 0 ; break ;
            }
        }
        
        if(flag) answer++ ;
        if(item >= 9) day[discount[item - 9]]--;
    }
    
    return answer;
}