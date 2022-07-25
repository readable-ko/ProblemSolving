#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
deque< pair <int, int> > arr ;
priority_queue<int, vector<int>, greater<int> > room ;
int N ;

bool compare(pair <int, int> a, pair <int, int> &b)
{
    if(a.first == b.first) return a.second < b.second ;
    return a.first < b.first ;
}

void InputSetting()
{
    cin >> N ;
    arr = deque< pair <int, int> >(N) ;

    for(auto& it : arr)
        cin >> it.first >> it.second ;
    sort(arr.begin(), arr.end(), compare) ;
}

void FindAnswer()
{
    room.push(arr[0].second) ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        if(room.top() <= arr[i].first)
            room.pop() ;
        
        room.push(arr[i].second) ;
    }

    cout << room.size() ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    FindAnswer() ;
}