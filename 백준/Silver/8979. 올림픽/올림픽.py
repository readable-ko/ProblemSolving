import sys
GOLD, SILVER, BRONZE = 1, 2, 3

total, want = map(int, sys.stdin.readline().split())
medal = [list(map(int, sys.stdin.readline().split())) for _ in range(total)]
mother_land = medal[[medal[idx][0] for idx in range(total)].index(want)]
answer = 1

for contry in medal:
  if contry[GOLD] > mother_land[GOLD]:
    answer += 1
  elif contry[GOLD] == mother_land[GOLD]:
    if contry[SILVER] > mother_land[SILVER]:
      answer += 1
    elif contry[SILVER] == mother_land[SILVER]:
      if contry[BRONZE] > mother_land[BRONZE]:
        answer += 1
print(answer)