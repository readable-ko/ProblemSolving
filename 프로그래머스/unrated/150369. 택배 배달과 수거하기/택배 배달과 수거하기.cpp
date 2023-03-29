#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long d = 0, p = 0, answer = 0 ;
    
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        long long int cnt = 0 ;
        d -= deliveries[i] ;
        p -= pickups[i] ;
        
        while(d < 0 || p < 0)
        {
            d += cap ;
            p += cap ;
            cnt++ ;
        }
        
        answer += (i + 1) * 2 * cnt ;
    }
    
    return answer ;
}