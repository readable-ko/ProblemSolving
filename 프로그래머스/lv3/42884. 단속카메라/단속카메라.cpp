#include <bits/stdc++.h>
using namespace std; 

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(),
         [&](vector<int> a, vector<int>b) {
             return a[1] < b[1];
         });
    
    int now = routes[0][1] ;
    for(auto r : routes)
        if(r[0] > now) {
            answer++ ;
            now = r[1] ;
            cout << now ;
        }
    
    return answer;
}