#include <bits/stdc++.h>
using namespace std;
class value {
    public:
    int index;
    int num;
    value(int i, int n){index = i, num = n;}
};

struct cmp {
    bool operator()(value lhs, value rhs) {
        if(lhs.num == rhs.num) return lhs.index > rhs.index;
        return lhs.num > rhs.num;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, D;
    cin >> N >> D;
    vector<int> arr(N);
    priority_queue<value, vector<value>, cmp> pq;
    
    for (int idx = 0; idx < arr.size(); idx++) {
        cin >> arr[idx];
        pq.push(value(idx, arr[idx]));

        while (pq.size() > D) {
            if (pq.top().index > idx - D) {
                break;
            }
            pq.pop();
        }

        cout << pq.top().num << " ";
    }
}