#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2) ;
    vector<int> sum(1) ;
    
    for(int num : sequence)
        sum.push_back(sum.back() + num) ;
    
    answer[1] = sum.size() ;
    for(int sp = 0, ep = 0 ; sp <= ep && ep < sum.size() ;)
    {
        if(sum[ep] - sum[sp] > k)
            sp++ ;
        else
        {
            if(sum[ep] - sum[sp] == k && ep - sp < answer[1] - answer[0])
            {
                answer[0] = sp;
                answer[1] = ep;
            }
            ep++;
        }
    }
    answer[1]-- ;
    return answer;
}