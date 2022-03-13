/** 홍익대학교 브론즈1 세로로 된 문자열 가로로 받아서 장난질
 * 풀었나이다.
 */
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    
    string arr[5];
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < 10000; i++) {
        if(arr[0][i] == '\n' || arr[0][i] == '\0')break;
        if(arr[2][i] == 'o') {
            continue;
        }
        else if(arr[1][i] == 'o') {
            arr[0][i] = 'o';
            arr[1][i] = 'w';
            arr[2][i] = 'l';
            arr[3][i] = 'n';
            arr[4][i] = '.';
        } else if(arr[0][i] == 'o') {
            arr[0][i] = '.';
            arr[1][i] = 'o';
            arr[2][i] = 'm';
            arr[3][i] = 'l';
            arr[4][i] = 'n';
        }
    }
    
    for(string a : arr) {
        cout << a << endl;
    }
    
}
