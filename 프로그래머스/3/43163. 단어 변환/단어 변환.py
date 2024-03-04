answer = 0x3f3f3f3f
def solution(begin, target, words):
    visited = [False for _ in range(len(words))]
    def check(prev, now):
        cnt = 0
        if prev == now:
            return False
        
        for i in range(len(prev)):
            if prev[i] != now[i]:
                cnt += 1
            if cnt > 1:
                return False
            
        return True
    
    def dfs(depth, now, target):
        global answer
        if now == target:
            answer = min(answer, depth)
            return
        
        for idx, word in enumerate(words):
            if check(word, now) and not visited[idx]:
                visited[idx] = True
                dfs(depth + 1, word, target)
                visited[idx] = False
                
        return
    dfs(0, begin, target)
    
    return answer if answer != 0x3f3f3f3f else 0