#include <bits/stdc++.h>
using namespace std ;
int N ;
class Best
{
public:
    int val = 2e9 ;
    int first = 0 ;
    int second = 0 ;
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> liquid(N) ;

    for(int &it: liquid)
        cin >> it ;
    sort(liquid.begin(), liquid.end()) ;

    int sp = 0, ep = N - 1 ;
    Best best ;

    while(sp < ep)
    {
        int local_min = liquid[sp] + liquid[ep] ;

        if(abs(best.val) > abs(local_min))
        {
            best.val = local_min ;
            best.first = liquid[sp] ;
            best.second = liquid[ep] ;
        }
        
        if(local_min == 0) break ;

        local_min < 0 ? sp++ : ep-- ;
    }
    cout << best.first << " " << best.second << "\n" ;
}