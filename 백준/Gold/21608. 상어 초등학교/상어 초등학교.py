import sys
from collections import defaultdict
N = int(sys.stdin.readline())
students = [list(map(int,sys.stdin.readline().split())) for _ in range(N*N)]
chair = [[0 for _ in range(N)] for _ in range(N)]
chairMap = dict()
dx, dy = [1,0,-1,0], [0,1,0,-1]

class AssignSeats:
    def __init__(self, student):
        self.me = student[0]
        self.friends = student[1:]
        self.row = 0
        self.col = 0
    
    # 조건1: 비어있는 칸 중 좋아하는 학생이 가장 많은 칸 찾기
    def _findBestFriend(self):
        bf = defaultdict(int)
        val = []
        
        for r in range(N):
            for c in range(N):
                if chair[r][c] == 0:
                    val.append((r,c))
                elif chair[r][c] in self.friends:
                    for dr, dc in zip(dx,dy):
                        R, C = r+dr, c+dc
                        if R >= N or R < 0 or C >= N or C < 0:
                            continue
                        if chair[R][C] == 0:
                            bf[(R,C)] += 1
        
        if len(bf) > 0:
            maxVal = max(bf.values())
            val = [key for key, val in bf.items() if val == maxVal]
        
        return val

    # 조건2: 1을 만족하는 칸 중 빈 칸이 가장 많은 칸 찾기
    def _findBlank(self, val:list()):
        blank = defaultdict(int)
        
        for r, c in val:
            for dr, dc in zip(dx, dy):
                R, C = r+dr, c+dc
                if R >= N or R < 0 or C >= N or C < 0:
                    continue
                if chair[R][C] == 0:
                    blank[(r,c)] += 1
        
        if len(blank) > 0:
            maxVal = max(blank.values())
            val = [key for key, val in blank.items() if val == maxVal]
        return val

    # 조건3: 2를 만족하는 칸 중 행과 열이 가장 작은 칸 찾기
    def _findLowest(self, val:list()):
        for r in range(N):
            for c in range(N):
                if (r,c) in val:
                    return (r,c)
        return val[0]
    
    def _place(self):
        global chair, chairMap
        chair[self.row][self.col] = self.me
        chairMap[self.me] = [self.row, self.col]
    
    def find(self):
        betweenFriends = self._findBestFriend()
        betweenBlanks = self._findBlank(betweenFriends)
        self.row, self.col = self._findLowest(betweenBlanks)
        self._place()

"""
일단 학생을 넣어서 좋아하는 학생 번호가 있는 앞뒤 양옆 r, c에 +1 해주고 제일 값이 큰 애들만 뽑아서 리턴
만약 리턴 값이 2개 이상이면 2번 조건으로
"""
for student in students:
    AssignSeats(student).find()

answer = 0
for student in students:
    r, c = chairMap[student[0]]
    cnt = 0
    for dr, dc in zip(dx, dy):
        R, C = r + dr, c + dc
        if 0 <= R < N and 0 <= C < N:
            if chair[R][C] in student:
                cnt += 1

    answer += int(10 ** (cnt - 1))
print(answer)