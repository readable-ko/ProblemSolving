#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> datas, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string,int> ext_code;
    ext_code["code"]=0,ext_code["date"]=1, ext_code["maximum"]=2,ext_code["remain"]=3;
    
    for (vector<int> data : datas) {
        int num = ext_code[ext];
        if (data[num] < val_ext) {
            answer.push_back(data);
        }
    }
    
    sort(answer.begin(), answer.end(), [&](vector<int> lhs, vector<int> rhs) {
        int num = ext_code[sort_by];
        return lhs[num] < rhs[num];
    });
    return answer;
}