#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
int T, given, want ;
bool visited[10000] ;

void InputSetting()
{
    cin >> given >> want ;
    memset(visited, 0, sizeof(visited)) ;
}

void BFS()
{
    queue< pair<int, string> > que ;
    int DSLR[4] ;
    char DSLR_ch[] = {'D', 'S', 'L', 'R'} ;

    que.push(make_pair(given, "")) ;
    visited[given] = 1 ;

    while(!que.empty())
    {
        string now_ch = que.front().second ;
        int now_num = que.front().first ;
        que.pop() ;

        if(now_num == want)
        {
            cout << now_ch << "\n" ;
            return ;
        }

        DSLR[0] = (now_num << 1) % 10000 ;
        DSLR[1] = now_num == 0 ? 9999 : now_num - 1 ;
        DSLR[2] = (now_num % 1000) * 10 + (now_num / 1000) ;
        DSLR[3] = (now_num / 10) + (now_num % 10) * 1000 ;
        
        for(int i = 0 ; i < 4 ; i++)
        {
            if(!visited[DSLR[i]])
            {
                visited[DSLR[i]] = 1 ;
                que.push(make_pair(DSLR[i], now_ch + DSLR_ch[i])) ;
            }
        }
    }
}

int main()
{
    cin >> T ;
    while(T--)
    {
        InputSetting() ;
        BFS() ;
    }
}