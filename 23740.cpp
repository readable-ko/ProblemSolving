#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std ;

vector <pair <pair <int, int>, int> > bus_stop, answer ;
int N, S, E, C, idx ;

void InputSetting()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> S >> E >> C ;
        bus_stop.push_back({{S, E}, C});
    }
    sort(bus_stop.begin(), bus_stop.end()) ;
}

void MakeAnswer()
{
    S = bus_stop[0].first.first, E = bus_stop[0].first.second, C = bus_stop[0].second ;
    for(int i = 0 ; i < N ; i++)
    {
        if(bus_stop[i].first.first <= E)
        {
            E = max(E, bus_stop[i].first.second), C = min(C, bus_stop[i].second) ;
        }
        else
        {
            answer.push_back({{S, E}, C}) ;
            S = bus_stop[i].first.first, E = bus_stop[i].first.second, C = bus_stop[i].second ;
        }
    }
    answer.push_back({{S, E}, C}) ;
}

void PrintAnswer()
{
    cout << answer.size() << endl ;
    for(auto it : answer)
        cout << it.first.first << " " << it.first.second << " " << it.second << endl ;
}

int main()
{
    SETTING ;
    InputSetting() ;
    MakeAnswer() ;
    PrintAnswer() ;
}