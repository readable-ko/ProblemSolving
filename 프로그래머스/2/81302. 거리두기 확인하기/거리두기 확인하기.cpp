#include <bits/stdc++.h>
using namespace std;
vector<string> room;
vector<vector<bool>> visited;
int move_row[] = {1,-1,0,0};
int move_col[] = {0,0,1,-1};

vector< pair<int,int> > find_people() {
    vector< pair<int,int> > people;
    
    for(int row = 0 ; row < room.size() ; row++) {
        for(int col = 0 ; col < room[row].length() ; col++) {
            if(room[row][col] == 'P') {
                people.push_back(make_pair(row, col)) ;
            }
        }
    }
    
    return people;
}

bool is_nearby(int depth, int row, int col) {
    if(depth == 3) return true;
    if(depth != 0 && room[row][col] == 'P') return false ;
    if(room[row][col] == 'X') return true;
    bool result = true;
    
    for(int i = 0 ; i < 4 ; i++) {
        int next_row = row + move_row[i];
        int next_col = col + move_col[i];
        if(next_row < 0 || next_row >= 5 || next_col < 0 || next_col >= 5) continue;
        if(!visited[next_row][next_col]) {
            visited[next_row][next_col] = 1;
            bool around = is_nearby(depth + 1, next_row, next_col);
            visited[next_row][next_col] = 0;
            
            result = result & around;
        }
    }
    
    return result;
}

bool check_distance(vector< pair<int,int> > people) {
    for (pair<int,int> person : people) {
        int row = person.first;
        int col = person.second;
        visited = vector<vector<bool>>(5, vector<bool>(5));
        visited[row][col] = 1;
        if(is_nearby(0, row, col) == false)
           return false;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> place : places) {
        room = place;
        
        bool check = check_distance(find_people()) ;
        answer.push_back(check);
    }
    return answer;
}