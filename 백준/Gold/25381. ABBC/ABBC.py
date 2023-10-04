import sys
sentence = sys.stdin.readline().strip()
answer = set()

def erase_b(given:str, target:str):
    box = []
    front = 0

    for idx, char in enumerate(sentence):
        if char == given:
            box.append(idx)
        
        elif char == target and len(box) > front and idx not in answer:
            answer.add(box[front])
            front += 1

erase_b('B','C')
erase_b('A','B')

print(len(answer))