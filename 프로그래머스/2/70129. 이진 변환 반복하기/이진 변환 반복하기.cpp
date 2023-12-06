#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    if (s == "1")
       return answer; 
    //일단 총 문자열 갯수에서 1 갯수를 세고 나머지가 제거 횟수
    //계속 나누기 2 하면서 1갯수 세고 나눈 횟수 때면 제거 횟수
    //갯수 같을 때까지 반복
    for (char c : s) {
        if (c == '0') {
            answer[1]++;
        }
    }
    answer[0] = 1;
    int tmp = s.length() - answer[1];
    cout << answer[0] << " " << answer[1] << " " << tmp << "\n";
    
    while(tmp > 1) {
        int total = 0;
        int cnt = 0;
        while(tmp != 0) {
            cnt += tmp & 1;
            tmp >>= 1;
            total++;
        }
        tmp = cnt;
        answer[1] += total - cnt;
        answer[0]++;
        cout << answer[0] << " " << answer[1] << " " << tmp << "\n";
    }
    return answer;
}