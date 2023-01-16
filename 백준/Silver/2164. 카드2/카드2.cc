#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, temp = 0;
    cin >> N;
    queue<int> arr;
    for(int i = 0; i < N; i++) {
        arr.push(i+1);
    }
    while(arr.size() != 1) {
        arr.pop();
        temp = arr.front();
        arr.pop();
        arr.push(temp);
    }
    cout << arr.front();
}