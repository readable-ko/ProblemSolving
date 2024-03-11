def find(q:list, val):
    if len(q) == 0:
        return 0

    low, high = 0, len(q)
    while low < high:
        mid = (low + high) // 2
        if q[mid] < val:
            low = mid + 1
        else:
            high = mid

    return low

def solution(operations):
    answer = []
    for command in operations:
        cmd, value = command.split()
        val = int(value)
        if cmd == "D" and len(answer):
            if val == 1:
                answer.pop()
            else:
                answer.pop(0)
        elif cmd == "I":
            pos = find(answer, val)
            answer.insert(pos, val)
            
    return [answer[-1],answer[0]] if len(answer) else [0,0]