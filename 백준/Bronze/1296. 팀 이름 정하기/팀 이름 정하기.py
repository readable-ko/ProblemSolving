import sys
name = sys.stdin.readline().strip()
N = int(sys.stdin.readline())

selected = "Z" * 21
point = 0
for _ in range(N):
    team_name = sys.stdin.readline().strip()
    l = name.count('L') + team_name.count('L')
    o = name.count('O') + team_name.count('O')
    v = name.count('V') + team_name.count('V')
    e = name.count('E') + team_name.count('E')
    
    sub_point = ((l+o) * (l+v) * (l+e) * (o+v) * (o+e) * (v+e)) % 100
    if sub_point == point and selected > team_name:
        selected = team_name
    elif sub_point > point:
        
        selected = team_name
        point = sub_point

print(selected)