#include<bits/stdc++.h>
using namespace std;
string tmp ;
int now ;

void DFS(int idx, string str, int cnt)
{
    if(idx == str.length())
    {
        return ;
    }

    for(int i = 0 ; i <= 9 ; i++)
    {
        if(i == 0 && idx == 0) continue ;
        if(now == cnt) return ;

        tmp.push_back(i + '0') ;

        int pr = stoi(tmp) ;
        if(pr <= stoi(str))
        {
            cout << " " << stoi(tmp) << ".png" ;
            now++ ;
        }

        DFS(idx+1, str, cnt) ;
        tmp.pop_back() ;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str ;
        cin >> str ;
        tmp = "" ;
        cout << "#" << test_case ;
        
        int cnt = min(stoi(str), 50) ;
        now = 0 ;

        DFS(0, str, cnt) ;
        cout << '\n' ;
	}
	return 0;
}