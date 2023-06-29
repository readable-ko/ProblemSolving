#include <string>
#include <vector>
/**
1. 만약 내 숫자가 요구숫자보다 작은 상황이야.
-> 그럼 숫자 담으면서 진행
2. 만약 내 숫자가 요구숫자와 같은 상황이야.
-> 정답 + 1
3. 만약 내 숫자가 요구숫자보다 큰 상황이면 스택을 본다.
-> 스택에 답이 있으면 정답 + 1
-> 없으면 break
*/
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> st ;
    
    for(int i = 1 ; answer != order.size() ;) {
        if(order[answer] < i) {
            if(st.empty() || st.back() != order[answer]) break;
            answer++ ;
            st.pop_back() ;
        }
        else {            
            if(order[answer] == i) answer++ ;
            else st.push_back(i) ;
            if(i < order.size()) i++;
        }
    }
    return answer;
}