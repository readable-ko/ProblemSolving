#include <iostream>
#include <vector>

using namespace std;
class Tree {
  public:
    int x;
    int y;
    int age;

    Tree() { x = 0, y = 0, age = 0; }
    Tree(int r, int c, int a) { x = r, y = c, age = a; }
    Tree(int r, int c) { x = r, y = c, age = 0; }
};

/**
    문제 준나 쉬워보이네...
    맵 최대 10*10 => 100, 최대 나무 개수 100개, 최대 k=1000, 최대 나무 나이 1010

    각 양분 먼저 입력한 후 input 받을 때 나무 위치 받아서 queue에 넣기 -> 가장
   어린 나무 어케 암? 각 양분 먼저 입력한 후 for문 돌려버리기

    해시 맵으로 풀면 안되나?
    각 자리에 [1][1]위치에 [1]{} [2]{} [3]{} 이 있음
    만약 [2]이후로 양분 없으면 뒤로 다 죽여
    나무 위치는 어떻게? set으로 위치만 중복 없이 넣어보면 되지 않을까? pair가
   중복 인식 되는지? Tree랑...? -> 됨

   해시맵 지웠다 꺼냈다 좀 그런데?
   그럼 그냥 배열로 하자. [10][10][1012] (최대 나무 1010살)
   그래서 for문 돌면서 나무 있으면 젤 앞의 배열부터 나이 까먹고 양분 없으면 뒤
   0으로 만들면서 여름에 줄 양분으로 기억

[ ] 그 칸의 나이 0이 남은 양분이다
[ ] 그 칸의 나이 N이 1부터 K까지 가능한 만큼 간다
[ ] 만약 사이에 부족해진다면 그 나이에 남은 애들 개수를 체크한다.
[ ] 이후 뒤에서부터 측정하며 양분으로 만들어준다. 이 때 K부터 1까지는 앞으로
1칸씩 땡긴다.

   여름에 각 양분 위치 양분 주기

   가을에 번식하기 근처 8칸 5의 배수로 모든 칸을 보면서 각 칸에서 근처 8칸 +1
   해줄 값 정리해서 근처에 한번에 값 추가

   겨울에 초기와 동일한 양분 주입

   이 모든 과정을 K번 반복

*/
const int MAX_K = 1011;
int ground[11][11][1020];
vector<vector<int>> s2d2;
int N, M, K;

void SpringAndSummer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k = 1;      // 내가 키울 수 있는 나이
            int remain = 0; // 그 나이에 남은 애들 수 (양분 될 애들)
            for (; k < MAX_K; k++) {
                // k * 개수 = 필요 양분 수
                int need = ground[i][j][k] * k;

                if (ground[i][j][0] >= need) {
                    ground[i][j][0] -= need;
                } else {
                    // 죽은거 = 줄 거 - 양분남은거
                    // 준애들
                    // ex: 5*2 - 7 = 3 || 2
                    remain = ground[i][j][k] - ground[i][j][0] / k;
                    ground[i][j][k] -= remain;
                    ground[i][j][0] -= (ground[i][j][k] * k);
                    break;
                }
            }
            for (int l = MAX_K; l > 0; l--) {
                // 죽은 나무는 양분으로
                if (l > k) {
                    ground[i][j][0] += ground[i][j][l] * (l / 2);
                    ground[i][j][l] = 0;

                    // 산 나무 레벨 1씩 증가, 부분 양분도 처리
                } else {
                    if (remain > 0) {
                        ground[i][j][0] += remain * (l / 2);
                        ground[i][j][l + 1] = ground[i][j][l];
                        remain = 0;
                    } else {
                        ground[i][j][l + 1] = ground[i][j][l];
                    }
                    ground[i][j][l] = 0;
                }
            }
        }
    }
}

void FallAndWinter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int giving = 0;
            for (int k = 5; k < MAX_K; k += 5) {
                if (ground[i][j][k] > 0) {
                    giving += ground[i][j][k];
                }
            }
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int ni = i + x;
                    int nj = j + y;
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                        continue;
                    }

                    ground[ni][nj][1] += giving;
                }
            }

            ground[i][j][0] += s2d2[i][j];
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    s2d2 = vector<vector<int>>(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s2d2[i][j];
            ground[i][j][0] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        ground[x - 1][y - 1][age]++;
    }

    for (int i = 0; i < K; i++) {
        SpringAndSummer();
        FallAndWinter();
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k < MAX_K; k++) {
                answer += ground[i][j][k];
            }
        }
    }

    cout << answer << "\n";
}