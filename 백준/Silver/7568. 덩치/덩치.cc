#include <bits/stdc++.h>
using namespace std ;
int N ;

typedef struct dongchi
{
    int idx ;
    int weight ;
    int height ;

} Dongchi;

bool comp(Dongchi &a, Dongchi &b)
{
    return a.height < b.height && a.weight < b.weight ;
}

int main()
{
    cin >> N ;
    vector<Dongchi> arr(N) ;

    for(auto &it : arr)
        cin >> it.weight >> it.height ;
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            if(arr[i].height < arr[j].height && arr[i].weight < arr[j].weight)
                arr[i].idx++ ;
    
    for(auto it : arr)
        cout << ++it.idx << " " ;
}
