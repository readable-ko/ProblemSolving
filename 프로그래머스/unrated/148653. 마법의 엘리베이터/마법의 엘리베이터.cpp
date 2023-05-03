#include <string>
#include <vector>
//56일 때 반례 발생
using namespace std;

int solution(int storey) {
    int answer = 0;
    int tmp = storey ;
    while(tmp != 0)
    {
        int now = tmp % 10;
        if(now > 5)
        {
            answer += (10 - now) ;
            tmp += 10 ;
        }
        else if (((tmp / 10) % 10 >= 5) && now == 5)
        {
            answer += 5;
            tmp += 10 ;
        }
        else
            answer += now ;
            
        tmp /= 10 ;
    }
    return answer;
}