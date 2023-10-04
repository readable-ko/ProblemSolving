import sys
sentence = sys.stdin.readline().strip()
check = 0

box_a = []
box_b = []
box_c = []

for idx, char in enumerate(sentence):
    if char == 'A':
        box_a.append(idx)
        
    elif char == 'B':
        if len(box_a) != 0:
            box_a.pop(0)
            check += 1
        box_b.append(idx)
        
    elif len(box_b) != 0:
        num = box_b.pop(0)
        print(num)
        check += 1

num_of_b = sentence.count('B')
print(check if check <= num_of_b else num_of_b)