#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long d = 0, p = 0, answer = 0 ;
    
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        long long int cnt = 0 ;
        while(deliveries[i] > d || pickups[i] > p)
        {
            d += cap ;
            p += cap ;
            cnt++ ;
        }
        
        d -= deliveries[i] ;
        p -= pickups[i] ;
        answer += (long long)(i + 1) * 2 * cnt ;
    }
    return answer ;
}