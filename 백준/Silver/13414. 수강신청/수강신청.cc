#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;

vector< pair<string, int> > box ;
unordered_map<string,int> ump ;
int cut, applier ;

bool comp(pair<string,int> &a, pair<string,int> &b)
{
    return a.second < b.second ;
}

int main()
{
    SETTING ;
    cin >> cut >> applier ;
    string temp_id ;
    for(int i = 1 ; i <= applier ; i++)
    {
        cin >> temp_id ;
        ump[temp_id] = i ;
    }
    
    for(auto ele : ump)
    {
        box.push_back(make_pair(ele.first, ele.second)) ;
    }
    sort(box.begin(), box.end(), comp) ;

    for(int i = 0 ; i < cut ; i++)
    {
        if(i >= box.size()) break ;
        cout << box[i].first << "\n" ;
    }
}