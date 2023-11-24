#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> stack;

    for(char c : s) {
        if (c == '(') {
            stack.push_back(c);
        } else if (c == ')' && !stack.empty()) {
            stack.pop_back();
        } else {
            answer = false;
            break;
        }
    }
    
    if (!stack.empty()) answer = false;
    
    return answer;
}