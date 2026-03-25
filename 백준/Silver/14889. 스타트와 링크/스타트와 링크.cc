#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <vector>

using namespace std;

/**
4 <=    N    <= 20  N은 짝수 - 사람
1 <= S(i, j) <= 100 정수     - 능력치

n C n/2 로 해서 생긴 경우의 수들에 대한 능력 차이 비교
최대 실행 횟수
=> 20! / 10! * 10!  => 19 * 17 * 13 * 12 * 11 / 3 => 10~30만..? * 100만? 시간
되려나...

선택 로직
1. combination(조합) 으로 풀어보자!
[v] 1-1. N을 받은 후 com함수에 N, N/2 넣기
[v] 1-2. for 문을 돌면서 현재 칸을 채우고 다음 com 호출
[v]     - 이 때 한 번 방문한 곳은 가지 않도록
[ ] 1-3. 최종 다 찼을 때 담긴 친구들 계산 / 안담긴 친구들 계산

계산 로직
[ ] 2. 이때 담긴 친구들의 값은 permutaion 순열로 계산!
[ ] 2-1. combination 목록과 2 넣기
[ ] 2-2. for 문 돌면서 현재 칸을 채우고 다음 per 호출
[ ]    - 이 때 본인을 제외 하고 가도록
[ ] 2-3. 최종 다 찼을 때 순열값 모두 더하기
[ ] 2-4. 반대 애들 똑같이 해서 모두 더하기
[ ] 2-5. 뺸 값돌려주기.


*/
vector<int> choosen;
vector<bool> visited;
vector<vector<int>> S(20, vector<int>(20));
vector<int> arr(20);
vector<int> selected(3);
int N, answer = 0x3f3f3f3f;

int calculation(vector<int> &vec, int d) {
  if (d == 2) {
    int x = selected[0];
    int y = selected[1];
    return S[x][y];
  }

  int sum = 0;
  int n = N / 2;
  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue;

    selected[d] = vec[i];
    visited[i] = true;
    sum += calculation(vec, d + 1);
    visited[i] = false;
  }
  return sum;
}

// sz: size d: depth
void combination(int sz, int d, int sp) {

  if (sz == d) {
    // 계산하기
    vector<int> buff(N);
    vector<int> other(sz);
    iota(buff.begin(), buff.end(), 0);
    set_difference(buff.begin(), buff.end(), arr.begin(), arr.begin() + sz,
                   other.begin());

    int a = calculation(arr, 0);
    int b = calculation(other, 0);
    answer = min(abs(a - b), answer);
  }

  // 1 2 3 4 5 6
  for (int i = sp; i < N; i++) {
    int val = choosen[i];
    arr[d] = val;
    combination(sz, d + 1, i + 1);
  }

  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }

  choosen = vector<int>(N);
  iota(choosen.begin(), choosen.end(), 0);

  visited = vector<bool>(N);

  int sz = (int)(N / 2);
  combination(sz, 0, 0);
  cout << answer;
}