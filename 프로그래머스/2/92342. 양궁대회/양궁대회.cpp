#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = {-1};
    int max_point = -1 ;
    int j = 0 ;
    reverse(info.begin(), info.end()) ;
    
    for(int i = 0b0 ; i < 0b11111111111 ; i++) {
        // 화살 갯수 따지기
        // 점수 계산해보고 더 큰지 확인
        // 점수 더 큰거 중 최저 점수인지 확인
        // 최저 점수라면 가장 낮은 점수 많이 맞춘거 체크
        int ryon = 0, apeach = 0 ;
        int arrow = n ;
        vector<int> tmp(11) ;
        
        for(int idx = 0 ; idx <= 10 ; idx++) {
            if((i >> idx) & 1) {
                arrow -= (info[idx] + 1);
                tmp[idx] = (info[idx] + 1);
                ryon += idx ;
            }
            else if(info[idx])
            {
                apeach += idx ;
            }
        }
        if(arrow) tmp[0] += arrow;
        
        if(arrow >= 0 && ryon > apeach && ryon - apeach >= max_point) {
            if(ryon - apeach == max_point) {
                bool check = 0 ;
                for(int idx = 0 ; idx <= 10 ; idx++) {
                    if(answer[idx] < tmp[idx]) {
                        check = 1; break ;
                    }
                    else if(answer[idx] > tmp[idx]) break ;
                }
                if(check) answer = tmp ;
            }
            else answer = tmp ;
            max_point = ryon - apeach ;
        }
    }
    
    cout << max_point << ":" << j ;
    reverse(answer.begin(),answer.end());
    return answer;
}