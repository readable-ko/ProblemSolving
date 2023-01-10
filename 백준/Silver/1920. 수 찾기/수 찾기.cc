#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int>a(n);
    int temp;
    int ck;
    int left, right, mid;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a[i] = temp ;
    }
    sort(a.begin(),a.end());
   

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        ck = 0;
        left = 0;
        right = n - 1;
        while(left <= right){
            mid = (left + right)/2;
            
            if(temp < a[mid]){
                right = mid - 1;
            }
            else if(temp > a[mid]){
                left = mid + 1;
            }
            else{
                ck = 1; 
                break;
            }
        }
        if(ck == 1){
            cout << "1\n";
        }
        else cout << "0\n";
    }

}