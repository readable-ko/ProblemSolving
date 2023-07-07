#include <bits/stdc++.h>
using namespace std ;
int N ;

int main() {
    //lol
    //앞뒤로 l lo ol ll
    //l o l
    cin >> N ;

    while(N--) {
        string s ;
        cin >> s;
        s += "kk" ;
        int str = 3 ;
        for(int i = 0 ; i < s.length() - 2 ; i++) {
            if(s[i] == 'l') {
                str = min(str, 2); 
                if(s[i+1] == 'l' || s[i+2] == 'l' || s[i+1] == 'o') str = min(str, 1) ;
                if(s[i+1] == 'o' && s[i+2] == 'l') {
                    str = min(str, 0) ; break;
                }
            }
            else if(s[i] == 'o') {
                str = min(str, 2);
                if(s[i+1] == 'l') str = min(str, 1) ;
            }
        }
        cout << str << "\n" ;
    }
}