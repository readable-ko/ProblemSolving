from collections import defaultdict
import sys

N = int(sys.stdin.readline())
mp = defaultdict(bool)

def print_word(arr:list):
    for s in arr:
        print(s, end=" ")

def check_word(arr:list):
    check = False
    
    for idx, lst in enumerate(arr):
        s = str.lower(lst)
        if not mp[s[0]]:
            arr[idx] = '[' + arr[idx][0] + ']' + arr[idx][1:]
            mp[s[0]] = True
            print_word(arr)
            return True
    
    return False

def check_char(s:str):
    for idx, c in enumerate(s):
        if not mp[str.lower(c)] and c != ' ':
            mp[str.lower(c)] = True
            print('[{}]'.format(c), end="")
            print(s[idx+1:], end="")
            return
        else:
            print(c, end="")
    return

for i in range(N):
    sentence = sys.stdin.readline().strip()
    sentences = sentence.split()
    
    if check_word(sentences):
        print()
    else:
        check_char(sentence)
        print()