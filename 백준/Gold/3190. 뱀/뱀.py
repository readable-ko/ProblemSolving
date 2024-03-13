import sys
from collections import deque

N = int(sys.stdin.readline())
apple_cnt = int(sys.stdin.readline())
b = [[[False, False] for _ in range(N)] for __ in range(N)]

for _ in range(apple_cnt):
    x, y = map(int, sys.stdin.readline().split())
    b[x-1][y-1][0] = True

turn_cmd = int(sys.stdin.readline())
tp = [list(sys.stdin.readline().split()) for _ in range(turn_cmd)]

class Game:
    def __init__(self, board, turning_point):
        self.board = board
        self.N = len(board)
        self.turning_point = turning_point
        self.time = 1
        self.way = 0
        self.idx = 0
        self.direction = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        self.snake = deque()

    def _init(self):
        self.snake.append([0, 0])
        self.board[0][0][1] = True

    def _is_end_point(self, pos):
        r, c = pos
        if r < 0 or r >= self.N or c < 0 or c >= self.N:
            return True
        return False

    def _is_body(self, pos):
        r, c = pos
        if self.board[r][c][1]:
            return True
        return False

    def _is_apple(self, pos):
        r, c = pos
        if self.board[r][c][0]:
            self.board[r][c][0] = False
            return True
        return False

    def _check_turning_point(self):
        if self.get_turing_time() == self.time:
            if self.get_turning_point() == 'D':
                self.way = (self.way + 1) % 4
            else:
                if self.way == 0:
                    self.way = 3
                else:
                    self.way = self.way - 1

    def move(self):
        head = [self.snake[-1][i] + self.direction[self.way][i] for i in range(2)]

        if self._is_end_point(head) or self._is_body(head):
            return False

        if not self._is_apple(head):
            tail = self.snake.popleft()
            self.board[tail[0]][tail[1]][1] = False

        self.snake.append(head)
        self.board[head[0]][head[1]][1] = True
        self._check_turning_point()

        return True

    def simulate(self):
        self._init()
        while True:
            if self.move():
                self.time += 1
            else:
                print(self.time)
                break

    def get_turing_time(self):
        if self.idx < len(self.turning_point):
            return int(self.turning_point[self.idx][0])
        else:
            return -1

    def get_turning_point(self):
        val = self.turning_point[self.idx][1]
        self.idx += 1
        return val

game = Game(b, tp)
game.simulate()
