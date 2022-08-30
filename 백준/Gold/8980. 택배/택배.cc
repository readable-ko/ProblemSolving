// This Code is written by gloryko fpqpsxh.
#include <bits/stdc++.h>
using namespace std ;
int N, C, M, now, s, e, w, answer, town[2001] ;

typedef struct Delivery
{
    int s, e, w ;
    Delivery() {s=0 ; e=0 ; w=0 ;}
    Delivery(int S, int E, int W) : s(S), e(E), w(W) {}

}delivery;

bool cmp(Delivery lhs, Delivery rhs)
{
    if(rhs.e == lhs.e) return lhs.s < rhs.s ;
    return lhs.e < rhs.e ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N >> C >> M ;
    vector<Delivery> arr(M) ;
    for(Delivery &it : arr)
    {
        cin >> s >> e >> w ;
        it = Delivery(s, e, w) ;
    }
    
    sort(arr.begin(), arr.end(), cmp) ;

    for(int i = 0 ; i < M ; i++)
    {
        int maximum = 0 ;
        for(int j = arr[i].s ; j < arr[i].e ; j++)
            maximum = max(maximum, town[j]) ;
        
        now = min(C - maximum, arr[i].w) ;
        answer += now ;
        for(int j = arr[i].s ; j < arr[i].e ; j++)
            town[j] += now ;
    }

    cout << answer ;
}