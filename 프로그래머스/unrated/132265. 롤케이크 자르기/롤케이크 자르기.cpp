#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    set<int> left, right;
    int check[10001] = {0, }, answer = 0 ;
    
    for(int top : topping) {
        check[top]++ ;
        left.insert(top) ;
    }
    
    while(!topping.empty()) {
        int top = topping.back();
        topping.pop_back() ;
        right.insert(top);
        
        check[top]--;
        if(check[top] == 0) left.erase(top);
        if(left.size() == right.size()) answer++ ;
    }
    return answer;
}