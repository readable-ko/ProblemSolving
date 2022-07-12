#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    for(answer; answer < 500; ++answer) {
        if(num == 1) break;
        num % 2 == 1 ? num = num*3 +1 : num /= 2;
    }
    return answer == 500 ? answer = -1 : answer;
}