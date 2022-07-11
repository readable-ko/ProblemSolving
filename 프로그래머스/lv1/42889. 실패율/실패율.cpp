#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

bool compare(pair<double, int> &a, pair<double, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end(), greater<>());
    int count_top, count_bottom;
    double p = 0;
    vector<pair <double, int>> arr;
    vector<int> answer;

    for(int i = 1; i <= N; i++) {
        count_top = 0; count_bottom = 0;
        for(int j = stages.size()-1; j >= 0; j--) {
            if(stages[j] == i) count_top++;
            if(stages[j] >= i) count_bottom++;
        }
        count_bottom != 0 ? p = (double)count_top/count_bottom : p = 0.0;
        arr.push_back(make_pair(p, i));
    }
    sort(arr.begin(), arr.end(), compare);
    for(auto aa : arr) {
        answer.push_back(aa.second);
    }

    return answer;
}