#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int sp1 = 0, sp2 = 0 ;
    int one_max = cards1.size(), two_max = cards2.size() ;
    
    for(string s : goal)
    {
        if(sp1 < one_max && s == cards1[sp1]) sp1++ ;
        else if(sp2 < two_max && s == cards2[sp2]) sp2++ ;
        else
        {
            answer = "No" ; break ;
        }
    }
    return answer;
}