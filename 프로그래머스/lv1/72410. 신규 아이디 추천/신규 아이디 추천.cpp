#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int length = new_id.length() ;
    
    for(int i = 0 ; i < length ; i++)
    {
        char curr;
        curr = tolower(new_id[i]) ;
        if(curr == ' ') curr = 'a';
        if(!(isalnum(curr) || curr == '.' || curr == '_' || curr == '-')) continue ;
        if(!answer.empty() && curr == '.' && answer.back() == '.') continue ;
        if(answer.empty() && curr == '.') continue;
        if(curr == '.' && (i == 0 || i == length - 1)) continue ;
        if(answer.size() == 15) break ;
        answer += curr ;
    }
    if(answer.empty()) answer += 'a';
    if(answer.back() == '.') answer.pop_back();
    
    while(answer.size() < 3)
        answer += answer.back() ;
    
    cout << answer ;
    return answer;
}