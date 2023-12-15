from itertools import permutations
from collections import defaultdict
import operator
import sys

N = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
operator_cnt = list(map(int, sys.stdin.readline().split()))

ops = {"+":operator.add, "-":operator.sub, "*":operator.mul, "/":operator.floordiv}
operators = ""
visited = defaultdict(tuple)
max_value, min_value = -0x3f3f3f3f, 0x3f3f3f3f

for opts, cnt in zip(list(ops.keys()), operator_cnt):
  operators += opts * cnt;

for temp in permutations(operators, len(operators)):
  if visited[temp]:
    continue
  else:
    visited[temp] = True;
    now = numbers[0]
    for idx in range(len(temp)):
      if now < 0 and temp[idx] == "/":
        now = abs(now)
        now = -ops[temp[idx]](now, numbers[idx+1])
      else:
        now = ops[temp[idx]](now, numbers[idx+1])

    max_value = max(max_value, now)
    min_value = min(min_value, now)

print(max_value,min_value,sep="\n")
