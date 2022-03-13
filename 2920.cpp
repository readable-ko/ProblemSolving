#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr(8);
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    int key = arr[0] < arr[1] ? key = 1 : key = 0 ;
    for(int i = 1; i < arr.size(); i++) {
        if(key == 1) {
            arr[i-1] < arr[i] ? key = 1 : key = -1 ;
        } else if(key == 0) {
            arr[i-1] > arr[i] ? key = 0 : key = -1 ;
        }

        if(key == -1) break;
    }

    switch(key) {
        case -1 : cout << "mixed"; break;
        case 0 : cout << "descending"; break;
        case 1 : cout << "ascending"; break;
    }
}