import sys
date, term = map(int,sys.stdin.readline().split())
days = list(map(int,sys.stdin.readline().split()))
answer = people = sum(days[:term])
cnt = 1

def compare(a, b):
    global cnt
    if a < b:
        cnt = 1
        return b
    elif a == b:
        cnt += 1
    return a

for idx in range(term,date):
    people = people - days[idx - term] + days[idx]
    answer = compare(answer, people)

print(f'{answer}\n{cnt}') if answer != 0 else print("SAD")