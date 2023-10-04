import sys
sentence = sys.stdin.readline().strip()
answer = set()

# for split a, b, c
def erase_b(target:str, give:str):
    box = []
    for idx, char in enumerate(sentence):
        if char == target:
            box.append(idx)
        
        if char == give and len(box) > 0 and idx not in answer:
            answer.add(box.pop(0))
    
    return

erase_b('B','C')
erase_b('A','B')
print(len(answer))