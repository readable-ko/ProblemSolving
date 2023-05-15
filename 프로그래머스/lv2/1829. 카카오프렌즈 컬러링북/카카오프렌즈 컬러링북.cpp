#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int M, N, connected_point_count;
bool check[101][101];
vector<pair<int, int>> move_points;

inline void dfs(const int& m_index, const int& n_index, const vector<vector<int>>& picture)
{
    check[m_index][n_index] = true;
    ++connected_point_count;
    for(const auto& move_point : move_points)
    {
        auto row_index = m_index + move_point.first;
        auto column_index = n_index + move_point.second;
        if((0 <= row_index) && (row_index < M) &&
           (0 <= column_index) && (column_index < N) &&
           !check[row_index][column_index] &&
           (picture[m_index][n_index] == picture[row_index][column_index]))
            dfs(row_index, column_index, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m;
    N = n;
    connected_point_count = 0;
    fill(&check[0][0], &check[M][N], false);
    move_points.push_back(make_pair(0, 1));
    move_points.push_back(make_pair(0, -1));
    move_points.push_back(make_pair(1, 0));
    move_points.push_back(make_pair(-1, 0));
    
    vector<int> connected_point_tmpl;
    for(auto row = 0; row < m; ++row)
    {
        for(auto column = 0; column < n; ++column)
        {
            if(picture[row][column] && !check[row][column])
            {
                connected_point_count = 0;
                dfs(row, column, picture);
                connected_point_tmpl.push_back(connected_point_count);
            }
        }
    }
    return vector<int>{static_cast<int>(connected_point_tmpl.size()), *max_element(connected_point_tmpl.begin(), connected_point_tmpl.end())};
}