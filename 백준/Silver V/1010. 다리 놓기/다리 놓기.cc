#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Combination(vector<vector <int> > &arr, int Right, int Left) {
    if(Left < 0 || Right < 1 || Left > Right) {
        arr[Right][Left] = 0;
        return 0;
    }
    if(Left == 0 || Right == 1) {
        arr[Right][Left] = 1;
        return 1;
    }
    if(arr[Right][Left] == 0) {
        arr[Right][Left] = Combination(arr, Right-1, Left) + Combination(arr, Right-1, Left-1);
    }
    return arr[Right][Left];
}

int main() {
  int Num;
  cin >> Num;
    
    vector<int> LeftSide(Num);
    vector<int> RightSide(Num);
    
    for(int i = 0 ; i < Num ; i++) {
        cin >> LeftSide[i] >> RightSide[i];
    }
    
    vector<vector <int> > arr(31, vector<int>(31));
    for(int i = 0; i < Num ; i++) {
        if(arr[RightSide[i]][LeftSide[i]] != 0) {
            cout << arr[RightSide[i]][LeftSide[i]] << endl;
        } else {
           arr[RightSide[i]][LeftSide[i]] = Combination(arr, RightSide[i], LeftSide[i]);
            cout << arr[RightSide[i]][LeftSide[i]] << endl;
        }
    }
}