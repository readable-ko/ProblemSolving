import sys

def find_palindrom(palindrom):
    global ans, visited
    
    if len(palindrom) > len(str(N)):
        return;
    
    for i in starter:
        next_palindrom = i + palindrom + i
        if next_palindrom not in visited:
            visited.add(next_palindrom)
            find_palindrom(next_palindrom)
            if len(next_palindrom) > 0 and next_palindrom[0] != "0":
                num = int(next_palindrom)
                if num <= N:
                    ans.add(num)
        
    return 

N = int(sys.stdin.readline())
starter = ["","0","1","2","3","4","5","6","7","8","9"]
visited = set()
ans = set()

for i in starter:
    find_palindrom(i)
    
print(len(ans))