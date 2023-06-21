#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> subak, sum(1), answer;
    subak.emplace_back(k) ;
    
    while(k != 1) {
        if((k & 1) == 0) k = k / 2.0 ;
        else k = k * 3.0 + 1 ;
        subak.emplace_back(k) ;
    }
    
    for(int i = 1 ; i < subak.size() ; i++)
        sum.push_back((subak[i-1] + subak[i]) / 2.0 + sum.back()) ;
    
    for(vector<int> range : ranges) {
        int first = sum.size() + range[1] - 1;
        int second = range[0] ;
        if(first < second) answer.emplace_back(-1.0);
        else answer.emplace_back(sum[first] - sum[second]);
    }
    
    return answer;
}