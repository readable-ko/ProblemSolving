#include <bits/stdc++.h>

using namespace std;

bool divCheck(vector<int> arr, int num) {
    for(auto a : arr)
        if(a % num == 0) return false ;
    return true ;
}

int gcd(vector<int> arr) {
    int a = arr[0] ;
    
    for(int b : arr) {
        int c = max(a, b);
        b = min(a, b);
        a = c ;
        while(b) {
            c = a % b ;
            a = b ;
            b = c ;
        }
    }
    
    return a ;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    int maxA = gcd(arrayA) ;
    int maxB = gcd(arrayB) ;
    int answer = 0 ;
    
    if(divCheck(arrayA, maxB))
        if(answer < maxB) answer = maxB ;
    
    if(divCheck(arrayB, maxA))
        if(answer < maxA) answer = maxA ;
    
    return answer ;
}