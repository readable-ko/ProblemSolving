//주어진 것에서 경우의 수를 따질 때는 array를 쓰자.
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    bool arr[101][101] = {false};
    int x1,x2, y1,y2, count = 0;
    for(int i = 0 ; i < 4 ; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 ; j < x2 ; j++) {
            for(int k = y1; k < y2 ; k++) {
                arr[j][k] = true;
            }
        }
    }
    
    for(int i = 0 ; i < 101; i++) {
        for(int j = 0 ; j < 101; j++) {
            if(arr[i][j]) count++;
        }
    }
    cout << count;
}
