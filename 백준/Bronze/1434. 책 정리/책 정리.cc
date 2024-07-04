#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, remain = 0;
    cin >> N >> M ;

    vector<int> boxs(N);
    vector<int> books(M);
    for (int& box : boxs)
        cin >> box;
    
    for (int& book : books)
        cin >> book;
    
    for (int i = 0, j = 0; i < N;) {
        if (j == M) {
            remain += boxs[i++];
        }
        else if (boxs[i] < books[j]) {
            remain += boxs[i++];
        }
        else {
            boxs[i] -= books[j++];
        }
    }

    cout << remain << "\n" ;
}