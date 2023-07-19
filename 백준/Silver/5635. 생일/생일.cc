#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    map<int, string> mp;
    vector<int> v;
    int temp;
    cin >> temp;

    while (temp--)
    {
        string s = "", tmp, name;
        cin >> name;
        for (int i = 0; i < 3; i++)
        {
            cin >> tmp;
            if (tmp.length() < 2)
                tmp = "0" + tmp;
            s = tmp + s;
        }
        int birth = stoi(s);
        v.push_back(birth);
        mp[birth] = name;
    }

    sort(v.begin(), v.end());
    cout << mp[v.back()] << "\n" << mp[v[0]] ;
}