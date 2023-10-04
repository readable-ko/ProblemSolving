import sys
sentence = sys.stdin.readline().strip()
answer = set()

# for split a, b, c
def erase_b(target:str, give:str):
    box = []
    for idx, char in enumerate(sentence):
        if char == target:
            box.append(idx)
        
        if char == give and len(box) > 0:
            answer.add(box.pop(0))
    
    return

erase_b('A','B')
erase_b('B','C')
print(len(answer))