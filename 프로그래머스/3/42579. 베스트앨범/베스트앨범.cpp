#include <bits/stdc++.h>
using namespace std;

bool comp_total(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

bool comp_dict(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_total;
    
    //index, plays
    map<string, vector<pair<int, int>>> genres_dict;
    
    for(int i = 0; i < genres.size(); i++) {
        string g = genres[i];
        int p = plays[i];
        
        genres_total[g]+= p;
        genres_dict[g].push_back(make_pair(i, p));
    }
    
    vector<pair<string, int>> sorted_genres_total = vector<pair<string,int>>(genres_total.begin(), genres_total.end());
    
    // 가장 재생 많이된 장르 순으로 정렬
    sort(sorted_genres_total.begin(), sorted_genres_total.end(), comp_total);
    
    for (pair<string, int> it : sorted_genres_total) {
        string g = it.first;
        vector<pair<int, int>> gd = vector<pair<int, int>>(genres_dict[g].begin(), genres_dict[g].end());
        
        int min_size = min((int)gd.size(), 2);
        
        sort(gd.begin(), gd.end(), comp_dict);
        
        for (int idx = 0; idx < min_size; idx++) {
            answer.emplace_back(gd[idx].first);
        }
    }
    
    return answer;
}