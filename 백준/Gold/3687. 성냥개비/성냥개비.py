import sys
test_case = int(sys.stdin.readline())
minimum = [0,0,1,7,4,2,0,8,10] + [0] * 93

# for minimum range
for idx in range(9, 101):
    minimum[idx] = minimum[idx - 2] * 10 + minimum[2]
    for sub in range(3, 8):
        if idx - sub == 6:
            minimum[idx] = min(minimum[idx], 60 + minimum[sub])
        else:
            minimum[idx] = min(minimum[idx], minimum[idx - sub] * 10 + minimum[sub])
minimum[6] = 6
    
for _ in range(test_case):
    maximum = 0
    matches = int(sys.stdin.readline())

    print(minimum[matches], end=' ')
    
    if matches % 2 == 0:
        for i in range(matches//2):
            print('1', end='')
    else:
        print('7', end='')
        for i in range((matches - 3)//2):
            print('1',end='')
    print()