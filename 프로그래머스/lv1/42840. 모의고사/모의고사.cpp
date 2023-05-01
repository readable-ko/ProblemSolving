#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer ;
    int chck[3] = {0,};
    int p1[] = {1,2,3,4,5};
    int p2[] = {2,1,2,3,2,4,2,5};
    int p3[] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0 ; i < answers.size() ; i++)
    {
        if(p1[i%5] == answers[i]) chck[0]++ ;
        if(p2[i%8] == answers[i]) chck[1]++ ;
        if(p3[i%10] == answers[i]) chck[2]++ ;
    }
    
    int maxi = max(chck[0], max(chck[1], chck[2]));
    for(int i = 0 ; i < 3 ; i++)
        if(maxi == chck[i]) answer.push_back(i+1);
    return answer;
}