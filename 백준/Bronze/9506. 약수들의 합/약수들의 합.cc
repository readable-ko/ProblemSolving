#include <iostream>
#include <vector>
using namespace std ;
vector<int> box[100001];
int sum[100001] ;

void fill_box(int n) {
    if(sum[n] != 0) return ;

    for(int j = 1 ; j < n ; j++) {
        if(n % j == 0) {
            box[n].push_back(j) ;
            sum[n] += j ;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0) ;

    int tmp;
    cin >> tmp ;

    while(tmp != -1) {
        fill_box(tmp) ;
        
        if(sum[tmp] == tmp) {
            cout << tmp << " = " ;
            for(int i = 0 ; i < box[tmp].size() - 1 ; i++)
                cout << box[tmp][i] << " + ";
            cout << box[tmp].back() << "\n";
        }
        else {
            cout << tmp << " is NOT perfect.\n";
        }
        cin >> tmp ;
    }
}