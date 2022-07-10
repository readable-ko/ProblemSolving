#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(string s) {
    int a = 0;
    if(s.length() == 4 || s.length() == 6) {
        for(int i = 0; i < s.length(); ++i) {
            if(a > 0) break;
            if(isdigit(s[i]) == false) {
                ++a;
            }
        } return a == 0 ? true : false;
    }else return false;
}