#include <bits/stdc++.h>
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

    //같은 색 중복 제거하고 최대 값만 취하기
    for(int i = 1 ; i < chk.length() ; i++)
    {
        cin >> tmp ;
        if(chk[i-1] != chk[i]) arr.push_back(tmp) ;
        else if(tmp > arr.back()) arr.back() = tmp ;
    }
    
    // 결국 취하는 돌은 앞뒤를 제외한 것들 중 아래 갯수만큼임.
    // 1:1 2:2 3:2 4:3 5:3
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