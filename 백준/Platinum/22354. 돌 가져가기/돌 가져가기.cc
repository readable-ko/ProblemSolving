#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int N, tmp ;
long long int answer ;

int main()
{
    SETTING ;
    cin >> N ;
    string chk ;
    vector<int> arr ;
    cin >> chk ;
    cin >> tmp ;
    arr.push_back(tmp) ;

    for(int i = 1 ; i < chk.length() ; i++)
    {
        cin >> tmp ;
        if(chk[i-1] != chk[i]) arr.push_back(tmp) ;
        else if(tmp > arr.back()) arr.back() = tmp ;
    }
    // 1:1 2:2 3:2 4:3 5:3   // 8 2 5 3
    int size = ceil((arr.size() - 2) / 2.0);
    priority_queue<int> pq ;
    for(int i = 1 ; i < arr.size() - 1 ; i++)
        pq.push(arr[i]) ;

    for(int i = 0 ; i < size ; i++)
    {
        answer += pq.top() ;
        pq.pop() ;
    }

    cout << answer ;
}