#include <bits/stdc++.h>
using namespace std ;
int N ;
bool NSWE[4] ;
typedef struct _position
{
    int x ;
    int y ;
}position;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;

    cin >> N ;
    vector<position> police(N) ;
    position thief ;

    for(auto &it : police)
        cin >> it.x >> it.y ;
    cin >> thief.x >> thief.y ;

    for(auto p : police)
    {
        if(p.x < thief.x)
        {
            if(abs(thief.y - p.y) <= (thief.x - p.x)) NSWE[2] = 1 ;
        }
        if(p.x > thief.x)
        {
            if(abs(thief.y - p.y) <= (p.x - thief.x)) NSWE[3] = 1 ;
        }
        if(p.y > thief.y)
        {
            if(abs(thief.x - p.x) <= (p.y - thief.y)) NSWE[0] = 1 ;
        }
        if(p.y < thief.y)
        {
            if(abs(thief.x - p.x) <= (thief.y - p.y)) NSWE[1] = 1 ;
        }
    }

    bool flag = 1 ;
    for(int i = 0 ; i < 4 ; i++)
        flag = flag & NSWE[i] ;
    
    flag == 0 ? cout << "YES" : cout << "NO" ;
}