#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector < vector < int > > arr(N);
    int input;

    for(int i = 0 ; i < N ; i++) {
        cin >> input;
        arr[input-1].push_back(i+1);
    }

    int count = 0;
    cout << "size : " << arr[0].size() << endl;
    for(int i = 0; i < arr[0].size(); i++) {
        if(!arr[0].empty()) {
            count++;
            arr[0].pop_back();
        } else break;
    }

    cout << count;

    
}