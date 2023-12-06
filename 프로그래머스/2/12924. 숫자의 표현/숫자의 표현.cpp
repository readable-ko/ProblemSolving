#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 1, ep = 0, sum = 0, sp = 1;
    
    for (int i = 0 ; i < n/2; i++) {
        if (i * (i + 1) / 2 >= n) {
            ep = i;
            sum = i * (i + 1) / 2;
            break;
        }
    }
    
    while (ep != n) {
        if (sum == n) {
            answer++;
            sum -= sp;
            sp++;
        }
        else if(sum > n) {
            sum -= sp;
            sp++;
        }
        else {
            ep++;
            sum += ep;
        }
    }
    
    return answer;
}