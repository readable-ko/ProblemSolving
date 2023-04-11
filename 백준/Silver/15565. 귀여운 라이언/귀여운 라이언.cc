#include <bits/stdc++.h>
using namespace std ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, min_int = 0x3f3f3f3f ;
    cin >> N >> K ;

    vector<int> doll(N) ;
    queue<int> que ;

    for(int i = 0 ; i < N ; i++) {
        cin >> doll[i] ;

        if(doll[i] == 1 && que.size() < K) {
            que.push(i) ;
            if(que.size() == K) min_int = min(min_int, i - que.front() + 1) ;
        }
        else if(doll[i] == 1 && que.size() == K) {
            que.pop() ;
            que.push(i) ;
            if(que.size() == K) min_int = min(min_int, i - que.front() + 1) ;
        }
    }

    min_int == 0x3f3f3f3f ? cout << "-1\n" : cout << min_int ;
}