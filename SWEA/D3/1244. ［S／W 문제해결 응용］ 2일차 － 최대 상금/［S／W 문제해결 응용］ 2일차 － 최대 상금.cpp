#include<bits/stdc++.h>
using namespace std;
int answer = 0;
map< pair<string,int>, bool > visited;

string swap_num(string num, int lhs, int rhs) {
    char tmp = num[lhs];
    num[lhs] = num[rhs];
    num[rhs] = tmp;
    return num;
}

void swap_simulation(string num, int N, int depth) {
    if (depth == N) {
        answer = max(answer, stoi(num));
        return;
    }

    for (int i = 0; i < num.length() ; i++) {
        for (int j = i + 1; j < num.length(); j++) {
            string new_num = swap_num(num, i, j);

            if (!visited[make_pair(new_num, depth)]) {
                swap_simulation(new_num, N, depth + 1);
                visited[make_pair(new_num, depth)] = true;
            }
        }
    }
}

void init() {
    answer = 0;
    visited = map< pair<string,int>, bool>();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string num;
        int N;
        init();
        cin >> num >> N;
        swap_simulation(num, N, 0);
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}