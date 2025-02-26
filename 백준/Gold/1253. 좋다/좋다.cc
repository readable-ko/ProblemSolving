#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int N;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    int answer = 0;
    num = vector<int>(N);

    // input 데이터 받기
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    // 정렬
    sort(num.begin(), num.end());

    for(int i = 0; i < N; i++) {
        int row = 0, high = N - 1;
        while(row < high) {
            if(row == i) {
                row++;
                continue;
            }
            if(high == i) {
                high--;
                continue;
            }

            int sum = num[row] + num[high];

            if(sum > num[i]) {
                high--;
            } else if(sum < num[i]) {
                row++;
            } else {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}