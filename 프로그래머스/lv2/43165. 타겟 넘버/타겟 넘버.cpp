#include <bits/stdc++.h>
using namespace std;
int num, t, answer ;
vector<int> arr ;

void DFS(int idx, int n)
{
    if(idx == num)
    {
        if(n == t) answer++ ;
        return ;
    }

    DFS(idx + 1, n + arr[idx]) ;
    DFS(idx + 1, n - arr[idx]) ;
}

int solution(vector<int> numbers, int target) {
    num = numbers.size() ;
    t = target ;
    arr = numbers ;
    DFS(0, 0) ;
    return answer;
}