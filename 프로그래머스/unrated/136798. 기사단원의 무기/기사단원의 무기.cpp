#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> check(number + 1) ;
    
    for(int i = 1 ; i <= number ; i++)
    {
        for(int j = i ; j <= number ; j+=i)
        {
            check[j]++ ;
        }
        check[i] > limit ? answer += power : answer += check[i] ;
    }
    
    return answer;
}