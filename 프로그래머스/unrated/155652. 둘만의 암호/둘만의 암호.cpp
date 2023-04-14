#include <bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    bool possible[26] ;
    string answer = "";
    memset(possible, 0, sizeof(possible));
    for(char c : skip)
        possible[c % 26] = 1 ;

    for(char c : s)
    {
        int now = index ;
        for(int i = 1 ; i <= now ; i++)
        {
            if(possible[(c + i) % 26]) now++ ;
        }
        now = now % 26 ;
        answer += (c + now) > 'z' ? c + now - 26 : c + now;
    }
        
    return answer;
}