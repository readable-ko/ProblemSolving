#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector <bool> > arr(N+1,vector<bool>(N+1));
    cin >> N;
    int input, output;

    for(int i = 0; i < N; i++) {
        cin >> input >> output;
        arr[input][output] = true;
        arr[output][input] = true;
    }

    int count = 0;
    queue<int> save_point;
    vector<int> answer;
    save_point.push(1);

    while(!save_point.empty()) {
        for(int i = 1; i < arr.size(); i++) {
            bool connected = arr[save_point.front()][i];
            if(connected == true) {
                arr[save_point.front()][i] = false;
                save_point.push(i);
                answer.push_back(i);
            }
        }
        save_point.pop();
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()),answer.end());

    cout << answer.size()-1;
}