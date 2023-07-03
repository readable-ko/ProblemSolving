#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    set<int> answer ;
    
    for(int i = 1 ; i <= elements.size() ; i++) {
        for(int idx = 0 ; idx < elements.size() ; idx++) {
            int sub_sum = 0 ;
            for(int rot = 0 ; rot < i ; rot++) {
                sub_sum += elements[(idx + rot) % elements.size()] ;
            }
            answer.insert(sub_sum) ;
        }
    }
    
    return answer.size();
}