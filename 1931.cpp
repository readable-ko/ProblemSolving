#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
pair<int,int> arr[100001] ;
int N, answer ;

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second == b.second ? a.first < b.first : a.second < b.second ;
}

void FindAnswer()
{
    int curr = 0 ;
    for(int i = 1 ; i <= N ; i++)
    {
        if(curr <= arr[i].first)
        {
            answer++ ; curr = arr[i].second ;
        }
    }
}

void InputSetting()
{
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
        cin >> arr[i].first >> arr[i].second ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    sort(&arr[1], &arr[N+1], comp) ;
    FindAnswer() ;
    cout << answer ;
}