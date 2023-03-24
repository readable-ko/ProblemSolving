#include<bits/stdc++.h>
using namespace std;
pair<string, int> maxi ;

int main()
{
    int N ;
    cin >> N ;

    map<string,int> mp ;
    vector<string> name ;

    for(int i = 0 ; i < N ; i++)
    {
        string tmp ;
        cin >> tmp ;
        name.push_back(tmp) ;
        mp[tmp]++ ;
    }
    
    sort(name.begin(), name.end()) ;
    for(string s : name)
    {
        if(maxi.second < mp[s])
        {
            maxi.first = s ;
            maxi.second = mp[s] ;
        }
    }
    cout << maxi.first ;
}