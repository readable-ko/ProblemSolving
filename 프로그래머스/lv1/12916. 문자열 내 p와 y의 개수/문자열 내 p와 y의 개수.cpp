#include <string>
#include <iostream>
using namespace std;
int count(string s, char c) {
    int num = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] < 96) s[i] += 32;
        if(s[i] == c) ++num;
    }
    return num;
}

bool solution(string s)
{
    int a = 0 ; int b = 0;
    a = count(s,'p');
    b = count(s,'y');
    
    
    return (a == b) ? true : false;

}