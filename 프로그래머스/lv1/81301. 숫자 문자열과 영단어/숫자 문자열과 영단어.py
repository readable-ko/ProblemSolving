import re
def solution(s):
    answer = 0
    alph = ['zero', 'one', 'two', 'three', 'four',
         'five', 'six', 'seven', 'eight', 'nine']
    
    for idx, val in enumerate(alph):
        s = re.sub(val, str(idx), s)

    return int(s)