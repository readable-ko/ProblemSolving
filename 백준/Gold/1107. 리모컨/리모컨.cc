//두번째로 for문 10만 아래로 줘도 틀림 왜냐면 2배 이상 3배 4배 위로 갔다가 내려오는게 더 빠를 수도 있거든. 반례 1 9 0 1 2 3 4 5 6 7 8
#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define VMAX 1000000
using namespace std ;

bool arr[10] ;
int N, K ;

bool check(int i)
{
    string str = to_string(i) ;
    for(int i = 0 ; i < str.length() ; i++)
        if(arr[str[i] - '0']) return false ;
    
    return true ;
}

int main()
{
    SETTING ;
    cin >> N >> K ;
    while(K--)
    {
        int broken ;
        cin >> broken ;
        arr[broken] = true ;
    }

    int NSIZE = to_string(N).length() ;
    int answer = abs(N - 100) ;

    if(K == 10) cout << answer ;
    else if(K == 0) cout << NSIZE ;
    else
    {
        for(int i = 0 ; i <= VMAX ; i++)
        {
            if(!check(i)) continue ;
            NSIZE = to_string(i).length() ;
            answer = min(answer, abs(N - i) + NSIZE ) ;
        }
        cout << answer ;
    }

}