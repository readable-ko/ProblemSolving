#include <bits/stdc++.h>
using namespace std;

class LIS {
private:
    vector<int> order;
    vector<int> record;
    vector<int> sequence;

public:
    int size;
    
    int record_length() {
        return record.size() - 1;
    }

    int order_length() {
        return order.size() - 1;
    }

    int order_size() {
        return order_length() + 1;
    }

    int change_order_from_seq(int cnt, int idx) {
        order[cnt] = sequence[idx];
        return cnt - 1;
    }

    vector<int> get_order() {
        return order;
    }

    bool is_eqaul_record(int cnt, int idx) {
        return record[idx] == cnt;
    }

    void get_input() {
        for (int i = 0 ; i < size ; i++) {
            cin >> sequence[i];
            
            if (order.empty() || order.back() < sequence[i]) {
                order.push_back(sequence[i]);
                record[i] = order.size() - 1;
            } else {
                find_lower_bound(i);
            }
        }
    }

    void find_lower_bound(int idx) {
        int low = 0;
        int high = order.size() - 1;
        
        while(low < high) {
            int mid = (low + high) / 2;
            
            if (order[mid] < sequence[idx]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        order[low] = sequence[idx];
        record[idx] = low;
    }

    LIS(int sz) {
        size = sz;
        sequence = vector<int>(sz);
        record = vector<int>(sz);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, num;
    cin >> N;

    LIS longest_increase_sequence = LIS(N);
    longest_increase_sequence.get_input();
    
    cout << longest_increase_sequence.order_size() << "\n";
    int cnt = longest_increase_sequence.order_length();
    int sp = longest_increase_sequence.record_length();

    for (int i = sp ; i >= 0 ; i--) {
        if(cnt == -1) break;
        if(longest_increase_sequence.is_eqaul_record(cnt, i)) {
            cnt = longest_increase_sequence.change_order_from_seq(cnt, i);
        }
    }

    for(int it : longest_increase_sequence.get_order()) {
        cout << it << " ";
    }
}