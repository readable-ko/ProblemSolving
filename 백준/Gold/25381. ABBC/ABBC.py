import sys
sentence = sys.stdin.readline().strip()
answer = set()

box_a = []
box_b = []

# for split a, b, c
for idx, char in enumerate(sentence):
    if char == 'B':
        box_b.append(idx)
    elif char == 'C' and len(box_b) > 0:
        answer.add(box_b.pop(0))

for idx, char in enumerate(sentence):
    if char == 'A':
        box_a.append(idx)   
    elif char == 'B' and len(box_a) > 0 and idx not in answer:
        box_a.pop(0)
        answer.add(idx)
        
print(len(answer))