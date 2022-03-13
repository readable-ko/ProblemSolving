#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr1(N);
    vector<int> arr2(N);
    int answer = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> arr2[i];
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    for(int i = 0; i < N; i++) {
        answer += arr1[i] * arr2[i];
    }
    cout << answer;
}