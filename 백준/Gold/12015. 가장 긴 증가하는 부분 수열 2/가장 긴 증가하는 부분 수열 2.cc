#include <bits/stdc++.h>
using namespace std;
vector<int> answer = {0x3f3f3f3f};

void find_lower_bound(int num) {
    int low = 0;
    int high = answer.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if(answer[mid] < num) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    answer[low] = num;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, num;
    cin >> N;

    for (int i = 0 ; i < N ; i++) {
        cin >> num;
        
        if (answer.back() < num) {
            answer.push_back(num);
        } else {
            find_lower_bound(num);
        }
    }

    cout << answer.size();
}