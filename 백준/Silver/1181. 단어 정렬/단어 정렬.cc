#include <iostream>
#include <set>
using namespace std ;

struct cmp
{
    bool operator()(string a, string b) const {
        if(a.length() == b.length()) return a < b ;
        return a.length() < b.length() ;
    }
};

int main()
{
    int N ;
    cin >> N ;
    set<string, cmp> s ;
    string str ;

    for(int i = 0 ; i < N ; i++) {
        cin >> str ;
        s.insert(str) ;
    }

    for(auto str : s)
        cout << str << "\n" ;
}