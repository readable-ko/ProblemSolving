#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int arr[201][201];

int Combination(int index, int div) {
    if(index == div || div == 0) {
        arr[index][div] = 1;
        return 1;
    }
    if(arr[index][div] != 0) return arr[index][div];
    return arr[index][div] = Combination(index-1, div -1) + Combination(index-1, div);
}

int main() {
    
    int index, div;
    cin >> index >> div;
    cout << Combination(index-1, div);
}