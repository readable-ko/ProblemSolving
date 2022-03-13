/** 홍익대 절대평가 문제 브론즈2 그냥 간단한 구현 
 * 풀었나이다.
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n = 0, sangda = 0, julda = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> sangda >> julda;
    pair<int,int> answer;
    answer.second = 0;
    
    answer.first = (n * sangda) / 100;
    for ( int i : arr ) {
        if(i >= julda) answer.second++;
    }
    cout << answer.first << " " << answer.second;
}